#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long LL;

const int maxn = 1005;
const int N = 2000;
LL ABS(LL x) {return x>0?x:-x;}
LL gcd(LL a,LL b) {return b?gcd(b,a%b):a;}
bool ing(LL x) {return x>=-N&&x<=N;}
LL xx;LL yy;
LL g[maxn][maxn],u,v;int n;
void exgcd(LL a,LL b)
{
	if (!b) {
		xx=1;yy=0;
		return ;
	}
	else {
		exgcd(b,a%b);
		LL x=xx,y=yy;
		xx=y;yy=x-(a/b)*y;
	}
}
void print()
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		printf("%lld%c",g[i][j]," \n"[j==n]);
}
int dop[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("final.in","r",stdin);
		freopen("final.out","w",stdout);
	#endif
	scanf("%d",&n);
	if (n==1) {
		if (g[1][1]==1) printf("1");
		else puts("no solution");
		return 0;
	}
	for (int i=1;i<=n;i++)
		scanf("%lld",&g[1][i]);
	//for (int i=1;i<=n;i++)
	int i=1;
	for (int j=i+1;j<=n;j++)
	if (gcd(ABS(g[1][i]),ABS(g[1][j]))==1) {
		exgcd(g[1][i],g[1][j]);u=-yy;v=xx;
		LL a=g[1][i],b=g[1][j];
		for (LL w=-N*2;w<=N;w++)
		if (ing(u+a*w)&&ing(v+b*w)) {
			g[j][1]=u+a*w;g[j][j]=v+b*w;
			for (int k=2;k<=n;k++)
			if (k!=j) g[k][k]=1;
			print();return 0;
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	if (gcd(ABS(g[1][i]),ABS(g[1][j]))==1) {
		exgcd(g[1][i],g[1][j]);u=-yy;v=xx;
		LL a=g[1][i],b=g[1][j];
		for (LL w=-N*2;w<=N;w++)
		if (ing(u+a*w)&&ing(v+b*w)) {
			g[2][i]=u+a*w;g[2][j]=v+b*w;
			int o=1;dop[i]=dop[j]=1;
			for (int k=3;k<=n;k++)
			{
				while (dop[o]) ++o;
				g[k][o]=1;dop[o]=1;
			}
			print();return 0;
		}
	}
	return 0;
}
