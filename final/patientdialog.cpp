#include "patientdialog.h"
#include "ui_patientdialog.h"
#include "mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QString>
#include <iostream>

using namespace std;

PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientDialog){
    QString patientName;
    patientName.fromStdString("");
    ui->setupUi(this);
}


PatientDialog::~PatientDialog()
{
    delete ui;
}

void PatientDialog::setData(QList<QString> patients){
    ui->choosePatientComboB->addItems(patients);
}

QString PatientDialog::getData(){
    if(patientName.toStdString()==""){
        return QString::fromStdString("");
    }else{
        if(ui->choosePatientRb->isChecked()){
            return ui->choosePatientComboB->currentText();
        }else{
            if(ui->newPatientRB->isChecked()){
                return ui->newPatientLineE->text();
            }
        }
    }
    return QString::fromStdString("");
}

void PatientDialog::on_newPatientRB_clicked()
{
    ui->choosePatientComboB->setDisabled(true);
    ui->newPatientLineE->setEnabled(true);
}

void PatientDialog::on_choosePatientRb_clicked()
{
    ui->choosePatientComboB->setEnabled(true);
    ui->newPatientLineE->setDisabled(true);
}

void PatientDialog::on_buttonBox_accepted()
{
        patientName=getData();
        cout << ui->choosePatientComboB->currentText().toStdString();
        cout << ui->newPatientLineE->text().toStdString();
        cout << patientName.toStdString()<< "za";

}
