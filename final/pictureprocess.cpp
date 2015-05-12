#include "pictureprocess.h"
#include "ciliarecognition.h"
#include "picture.h"

PictureProcess::PictureProcess(int cilia_radius,int cil_x,int cil_y)
{
    cilia_rad=cilia_radius;
//    cil=cilia;
    init_circles(cir,cilia_radius,255);
}

PictureProcess::~PictureProcess()
{

}

QImage* PictureProcess::step1(int threshold){
    Picture * p3=new Picture(p1->x,p1->y);
    double thr=threshold/255.0;
    threshold1(p0,p3,thr);
    return p3->toQImage();
}

void PictureProcess::step0(QImage * img){
    p1=new Picture(img,num_colors);
    p1->setRad(cilia_rad);
    p0=new Picture(p1->x,p1->y);
    preprocessPrefix(p1,p0);
}
