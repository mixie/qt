#include "picturedeviation.h"
#include <QtCore>
#include <iostream>

using namespace std;

PictureDeviation::PictureDeviation(double dev,int n)
{
    deviation=dev;
    count=n;
}

PictureDeviation::~PictureDeviation()
{

}

double PictureDeviation::countNewDeviation(QList<PictureDeviation*> &pd,int & n){
    double sum=0;
    int count=0;
    for(int i=0;i<pd.size();i++){
        int n=pd.at(i)->count;
        count+=n;
        double dev=pd.at(i)->deviation;
        sum+=(n-1)*dev*dev;
    }
    n=count;
    return qSqrt(sum/(count-1));
}
