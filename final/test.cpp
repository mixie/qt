#include "test.h"
#include "ui_test.h"
#include <QGraphicsScene>

Test::Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    QGraphicsScene * scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QBrush rb(Qt::red);
    QPen bl(Qt::blue);
    scene->addRect(25,25,50,50,bl,rb);
    scene->addRect(-25,-25,-100,-100,bl,rb);

}

Test::~Test()
{
    delete ui;
}
