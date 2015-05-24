#ifndef PICTURE_H
#define PICTURE_H
#include <vector>
#include <QImage>

using namespace std;


class Picture{
    public:
        int x,y;
        int rad=-1;
        vector<vector<int> > m;
        Picture();
        Picture(char * file,int num_colors);
        Picture(int s_x, int s_y);
        Picture(int s_x,int s_y,int def);
        Picture(QImage *,int num_colors);
        void save(char *);
        bool inrange(int, int);
        void setRad(int);
        QImage * toQImage();
};


#endif // PICTURE_H
