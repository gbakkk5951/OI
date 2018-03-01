#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
bool M[210][210];int n;
struct Data{
	int to,next;
}e[40100];
int head[210],cnt=0;
void ins(int u,int v){
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int mat[210];
bool vis[210];
bool match(int u){
	for(int i=head[u];i;i=e[i].next)if(!vis[e[i].to]){
		vis[e[i].to]=true;
		if(!mat[e[i].to]||match(mat[e[i].to])){
			mat[e[i].to]=u;
			return true;
		}
	}
	return false;
}
int cross(){
	int ret=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(match(i))ret++;
	}
	return ret;	
}
int deg[210];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		scanf("%d",&M[i][j]);
		if(M[i][j])ins(j,i);
	}
	int ans=cross();
	if(ans==n){
		printf("0\n");
		int u=1;
		for(int i=1;i<=n;i++){
			printf("%d ",u);
			u=mat[u];
		}
	}
	else if(ans==n-1){
		printf("1\n");
		int u;
		for(int i=1;i<=n;i++)deg[mat[i]]++;
		for(int i=1;i<=n;i++)if(!deg[i])u=i;
		for(int i=1;i<=n;i++){
			printf("%d ",u);
			u=mat[u];
		}
	}
	else{
		printf("-1\n");
	}
	return 0;
}
