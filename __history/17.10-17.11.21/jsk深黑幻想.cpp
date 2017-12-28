using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
namespace Protector{
const int beg=0,dst=100010;
const int ebase=50005;

int n,m;
int eidx=1;
int layer[100050],head[100050],now[100050],flow[400050],nxt[400050],to[400050];
bool vis[100050];

int deg[50050];
int edge[50050][3];

int q[100050];

struct _Main{
	template<typename Type>
		void read(Type &a){
			char t;
			while(!isdigit(t=getchar()));
			a=t-'0';
			while( isdigit(t=getchar())){
				a*=10;a+=t-'0';
			}
		}

	bool  getlayer(){
		memset(vis,0,sizeof(vis));
		int qhead=0,qtail=0;
		q[qtail++]=beg;
		vis[beg]=1;
		int i;
		int nd;
		while(qhead<qtail){
			nd=q[qhead++];
			for(i=head[nd];i;i=nxt[i]){
				if(flow[i] && !vis[to[i]]){
					layer[to[i]]=layer[nd]+1;
					q[qtail++]=to[i];
					vis[to[i]]=1;
				}
			}
		}
		return vis[dst];
	}
	int getflow(int nd,int rem){
		if(nd==dst)return rem;
		int tot=0;
		int i,tmp;
		for(i=(now[nd]==-1?head[nd]:now[nd]);i;i=nxt[i])if(flow[i] && layer[to[i]]>layer[nd]){
			if(tmp=getflow(to[i],min(flow[i],rem))){
				flow[i]-=tmp;
				flow[i^1]+=tmp;
				tot+=tmp;
				rem-=tmp;		
				if(rem==0)break;		
			}
		}
		now[nd]=i;
		return tot;
	}
	void inline add(int a,int b,int c){
		eidx++;
		nxt[eidx]=head[a];
		head[a]=eidx;
		to[eidx]=b;
		flow[eidx]=c;
	}
	_Main(){
		int i,j,k;
		int a,b,c;
		read(n);read(m);
		for(i=1;i<=m;i++){
			read(edge[i][0]);
			read(edge[i][1]);
			read(edge[i][2]);
			deg[edge[i][0]]++;

		}
		for(i=1;i<=m;i++){
			add(beg,ebase+i,1);
			add(ebase+i,beg,0);
			if(deg[edge[i][1]]){
				add(ebase+i,edge[i][1],1);
				add(edge[i][1],ebase+i,0);				
			}
			if(deg[edge[i][2]]){
				add(ebase+i,edge[i][2],1);
				add(edge[i][2],ebase+i,0);					
			}
		}
		
		for(i=1;i<=n;i++)if(deg[i]){
			add(i,dst,deg[i]);
			add(dst,i,0);
		}
		while(getlayer()){
			memset(now,255,sizeof(now));
			while(getflow(beg,1e6));
		}
		for(i=1;i<=m;i++){
			for(j=head[ebase+i];j;j=nxt[j]){
				if(flow[j]==0){
					if(to[j]==edge[i][1]){
						putchar('0');
						break;					
					}else if(to[j]==edge[i][2]){
						putchar('1');
						break;										
					}
				}
			}
		}
	}
	
	
	
	
	
	
	
}DeepDarkFantasy;


}
