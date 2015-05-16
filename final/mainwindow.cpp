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

#define PI 3.14159265

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
    state=1;
    scene=new CiliaScene(this);
    scene->state=1;
    ui->graphicsView->setScene(scene);
    QPixmap im(filename);
    picture=im.toImage();
    scene->addPixmap(im);
    ui->nextButton->setEnabled(true);
    ui->graphicsView->setEnabled(true);
    ui->verticalSlider->setEnabled(true);
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
}

void MainWindow::delState1(){
    scene->removeSamples();
}

void MainWindow::setState2(){
    state=2;
    scene->state=2;
    ui->horizontalSlider->setEnabled(true);
    pictureProcess=new PictureProcess(scene->getCiliaRadius(),scene->getPointX(),scene->getPointY());
    pictureProcess->step0(&picture);
    QImage * im=pictureProcess->step1(defaultSliderPos);
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
    ui->horizontalSlider->setEnabled(false);
}

void MainWindow::setState3(){
    centres=pictureProcess->step2();
    for(int i=0;i<centres.size();i++){
        QGraphicsEllipseItem * newEllipse=new QGraphicsEllipseItem(0,0,8,8);
        QBrush rb(Qt::red);
        QPen rp(Qt::red);
        newEllipse->setOpacity(0.5);
        newEllipse->setBrush(rb);
        newEllipse->setPen(rp);
        newEllipse->setPos(centres[i].second,centres[i].first);
        scene->addItem(newEllipse);
        centreEllipses.push_back(newEllipse);
    }
    state=3;
    scene->state=3;
}

void MainWindow::delState3(){
    for(int i=0;i<centreEllipses.size();i++){
        scene->removeItem(centreEllipses[i]);
    }
}

void MainWindow::backState3(){
    delState3();
    for(int i=0;i<centreEllipses.size();i++){
        delete(centreEllipses[i]);
    }
    centreEllipses.clear();
}

void MainWindow::setState4(){
    QList<QGraphicsItem *> items=scene->items();
    for(int i=0;i<items.size();i++){
        if(items.at(i)->type()==4){
            centres.push_back(make_pair(items.at(i)->pos().y(),items.at(i)->pos().x()));
        }
    }
    vector<int> orient=pictureProcess->step3(centres);
    for(int i=0;i<orient.size();i++){
        double vek_y=qSin(((PI)/100)*orient[i]);
        double vek_x=qCos(((PI)/100)*orient[i]);
        QPen p(Qt::red);
        p.setWidth(3);
        scene->addLine(centres[i].second-vek_x*30.,centres[i].first-vek_y*30.,
                       centres[i].second+vek_x*30.,centres[i].first+vek_y*30.,p);
    }
    ui->nextButton->setText("Dokončiť");
}

void MainWindow::on_newPictureB_clicked()
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
    }
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
   QImage * im=pictureProcess->step1(position);
   scene->removeItem(picturePix);
   delete(picturePix);
   picturePix=new QGraphicsPixmapItem(QPixmap::fromImage(*im));
   picturePix->setOpacity(0.5);
   scene->addItem(picturePix);
}

void MainWindow::on_nextButton_clicked()
{
    if(state==1){
        if(scene->samplesAddes()){
            delState1();
            setState2();
        }
    }
    else if(state==2){
        delState2();
        setState3();
    }else if(state==3){
        setState4();
        delState3();
    }
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
}
