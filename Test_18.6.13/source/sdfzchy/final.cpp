//by achhhy
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
inline int in()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return f*x;
}
//need changing
const int inf=(1<<30);
const int mod=1e9+7;
const int N=100010;

int n,m;
int h[10][10];

bool work2()
{
	rep(i,-2000,2000) rep(j,-2000,2000)
	{
		h[2][1]=i;
		h[2][2]=j;
		if((h[1][1]*h[2][2]-h[1][2]*h[2][1])==1) return 1;
	}
	return 0;	
}

void print()
{
	rep(i,1,n)
	{
		rep(j,1,n) printf("%d ",h[i][j]);
		puts("");
	}
}

int main()
{
 	#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);
	#endif
	n=in();
	rep(i,1,n) h[1][i]=in();
	if(n==2)
	{
		if(work2()) print();
		else puts("no solution");
	}
	else puts("no solution");
	return 0;
}
