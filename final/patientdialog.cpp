#include "patientdialog.h"
#include "ui_patientdialog.h"
#include <QtCore>
#include <QtGui>
#include <QString>

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
    if()
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
    if(ui->choosePatientRb->isChecked()){

    }
}
