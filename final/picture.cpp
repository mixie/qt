#include "picture.h"
#include <QColor>
#include <iostream>


Picture::Picture(char * file,int num_colors){
    FILE *fr=fopen(file,"r");
    char str[500];
    fgets (  str, 500, fr);
    fgets ( str, 500, fr);
    int colors;
    fscanf(fr,"%d %d",&x,&y);
    m.resize(y+47);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            double num;
            fscanf(fr,"%lf",&num);
            m[i].push_back(num/num_colors);
        }
    }
    fclose(fr);
}


Picture::Picture(int s_x,int s_y,double d){
    x=s_x;
    y=s_y;
    m.resize(y+47);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            m[i].push_back(d);
        }
    }
}


Picture::Picture(int s_x, int s_y):Picture(s_x,s_y,0.0) {}

Picture::Picture(){

}

Picture::Picture(QImage * im,int num_colors){
    x=im->width();
    y=im->height();
    m.resize(y+47);
    cout << "new picture\n";
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            double val=(double)(qGray(im->pixel(j,i)))/num_colors;
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
    //printf("%f\n", m.size());
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            int a=(int)255.0*m[i][j];
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
    QImage * img=new QImage(x,y,QImage::Format_ARGB32);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            int val=(int)(m[i][j]*255);
            QColor col(val,val,val);
            col.setAlpha(150);
            img->setPixel(j,i,col.rgb());
        }
    }
    return img;
}

