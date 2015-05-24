#ifndef CILIA_H
#define CILIA_H
#include "cilia.h"
#include "picture.h"

class Cilia{
    public:
        int m=-1.;
        Picture * pic;
        int rad;
        int cen_x,cen_y;
        Cilia(int, int, Picture * );
        int  ret_xy(int , int );
        int simple_repres(vector<int> & ,vector<vector<pair<int,int> > > & cir);
        int mean();
        void changeCenter(int, int);
};



#endif // CILIA_H
