//by sdfzchy
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int inf=(1<<30);
inline int in()
{
	char ch=getchar();
	int f=1,tmp=0;
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {tmp=(tmp<<1)+(tmp<<3)+(ch-'0');ch=getchar();}
	return tmp*f;
}

const int N=210;
int n,m,ans=-1,a[N];
int con[N][N],vis[N];

vector<int> cur;
vector<int> e[N];
int st;
void dfs(int u,int tmp)
{
	if(ans==0||vis[u]) return;
	vis[u]=1,a[tmp]=u;
	if(tmp==n)
	{
		ans=con[u][st]^1;
		cur.clear();
		for(int i=1;i<=n;i++) cur.push_back(a[i]);
		vis[u]=0;
		return;
	}
	for(int i=0;i<e[u].size();i++)
		dfs(e[u][i],tmp+1);
	vis[u]=0;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=in();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			con[i][j]=in();
			if(con[i][j]) e[i].push_back(j);
		}
		
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(st=i,1);
		if(ans==0) break;
	}

	int cnt[N];
	memset(cnt,0,sizeof(cnt));
	cout<<ans<<endl;
	if(ans!=-1)
		for(int i=0;i<cur.size();i++)
			cout<<cur[i]<<" ";
	return 0;
}

