#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T15:36:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = final
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    patientdialog.cpp \
    filehelper.cpp \
    patient.cpp \
    test.cpp \
    chooseciliascene.cpp \
    ciliarecognition.cpp \
    cilia.cpp \
    picture.cpp \
    pictureprocess.cpp

HEADERS  += mainwindow.h \
    patientdialog.h \
    filehelper.h \
    patient.h \
    test.h \
    chooseciliascene.h \
    ciliarecognition.h \
    cilia.h \
    picture.h \
    pictureprocess.h

FORMS    += mainwindow.ui \
    patientdialog.ui \
    test.ui

DISTFILES += \
    data/init.csv \
    data/jozko_mrkvicka_1234.csv \
    data/janko_dobry_157.csv \
    data/kristinka_syslova_1578.csv
