#ifndef CILIARECOGNITION
#define CILIARECOGNITION
#include<vector>
#include "picture.h"
#include "cilia.h"

using namespace std;

void preprocessPrefix(Picture * in, Picture * out);
int threshold1(Picture * in, Picture * out, int threshold);
void init_circles(vector<vector<pair<int,int> > > & cir, int size,unsigned int res);
void pear_selective(Cilia sam,Picture * in1,
                    Picture * in2, Picture * out, int threshold,vector<vector<pair<int,int> > > & cir);
void findCentres(Picture * in, int rad,
                 int threshold, int threshold2, vector<pair<int,int>> & centres);
void findOrientation(Picture * in, int rad,
               vector<pair<int,int> > & centres,int num_lines,vector <int> & orient);
double findDeviation(vector <int> & orient, int num_lines , vector<int> & distances);

#endif // CILIARECOGNITION

