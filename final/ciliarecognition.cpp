#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <cstdio>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <string.h>
#include "cilia.h"
#include <cstdio>



using namespace std;


#define PI 3.14159265
#define num_colors 255

vector<vector<pair<int,int> > > cir;

/**
Funkcia, ktora vytvori tie "chlieviky" pre rozne vzdialenosti od stredu kruhu
*/
void init_circles(vector<vector<pair<int,int> > >	& cir, int size,unsigned int res){
    cir.resize(size*2);
    for(int i=-size;i<size;i++){
        for(int j=-size;j<size;j++){
            int temp=0.5+sqrt(j*j+i*i);
            cir[temp].push_back( make_pair(i,j));
        }
    }
    for(int i=0;i<size;i++){
        random_shuffle(cir[i].begin(),cir[i].end());
        if(cir[i].size()>res){
           cir[i].resize(res);
        }
    }
}

double simple_pearson(Cilia & a, Cilia & b,vector<vector<pair<int,int> > > & cir,
                      vector<double> & simple_repres_a,vector<double> & simple_repres_b,double mean_a){
    simple_repres_b.clear();
    double mean_b=b.simple_repres(simple_repres_b, cir);
    assert(a.rad==b.rad);
    double sum=0; double d_a=0; double d_b=0;
    for(int i=0;i<a.rad;i++){
        sum+=(simple_repres_a[i]-mean_a)*(simple_repres_b[i]-mean_b);
        d_a+=(simple_repres_a[i]-mean_a)*(simple_repres_a[i]-mean_a);
        d_b+=(simple_repres_b[i]-mean_b)*(simple_repres_b[i]-mean_b);
    }
    return sum/(sqrt(d_a)*sqrt(d_b));
}

double pearson(Cilia & a, Cilia & b){
    double mean_a=a.mean();
    double mean_b=b.mean();
    assert(a.rad==b.rad);
    double sum=0; double d_a=0; double d_b=0;
    for(int i=0;i<2*a.rad;i++){
        for(int j=0;j<2*a.rad;j++){
            sum+=(a.ret_xy(j,i)-mean_a)*(b.ret_xy(j,i)-mean_b);
            d_a+=(a.ret_xy(j,i)-mean_a)*(a.ret_xy(j,i)-mean_a);
            d_b+=(b.ret_xy(j,i)-mean_b)*(b.ret_xy(j,i)-mean_b);
        }
    }

    return sum/(sqrt(d_a)*sqrt(d_b));
}

//TODO: treba tam tych 10?
bool inrange(int x, int y, Cilia & c, Picture * p){
    if((x>p->x-c.rad)||(x<c.rad+10)||(y>p->y-c.rad)||(y<c.rad+10)){
        return false;
    }
    return true;
}


/**
Funkcia, ktora pre jednu sample riasinku skusi najst ine riasinky na obrazku
sam - sample riasinka
in,out - vstupny, vystupny obrazok
int simple - (0/1) 0 - rata korelaciu pre celu riasinku, 1 - rata korelaciu sum bodov podla vzdialenosti od stredu
*/
void pear(Cilia sam,Picture * in,Picture * out,int simple,vector<vector<pair<int,int> > > & cir){
    for(int i=0;i<in->y;i++){
        printf("%d\n", i);
        for(int j=0;j<in->x;j++){
            if(inrange(j,i,sam,in)){
                Cilia act(j,i,in);
                if(simple){
                    //out->m[i][j]=simple_pearson(sam,act,cir);
                }else{
                    out->m[i][j]=pearson(sam,act);
                }
            }else
            out->m[i][j]=0;
        }
    }
}

