#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100005,inf=1e9;
int n,lk[N],h[N],ans,cnt,used[N],ti,an[N];
struct qwe
{
    int ne,to;
}e[40005];
void add(int u,int v)
{
	cnt++;
	e[cnt].ne=h[u];
	e[cnt].to=v;
	h[u]=cnt;
}
bool find(int u)
{
    for(int i=h[u];i;i=e[i].ne)
		if(used[e[i].to]!=ti)
		{
			used[e[i].to]=ti;
			if(!lk[e[i].to]||find(lk[e[i].to]))
			{
				lk[e[i].to]=u;
				return 1;
			}
		}
    return 0;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			if(x)
				add(i,j);
		}
	for(int i=1;i<=n;i++)
	{
		ti++;
		if(find(i))
			ans++;
	}//cout<<ans<<endl;
	if(ans!=n)
	{
		puts("-1");
		return 0;
	}
	for(int u=1,con=1;con<=n;con++)
	{
		an[con]=u;;
		u=lk[u];
	}
	if(lk[an[n]]==an[1])
		puts("0");
	else
		puts("1");
	for(int i=n;i>=1;i--)
		printf("%d ",an[i]);
	return 0;
}
/*
5
0 0 1 1 1
1 0 1 1 0
0 0 0 1 0
0 0 0 0 1
0 1 1 0 0
*/