/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNov_obr_zok22;
    QAction *actionInfo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QSlider *verticalSlider;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QSlider *horizontalSlider;
    QPushButton *nextButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuNov_obr_zok;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(731, 488);
        MainWindow->setBaseSize(QSize(0, 3));
        actionNov_obr_zok22 = new QAction(MainWindow);
        actionNov_obr_zok22->setObjectName(QStringLiteral("actionNov_obr_zok22"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);

        verticalLayout_2->addWidget(label_3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSlider = new QSlider(groupBox_3);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setEnabled(false);
        verticalSlider->setMinimum(1);
        verticalSlider->setMaximum(20);
        verticalSlider->setSingleStep(1);
        verticalSlider->setPageStep(3);
        verticalSlider->setValue(4);
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider, 1, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_3);

        graphicsView = new QGraphicsView(groupBox_2);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(false);
        graphicsView->setMouseTracking(true);

        horizontalLayout_2->addWidget(graphicsView);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        backButton = new QPushButton(groupBox);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setEnabled(false);

        horizontalLayout->addWidget(backButton);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setEnabled(false);
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setSingleStep(5);
        horizontalSlider->setPageStep(20);
        horizontalSlider->setValue(170);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        nextButton = new QPushButton(groupBox);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setEnabled(false);

        horizontalLayout->addWidget(nextButton);


        verticalLayout_2->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 27));
        menuNov_obr_zok = new QMenu(menuBar);
        menuNov_obr_zok->setObjectName(QStringLiteral("menuNov_obr_zok"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuNov_obr_zok->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuNov_obr_zok->addAction(actionNov_obr_zok22);
        menuAbout->addAction(actionInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CiDi - Rozozn\303\241vanie orient\303\241cie riasiniek", 0));
        actionNov_obr_zok22->setText(QApplication::translate("MainWindow", "Nov\303\275 obr\303\241zok", 0));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0));
        label_3->setText(QApplication::translate("MainWindow", "Vitajte v aplik\303\241cii na rozozn\303\241vanie riasiniek. Za\304\215nite vybrat\303\255m obr\303\241zku s riasinkami v hornom menu S\303\272bor.", 0));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "  -", 0));
        label->setText(QApplication::translate("MainWindow", "  +", 0));
        groupBox->setTitle(QString());
        backButton->setText(QApplication::translate("MainWindow", "Back", 0));
        nextButton->setText(QApplication::translate("MainWindow", "Next", 0));
        menuNov_obr_zok->setTitle(QApplication::translate("MainWindow", "S\303\272bor", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Info", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
