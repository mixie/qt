#include "chooseciliascene.h"
#include <iostream>

using namespace std;

CiliaScene::CiliaScene(QObject *parent) :
    QGraphicsScene(parent)
{\
    QBrush rb(Qt::red);
    QPen rp(Qt::red);
    rp.setWidth(3);
    point=new QGraphicsEllipseItem(0,0,10,10);
    point->setFlag(QGraphicsItem::ItemIsMovable);
    point->setBrush(rb);
    pointSize=8;
    point->setPen(rp);
    point->setOpacity(0.5);
    pointAdded=false;
    cilia=new QGraphicsEllipseItem(0,0,pointSize,pointSize);
    cilia->setFlag(QGraphicsItem::ItemIsMovable);
    ciliaAdded=false;
    cilia->setPen(rp);
    cilia->setOpacity(0.5);
    state=1;
}


void CiliaScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if(state==1){
        point->setPos(mouseEvent->scenePos().x()-pointSize,mouseEvent->scenePos().y()-pointSize);
        if(!pointAdded){
            this->addItem(point);
               pointAdded=true;
        }
    }
    if(state==3){
        QGraphicsItem * it=this->itemAt(mouseEvent->scenePos(), QTransform());
        if(it->type()==4){
            this->removeItem(it);
        }else{
            QBrush rb(Qt::red);
            QPen bl(Qt::blue);
            QGraphicsEllipseItem * it= new QGraphicsEllipseItem(0,0,7,7); //uvolnit vsetky tie pointre!!!
            it->setBrush(rb);
            it->setPen(bl);
            it->setPos(mouseEvent->scenePos().x()-4,mouseEvent->scenePos().y()-4);
            this->addItem(it);
        }
    }
    QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
}

void CiliaScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if(state==1){
        startX=mouseEvent->scenePos().x();
        startY=mouseEvent->scenePos().y();
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void CiliaScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent){
    if(state==1){
        if(!ciliaAdded){
            this->addItem(cilia);
            ciliaAdded=true;
        }
        if((qAbs(mouseEvent->scenePos().x()-startX)>1)&&(qAbs(mouseEvent->scenePos().y()-startY)>1)){
            cilia->setRect(startX,startY,qAbs(mouseEvent->scenePos().x()-startX),qAbs(mouseEvent->scenePos().y()-startY));
        }
    }
    QGraphicsScene::mouseReleaseEvent(mouseEvent);

}

bool CiliaScene::samplesAddes(){
    return ciliaAdded&&pointAdded;
}

void CiliaScene::removeSamples(){
    this->removeItem(cilia);
    this->removeItem(point);
    pointAdded=false;
    ciliaAdded=false;
}

//TODO: v destruktore deletnut point a ciliu

int CiliaScene::getCiliaRadius(){
    return (cilia->rect().height()+cilia->rect().width())/4;
}
int CiliaScene::getPointX(){
    return point->scenePos().x();
}
int CiliaScene::getPointY(){
    return point->scenePos().y();
}

void addCentres(){

}


