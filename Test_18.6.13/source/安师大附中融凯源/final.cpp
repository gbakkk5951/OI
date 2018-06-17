#include <stdio.h>
#include <iostream>
#include <cstring>
const int N=10;
int n,h[N],seq[N],mat[N][N],ans[N][N];
using namespace std;

int f(int x){return max(x,-x);}
int gcd(int x,int y)
{
	if (y==0) return x;
	return gcd(y,x%y);
}
void exgcd(int a,int b,int& x,int& y)
{
	if (b==0){x=1,y=0;return;}
	exgcd(b,a%b,x,y);
	int x0=y,y0=x-(a/b)*y;
	x=x0,y=y0;
}
void solve()
{
	int i;
	for (i=2;i<n;i++) mat[i][i]=1;
	int a=mat[1][1],b=mat[1][n],x,y;
	exgcd(f(a),f(b),x,y);
	if (a<0 && b<0) x=-x,y=-y;
	if (a>0 && b<0) y=-y;
	if (a<0 && b>0) x=-x;
	while (b>0 && x>=b) x-=b,y+=a;
	while (b>0 && x<0) x+=b,y-=a;
	while (b<0 && x>=b) x+=b,y-=a;
	while (b<0 && x<0) x-=b,y+=a;
	y=-y;
	mat[n][1]=y,mat[n][n]=x;
}
int main()
{
	freopen ("final.in","r",stdin);
	freopen ("final.out","w",stdout);
	scanf ("%d",&n);
	int i,j;
	for (i=1;i<=n;i++)
	scanf ("%d",&h[i]),seq[i]=i;
	for (i=1;i<=n;i++)
	{
		for (j=i+1;j<=n;j++)
		if (h[i]!=0 && h[j]!=0 && gcd(f(h[i]),f(h[j]))==1) break;
		if (j<=n) break;
	}
	if (i!=1 || j!=n)
	{
		if (i==1) seq[1]=j,seq[j]=n,seq[n]=1;
		else
		{
			if (j==n) seq[1]=n,seq[i]=1,seq[n]=i;
			else seq[1]=i,seq[i]=1,seq[n]=j,seq[j]=n;
		}
	}
	for (i=1;i<=n;i++) mat[1][i]=h[seq[i]];
	solve();
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	ans[i][seq[j]]=mat[i][j];
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		printf ("%d ",ans[i][j]);
		printf ("\n");
	}
	return 0;
}

