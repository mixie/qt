/********************************************************************************
** Form generated from reading UI file 'patientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTDIALOG_H
#define UI_PATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientDialog
{
public:
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QRadioButton *newPatientRB;
    QLineEdit *newPatientLineE;
    QRadioButton *choosePatientRb;
    QComboBox *choosePatientComboB;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PatientDialog)
    {
        if (PatientDialog->objectName().isEmpty())
            PatientDialog->setObjectName(QStringLiteral("PatientDialog"));
        PatientDialog->resize(480, 165);
        widget = new QWidget(PatientDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 451, 191));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        newPatientRB = new QRadioButton(widget);
        newPatientRB->setObjectName(QStringLiteral("newPatientRB"));

        formLayout->setWidget(1, QFormLayout::LabelRole, newPatientRB);

        newPatientLineE = new QLineEdit(widget);
        newPatientLineE->setObjectName(QStringLiteral("newPatientLineE"));
        newPatientLineE->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, newPatientLineE);

        choosePatientRb = new QRadioButton(widget);
        choosePatientRb->setObjectName(QStringLiteral("choosePatientRb"));

        formLayout->setWidget(2, QFormLayout::LabelRole, choosePatientRb);

        choosePatientComboB = new QComboBox(widget);
        choosePatientComboB->setObjectName(QStringLiteral("choosePatientComboB"));
        choosePatientComboB->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, choosePatientComboB);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(PatientDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PatientDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PatientDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PatientDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientDialog)
    {
        PatientDialog->setWindowTitle(QApplication::translate("PatientDialog", "Dialog", 0));
        label->setText(QApplication::translate("PatientDialog", "V\303\275ber osoby k obr\303\241zku ", 0));
        newPatientRB->setText(QApplication::translate("PatientDialog", "nov\303\241 osoba", 0));
        choosePatientRb->setText(QApplication::translate("PatientDialog", "vybra\305\245 zo zoznamu", 0));
    } // retranslateUi

};

namespace Ui {
    class PatientDialog: public Ui_PatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDIALOG_H
