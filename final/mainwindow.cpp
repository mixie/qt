#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QtCore>
#include <QtGui>
#include <iostream>
#include <QPixmap>
#include "patientdialog.h"
#include <QGraphicsPixmapItem>
#include "test.h"
#include "filehelper.h"
#include "picturedeviation.h"
#include "finaldialog.h"
#include "aboutdialog.h"
#include <QMessageBox>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    state=0;
    scene=0;
    pictureProcess=0;
    picturePix=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startAgain(){
    if(scene){
        delete(scene);
    }
}

void MainWindow::setState1(QString filename){
    ui->label_3->setText("Dvojklikom presne kliknite do stredu jednej riasinky. Stlačením a držaním tlačidla myši od stredu po okraj riasinky nakreslite kruh.");
    state=1;
    scene=new CiliaScene(this);
    scene->state=1;
    ui->graphicsView->setScene(scene);
    QPixmap im(filename);
    picture=im.toImage();
    scene->addPixmap(im);
    ui->nextButton->setEnabled(true);
    ui->backButton->setEnabled(false);
    ui->graphicsView->setEnabled(true);
    ui->verticalSlider->setEnabled(true);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
}

void MainWindow::delState1(){
    scene->removeSamples();
}

void MainWindow::setState2(){
    ui->label_3->setText("Posuňte horizontálny posuvník tak, aby bolo vyznačených čo najviac stredov riasiniek a zároveň čo najmenej iných častí obrázkov.");
    state=2;
    scene->state=2;
    ui->verticalSlider->setValue(4);
    ui->horizontalSlider->setEnabled(true);
    pictureProcess=new PictureProcess(scene->getCiliaRadius(),scene->getPointX(),scene->getPointY());
    pictureProcess->step0(&picture);
    QImage * im=pictureProcess->step1(ui->horizontalSlider->value());
    picturePix=new QGraphicsPixmapItem(QPixmap::fromImage(*im));
    picturePix->setOpacity(0.5);
    scene->addItem(picturePix);
    ui->backButton->setEnabled(true);
}

void MainWindow::backState2(){
    state=1;
    scene->state=1;
    delete(pictureProcess);
    delState2();
}

void MainWindow::delState2(){
    scene->removeItem(picturePix);
    delete(picturePix);
}

void MainWindow::setState3(){
    state=-1;
    ui->horizontalSlider->setEnabled(true);
    ui->horizontalSlider->setValue(180);
    state=2;
    ui->label_3->setText("Dvojklikom myši môžete stredy riasiniek pridávať a odoberať. Držaním myši môžete stredy posúvať.");
    centres=pictureProcess->step2(ui->horizontalSlider->value());
    scene->addCentreEllipses(centres);
    state=3;
    scene->state=3;
}

void MainWindow::delState4(){
    scene->removeOrientLinesFromScene();
    scene->deleteOrientLines();
}

void MainWindow::backState4(){
    delState4();
    scene->addCentreEllipses(centres);
    state=3;
    scene->state=3;
    ui->nextButton->setText("Ďalej");
    ui->horizontalSlider->setEnabled(true);
}

void MainWindow::delState3(){
    scene->removeCentreEllipsesFromScene();
}

void MainWindow::backState3(){
    scene->deleteCentreEllipses();
    setState2();
}

void MainWindow::setState4(){
    ui->horizontalSlider->setEnabled(false);
    ui->label_3->setText("Pravým klikom myši otočíte najbližšou riasinkou doprava. Ľavým klikom myši doľava. CTRL + dvojklik vymaže otočenie.");
    scene->getCentersFromScene(centres);
    pictureProcess->step3(centres,num_lines,orient);
    scene->drawOrientationLines(orient,centres,num_lines);
    ui->nextButton->setText("Dokončiť");
    state=4;
    scene->state=4;
}


void MainWindow::on_nextButton_clicked()
{
    if(state==1){
        if(scene->samplesAddes()){
            delState1();
            setState2();
        }else{
            QMessageBox messageBox;
            messageBox.setText("Nezadali ste stred a polomer riasinky.");
            messageBox.setModal(true);
            messageBox.exec();
        }
    }
    else if(state==2){
        delState2();
        setState3();
    }else if(state==3){
        setState4();
        delState3();
    }else if(state==4){
        finishPic();
    }
}

void MainWindow::finishPic(){
    scene->getOrientations(orient);
    double dev=pictureProcess->step4(orient,num_lines);
    int num_cilia=orient.size();
    QList<PictureDeviation*> devs;
    FileHelper::getPatientDeviations(patientFile,patientName,devs);
    PictureDeviation *newDev=new PictureDeviation(dev,num_cilia);
    devs.append(newDev);
    int countOverall;
    double overallDev=PictureDeviation::countNewDeviation(devs,countOverall);
    FinalDialog fd(this,patientName,num_cilia,dev,overallDev);
    fd.setModal(true);
    if(fd.exec()==QDialog::Accepted){
        FileHelper::addPatientDeviationToFile(*newDev,patientFile);
    }
    PictureDeviation pd1(overallDev,countOverall);
    FileHelper::addPatientOverallDevToFIle(pd1 ,patientFile);
}


void MainWindow::on_verticalSlider_valueChanged(int value)
{
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
    ui->graphicsView->scale(value/4.,value/4.);
}


void MainWindow::on_backButton_clicked()
{
    if(state==2){
        backState2();
    }
    if(state==3){
        backState3();
    }
    if(state==4){
        backState4();
    }
}

void MainWindow::on_actionNov_obr_zok22_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Otvoriť obrázok"), "C:\\", tr("Obrázky (*.png *.jpg *.bmp *.pbm *.pgm)"));
    if(filename!=""){
        PatientDialog pd;
        pd.setModal(true);
        pd.populateData();
        if(pd.exec()==QDialog::Accepted){
            setState1(filename);
        }
        patientFile=pd.patient.filename;
        patientName=pd.patient.name;
        if(pd.isNewPatient()){
            FileHelper::createNewPatient(patientName,patientFile);
        }
        ui->nextButton->setText("Next");
    }
}

void MainWindow::on_actionInfo_triggered()
{
    AboutDialog ad(this);
    ad.exec();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    cout << "state:"<<state << "\n";
    if(state==2){
        QImage * im=pictureProcess->step1(value);
        scene->removeItem(picturePix);
        delete(picturePix);
        picturePix=new QGraphicsPixmapItem(QPixmap::fromImage(*im));
        picturePix->setOpacity(0.5);
        scene->addItem(picturePix);
    }else if(state==3){
         centres.clear();
         centres=pictureProcess->step2_1(value);
         scene->removeCentreEllipsesFromScene();
         scene->deleteCentreEllipses();
         scene->addCentreEllipses(centres);
    }
}
