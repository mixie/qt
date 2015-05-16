#include "patientdialog.h"
#include "ui_patientdialog.h"
#include <QtCore>
#include <QtGui>
#include <QString>
#include <iostream>
#include "filehelper.h"

using namespace std;


PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientDialog){
    Patient patient;
    QList<Patient> patients;
    ui->setupUi(this);
}


PatientDialog::~PatientDialog()
{
    delete ui;
}

void PatientDialog::populateData(){
    patients=FileHelper::getPatients();
    cout << patients.size();
    for(int i=0;i<patients.size();i++){
         ui->choosePatientComboB->addItem(patients[i].name);
    }
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
        patient=patients[ui->choosePatientComboB->currentIndex()];

    }
    if(ui->newPatientRB->isChecked()){
        QString patientname=ui->newPatientLineE->text();
        QString filename(patientname);
        patient.filename=filename.replace(" ","_");
        cout << patient.filename.toStdString() << "\n";
        patient.name=patientname;
    }
}

bool PatientDialog::isNewPatient(){
    return ui->newPatientRB->isChecked();
}
