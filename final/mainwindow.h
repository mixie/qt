#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "patient.h"
#include <QGraphicsScene>
#include "chooseciliascene.h"
#include "pictureprocess.h"

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
    void on_newPictureB_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_nextButton_clicked();

    void on_verticalSlider_valueChanged(int value);

    void on_backButton_clicked();

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
    void startAgain();
    vector<QGraphicsEllipseItem *> centreEllipses;


//imageProcessing
    PictureProcess * pictureProcess;
    vector <pair<int,int>> centres;

};

#endif // MAINWINDOW_H
