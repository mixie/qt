#ifndef PICTUREDEVIATION_H
#define PICTUREDEVIATION_H
#include <QList>


class PictureDeviation
{
public:
    PictureDeviation(double dev,int n);
    ~PictureDeviation();
    double deviation;
    int count;
    static double countNewDeviation(QList<PictureDeviation*> & pd,int &);
};

#endif // PICTUREDEVIATION_H
