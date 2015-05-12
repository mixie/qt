#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "patient.h"
#include <QGraphicsScene>
#include "chooseciliascene.h"

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

private:
    Ui::MainWindow *ui;
    ChooseCiliaScene * scene;
};

#endif // MAINWINDOW_H
