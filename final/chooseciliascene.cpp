#include "chooseciliascene.h"
#include <iostream>
using namespace std;

CiliaScene::CiliaScene(QObject *parent) :
    QGraphicsScene(parent)
{\
    rp=new QPen(Qt::red);
    rp->setWidth(4);
    rb=new QBrush(Qt::red);
    point=new QGraphicsEllipseItem(0,0,point_size,point_size);
    point->setFlag(QGraphicsItem::ItemIsMovable);
    point->setBrush(*rb);
    point->setPen(*rp);
    point->setOpacity(opacity);
    pointAdded=false;
    cilia=new QGraphicsEllipseItem(0,0,point_size,point_size);
    cilia->setFlag(QGraphicsItem::ItemIsMovable);
    ciliaAdded=false;
    cilia->setPen(*rp);
    cilia->setOpacity(opacity);
    state=1;
}


void CiliaScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if(state==1){
        point->setPos(mouseEvent->scenePos().x()-point_size,mouseEvent->scenePos().y()-point_size);
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
            QGraphicsEllipseItem * it= new QGraphicsEllipseItem(0,0,point_size,point_size);
            it->setBrush(*rb);
            it->setPen(*rp);
            it->setPos(mouseEvent->scenePos().x()-point_size/2,mouseEvent->scenePos().y()-point_size/2);
            it->setOpacity(opacity);
            this->addItem(it);
            centreEllipses.push_back(it);
        }
    }
    if(state==4){
        int x=mouseEvent->scenePos().x();
        int y=mouseEvent->scenePos().y();
        QList<QGraphicsItem *> items=this->items(x-getCiliaRadius()*2,
                                            y-getCiliaRadius()*2,x+getCiliaRadius()*2,
                                            y+getCiliaRadius()*2,Qt::IntersectsItemShape,Qt::DescendingOrder);
        QGraphicsItem * min_item=0;
        double min_dist=9999999;
        for(int i=0;i<items.size();i++){
            if(items.at(i)->type()==6){
                QGraphicsItem * item=items.at(i);
                int dist_x=item->boundingRect().center().x()-mouseEvent->scenePos().x();
                int dist_y=item->boundingRect().center().y()-mouseEvent->scenePos().y();
                double dist=qSqrt(dist_x*dist_x+dist_y*dist_y);
                if(dist<min_dist){
                    min_dist=dist;
                    min_item=item;
                }
            }
        }
        if(min_item!=0){
            min_item->setTransformOriginPoint(min_item->boundingRect().center());
            if(mouseEvent->button()==Qt::LeftButton){
                min_item->setRotation(min_item->rotation()-rotation_unit);
            }
            if(mouseEvent->button()==Qt::RightButton){
                min_item->setRotation(min_item->rotation()+rotation_unit);
            }
        }
        if(QGuiApplication::keyboardModifiers()==0x04000000){
            this->removeItem(min_item);
        }
    }
    QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
}

void CiliaScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if(state==1){
        if(QGuiApplication::keyboardModifiers()==0x04000000){
            startX=mouseEvent->scenePos().x();
            startY=mouseEvent->scenePos().y();
        }
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void CiliaScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent){
    if(state==1){
        if(QGuiApplication::keyboardModifiers()==0x04000000){
            if(!ciliaAdded){
                this->addItem(cilia);
                ciliaAdded=true;
            }
            int max=qMax(qAbs(mouseEvent->scenePos().x()-startX),qAbs(mouseEvent->scenePos().y()-startY));
            if(max>1){
                int diffx=qAbs(mouseEvent->scenePos().x()-startX);
                int diffy=qAbs(mouseEvent->scenePos().y()-startY);
                int z=qSqrt((diffx*diffx+diffy*diffy));
                cilia->setRect(startX-z,startY-z,z*2,z*2);
            }
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

void CiliaScene::returnSamples(){
    this->addItem(cilia);
    this->addItem(point);
    pointAdded=true;
    ciliaAdded=true;
}

//TODO: v destruktore deletnut point a ciliu

int CiliaScene::getCiliaRadius(){
    return qMax(cilia->rect().height(),cilia->rect().width())/2;
}
int CiliaScene::getPointX(){
    return point->scenePos().x();
}
int CiliaScene::getPointY(){
    return point->scenePos().y();
}

void CiliaScene::addCentreEllipses(vector <pair<int,int>> & centres){
    for(int i=0;i<centres.size();i++){
        QGraphicsEllipseItem * newEllipse=new QGraphicsEllipseItem(0,0,point_size,point_size);
        newEllipse->setOpacity(opacity);
        newEllipse->setBrush(*rb);
        newEllipse->setPen(*rp);
        newEllipse->setPos(centres[i].second,centres[i].first);
        newEllipse->setFlag(QGraphicsItem::ItemIsMovable);
        this->addItem(newEllipse);
        centreEllipses.push_back(newEllipse);
    }
}

void CiliaScene::removeCentreEllipsesFromScene(){
    for(int i=0;i<centreEllipses.size();i++){
        this->removeItem(centreEllipses[i]);
    }
}

void CiliaScene::deleteCentreEllipses(){
    for(int i=0;i<centreEllipses.size();i++){
        delete(centreEllipses[i]);
    }
    centreEllipses.clear();
}

void CiliaScene::getCentersFromScene(vector<pair<int,int>> & centres){
    centres.clear();
    QList<QGraphicsItem *> items=this->items();
    for(int i=0;i<items.size();i++){
        if(items.at(i)->type()==4){
            centres.push_back(make_pair(items.at(i)->pos().y(),items.at(i)->pos().x()));
        }
    }
}

void CiliaScene::drawOrientationLines(vector<int> &orient,vector<pair<int,int>> & centres,int num_lines){
    for(int i=0;i<orient.size();i++){
        QGraphicsLineItem * line=new QGraphicsLineItem(centres[i].second-getCiliaRadius(),centres[i].first,
                                                       centres[i].second+getCiliaRadius(),centres[i].first);
        line->setRotation(orient[i]);
        line->setTransformOriginPoint(line->boundingRect().center());
        line->setOpacity(opacity);
        line->setPen(*rp);
        this->addItem(line);
        orientLines.push_back(line);
    }
}

void CiliaScene::removeOrientLinesFromScene(){
    for(int i=0;i<orientLines.size();i++){
        this->removeItem(orientLines[i]);
    }
}

void CiliaScene::deleteOrientLines(){
    for(int i=0;i<orientLines.size();i++){
        delete(orientLines[i]);
    }
    orientLines.clear();
}

void CiliaScene::getOrientations(vector<int> & orient){
    orient.clear();
    QList<QGraphicsItem *> items=this->items();
    for(int i=0;i<items.size();i++){
        if(items.at(i)->type()==6){
            orient.push_back(items.at(i)->rotation());
        }
    }
}


