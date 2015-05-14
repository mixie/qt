#ifndef CILIA_H
#define CILIA_H
#include "cilia.h"
#include "picture.h"

class Cilia{
    public:
        double m=-1.;
        Picture * pic;
        int rad;
        int cen_x,cen_y;
        Cilia(int, int, Picture * );
        int ret_xy(int , int );
        double simple_repres(vector<double> & ,vector<vector<pair<int,int> > > & cir);
        double mean();
        void changeCenter(int, int);
};



#endif // CILIA_H
