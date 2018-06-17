#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#define maxn 105
using namespace std;
template <typename T>
inline void _read(T& x){
	char ch=getchar();bool sign=true;
	while(!isdigit(ch)){if(ch=='-')sign=false;ch=getchar();}
	for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(!sign)x=-x;
}
const double eps=1e-4;
const double pi=3.1415926535897932384626433832795;
double d[maxn][maxn];
int dcmp(double x){
    if(fabs(x)<eps) return 0;
    return x>0 ? 1:-1;
}
struct pt {
    double x,y;
    pt(){}
    pt (double x,double y) :x(x),y(y){}
    bool operator == (const pt p)const {
        return dcmp(x-p.x)==0 &&  dcmp(y-p.y)==0;
    }
}p[maxn];
typedef pt Vector;
Vector operator - (Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b){return a.x*b.y -a.y*b.x;}
double len(Vector a){return sqrt(Dot(a,a));}
pt getpt(pt c,double r,double ang){
    return pt(c.x+cos(ang)*r,c.y+sin(ang)*r);
}
int solve(pt c1,double r1,pt c2,double r2,vector<pt>& s){
    Vector v1 = c2 - c1;
    double d = len(v1),alpha = atan2(v1.y,v1.x);
    double beta = acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
    if(dcmp((r1*r1+d*d-r2*r2)/(2.0*r1*d)-1)==0) beta = 0;
    if(dcmp((r1*r1+d*d-r2*r2)/(2.0*r1*d)+1)==0) beta = pi;
    double t1 = alpha+beta,t2 = alpha-beta;
    if(dcmp(t1-pi)>0) t1 -= 2*pi;
    if(dcmp(pi+t2)<=0) t2 += 2*pi;
    pt p1 = getpt(c1,r1,t1), p2 = getpt(c1,r1,t2);
    s.push_back(p1);
    if(p1==p2)return 1;
    s.push_back(p2);
    return 2;    
}
int n;
int main(){
    freopen("restore.in","r",stdin);
    freopen("restore.out","w",stdout);
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%lf",&d[i][j]);    
    int t2=2,t3=0;
    p[1]=pt(0,0);
    p[t2]=pt(d[1][t2],0);
    vector<pt> s;
    for(i=3;i<=n;i++){
        if(!t3){
            if(solve(p[1],d[1][i],p[t2],d[t2][i],s)==1)p[i]=s[s.size()-1];
            else t3 = i,p[i]=s[s.size()-1];
        }
        if(dcmp(d[1][i])==0)p[i]=p[1];
        else if(dcmp(d[t2][i])==0)p[i]=p[t2];
        else {
            if(solve(p[1],d[1][i],p[t2],d[t2][i],s)==1)p[i]=s[s.size()-1];
            else {
                int sz=s.size();
                double l1=len(s[sz-1]-p[t3]),l2=len(s[sz-2]-p[t3]);
                if(dcmp(fabs(l1-d[t3][i])-fabs(l2-d[t3][i]))<=0)p[i]=s[sz-1];
                else p[i]=s[sz-2];
            }
        }
    }
    for(i=1;i<=n;i++)printf("%.6lf %.6lf\n",p[i].x,p[i].y);
} 
