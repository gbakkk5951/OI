#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std;

const int N=205;
int n;
int d[N][N];
bool vis[N];
int tot;
int st[N];
bool huan;
int flag=-1,lin=-1;
int ans[N],nxt[N];

void dfs(int u,int now){
	//vis[u]=1;
	//st[++tot]=u;
	if(tot==n) {
		if(d[u][1]==now) {
			flag=now;
			if(now==1) for(int i=1;i<=tot;++i) ans[i]=st[i];
			if(now==0) {
				ans[1]=1;
				for(int i=1;i<n;++i) ans[i+1]=st[n-i+1];
			}
		}
		else {
			lin=1;
			if(now==1) for(int i=1;i<=tot;++i) nxt[i]=st[i];
			if(now==0) {
				nxt[1]=1;
				for(int i=1;i<n;++i) nxt[i+1]=st[n-i+1];
			}
		}
		return;
	}
	for(int i=n;i>=1;--i)
		if((d[u][i]==now)&&(i!=u)&&(!vis[i])) {
			//cout<<i<<" "<<vis[i]<<endl;
			st[++tot]=i;
			vis[i]=1;
			dfs(i,now);
			if(flag!=-1) return;
			--tot;
			vis[i]=0;
		}
	//vis[u]=0;
	//tot--;
}

int main(){
	//freopen("in.in","r",stdin);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	scanf("%d",&n);
	huan=1;
	for(int i=1;i<=n;++i){
		int sum=0;
		for(int j=1;j<=n;++j) scanf("%d",&d[i][j]),sum+=d[i][j];
		if(sum==0||sum==n) huan=0;
	}
	vis[1]=1;
	tot=1;
	st[tot]=1;
	dfs(1,1);
	memset(vis,0,sizeof(vis));
	memset(st,0,sizeof(st));
	//for(int i=1;i<=n;++i) cout<<vis[i]<<" ";cout<<endl;
	vis[1]=1;
	tot=1;
	st[tot]=1;
	if(flag==-1) dfs(1,0);
	if(flag!=-1){
		puts("0");
		for(int i=1;i<=n;++i) printf("%d ",ans[i]);
		return 0;
	}
	if(lin==-1) puts("-1");
	else{
		puts("1");
		for(int i=1;i<=n;++i) printf("%d ",nxt[i]);
	}
	return 0;
}

/*
5
0 0 1 1 1
1 0 1 1 0
0 0 0 1 0
0 0 0 0 0
0 1 1 1 0
*/

/*
4
0 1 0 0
0 0 1 0
1 0 0 1
1 1 0 0
*/