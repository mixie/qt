#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "patient.h"
#include <QGraphicsScene>
#include "chooseciliascene.h"
#include "pictureprocess.h"

#define num_lines 180

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void gotNewPicture(Patient patient);
    ~MainWindow();

private slots:
    void on_nextButton_clicked();

    void on_verticalSlider_valueChanged(int value);

    void on_backButton_clicked();

    void on_actionNov_obr_zok22_triggered();

    void on_actionInfo_triggered();

    void on_horizontalSlider_valueChanged(int value);

private:
//graphics
    Ui::MainWindow *ui;
    CiliaScene * scene;
    QImage picture;
    QGraphicsPixmapItem * picturePix;
    int state;
    int defaultSliderPos;
    void setState1(QString);
    void delState1();
    void setState2();
    void delState2();
    void backState2();
    void setState3();
    void delState3();
    void backState3();
    void setState4();
    void delState4();
    void backState4();
    void startAgain();
    void finishPic();


//imageProcessing
    PictureProcess * pictureProcess;
    vector <pair<int,int>> centres;
    vector <int> orient;

//patientInfo
    QString patientName;
    QString patientFile;
};

#endif // MAINWINDOW_H
