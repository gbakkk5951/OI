#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,top,s[205],e[205][205],ans[205];
bool vis[205],flag,flag1;
void dfs(int u){
	if(flag)return;
	vis[u]=1;
	s[++top]=u;
	if(top==n){
		if(e[u][s[1]]){flag=1;return;}
		flag1=1;
		for(int i=1;i<=n;++i)
			ans[i]=s[i];
		return;
	}
	for(int i=1;i<=n;++i){
		if(e[u][i]&&!vis[i])dfs(i);
		if(flag)return;
	}
	vis[u]=0;
	top--;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&e[i][j]);
	for(int i=1;i<=n;++i){
		dfs(i);
		if(flag){
			puts("0");
			for(int j=1;j<=n;++j)
				printf("%d ",s[j]); 
			return 0;
		}
	}
	if(flag1){
		puts("1");
		for(int j=1;j<=n;++j)
			printf("%d ",ans[j]);
	}
	else puts("-1");
	return 0;
}
