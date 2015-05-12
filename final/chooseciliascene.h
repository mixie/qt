#ifndef CHOOSECILIASCENE_H
#define CHOOSECILIASCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEllipseItem>
#include <QPointF>
#include <QList>
#include <QtCore>
#include <QtGui>
#include <QPixmap>


class ChooseCiliaScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit ChooseCiliaScene(QObject *parent = 0);
protected:
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
  //  virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
signals:

public slots:

private:
    QGraphicsEllipseItem * point;
    QGraphicsEllipseItem * cilia;
    bool pointAdded,ciliaAdded;
    int pointSize;
    int startX,startY;

};

#endif // CHOOSECILIASCENE_H
