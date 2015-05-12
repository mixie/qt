#include "chooseciliascene.h"
#include <iostream>

using namespace std;

ChooseCiliaScene::ChooseCiliaScene(QObject *parent) :
    QGraphicsScene(parent)
{\
    point=new QGraphicsEllipseItem(0,0,10,10);
    point->setFlag(QGraphicsItem::ItemIsMovable);
    QBrush rb(Qt::red);
    QPen rp(Qt::red);
    point->setBrush(rb);
    pointSize=8;
    point->setPen(rp);
    pointAdded=false;
    cilia=new QGraphicsEllipseItem(0,0,pointSize,pointSize);
    cilia->setFlag(QGraphicsItem::ItemIsMovable);
    ciliaAdded=false;
    cilia->setPen(rp);

}


void ChooseCiliaScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent){
    point->setPos(mouseEvent->scenePos().x()-pointSize,mouseEvent->scenePos().y()-pointSize);
    cout << "bod:"<< mouseEvent->scenePos().x()-pointSize << " " <<mouseEvent->scenePos().x()-pointSize << "\n";
    if(!pointAdded){
        this->addItem(point);
           pointAdded=true;
    }
    QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
}

void ChooseCiliaScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
    startX=mouseEvent->scenePos().x();
    startY=mouseEvent->scenePos().y();
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void ChooseCiliaScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent){
    if(!ciliaAdded){
        this->addItem(cilia);
        ciliaAdded=true;
    }
    if((qAbs(mouseEvent->scenePos().x()-startX)>1)&&(qAbs(mouseEvent->scenePos().y()-startY)>1)){
        cilia->setRect(startX,startY,qAbs(mouseEvent->scenePos().x()-startX),qAbs(mouseEvent->scenePos().y()-startY));
        QGraphicsScene::mouseReleaseEvent(mouseEvent);
    }
}
