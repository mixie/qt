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
            ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
           // scale=4;
            state=1;
            scene->state=1;
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
    //ui->graphicsView->scale(0.5,0.5);
    if(state==1){
        if(scene->samplesAddes()){
            scene->removeSamples();
            ui->horizontalSlider->setEnabled(true);
            ui->verticalSlider->setEnabled(true);
            pic_proc=new PictureProcess(scene->getCiliaRadius(),scene->getPointX(),scene->getPointY());
            pic_proc->step0(&initial_image);
            QImage * im=pic_proc->step1(defaultSliderPos);
            pix=new QGraphicsPixmapItem(QPixmap::fromImage(*im));
            pix->setOpacity(0.5);
            scene->addItem(pix);
            state=2;
            scene->state=2;
        }
    }
    else if(state==2){
        ui->horizontalSlider->setEnabled(false);
        scene->removeItem(pix);
        vector <pair<int,int>> centres=pic_proc->step2();
        QBrush rb(Qt::red);
        QPen bl(Qt::blue);
       // vector<QGraphicsEllipseItem *> centres1;
        for(int i=0;i<centres.size();i++){
            QGraphicsEllipseItem * it= new QGraphicsEllipseItem(0,0,7,7); //uvolnit vsetky tie pointre!!!
            it->setBrush(rb);
            it->setPen(bl);
            it->setPos(centres[i].second,centres[i].first);
            scene->addItem(it);
        }
        for(int i=0;i<centres.size();i++){
            cout << centres[i].first << " " << centres[i].second << "\n";
        }
        cout << "**********\n";
        state=3;
        scene->state=3;
    }else if(state==3){
        vector <pair<int,int>> centres;
        QList<QGraphicsItem *> items=scene->items();
        for(int i=0;i<items.size();i++){
            if(items.at(i)->type()==4){
                centres.push_back(make_pair(items.at(i)->pos().y(),items.at(i)->pos().x()));
            }
        }
        for(int i=0;i<centres.size();i++){
            cout << centres[i].first << " " << centres[i].second << "\n";
        }
        vector<int> orient=pic_proc->step3(centres);
        QBrush rb(Qt::red);
        QPen bl(Qt::blue);
        for(int i=0;i<orient.size();i++){
            cout << "tu tu\n";
            double vek_y=qSin(((PI)/100)*orient[i]);
            double vek_x=qCos(((PI)/100)*orient[i]);
            QPen p(Qt::red);
            p.setWidth(3);
            scene->addLine(centres[i].second-vek_x*30.,centres[i].first-vek_y*30.,
                           centres[i].second+vek_x*30.,centres[i].first+vek_y*30.,p);
            for(int j=-25;j<25;j+=2){
                      //  scene->addEllipse(centres[i].first+vek_x*j,centres[i].second+vek_y*j,
                       //                  2,2,bl);
                    }
        }
    }

}


void MainWindow::on_verticalSlider_valueChanged(int value)
{
    ui->graphicsView->fitInView(scene->itemsBoundingRect() ,Qt::KeepAspectRatio);
    ui->graphicsView->scale(value/4.,value/4.);
}
