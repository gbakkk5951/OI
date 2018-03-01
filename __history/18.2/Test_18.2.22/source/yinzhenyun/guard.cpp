#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int m;
struct Data{
	int to,next;
}e[40100];
int head[510],cnt=0;
void ins(int u,int v){
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int h[51];
int inq[510];
int mat[510];
bool vis[510];
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
	for(int i=1;i<=m;i++)if(i%2)
	for(int j=1;j<=h[i];j++)if(inq[(i-1)*10+j]){
		memset(vis,0,sizeof(vis));
		if(match(i))ret++;
	}
	return ret;	
}
int main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	scanf("%d",&m);
	int A,B,C;
	while(scanf("%d%d%d",&A,&B,&C)!=EOF){
		h[C]=max(h[C],A);
		h[C==m?1:C+1]=max(h[C==m?1:C+1],B);
		if(C%2)ins((C-1)*10+A,(C==m?0:C)*10+B);
		else ins((C==m?0:C)*10+B,(C-1)*10+A);
		inq[(C-1)*10+A]=true;
		inq[(C==m?0:C)*10+B]=true;
	}
	int ans=cross();
	for(int i=1;i<=m;i++)
	for(int j=1;j<=h[i];j++)if(!inq[(i-1)*10+j])ans++;
	printf("%d\n",ans);
	return 0;
}
