#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
struct _Main{
int cnt;
int head[403250];
int nxt[440000];
int flow[440000];
int from[440000];
int to[440000];
int cc[233234];
int ans;
int tot;
bool vis[233235];
int inline min ( int a , int  b ){
	return a>b?b:a;
}
void bfs(){
	int i,j,k,ceng=0; 
	stack2[0]=0;
	vis[0]=true;
	cc[0]=++ceng;
	int last=0;
	int too=1;
	memset(stack2,0,sizeof(stack2));
	while(too!=last){
		ceng++;
		j=too;
	
		for(i=last;i<j;i++){
			for(k=head[stack2[i]];k;k=nxt[k]){
				if(!vis[to[k]] && flow[k]>0){
					vis[to[k]]=true;
					cc[to[k]]=ceng;
					stack2[too++]=to[k];
				}
			}
		}
		last=j;
	}
	
	
}
int stack2[50000];
int stack[50000];
int way[50000];
void dinic(){
	
	int tt;
	int i,j,k,l;
	int min_flow;
	bool flag=true;
	while(1){
		bfs();
		if(!vis[n*1000+m-1001]){
			return;
		}
		memset(vis,0,sizeof(vis));
		tt=0;
		stack[++tt]=0;

		while(tt){
			flag=true;
			for(i=head[stack[tt]];i;flag?i=nxt[i]:i){
				flag=true;
				if(to[i]==n*1000-1001+m && flow[i]>0 && cc[stack[tt]]+1 == cc[to[i]]){
					way[tt]=i;
					stack[++tt]=to[i];
					min_flow=2147483647;
					for(j=1;j<tt;j++){
						min_flow=min(min_flow,flow[way[j]]);
					}
					for(j=tt-1;j;j--){
						flow[way[j]]-=min_flow;
						flow[way[j]^1]+=min_flow;
						if(!flow[way[j]]){
							tt=j;
						}
					}
					ans+=min_flow;
					flag=false;
					break;
				}
				else if(!vis[to[i]]	&& cc[stack[tt]]+1 == cc[to[i]] &&flow[i]>0){
					way[tt]=i;
					stack[++tt]=to[i];
					i=head[to[i]];
					flag=false;
				}
			}
			if(flag){
				vis[stack[tt]]=true;
				tt--;
			}
		}
		memset(vis,0,sizeof(vis));
	}
	
}

void netflow(){
	dinic();
}


int read(){
	char t;int a;
	while( !isdigit ( t = getchar () ) );
	a=t-'0';
	while( isdigit ( t = getchar() ) ){
		a*=10;
		a+=t-'0';
	} 
	return a;
}	
void inline add(int a,int b,int _flow){
	nxt[tot]=head[a];
	head[a]=tot;
	flow[tot]=_flow;
	from[tot]=a;
	to[tot++]=b;
}
int n,m;
_Main(){
	tot=2;
	int i,j,k;
	n=read();
	m=read();
	for(i=0;i<n;i++){
		for(j=0;j<m-1;j++){
			k=read();
			add(i*1000+j,i*1000+j+1,k);
			add(i*1000+j+1,i*1000+j,0);
			add(i*1000+j+1,i*1000+j,k);
			add(i*1000+j,i*1000+j+1,0);
		}
	}
	for(j=0;j<m;j++){
		for(i=0;i<n-1;i++){
			k=read();
			add(i*1000+j,(i+1)*1000+j,k);
			add((i+1)*1000+j,i*1000+j,0);
			add((i+1)*1000+j,i*1000+j,k);
			add(i*1000+j,(i+1)*1000+j,0);
		}
	}
	netflow();
	printf("%d",ans/2);
}

}cdvs2100;int main(){}
