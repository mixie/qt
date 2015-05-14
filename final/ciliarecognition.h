#ifndef CILIARECOGNITION
#define CILIARECOGNITION
#include<vector>
#include "picture.h"
#include "cilia.h"

using namespace std;

void preprocessPrefix(Picture * in, Picture * out);
int threshold1(Picture * in, Picture * out, double threshold);
void init_circles(vector<vector<pair<int,int> > > & cir, int size,unsigned int res);
void pear(Cilia sam,Picture * in,Picture * out,int simple,vector<vector<pair<int,int> > > & cir);
void pear_selective(Cilia sam,Picture * in1,
                    Picture * in2, Picture * out, double threshold,vector<vector<pair<int,int> > > & cir);
void findCentres(Picture * in, int rad,
                 double threshold, vector<pair<int,int>> & centres);
void findOrientation(Picture * in, int rad,
               vector<pair<int,int> > & centres,int num_lines,vector <int> & orient);
int findMean(vector <int> & orient, int num_lines );

#endif // CILIARECOGNITION