void pear_selective(Cilia sam,Picture * in1,Picture * in2, Picture * out, double threshold,vector<vector<pair<int,int> > > & cir){
    vector<double> simple_repres_a;
    double mean_a=sam.simple_repres(simple_repres_a,cir);
    vector <pair<double,pair<int,int > > >to_sort;
    for(int i=0;i<in2->y;i++){
        for(int j=0;j<in2->x;j++){
            if(in2->m[i][j]<threshold){
                to_sort.push_back(make_pair(in2->m[i][j],make_pair(i,j)));
            }
        }
    }
    sort(to_sort.begin(),to_sort.end());
    for(int i=0;i<to_sort.size();i++){
        if(to_sort[i].first<threshold){
            if(inrange(to_sort[i].second.second,to_sort[i].second.first,sam,in1)){
                Cilia act(to_sort[i].second.second,to_sort[i].second.first,in1);
                vector<double>  simple_repres_b;
                out->m[to_sort[i].second.first][to_sort[i].second.second]
                        =simple_pearson(sam,act,cir,simple_repres_a,simple_repres_b,mean_a);
            }
        }else{
            return;
        }
    }
}


bool isNewCiliaCentre(int x1,int y1,int x2,int y2, int rad){
    return sqrt(abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2))>2*rad;
}

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
/**
Ak je najdeny priblizny stred riasinky, tato funkcia spusti BFSko
na jeho okolie, ktore je dostatocne biele (t.j. dostatocne stred) a najde priemer
in - vstupnyobrazok
x,y - suradnice zatial najdeneho stredu
threshold - hranica, po ktoru povazuje body za mozne stredy
*/
pair<int,int> findExactCentre(Picture * in, int x, int y, double threshold){
    queue <pair<int,int> > q;
    unordered_set <pair<int,int>,pair_hash > visited;
    q.push(make_pair(x,y));
    visited.insert(make_pair(x,y));
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    int sumX=0,sumY=0;
    int count=0;
    while(!q.empty()){
        tie(x,y)=q.front();
        sumX+=x;
        sumY+=y;
        count++;
        q.pop();
        for(int i=0;i<4;i++){
            if(in->inrange(x+dx[i],y+dy[i])){
                if((in->m[y+dy[i]][x+dx[i]]>threshold)&&(visited.count(make_pair(x+dx[i],y+dy[i]))==0)){
                    q.push(make_pair(x+dx[i],y+dy[i]));
                    visited.insert(make_pair(x+dx[i],y+dy[i]));
                }
            }
        }
    }
    return make_pair(sumY/count,sumX/count);
}

/**
Nakresli trosku vacsi bod do obrazku
*/
void draw_point(int rad,int x, int y, Picture * p,double color){
    for(int i=y-rad;i<y+rad;i++){
        for(int j=x-rad;j<x+rad;j++){
            if(p->inrange(j,i)){
                p->m[i][j]=color;
            }
        }
    }
}



/**
 Hlada centra riasiniek z predspracovaneho orazku, zoradi si body podla "belosti" a potom hlada take, co su dostatocne
 daleko od seba, aby mohli byt stredy a tie este potom vylepsuje cez findExactCircles
 in - vstupny obrazok, ktory bol ako vystup funkcie pear
out -vystupny obrazok, kdesu iba nakreslene bodky na mieste riasiniek
rad- polomer riasinky
threshold - po aku hranicu este bude povazovat body za mozny stred
centres - vysledny vektor stredov riasiniek
*/
void findCentres(Picture * in, int rad,double threshold, double threshold2, vector<pair<int,int>> & centres){
    printf("%f\n",threshold);
    threshold=threshold/255.0;
    printf("%f\n",threshold);
    vector <pair<double,pair<int,int > > >to_sort;
    for(int i=0;i<in->y;i++){
        for(int j=0;j<in->x;j++){
            if(in->m[i][j]>threshold2){
                to_sort.push_back(make_pair(in->m[i][j],make_pair(i,j)));
            }
        }
    }
    sort(to_sort.begin(),to_sort.end());
    for(int i=to_sort.size()-1;i>=0;i--){
        int an=true;
        for(unsigned int j=0;j<centres.size();j++){
            if(!isNewCiliaCentre(to_sort[i].second.first,to_sort[i].second.second,
                centres[j].first,centres[j].second,rad)){
                an=false;
            break;
            }
        }
        if(an){
            if(to_sort[i].first>threshold){
                pair<int, int> p=findExactCentre(in,to_sort[i].second.second,to_sort[i].second.first,threshold);
                centres.push_back(p);
            }
        }
    }
}
/**
Najde orientaciu riasinky, na vstupe potrebuje povodny obrazok a presny stred kazdej riasinky,
zatial to len vykresluje
in - vstupny obrazok, mal by to byt povodny, nespracovany obrazok riasinky
out -vystupny obrazok
rad- polomer riasinky
circles - vysledny vektor stredov riasiniek
num_lines - koľko veľa rôzne otočených priamok bude skúšať
**/
void findOrientation(Picture * in, int rad, vector<pair<int,int> > & centres,int num_lines,vector <int> & orient){
    rad=rad/3;
    orient.clear();
        for(auto &v:centres){
            int x,y;
            tie(y,x)=v;
            double min=99999999;
            double m_x=0,m_y=0;
            int min_k=0;
            for(int k=0;k<num_lines;k++){
                double sum=0;
                pair<double,double> ab,ac;
                ab.second=cos(((PI)/num_lines)*k);
                ab.first=sin(((PI)/num_lines)*k);
                for(int i=y-rad;i<y+rad;i++){
                    for(int j=x-rad;j<x+rad;j++){
                        if(sqrt((x-j)*(x-j)+(y-i)*(y-i))<rad){
                            ac.first=i-y; ac.second=j-x;
                            if(in->inrange(j,i)){
                                sum+=(in->m[i][j]*255)/(abs(-ab.second*ac.first+ab.first*ac.second)+1);
                            }
                        }
                    }
                }
                if(sum<min){
                    min_k=k;
                    min=sum;
                    m_x=ab.first;
                    m_y=ab.second;
                }
            }
            orient.push_back(min_k);
            printf("%d %d %d\n", min_k,x,y);
        }

}

