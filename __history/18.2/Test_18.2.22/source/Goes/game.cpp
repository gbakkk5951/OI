#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
inline int read(){
	char ch='*';int sum=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
		sum*=10,sum+=ch-'0',ch=getchar();
	return sum;
}
#if 0
Writers: G.S.M. && Goes;
Fall in love with Z J Y
#endif
const int N=205;
struct ss{
	int to,nex;
}edge[N*N];int head[N],ecnt;
void add(int x,int y){
	edge[++ecnt]=(ss){y,head[x]};
	head[x]=ecnt;
}
//tarjan 
int dfn[N],low[N],ti,fa[N];
int stack[N],top,goes[N];
bool tarjan(int pos){
	dfn[pos]=low[pos]=++ti;
	stack[++top]=pos;
	for(int i=head[pos];i;i=edge[i].nex)
	if(!dfn[edge[i].to]){
		tarjan(edge[i].to);
		if(low[pos]>low[edge[i].to]){
			low[pos]=low[edge[i].to];
			goes[pos]=edge[i].to;
		}
	}else if(low[pos]>dfn[edge[i].to]){
			low[pos]=dfn[edge[i].to];
			goes[pos]=edge[i].to;
	}
	if(dfn[pos]==low[pos])return 0;return 1;
}
//瞎搞链 
int n,map[N][N];
bool vis[N];
bool dfs(int pos){
	vis[pos]=true;int flag=true;
	for(int i=head[pos];i;i=edge[i].nex)
	if(!vis[edge[i].to]){
		if(dfs(edge[i].to)){
			goes[pos]=edge[i].to;return true;}
		flag=false;
	}
	if(flag){
		for(int i=1;i<=n;i++)
		if(!vis[i]) flag=false,i=n+1;
	}vis[pos]=false;return flag;
}
//辅助部分
bool check(int x){
	int step=0;while(goes[x])x=goes[x],step++;
	if((++step)!=n) return false;
	else return true;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();int flag=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		map[i][j]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<i;j++)
	if(map[i][j]) add(i,j);else add(j,i);
	//如果是环从1开始就能绕回来tarjan一次就好 
	if(!tarjan(1)){
		cout<<0<<endl;int pos;cout<<1<<" ";
		for(int i=head[1];i;i=edge[i].nex)
		if(check(edge[i].to)) pos=edge[i].to,i=0;
		while(goes[pos]){cout<<pos<<" ";pos=goes[pos];}
		return 0;
	}
	//不是环，暴力找有没有链 
	int pos=0;
	for(int i=1;i<=n;i++)
	if(dfs(i))pos=i,i=n+1;
	cout<<goes[2]<<goes[3]<<goes[4]<<endl;
	if(!pos){cout<<"-1"<<endl;return 0;}
	cout<<"1"<<endl<<pos<<" ";
	while(goes[pos]){cout<<goes[pos]<<" ";pos=goes[pos];}
	//√ 
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
