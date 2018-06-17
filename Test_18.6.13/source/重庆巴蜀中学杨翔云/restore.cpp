#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cstdlib>
#define eps 1e-4
using namespace std;
typedef long long ll;
double f[105][105];
struct Point 
{
	double x,y;
	Point(double a=0,double b=0){x=a;y=b;}
}P[105];
int n;
inline double Abs(double k)
{
	return k<0?-k:k;
}
void Cal(int x,int y,int z)
{
	if(Abs(P[x].x-P[y].x)<=eps)
	{
		P[z].y=(f[x][z]*f[x][z]-f[y][z]*f[y][z]+P[y].y*P[y].y-P[x].y*P[x].y)/(2*(P[y].y-P[x].y));
		P[z].x=(2*P[x].x+2*sqrt(f[x][z]*f[x][z]-(P[z].y-P[x].y)*(P[z].y-P[x].y)))/2.0;
		return ;
	}
	if(Abs(P[x].y-P[y].y)<=eps)
	{
		P[z].x=(f[x][z]*f[x][z]-f[y][z]*f[y][z]+P[y].x*P[y].x-P[x].x*P[x].x)/(2*(P[y].x-P[x].x));
		P[z].y=(2*P[x].y+2*sqrt(f[x][z]*f[x][z]-(P[z].x-P[x].x)*(P[z].x-P[x].x)))/2.0;
		return ;
	}
}
pair<Point,Point> Cal1(int x,int y,int z)
{
	Point P1,P2;
	if(Abs(P[x].x-P[y].x)<=eps)
	{
		P1.y=(f[x][z]*f[x][z]-f[y][z]*f[y][z]+P[y].y*P[y].y-P[x].y*P[x].y)/(2*(P[y].y-P[x].y));
		P1.x=(2*P[x].x+2*sqrt(f[x][z]*f[x][z]-(P[z].y-P[x].y)*(P[z].y-P[x].y)))/2.0;
		P2=P1;
		P2.x=(2*P[x].x-2*sqrt(f[x][z]*f[x][z]-(P[z].y-P[x].y)*(P[z].y-P[x].y)))/2.0;
		return make_pair(P1,P2);
	}
	if(Abs(P[x].y-P[y].y)<=eps)
	{
		P1.x=(f[x][z]*f[x][z]-f[y][z]*f[y][z]+P[y].x*P[y].x-P[x].x*P[x].x)/(2*(P[y].x-P[x].x));
		P1.y=(2*P[x].y+2*sqrt(f[x][z]*f[x][z]-(P[z].x-P[x].x)*(P[z].x-P[x].x)))/2.0;
		P2=P1;
		P2.y=(2*P[x].y-2*sqrt(f[x][z]*f[x][z]-(P[z].x-P[x].x)*(P[z].x-P[x].x)))/2.0;
		return make_pair(P1,P2);
	}
	Point Q;
	double k=(P[y].y-P[x].y)/(P[y].x-P[x].x);
	double k1=-1.0/k;
	double r=f[x][z]*f[x][z];
	double R=f[y][z]*f[y][z];
	double L2=(P[x].x-P[y].x)*(P[x].x-P[y].x)+(P[x].y-P[y].y)*(P[x].y-P[y].y);
	double L=sqrt(L2);
	double g=(R-r+L2);
	double q2=R-g*g/(4*L2);	
	Q.x=P[y].x-g*(P[y].x-P[x].x)/(2*L2);
	Q.y=P[y].y+g*(P[x].y-P[y].y)/(2*L2);
	double p=sqrt(q2/(k1*k1+1));
	double q=k1*p;
	P1.x=Q.x+p;
	P1.y=Q.y+q;
	P2.x=Q.x-p;
	P2.y=Q.y-q;
	return make_pair(P1,P2);
}
void Cal2(int x,int y,int z,int p)
{
	pair<Point,Point> tmp1,tmp2;
	tmp1=Cal1(x,y,p);
	tmp2=Cal1(x,z,p);
	if(Abs(tmp1.first.x-tmp2.first.x)<=eps&&Abs(tmp1.first.y-tmp2.first.y)<=eps)
	{
		P[p]=tmp1.first;
		return ;
	}
	if(Abs(tmp1.first.x-tmp2.second.x)<=eps&&Abs(tmp1.first.y-tmp2.second.y)<=eps)
	{
		P[p]=tmp1.first;
		return ;
	}
	if(Abs(tmp1.second.x-tmp2.first.x)<=eps&&Abs(tmp1.second.y-tmp2.first.y)<=eps)
	{
		P[p]=tmp1.second;
		return ;
	}
	if(Abs(tmp1.second.x-tmp2.second.x)<=eps&&Abs(tmp1.second.y-tmp2.second.y)<=eps)
	{
		P[p]=tmp1.second;
		return ;
	}
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		scanf("%lf",&f[i][j]);
	}
	if(n==1)
	{
		cout<<"0.0 0.0";
		return 0;
	}
	if(n==2)
	{
		cout<<"0.0 0.0\n";
		cout<<fixed<<setprecision(4)<<"0.0 "<<f[1][2];
	} 
	P[1]=Point(0,0);
	int flag1=0,flag2=0;
	for(int i=2;i<=n;i++)
	{
		if(!flag1)
		{
			if(Abs(f[1][i])<=eps)
			{
				P[i]=P[1];
			}
			else 
			{
				flag1=i;
				P[i]=Point(f[1][i],0);
			}
		}
		else if(!flag2)
		{
			if(Abs(f[1][i])<=eps)
			{
				P[i]=P[1];
				continue;
			}
			if(Abs(f[flag1][i])<=eps)
			{
				P[i]=P[flag1];
				continue;
			}
			if(Abs(f[flag1][i]+f[1][i]-f[1][flag1])<=eps)
			{
				P[i]=Point(P[1].x+(P[flag1].x-P[1].x)*f[1][i]/(f[1][flag1]),P[1].y+(P[flag1].y-P[1].y)*f[1][i]/(f[1][flag1]));
				continue;
			}
			flag2=i;
			Cal(1,flag1,i);
		}
		else 
		{
			Cal2(1,flag1,flag2,i); 
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<fixed<<setprecision(6)<<P[i].x<<" "<<P[i].y<<"\n";
	}
	return 0;
}
