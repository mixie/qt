#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QtCore>
#include <QtGui>
#include <iostream>
#include <patientdialog.h>


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newPictureB_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Otvoriť obrázok"), "C:\\", tr("Obrázky (*.png *.jpg *.bmp *.pbm *.pgm)"));
    cout << fileName.toStdString()<< "\n";
    if(fileName!=""){
        PatientDialog pd;
        pd.setModal(true);
        QList<QString> list;
        list << "p1" << "p2" << "p3";
        pd.setData(list);
        pd.exec();
    }


}
