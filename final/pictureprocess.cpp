#include "pictureprocess.h"
#include "ciliarecognition.h"
#include "picture.h"
#include "iostream"

PictureProcess::PictureProcess(int cilia_radius,int cil_x,int cil_y)
{
    cilia_rad=cilia_radius;
    c_x=cil_x;
    c_y=cil_y;
    init_circles(cir,cilia_radius,num_circles);
    p0=0;p1=0;p2=0;p3=0;
}

PictureProcess::~PictureProcess()
{
    del(p0);del(p1);del(p2); del(p3);
}

QImage* PictureProcess::step1(int threshld){
    del(p3);
    p3=new Picture(p1->x,p1->y,1);
    threshold=threshld;
    threshold1(p0,p3,threshold);
    return p3->toQImage();
}

void PictureProcess::step0(QImage * img){
    del(p1);del(p0);
    p1=new Picture(img,num_colors);
    p1->setRad(cilia_rad);
    p0=new Picture(p1->x,p1->y,num_colors);
    preprocessPrefix(p1,p0);
}

vector <pair<int,int>> & PictureProcess::step2(int threshold2){
    del(p2);
    p2= new Picture(p1->x,p1->y,0);
    Cilia c(c_x,c_y,p1);
    pear_selective(c,p1,p0,p2,threshold,cir);
    findCentres(p2,cilia_rad,threshold2,threshold,centres);
    return centres;
}

vector<pair<int,int>> & PictureProcess::step2_1(int threshold2){
    int thr=threshold2;
    centres.clear();
    findCentres(p2,cilia_rad,thr,threshold,centres);
    return centres;
}

void PictureProcess::step3(vector <pair<int,int>> & centres,int num_lines,vector<int> & orient){
    findOrientation(p1,cilia_rad,centres,num_lines,orient);
}

double PictureProcess::step4(vector<int> orient,int num_lines){
    return findDeviation(orient,num_lines);
}

void PictureProcess::del(Picture * p){
 if(p){
    delete(p);
     p=0;
 }
}
