#include "pictureprocess.h"
#include "ciliarecognition.h"
#include "picture.h"
#include "iostream"

PictureProcess::PictureProcess(int cilia_radius,int cil_x,int cil_y)
{
    cilia_rad=cilia_radius;
    c_x=cil_x;
    c_y=cil_y;
    init_circles(cir,cilia_radius,255);
}

PictureProcess::~PictureProcess()
{

}

QImage* PictureProcess::step1(int threshold){
    Picture * p3=new Picture(p1->x,p1->y,1);
    threshh=threshold/255.0;
    cout << threshold1(p0,p3,threshh) << "thr\n";
    return p3->toQImage();
}

void PictureProcess::step0(QImage * img){
    p1=new Picture(img,num_colors);
    p1->setRad(cilia_rad);
    p0=new Picture(p1->x,p1->y,1);
    preprocessPrefix(p1,p0);
}

vector <pair<int,int>> & PictureProcess::step2(){
    p2= new Picture(p1->x,p1->y,0);
    pear_selective(Cilia(c_x,c_y,p1),p1,p0,p2,threshh,cir);
    findCentres(p2,cilia_rad,200,centres);
    for(int i=0;i<centres.size();i++){
        cout << centres[i].first<< " " << centres[i].second << "\n";
    }
    return centres;
}