void preprocessPrefix(Picture * in, Picture * out){
    vector <vector<double > > pr;
    pr.resize(in->y+5);
    for(int i =0;i<in->y+5;i++){
        pr[i].resize(in->x+5);
    }
    printf("%d %d\n", in->y,in->x);
    for(int i=0;i<in->y;i++){
        pr[i][0]=0;
    }
    for(int j=0;j<in->x;j++){
        pr[0][j]=0;
    }
    for(int i=1;i<=in->y;i++){
        for(int j=1;j<=in->x;j++){
            pr[i][j]=pr[i][j-1]+pr[i-1][j]-pr[i-1][j-1]+in->m[i-1][j-1];
        }
    }
    int rad=in->rad;
    double max=0;
    for(int i=rad;i<in->y-rad;i++){
        for(int j=rad;j<in->x-rad;j++){
            out->m[i][j]=pr[i+1+rad][j+1+rad]-pr[i+1+rad][j+1-rad]-pr[i+1-rad][j+1+rad]+pr[i+1-rad][j+1-rad];
            if(out->m[i][j]>max){
                max=out->m[i][j];
            }
        }
    }
    for(int i=rad;i<in->y-rad;i++){
        for(int j=rad;j<in->x-rad;j++){
            out->m[i][j]=out->m[i][j]/max;
        }
    }
}

int threshold1(Picture * in, Picture * out, double threshold){
    int c=0;
    for(int i=0;i<in->y;i++){
        for(int j=0;j<in->x;j++){
            if(in->m[i][j]<threshold){
                c++;
            }
            out->m[i][j]=(int)(in->m[i][j]>threshold);
        }
    }
    return c;
}

double findDeviation(vector <int> & orient, int num_lines){
    int min1=999999999;
    int min_angle=0;
    for(int i=0;i<num_lines;i++){
        int sum=0;
        for(unsigned int j=0;j<orient.size();j++){
            sum+=min(abs(i-orient[j]),abs(i-(-(num_lines-orient[j]))));
        }
        if(sum<min1){
            min1=sum;
            min_angle=i;
        }
    }
    double odchylka=0;
    for(unsigned int i=0;i<orient.size();i++){
        odchylka+=(orient[i]-min(abs(min_angle-orient[i]),abs(min_angle-(-(num_lines-orient[i])))))*
            (orient[i]-min(abs(min_angle-orient[i]),abs(min_angle-(-(num_lines-orient[i])))));
    }
    odchylka=sqrt(odchylka)/(orient.size()-1);
    printf("%f %d\n",odchylka,min_angle);
    return odchylka;
}


