#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int h[10][10];
int n,minn,maxn;
bool suc;
bool check2()
{
	if (h[1][1] * h[2][2] - h[1][2] * h[2][1] != 1) return false;
	printf("%d %d\n%d %d\n",h[1][1],h[1][2],h[2][1],h[2][2]);
	return true;
}
int nxd(int *vec)
{
	int tot = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j < i;j++)
		{
			if (vec[j] > vec[i]) tot++;
		}
	}
	return tot;
}
void t_check()
{
	int sec[10],t_suc = 0,res = 0;
	for (int i = 1;i <= n;i++) sec[i] = i;
	do
	{
		int ttt = 0;
		for (int i = 1;i <= n;i++) ttt += h[i][sec[i]];
		if (nxd(sec) & 1) res -= ttt;else res += ttt;
		if (res == 1)
		{
			t_suc = true;
			break;
		}
	} while (next_permutation(sec + 1,sec + n + 1)); 
	if (!t_suc) return;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++) printf("%d ",h[i][j]);
		printf("\n");
	}
	suc = true;
}
void dfs(int x,int y)
{
	if (x == n + 1)
	{
		t_check();
		return;
	}
	for (int i = minn;i <= maxn;i++)
	{
		h[x][y] = i;
		if (y == n) dfs(x + 1,1);else
			dfs(x,y + 1);
		if (suc) return; 
		h[x][y] = 0;
	}
}
long long fpow(int x,int k)
{
	if (k == 1) return x;
	long long t = fpow(x,k >> 1);
	if (k & 1) return t * t * x;
	return t * t; 
}
int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&h[1][i]);
	minn = 2001,maxn = -2001;
	for (int i = 1;i <= n;i++) minn = min(minn,h[1][i]),maxn = max(maxn,h[1][i]); 
	minn++,maxn--;
	minn = max(-2000,minn);
	maxn = min(2000,maxn);
	if (n == 1)
	{
		if (h[1][1] != 1) printf("no solution\n");else printf("%d\n",h[1][1]);
		return 0;
	}
	if (n == 2)
	{
		for (int i = -2000;i <= 2000;i++)
		{
			for (int j = -2000;j <= 2000;j++)
			{
				h[2][1] = i,h[2][2] = j;
				if (check2()) return 0;
			}
		}
		printf("no solution\n"); 
		return 0;
	}
	if (maxn - minn <= 10 && fpow(maxn - minn,n * (n - 1)) < 10000)
	{
		dfs(2,1);
		if (suc) return 0;
	}
	printf("no solution\n");
	return 0;
}
