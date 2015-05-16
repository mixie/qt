#include "finaldialog.h"
#include "ui_finaldialog.h"

FinalDialog::FinalDialog(QWidget *parent,QString patientName,int num_cilia,double dev1,double dev2) :
    QDialog(parent),
    ui(new Ui::FinalDialog)
{
    ui->setupUi(this);
    ui->deviation1->setText(QString::number(dev1));
    ui->deviation2->setText(QString::number(dev2));
    ui->count->setText(QString::number(num_cilia));
    ui->name->setText(patientName);
}

FinalDialog::~FinalDialog()
{
    delete ui;
}
