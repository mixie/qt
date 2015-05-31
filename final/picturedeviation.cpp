#include "picturedeviation.h"
#include <QtCore>
#include <iostream>
#include <cstdio>

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
    double dev;
    if(pd.size()>=2){
        printf(" %d %f %d %f\n",pd.at(0)->count,pd.at(0)->deviation,pd.at(1)->count,pd.at(1)->deviation);
        dev=(pd.at(0)->count-1)*(pd.at(0)->deviation*pd.at(0)->deviation)+
                (pd.at(1)->count-1)*(pd.at(1)->deviation*pd.at(1)->deviation);
        dev=qSqrt(dev/(pd.at(1)->count+pd.at(0)->count-2));
        count=pd.at(1)->count+pd.at(0)->count;
        printf("%f %d\n",dev,count);
        for(int i=2;i<pd.size();i++){
            int n_new=pd.at(i)->count;
            double dev_new=pd.at(i)->deviation;
            dev=(count-1)*(dev*dev)+(n_new-1)*(dev_new*dev_new);
            dev=qSqrt(dev/(count+n_new-2));
            count+=n_new;
            printf("%f %d\n",dev,count);
        }
        n=count;
    }
    return dev;
}
