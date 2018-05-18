#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int mk[200];
int m,t;
int fa[200];
int timl,vis[200];
int tot,had[200],nxt[1000454],point[1000056];
int ai[1000005],bi[1000006],ci[1000006];
int s[200];
inline void add(int x,int y)
{
	tot++;
	nxt[tot]=had[x];
	had[x]=tot;
	point[tot]=y;
}
int gef(int x)
{
	for(int i=had[x];i;i=nxt[i])
	{
		int to=point[i];
		if(vis[to]!=timl)
		{
			vis[to]=timl;
			if(fa[to]==0||gef(fa[to]))
			{
				fa[to]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	scanf("%d",&m);
	t=1;
	while(~scanf("%d%d%d",&ai[t],&bi[t],&ci[t]))
	{
		mk[ci[t]]=max(mk[ci[t]],ai[t]);
		int f;
		if(ci[t]==m)f=1;
		else f=ci[t]+1;
		mk[f]=max(f,bi[t]);
		t++;
	}
	t--;
	for(int i=1;i<=m;i++)
		s[i]=s[i-1]+mk[i];
	for(int i=1;i<=t;i++)
	{
		add(ai[i]+s[ci[i]-1]%s[m],bi[i]+s[ci[i]]%s[m]);
		add(bi[i]+s[ci[i]]%s[m],ai[i]+s[ci[i]-1]%s[m]);
	}
	int ans=0;
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=mk[i];j++)
		{
			timl++;
			if(gef(s[i-1]+j))ans++;
		}
	}
	int ans2=0;
	for(int i=2;i<=m;i+=2)
	{
		for(int j=1;j<=mk[i];j++)
		{
			timl++;
			if(gef(s[i-1]+j))ans2++;
		}
	}
	ans=max(ans,ans2);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
