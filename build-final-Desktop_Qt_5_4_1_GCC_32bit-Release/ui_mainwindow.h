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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *newPictureB;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QSlider *horizontalSlider;
    QPushButton *nextButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuObr_zok;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(731, 488);
        MainWindow->setBaseSize(QSize(0, 3));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        newPictureB = new QPushButton(centralWidget);
        newPictureB->setObjectName(QStringLiteral("newPictureB"));

        verticalLayout->addWidget(newPictureB);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(false);
        graphicsView->setMouseTracking(true);

        verticalLayout->addWidget(graphicsView);

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
        horizontalSlider->setValue(200);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        nextButton = new QPushButton(groupBox);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setEnabled(false);

        horizontalLayout->addWidget(nextButton);


        verticalLayout->addWidget(groupBox);

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
        menuObr_zok = new QMenu(menuBar);
        menuObr_zok->setObjectName(QStringLiteral("menuObr_zok"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuObr_zok->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Rozozn\303\241vanie orient\303\241cie riasiniek", 0));
        newPictureB->setText(QApplication::translate("MainWindow", "Nov\303\275 obr\303\241zok", 0));
        groupBox->setTitle(QString());
        backButton->setText(QApplication::translate("MainWindow", "Back", 0));
        nextButton->setText(QApplication::translate("MainWindow", "Next", 0));
        menuObr_zok->setTitle(QApplication::translate("MainWindow", "Nov\303\275 obr\303\241zok", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
