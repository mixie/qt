#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T15:36:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = final
TEMPLATE = app

INCLUDEPATH += /usr/include/opencv
LIBS += -L/usr/lib/i386-linux-gnu -lopencv_core -lopencv_imgproc -lopencv_highgui

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
    pictureprocess.cpp \
    finaldialog.cpp \
    picturedeviation.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    patientdialog.h \
    filehelper.h \
    patient.h \
    test.h \
    chooseciliascene.h \
    ciliarecognition.h \
    cilia.h \
    picture.h \
    pictureprocess.h \
    finaldialog.h \
    picturedeviation.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    patientdialog.ui \
    test.ui \
    finaldialog.ui \
    aboutdialog.ui

DISTFILES += \
    data/init.csv \
    data/jozko_mrkvicka_1234.csv \
    data/janko_dobry_157.csv \
    data/kristinka_syslova_1578.csv \
    data/Mama_Naja_sum.csv \
    data/Mama_Naja.csv \
    data/Mama Naja.csv \
    data/Maja_Maja_sum.csv \
    data/Maja_Maja.csv \
    data/Maja Maja.csv \
    data/jozko_mrkvicka_1234_sum.csv \
    data/Janko_Janko_sum.csv \
    data/Janko_Janko.csv \
    data/Ja_Ja_sum.csv \
    data/Ja_Ja_Ja_sum.csv \
    data/jajaja_sum.csv \
    data/Ja_Ja_Ja_Ja_sum.csv \
    data/jaja_jaja_sum.csv \
    data/Ja_Ja_Ja_Ja.csv \
    data/jaja_jaja.csv \
    data/Ja_Ja_Ja.csv \
    data/Ja Ja Ja.csv \
    data/jajaja.csv \
    data/Ja_Ja.csv \
    data/JaJa.csv \
    data/Aha Aha.csv
