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

private:
    Ui::MainWindow *ui;
    ChooseCiliaScene * scene;
    PictureProcess * pic_proc;
    QImage initial_image;
};

#endif // MAINWINDOW_H
