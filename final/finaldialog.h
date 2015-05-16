#ifndef FINALDIALOG_H
#define FINALDIALOG_H

#include <QDialog>

namespace Ui {
class FinalDialog;
}

class FinalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FinalDialog(QWidget *parent,QString patientName,int num_cilia,double dev1,double dev2);
    ~FinalDialog();

private:
    Ui::FinalDialog *ui;
};

#endif // FINALDIALOG_H
