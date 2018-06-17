#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-3;
double SIN,COS,dis[105][105];
int n;
struct ff{
	double x,y;
	inline ff (double _x=0,double _y=0){ x=_x; y=_y; }
	inline ff operator +(ff b){ return ff(x+b.x,y+b.y); }
}ans[105],ans1,ans2;
inline ff turn(ff a)
{
	return ff(a.x*COS-a.y*SIN,a.y*COS+a.x*SIN);
}
inline void poi(int i)
{
	double a=dis[1][2], b=dis[i][1], c=dis[i][2];
	COS=(a*a+b*b-c*c)/(a*b*2);
	SIN=sqrt(1-COS*COS);
	ff t=turn(ff(b,0));
	ans1=ans[1]+t;
	SIN*=-1;
	t=turn(ff(b,0));
	ans2=ans[1]+t;
}
inline double dist(ff a,ff b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline int sgn(double x)
{
	if (fabs(x)<=eps) return 0;
	return x<0?-1:1;
}
inline void query(int i)
{
	poi(i);	
	int flag1=1,flag2=1;
	for (int j=3; j<i; ++j){
		//printf("%.3lf %.3lf \n",dist(ans1,ans[j]),dist(ans2,ans[j]));
		int o1=sgn(dist(ans1,ans[j])-dis[i][j]),o2=sgn(dist(ans2,ans[j])-dis[i][j]);
		if (o1!=0) flag1=0;
		if (o2!=0) flag2=0;
		if (o1&&o2) (dist(ans1,ans[j])<dist(ans2,ans[j])?flag1:flag2)=1;
	}	
	//printf("%d %d\n",flag1,flag2);
	ans[i]=(flag1?ans1:ans2);
	//printf("%.5lf %.5lf\n",ans[i].x,ans[i].y);
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	//SIN=1, COS=0;
	scanf("%d",&n);
	for (int i=1; i<=n; ++i) 
		for (int j=1; j<=n; ++j)
			scanf("%lf",&dis[i][j]);
	//printf("over");
	ans[1]=ff(0,0);
	ans[2]=ff(dis[1][2],0);
	for (int i=3; i<=n; ++i){
		query(i);
	}
	for (int i=1; i<=n; ++i) printf("%.5lf %.5lf\n",ans[i].x,ans[i].y);
}
