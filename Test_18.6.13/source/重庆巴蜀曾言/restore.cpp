#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,j;
double l,r,m,a[102][102],b[102],c[102];
inline double dis(int x,int y)
{
	return sqrt((b[x]-b[y])*(b[x]-b[y])+(c[x]-c[y])*(c[x]-c[y]));
}
int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	      cin>>a[i][j];
	b[1]=c[1]=c[2]=0.0;
	b[2]=a[1][2];
	for(i=3;i<=n;i++)
	{
		if(a[1][i]*a[1][i]>a[1][2]*a[1][2]+a[2][i]*a[2][i])
		{
			l=0.0;
			r=a[2][i];
			while(r-l>1e-8)
			{
				m=(l+r)/2;
				if(sqrt(a[1][i]*a[1][i]-m*m)-sqrt(a[2][i]*a[2][i]-m*m)>a[1][2]) r=m;
				else l=m;
			}
			b[i]=sqrt(a[1][i]*a[1][i]-m*m);
			c[i]=m;
			for(j=3;j<i;j++)
			   if(fabs(dis(j,i)-a[j][i])>1e-3)
			     break;
			if(j<i) c[i]=-m;
		}
		else if(a[2][i]*a[2][i]>a[1][2]*a[1][2]+a[1][i]*a[1][i])
		{
			l=0.0;
			r=a[1][i];
			while(r-l>1e-8)
			{
				m=(l+r)/2;
				if(sqrt(a[2][i]*a[2][i]-m*m)-sqrt(a[1][i]*a[1][i]-m*m)>a[1][2]) r=m;
				else l=m;
			}
			b[i]=-sqrt(a[1][i]*a[1][i]-m*m);
			c[i]=m;
			for(j=3;j<i;j++)
			   if(fabs(dis(j,i)-a[j][i])>1e-3)
			     break;
			if(j<i) c[i]=-m;
		}
		else
		{
			l=0.0;
			r=a[2][i];
			while(r-l>1e-8)
			{
				m=(l+r)/2;
				if(sqrt(a[1][i]*a[1][i]-m*m)+sqrt(a[2][i]*a[2][i]-m*m)<a[1][2]) r=m;
				else l=m;
			}
			b[i]=sqrt(a[1][i]*a[1][i]-m*m);
			c[i]=m;
			for(j=3;j<i;j++)
			   if(fabs(dis(j,i)-a[j][i])>1e-3)
			     break;
			if(j<i) c[i]=-m;
		}
	}
	for(i=1;i<=n;i++) cout<<fixed<<setprecision(6)<<b[i]<<" "<<c[i]<<"\n";
	return 0;
}

