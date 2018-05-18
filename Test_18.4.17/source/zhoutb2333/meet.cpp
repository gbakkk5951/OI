#include<bits/stdc++.h>
#define maxn 110
using namespace std;

int head[maxn],point[maxn<<1],nxt[maxn<<1],val[maxn<<1],tot=0;
int fa[maxn],tag[maxn][3],d[maxn],n,q,cnt=0;
inline void add(int x,int y,int z){
	val[++tot]=z;
	point[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dfs(int x,int _fa){
	fa[x]=_fa;
	for(int j=head[x];j;j=nxt[j]){
		if(point[j]==_fa)
			continue;
		d[point[j]]=val[j],dfs(point[j],x);
	}
}
bool dfs(int x,int _fa,int tar,int dis,int tp){
	if(x==tar){
		tag[x][tp]=dis;
		return true;
	}
	for(int j=head[x];j;j=nxt[j]){
		if(point[j]==_fa)
			continue;
		if(dfs(point[j],x,tar,dis+val[j],tp)){
			tag[x][tp]=dis;
			return true;
		}
	}
}
void check(){
	bool flag=false;
	for(int i=2;i<=n;i++){
		if(!tag[i][1]||!tag[i][2]||!tag[fa[i]][1]||!tag[fa[i]][2])
			continue;
		if(tag[i][1]<tag[fa[i]][1]){
			if(tag[i][2]<tag[fa[i]][2]){
				if(tag[i][1]!=tag[i][2]&&abs(tag[i][1]-tag[i][2])<d[i])
					flag=true;
			}
			else{
				if(tag[i][1]==tag[i][2]||tag[fa[i]][1]==tag[fa[i]][2])
					continue;
				if((tag[i][1]<tag[fa[i]][2])==(tag[fa[i]][1]<tag[i][2]))
					flag=true;
			}
		}
		else{
			if(tag[i][2]>tag[fa[i]][2]){
				if(tag[i][1]!=tag[i][2]&&abs(tag[i][1]-tag[i][2])<d[i])
					flag=true;
			}
			else{
				if(tag[i][1]==tag[i][2]||tag[fa[i]][1]==tag[fa[i]][2])
					continue;
				if((tag[i][1]<tag[fa[i]][2])==(tag[fa[i]][1]<tag[i][2]))
					flag=true;
			}
		}
	}
	puts(flag?"YES":"NO");
}
int main(){
	freopen("meet.in","r",stdin);
	freopen("meet.out","w",stdout);
	int x,y,z,u1,v1,t1,u2,v2,t2;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n-1;i++)
		scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	dfs(1,0);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d%d%d%d",&u1,&v1,&t1,&u2,&v2,&t2);
		memset(tag,0,sizeof(tag));
		dfs(u1,0,v1,t1,1),dfs(u2,0,v2,t2,2);
		check();
	}
	return 0;
}
