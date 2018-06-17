#include<set>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<=y;++i)
using namespace std;

const int maxn=100+10;
const double eps=1e-9;
inline int dcmp(const double &x){return x<-eps?-1:x>eps?1:0;}

struct point{
	double x,y;
	point(double x=0,double y=0):x(x),y(y){}
	inline void input(){scanf("%lf%lf",&x,&y);}	
	inline bool operator == (const point &rhs)const{
		return dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)==0;	
	}
	inline bool operator < (const point &rhs)const{
		if(dcmp(x-rhs.x!=0)) return dcmp(x-rhs.x)<0;
		return dcmp(y-rhs.y) < 0;
	}
	inline void output(){printf("%.6f %.6f\n",x,y);}
}p[maxn];


typedef point vc; 
inline vc operator - (const point &a,const point &b){return vc(a.x-b.x,a.y-b.y);}
inline vc operator + (const vc &a,const vc &b){return vc(a.x+b.x,a.y+b.y);}
inline vc operator * (const vc &v,const double &k){return vc(v.x*k,v.y*k);}
inline vc operator / (const vc &v,const double &k){return vc(v.x/k,v.y/k);}

inline double dot(const vc &a,const vc &b){return a.x*b.x+a.y*b.y;}
inline double cross(const vc &a,const vc &b){return a.x*b.y-a.y*b.x;}
inline double getl(const vc &a){return sqrt(dot(a,a));}
inline double angle(const vc &a){return atan2(a.y,a.x);}

struct Cir{
	point c;double r;
	Cir(point c=point(),double r=0):c(c),r(r){}
	point getp(double ang){
		return point(c.x+cos(ang)*r,c.y+sin(ang)*r);
	}
};

vector<point>sol[maxn];

double d[maxn][maxn];

set<point>st;

inline void work(Cir C1,Cir C2,vector<point> &sol)
{
	double a = angle(C2.c - C1.c), d=getl(C2.c-C1.c); //向量C1C2的极角
	double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d)); //C1C2到C1P1的角
	point p1 = C1.getp(a-da),p2 = C1.getp(a+da);

	sol.push_back(p1);
	sol.push_back(p2);
}

int ok[10];
inline point solve(int x)
{
	rep(i,1,x-2)
	{
		sol[i].clear();
		work(Cir(p[i],d[i][x]),Cir(p[i+1],d[i+1][x]),sol[i]);
	}
	
	rep(i,1,x-2)
	{
		rep(j,0,1)
		{
			point tmp=sol[i][j]; int ok=1;
			rep(k,1,x-2)
				if(!(sol[k][0]==tmp) && !(sol[k][1]==tmp)) {ok=0;break;}	
				
			if(ok) {
				point ans;
				rep(k,1,x-2)
				{
					if(sol[k][0]==tmp) ans=ans+sol[k][0];
					else ans=ans+sol[k][1];
				}
				return ans/(x-2);
			}
		}
	}
	
	return *st.begin();
}

int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	
	int n;cin>>n;
	rep(i,1,n) rep(j,1,n) scanf("%lf",d[i]+j);	
	
	p[1]=point(0,0);
	p[2]=point(d[1][2],0);
	
	rep(i,3,n) p[i]=solve(i);

	rep(i,1,n) p[i].output();
	
	return 0;
}
