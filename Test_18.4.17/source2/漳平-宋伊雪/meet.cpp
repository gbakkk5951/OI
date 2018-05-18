#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<ext/pb_ds/priority_queue.hpp>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

const int maxn = 2E5 + 20;
const int T = 18;
typedef long long LL;

struct E{
	int to,w; E(){}
	E(int to,int w): to(to),w(w){}
};

int n,m,dfs_clock,dfn[maxn],L[maxn],stk[10],bin[maxn]
	,len[maxn],fa[maxn][T],MinL[maxn][T],Ans[maxn][T],Max[maxn][T];
LL dis[maxn],sum[maxn][T];

vector <E> v[maxn];

void Dfs(int x,int from)
{
	dfn[x] = ++dfs_clock;
	Ans[dfs_clock][0] = x; MinL[dfs_clock][0] = L[x];
	for (int i = 1; i < T; i++)
	{
		fa[x][i] = fa[fa[x][i-1]][i-1];
		sum[x][i] = sum[x][i-1] + sum[fa[x][i-1]][i-1];
		Max[x][i] = max(Max[x][i-1],Max[fa[x][i-1]][i-1]);
	}
	for (int i = 0; i < v[x].size(); i++)
	{
		E e = v[x][i];
		if (e.to == from) continue;
		dis[e.to] = dis[x] + 1LL * e.w; L[e.to] = L[x] + 1;
		Max[e.to][0] = sum[e.to][0] = e.w; fa[e.to][0] = x; Dfs(e.to,x);
		Ans[++dfs_clock][0] = x; MinL[dfs_clock][0] = L[x];
	}
}

void Rmq_Pre()
{
	for (int i = 1; i <= dfs_clock; i++)
	{
		bin[i] = (1 << bin[i-1] + 1) < i ? bin[i-1] + 1 : bin[i-1];
		len[i] = (1 << bin[i]);
	}
	for (int j = 1; j < T; j++)
		for (int i = 1; i <= dfs_clock; i++)
		{
			int Nex = i + (1 << j - 1);
			if (Nex > dfs_clock) break;
			if (MinL[i][j-1] < MinL[Nex][j-1])
				MinL[i][j] = MinL[i][j-1],Ans[i][j] = Ans[i][j-1];
			else MinL[i][j] = MinL[Nex][j-1],Ans[i][j] = Ans[Nex][j-1];
		}
}

int LCA(int x,int y)
{
	x = dfn[x]; y = dfn[y];
	if (x > y) swap(x,y); int k = y - x + 1;
	return MinL[x][bin[k]] < MinL[y - len[k] + 1][bin[k]] ? 
		   Ans[x][bin[k]] : Ans[y - len[k] + 1][bin[k]];
}

LL Dis(int x,int y)
{
	int lca = LCA(x,y);
	return dis[x] + dis[y] - 2LL * dis[lca];
}

int Get_Max(int x,int y)
{
	int ret = 0;
	if (L[x] < L[y]) swap(x,y);
	for (int i = T - 1; i >= 0; i--)
		if (L[x] - (1 << i) >= L[y])
			ret = max(ret,Max[x][i]),x = fa[x][i];
	if (x == y) return ret;
	for (int i = T - 1; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
		{
			ret = max(ret,Max[x][i]); x = fa[x][i];
			ret = max(ret,Max[y][i]); y = fa[y][i];
		}
	ret = max(ret,Max[x][0]); ret = max(ret,Max[y][0]);
	return ret;
}

bool ck(int x,LL k)
{
	for (int i = T - 1; i >= 0; i--)
		if (fa[x][i] && sum[x][i] <= k)
		{
			k -= sum[x][i]; x = fa[x][i];
			if (!k) return 0;
		}
	return 1;
}

bool Check(int a,int b,LL k)
{
	int lca = LCA(a,b);
	LL d = dis[a] - dis[lca];
	if (d == k) return 0;
	if (d > k) return ck(a,k);
	k -= d; k = dis[b] - dis[lca] - k;
	return ck(b,k);
}

bool Judge(int a1,LL t1,int a2,LL t2,int x,int y)
{
	LL lx = Dis(a1,x),ly = Dis(a1,y); int g1;
	g1 = lx < ly ? x : y; t1 += min(lx,ly);
	lx = Dis(a2,x); ly = Dis(a2,y); int g2;
	g2 = lx < ly ? x : y; t2 += min(lx,ly);
	if (t1 > t2) swap(t1,t2),swap(g1,g2);
	if (g1 == g2) return Get_Max(x,y) > t2 - t1;
	else
	{
		LL tot = Dis(x,y);
		if (tot <= t2 - t1) return 0;
		LL d = t2 - t1 + tot,k;
		if (d & 1LL) return 1; k = (d >> 1LL);
		return Check(g1,g2,k);
	}
}

bool InRoad(int x,int y,int z)
{
	int lca = LCA(x,y);
	if (LCA(z,lca) != lca) return 0;
	return (LCA(x,z) == z || LCA(y,z) == z);
}

bool cmp(const int &x,const int &y) {return dfn[x] < dfn[y];}
int getint()
{
	char ch = getchar(); int ret = 0;
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9')
		ret = ret * 10 + ch - '0',ch = getchar();
	return ret;
}

int main()
{
	#ifdef DMC
		freopen("DMC.txt","r",stdin);
		freopen("test.txt","w",stdout);
	#else
		freopen("meet.in","r",stdin);
		freopen("meet.out","w",stdout);
	#endif
	
	n = getint(); m = getint();
	for (int i = 1; i < n; i++)
	{
		int x = getint(),y,w;
		y = getint(); w = getint();
		v[x].push_back(E(y,w));
		v[y].push_back(E(x,w));
	}
	L[1] = 1; Dfs(1,0); Rmq_Pre();
	
	while (m--)
	{
		int a1,b1,a2,b2,t1,t2,x,y,tp,cur; tp = cur = 0;
		a1 = getint(); b1 = getint(); t1 = getint();
		a2 = getint(); b2 = getint(); t2 = getint();
		stk[++tp] = LCA(a1,a2); stk[++tp] = LCA(a1,b2);
		stk[++tp] = LCA(b1,a2); stk[++tp] = LCA(b1,b2);
		for (int i = 1; i <= tp; i++)
			if (InRoad(a1,b1,stk[i]) && InRoad(a2,b2,stk[i])) stk[++cur] = stk[i];
		if (!cur) {puts("NO"); continue;}
		sort(stk + 1,stk + cur + 1,cmp); tp = 1;
		for (int i = 2; i <= cur; i++)
			if (stk[i] != stk[i - 1]) stk[++tp] = stk[i];
		if (tp == 1) { puts("NO"); continue; }
		else if (tp == 2) x = stk[1],y = stk[2];
		else x = stk[2],y = stk[3];
		puts(Judge(a1,t1,a2,t2,x,y) ? "YES" : "NO");
	}
	return 0;
}
