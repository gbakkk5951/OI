#include <bits/stdc++.h>
using namespace std;

const int N=105;
const double eps=1e-14;
int n,u,v,a[N];
double D[N][N],x[N],y[N];

double sqr(double x)
{
    return x*x;
}

long double dis1(int i,int j)
{
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

long double dis2(int i,int j)
{
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]+y[j]));
}

void dfs(int x)
{
	a[x]=1;
	int i,j,k;
	for(i=x+1;i<=n;i++)
		if(i!=u&&i!=v)
		{
		    for(j=1,k=1;j<=x&&k;j++)
		    {
		    	if(j!=u&&j!=v&&a[j]&&fabs(dis1(i,j)-D[i][j])>fabs(dis2(i,j)-D[i][j]))
	                k=0;
	        }
		    if(k)
		    {
		    	dfs(i);
		    	break;
		    }
		}
}

int main()
{
	freopen("restore.in","r",stdin);
	freopen("restore.out","w",stdout);
	scanf("%d",&n);
	int i,j,u,v;
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	        scanf("%lf",&D[i][j]);
	if(n==1)
	{
		printf("0 0\n");
		return 0;
	}
	if(n==2)
	{
		printf("0 0\n0 %lf\n",D[1][2]);
		return 0;
	}
	u=1,v=2;
	for(i=1;i<=n;i++)
	    for(j=i+1;j<=n;j++)
	        if(D[i][j]>D[u][v])
	            u=i,v=j;
	x[u]=y[u]=y[v]=0,x[v]=D[u][v];
	for(i=1;i<=n;i++)
	    if(i!=u&&i!=v)
		{
			x[i]=(sqr(D[u][i])+sqr(D[u][v])-sqr(D[v][i]))/(2*D[u][v]);
			if(D[u][i]-x[i]<eps)y[i]=0;
			else y[i]=sqrt(sqr(D[u][i])-sqr(x[i]));
		}
	for(i=1;i==u||i==v;i++);
	dfs(i);
	for(i=1;i<=n;i++)
	    if(a[i])
	        printf("%.7lf %.7lf\n",x[i],y[i]);
	    else
	        printf("%.7lf %.7lf\n",x[i],-y[i]);
	return 0;
}

