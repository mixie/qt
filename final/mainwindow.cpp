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


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    state=0;
    defaultSliderPos=200;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newPictureB_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Otvoriť obrázok"), "C:\\", tr("Obrázky (*.png *.jpg *.bmp *.pbm *.pgm)"));
    if(fileName!=""){
        PatientDialog pd;
        pd.setModal(true);
        pd.populateData();
        if(pd.exec()==QDialog::Accepted){
            scene=new ChooseCiliaScene(this);
            ui->graphicsView->setScene(scene);
            QPixmap im(fileName);
            initial_image=im.toImage();
            QBrush rb(Qt::red);
            QPen bl(Qt::blue);
            scene->addPixmap(im);
            ui->nextButton->setEnabled(true);
            ui->graphicsView->setEnabled(true);
            state=1;
        }
    }

}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
   QImage * im=pic_proc->step1(position);
   scene->removeItem(pix);
   pix=new QGraphicsPixmapItem(QPixmap::fromImage(*im));
   pix->setOpacity(0.5);
   scene->addItem(pix);
}

void MainWindow::on_nextButton_clicked()
{
    if(state==1){
        if(scene->samplesAddes()){
            scene->removeSamples();
            ui->horizontalSlider->setEnabled(true);
            pic_proc=new PictureProcess(scene->getCiliaRadius(),scene->getPointX(),scene->getPointY());
            pic_proc->step0(&initial_image);
            QImage * im=pic_proc->step1(defaultSliderPos);
            pix=new QGraphicsPixmapItem(QPixmap::fromImage(*im));
            pix->setOpacity(0.5);
            scene->addItem(pix);
            state=2;
        }
    }
    else if(state==2){
        scene->removeItem(pix);
        //pic_proc->step2();
    }

}
