#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=205;
const int INF=0x3f3f3f3f;
const int maxe=maxn*maxn;

int head[maxn],nex[maxe],to[maxe],n,q[maxn],stack[maxn],top,tot;
bool vis[maxn],has;

inline void add(int x,int y){
	nex[++tot]=head[x];
	to[tot]=y;
	head[x]=tot;
}

inline bool dfs(int u){
	vis[u]=true;
	stack[++top]=u;
	int v;
	for(int i=head[u];i;i=nex[i]){
		v=to[i];
		if(!vis[v]){
			if(dfs(v)) return true;
		}
		else if(top==n){
			if(v==stack[1]){
				memcpy(q+1,stack+1,sizeof(int)*top);
				return true;
			}
			else if(!has){
				has=true;
				memcpy(q+1,stack+1,sizeof(int)*top);
			}
		}
	}
	vis[u]=false;
	top--;
	return false;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			if(i==j) continue;
			if(x==1) add(i,j);
			else if(x==0) add(j,i);
		}
	}
	bool huan=dfs(1);
	if(huan){
		printf("0\n");
		for(int i=1;i<=n;i++){
			printf("%d ",q[i]);
		}
		return 0;
	}
	for(int i=2;i<=n && !has;i++){
		dfs(i);
	}
	if(has){
		printf("1\n");
		for(int i=1;i<=n;i++){
			printf("%d ",q[i]);
		}
	}
	else{
		printf("-1");
	}
	return 0;
}
