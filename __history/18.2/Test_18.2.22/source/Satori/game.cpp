#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int head[210],nxt[80010],whr[80010],mat[210],pre[210],cnt=1;
bool vis[210];
void add(int a,int b){
	nxt[cnt]=head[a];
	whr[cnt]=b;
	head[a]=cnt++;
	return;
}
bool dfs(int pos){
	for(int i=head[pos];i;i=nxt[i]){
		int t=whr[i];
		if(vis[t]==true) continue;
		vis[t]=true;
		if(mat[t]==0||dfs(mat[t])==true){
			mat[t]=pos;
			pre[pos]=t;
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,i,j,a,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a);
			if(a==1) add(i,j);
		}
	}
	for(i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)==true) ans++;
	}
	if(ans<=n-2) printf("-1\n");
	else if(ans==n){
		printf("0\n");
		for(a=i=1;i<=n;i++){
			printf("%d ",a);
			a=pre[a];
		}
	}
	else{
		printf("1\n");
		for(a=1;mat[a]!=0;a=mat[a]);
		for(i=1;i<=n;i++){
			printf("%d ",a);
			a=pre[a];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
