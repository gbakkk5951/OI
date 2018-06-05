#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define si scanf
#define so printf
#define N 5001
#define M 930
#define INF  
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0; 
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp=='-')	mns=1;
		if(tmp==EOF)	return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	if(mns)	r=-r;
	return 1;
} 
int n,m;
int a[N],b[N],c[N],f[N][M];
int main()
{
	freopen("ggg.in","r",stdin);
	freopen("ggg.out","w",stdout);
	rd(n),rd(m);
	for(int i=1;i<=n;++i)
		rd(a[i]),rd(b[i]);
	memset(f[0],0xcf,sizeof(f));
	f[0][0]=0;
	for(int u=1,fa;u<=n;++u)
	{
		if(u>=2)
			rd(fa);
		else
			fa=0;
		for(int j=0;j<930;++j)
			f[u][j]=f[fa][j];
		for(int j=0;j<930;++j)
			if(j-a[u]>=0)
				f[u][j]=max(f[u][j],f[u][j-a[u]]+b[u]);
	}
	for(int u=1;u<=n;++u)
	for(int j=1;j<930;++j)
		f[u][j]=max(f[u][j],f[u][j-1]);
	for(int i=1;i<=m;++i)
		rd(c[i]);
	for(int i=1,d;i<=m;++i)
	{
		rd(d);
		so("%d\n",f[d][c[i]]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
