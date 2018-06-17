#include <bits/stdc++.h>
#define eps 1e-3
using namespace std;
double d[105][105],t[105][105];
double ansx[105],ansy[105];
double t1[105],t2[105];
int n;
inline double sqr(double x) {return x*x;}
inline void print()
{for (int i=1;i<=n;i++)
{printf ("%.8lf %.8lf\n",ansx[i],ansy[i]);}
exit(0);
}
void dfs(int pos,int tar)
{if (pos==n) {print();return;}
if (pos==tar) {dfs(pos+1,tar);return;}
int i,j;
if (fabs(t1[pos]-sqr(ansy[pos]))<0.0000001)
{ansx[pos]=0;dfs(pos+1,tar);return;}
ansx[pos]=sqrt(t1[pos]-ansy[pos]*ansy[pos]);
int tag=0;
for (i=1;i<pos;i++)
{if (fabs(sqr(ansx[pos]-ansx[i])+sqr(ansy[pos]-ansy[i])-sqr(d[pos][i]))>eps) 
{tag=1;break;}
}
if (tag==0) {dfs(pos+1,tar);}
tag=0;
ansx[pos]*=(-1);
for (i=1;i<pos;i++)
{if (fabs(sqr(ansx[pos]-ansx[i])+sqr(ansy[pos]-ansy[i])-sqr(d[pos][i]))>eps) 
{tag=1;break;}
}
if (tag==0) {dfs(pos+1,tar);}
return;
}
int main (){
	freopen ("restore.in","r",stdin);
	freopen ("restore.out","w",stdout);
	int i,j;
	scanf ("%d",&n);
	for (i=1;i<=n;i++)
	{for (j=1;j<=n;j++)
	{scanf ("%lf",&d[i][j]);}
	}
	ansx[n]=0;ansy[n]=0;
	int pos=n-1;
	while (pos>=1&&d[pos][n]<0.0000001) {pos--;}
	if (pos==0)
	{for (i=1;i<=n;i++)
	{printf ("0.00 0.00\n");}
	return 0;
	}
	ansx[pos]=0;ansy[pos]=d[pos][n];
	for (i=1;i<=n-1;i++)
	{if (i==pos) {continue;}
	t1[i]=sqr(d[i][n]);t2[i]=sqr(d[i][pos]);
	ansy[i]=(t1[i]-t2[i]+sqr(ansy[pos]))/(2.0*ansy[pos]);
	}
	dfs(1,pos);
	return 0;
}
	
	
	
	
	
	
	
