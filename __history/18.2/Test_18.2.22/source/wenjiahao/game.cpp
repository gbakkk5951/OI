#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n;
struct edge
{
	int to,nxt;
};
edge e[160001];
int edgenum = 0;
int lin[501];
int s,t;
bool v[501];
int a[501][501];
int res[501];
void add(int a,int b)
{
	e[edgenum].to = b;
	e[edgenum].nxt = lin[a];
	lin[a] = edgenum;
	++edgenum;
	return;
}
void init()
{
	memset(lin,-1,sizeof(lin));
	scanf("%d",&n);
	for(int i = 1;i <= n;++i)
	{
		for(int j = 1;j <= n;++j)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j] == 1)
			{
				add(i,j);
			}
		}
	}
	return;
}
bool dfs(int st,int k,int d)
{
	if(d == n)
	{
		if(a[k][st] == 1)
		{
			cout << 0 << endl;
			res[d] = k;
			return true;
		}
		else
		{
			cout << 1 << endl;
			res[d] = k;
			return true;
		}
	}
	for(int i = lin[k];i != -1;i = e[i].nxt)
	{
		if(!v[e[i].to])
		{
			v[e[i].to] = true;
			if(dfs(st,e[i].to,d + 1))
			{
				res[d] = k;
				return true;
			}
			v[e[i].to] = false;
		}
	}
	return false;
}
bool dfs2(int st,int k,int d)
{
	if(d == n)
	{
		if(a[k][st] == 1)
		{
			cout << 0 << endl;
			res[d] = k;
			return true;
		}
		else
		{
			return false;
		}
	}
	for(int i = lin[k];i != -1;i = e[i].nxt)
	{
		if(!v[e[i].to])
		{
			v[e[i].to] = true;
			if(dfs2(st,e[i].to,d + 1))
			{
				res[d] = k;
				return true;
			}
			v[e[i].to] = false;
		}
	}
	return false;
}
bool check()
{
	if(dfs2(1,1,1))
	{
		for(int i = 1;i <= n;++i)cout << res[i] << " ";
		return true;
	}
	return false;
}
void work()
{
	if(check())return;
	for(int i = 1;i <= n;++i)
	{
		memset(v,0,sizeof(v));
		v[i] = true;
		if(dfs(i,i,1))
		{
			for(int i = 1;i <= n;++i)cout << res[i] << " ";
			return;
		}
		v[i] = false;
	}
	cout << -1 << endl;
	return;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	init();
	work();
	fclose(stdout);
	fclose(stdin);
	return 0;
}
