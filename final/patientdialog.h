#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "patient.h"

namespace Ui {
class PatientDialog;
}

class PatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PatientDialog(QWidget *parent = 0);
    ~PatientDialog();
    void populateData();
    QList<Patient> patients;
    Patient patient;
    bool isNewPatient();


private slots:
    void on_newPatientRB_clicked();

    void on_choosePatientRb_clicked();

    void on_buttonBox_accepted();

private:
    Ui::PatientDialog *ui;
};

#endif // PATIENTDIALOG_H
