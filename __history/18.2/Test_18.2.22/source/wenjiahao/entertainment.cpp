#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,k,ms,me;
int s[1001],e[1001];
long long ans = 0;
bool d[1001];
void dfs(int t,long long now,int sl)
{
	if(t == n + 1)
	{
		ans = max(ans,now);
		return;
	}
	if(t < k)
	{
		d[t] = true;
		dfs(t + 1,now + s[t],sl + 1);
		d[t] = false;
		dfs(t + 1,now + e[t],sl);
		return;
	}
	if(d[t - k])--sl;
	if(sl + 1 >= ms && k - 1 - sl >= me)
	{
		d[t] = true;
		dfs(t + 1,now + s[t],sl + 1);
	}
	if(sl >= ms && k - 1 - sl + 1 >= me)
	{
		d[t] = false;
		dfs(t + 1,now + e[t],sl);
	}
	return;
}
int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	scanf("%d%d%d%d",&n,&k,&ms,&me);
	for(int i = 1;i <= n;++i)
	{
		scanf("%d",&s[i]);
	}
	for(int i = 1;i <= n;++i)
	{
		scanf("%d",&e[i]);
	}
	dfs(1,0,0);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
