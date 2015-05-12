#ifndef PICTUREPROCESS_H
#define PICTUREPROCESS_H
#include "picture.h"
#include <vector>
#include <utility>
#include "cilia.h"

using namespace std;

#define num_colors 255
#define num_random_points 10

class PictureProcess
{
public:
    PictureProcess(int cilia_rad,int cil_x,int cil_y);
    ~PictureProcess();
    void step0(QImage *);
    QImage* step1(int threshold);
    Picture * p1;
    Picture * p0;
    vector<vector<pair<int,int> > > cir;
    Cilia * cil;
    int cilia_rad;
};

#endif // PICTUREPROCESS_H
