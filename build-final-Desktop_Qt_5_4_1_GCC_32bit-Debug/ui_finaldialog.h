/********************************************************************************
** Form generated from reading UI file 'finaldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALDIALOG_H
#define UI_FINALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_FinalDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *Pacient;
    QLabel *name;
    QLabel *Pocet;
    QLabel *count;
    QLabel *Odchylka1;
    QLabel *deviation1;
    QLabel *Odchylka2;
    QLabel *deviation2;

    void setupUi(QDialog *FinalDialog)
    {
        if (FinalDialog->objectName().isEmpty())
            FinalDialog->setObjectName(QStringLiteral("FinalDialog"));
        FinalDialog->resize(525, 300);
        buttonBox = new QDialogButtonBox(FinalDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Pacient = new QLabel(FinalDialog);
        Pacient->setObjectName(QStringLiteral("Pacient"));
        Pacient->setGeometry(QRect(30, 10, 71, 20));
        name = new QLabel(FinalDialog);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(300, 10, 55, 17));
        Pocet = new QLabel(FinalDialog);
        Pocet->setObjectName(QStringLiteral("Pocet"));
        Pocet->setGeometry(QRect(30, 50, 171, 17));
        count = new QLabel(FinalDialog);
        count->setObjectName(QStringLiteral("count"));
        count->setGeometry(QRect(300, 50, 55, 17));
        Odchylka1 = new QLabel(FinalDialog);
        Odchylka1->setObjectName(QStringLiteral("Odchylka1"));
        Odchylka1->setGeometry(QRect(30, 90, 251, 17));
        deviation1 = new QLabel(FinalDialog);
        deviation1->setObjectName(QStringLiteral("deviation1"));
        deviation1->setGeometry(QRect(300, 90, 55, 17));
        Odchylka2 = new QLabel(FinalDialog);
        Odchylka2->setObjectName(QStringLiteral("Odchylka2"));
        Odchylka2->setGeometry(QRect(30, 140, 251, 17));
        deviation2 = new QLabel(FinalDialog);
        deviation2->setObjectName(QStringLiteral("deviation2"));
        deviation2->setGeometry(QRect(300, 140, 55, 17));

        retranslateUi(FinalDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FinalDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FinalDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FinalDialog);
    } // setupUi

    void retranslateUi(QDialog *FinalDialog)
    {
        FinalDialog->setWindowTitle(QApplication::translate("FinalDialog", "Dialog", 0));
        Pacient->setText(QApplication::translate("FinalDialog", "Pacient:", 0));
        name->setText(QApplication::translate("FinalDialog", "Meno", 0));
        Pocet->setText(QApplication::translate("FinalDialog", "Po\304\215et riasiniek na obr\303\241zku:", 0));
        count->setText(QApplication::translate("FinalDialog", "Po\304\215et", 0));
        Odchylka1->setText(QApplication::translate("FinalDialog", "\305\240tandartn\303\241 odch\303\275lka riasiniek na obr\303\241zku:", 0));
        deviation1->setText(QApplication::translate("FinalDialog", "Odchylka1", 0));
        Odchylka2->setText(QApplication::translate("FinalDialog", "\305\240tandartn\303\241 odch\303\275lka riasiniek pacienta:", 0));
        deviation2->setText(QApplication::translate("FinalDialog", "Odchylka1", 0));
    } // retranslateUi

};

namespace Ui {
    class FinalDialog: public Ui_FinalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALDIALOG_H
