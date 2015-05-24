#include "picture.h"
#include <QColor>
#include <iostream>


Picture::Picture(char * file,int num_colors){
    FILE *fr=fopen(file,"r");
    char str[500];
    fgets (  str, 500, fr);
    fgets ( str, 500, fr);
    fscanf(fr,"%d %d",&x,&y);
    m.resize(y+47);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            int num;
            fscanf(fr,"%lf",&num);
            m[i].push_back(num);
        }
    }
    fclose(fr);
}


Picture::Picture(int s_x,int s_y,int d){
    x=s_x;
    y=s_y;
    m.resize(y+47);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            m[i].push_back(d);
        }
    }
}


Picture::Picture(int s_x, int s_y):Picture(s_x,s_y,0) {}

Picture::Picture(){

}

Picture::Picture(QImage * im,int num_colors){
    x=im->width();
    y=im->height();
    m.resize(y+47);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            int val=qGray(im->pixel(j,i));
            m[i].push_back(val);
        }
    }
}

void Picture::setRad(int r){
    rad=r;
}



void Picture::save(char * file){
    FILE *fw=fopen(file,"w");
    fprintf(fw, "P2\n");
    fprintf(fw, "%d %d 255\n",x,y);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            int a=m[i][j];
            if(a<0){
                fprintf(fw, "0\n");
            }else{
                fprintf(fw, "%d\n", a);
            }
        }
    }
    fclose(fw);
}

bool Picture::inrange(int p_x, int p_y){
    if((p_x>=0)&&(p_y>=0)&&(p_x<x)&&(p_y<y)){
        return true;
    }
    return false;
}

QImage * Picture::toQImage(){
    QImage * img=new QImage(x,y,QImage::Format_ARGB32_Premultiplied);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            int val=m[i][j]*255;
            QColor col(val,255,255);
            img->setPixel(j,i,col.rgb());
        }
    }
    return img;
}

