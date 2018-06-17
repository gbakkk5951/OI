#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
#define maxn 105
#define fir first
#define sec second
struct Point {double x,y;};
double d[maxn][maxn];
Point list[maxn],bak[maxn];
int n,ord[maxn];

inline double sqr(double x) {return x*x;}

pair<Point,Point> Cross(Point A,Point B,double r1,double r2)
{
	double x1=A.x,x2=B.x;
	double y1=A.y,y2=B.y;
	double c=(r1-r2+sqr(x2)-sqr(x1)+sqr(y2)-sqr(y1))/(2*(x2-x1));
	double a=(y1-y2)/(x2-x1);
	double aa=(sqr(a)+1);
	double bb=(2*a*c-2*x1*a-2*y1);
	double cc=sqr(x1)+sqr(c)-2*x1*c-r1;
	double delta=sqr(bb)-4*aa*cc;
	double tmp=sqrt(delta);
	double yy1=(tmp-bb)/2,yy2=(-tmp-bb)/2;
	double xx1=a*yy1+c,xx2=a*yy2+c;
	return make_pair((Point){xx1,yy1},(Point){xx2,yy2});
}

bool fc(double x,double y)
{
	return fabs(x-y)<0.001;
}

inline bool cmp(int a,int b)
{
	return d[1][a]<d[1][b];	
}

int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	srand(20001111);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) 
			scanf("%lf",&d[i][j]);
	for (int i=1;i<=n;i++) ord[i]=i;
	while (1) 
	{
		list[1].x=list[1].y=0;
		list[2].x=d[ord[1]][ord[2]];list[2].y=0;
		for (int i=3;i<=n;i++)
		{
			pair<Point,Point> tmp=Cross(list[1],list[2],sqr(d[ord[1]][ord[i]]),sqr(d[ord[2]][ord[i]]));
			int flag=1;
			for (int j=3;j<i;j++)  
				if (!fc(sqr(list[j].x-tmp.sec.x)+sqr(list[j].y-tmp.sec.y),sqr(d[ord[j]][ord[i]])))
				{
					flag=0;
					break;	
				}
			if (flag) list[i]=tmp.sec;else list[i]=tmp.fir;
		}
		for (int i=1;i<=n;i++) bak[ord[i]]=list[i];
		for (int i=1;i<=n;i++) list[i]=bak[i];
		bool pd=1;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (!fc(sqr(list[i].x-list[j].x)+sqr(list[i].y-list[j].y),sqr(d[i][j]))) 
				{
					pd=0;
					break;
				}
		for (int i=1;i<=n;i++) swap(ord[rand()%n+1],ord[rand()%n+1]);
		if (!pd) continue;
		for (int i=1;i<=n;i++) printf("%.6f %.6f\n",list[i].x,list[i].y);
		break;
	}
	return 0;	
}
