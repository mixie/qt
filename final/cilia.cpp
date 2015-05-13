#include "cilia.h"
#include <numeric>

Cilia::Cilia(int x, int y,Picture * p){
    cen_x=x;
    cen_y=y;
    pic=p;
    rad=p->rad;
}


int Cilia::ret_xy(int x, int y){
    return pic->m[cen_y-rad+y][cen_x-rad+x];
}

double Cilia::simple_repres(vector<double> & simple_repres,vector<vector<pair<int,int> > > & cir){
    simple_repres.resize(rad+5,0.);
    for(int i=0;i<rad;i++){
        for(auto p:cir[i]){
            int y, x;
            tie(x,y) = p;
            simple_repres[i] += pic->m[cen_y+y][cen_x+x];
        }
        simple_repres[i]=simple_repres[i]/cir[i].size();
    }
    return accumulate(simple_repres.begin(),simple_repres.end(),0.)/(rad);
}


double Cilia::mean(){
    if(m==-1){
        double sum=0.;
        for(int i=0;i<rad*2;i++){
            for(int j=0;j<rad*2;j++){
                sum+=ret_xy(j,i);
            }
        }
        m=sum/((rad*2)*(rad*2));
    }return m;
}