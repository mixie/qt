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
#include <QGraphicsView>
#include <vector>

using namespace std;

#define point_size 10
#define PI 3.14159265
#define opacity 0.4
#define rotation_unit 10

class CiliaScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CiliaScene(QObject *parent = 0);
    bool samplesAddes();
    void removeSamples();
    int getPointX();
    int getPointY();
    int getCiliaRadius();
    void addCentreEllipses(vector <pair<int,int>> &);
    void removeCentreEllipsesFromScene();
    void deleteCentreEllipses();
    void getCentersFromScene(vector<pair<int,int>> & centres);
    void drawOrientationLines(vector <int> & orient,vector<pair<int,int>> & centers,int num_lines);
    void removeOrientLinesFromScene();
    void deleteOrientLines();
    void getOrientations(vector<int> & orient);
    int state;
    void returnSamples();
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
    int startX,startY;
    QBrush * rb;
    QPen * rp;
    vector<QGraphicsEllipseItem *> centreEllipses;
    vector<QGraphicsLineItem *> orientLines;
};

#endif // CHOOSECILIASCENE_H
