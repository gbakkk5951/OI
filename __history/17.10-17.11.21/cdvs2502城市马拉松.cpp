using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<map>
#include<queue>

struct Edge{
	int dis,nd;
	bool friend operator < (const Edge &a,const Edge &b){
		return a.dis<b.dis;
	}
};

priority_queue<Edge>heap;
struct _Main{
int dis[1005];
int mmpdis[25][25];
int degree[1005];
int head[1005];
int nxt[2000010];
int to[2000010];
int val[2000010];
map<int,int>mmp;
int mmpidx;
int eidx;
void dijkstra(int beg){
	int i;Edge tp;
	int nd;
	memset(dis,63,sizeof(dis));
	dis[beg]=0;
	heap.push((Edge){0,beg});
	while(!heap.empty()){
		tp=heap.top();heap.pop();
		if(tp.dis!=dis[tp.nd])continue;
		nd=tp.nd;
		for(i=head[nd];i;i=nxt[i]){
			if(dis[to[i]]>dis[nd]+val[i]){
				dis[to[i]]=dis[nd]+val[i];
				heap.push((Edge){dis[to[i]],to[i]});
			}
		}
	}
	
}

template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
void inline add(int a,int b,int c){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
	val[eidx]=c;
	degree[a]++;
}
int n,m,s,t;
long long ans;	
int dp[4200000];

_Main(){
	int mx;
	map<int,int>::iterator it1,it2;
	int i,j,I;int a,b,c;
	memset(dp,63,sizeof(dp));
	mx=dp[4199999];
	read(n);read(m);read(s);read(t);
	degree[s]++;degree[t]++;
	for(i=1;i<=m;i++){
		read(a);read(b);read(c);
		add(a,b,c);add(b,a,c);
		ans+=c;
	}
	for(i=1;i<=n;i++){
		if(degree[i]&1){
			mmp[i]=mmpidx++;
		}
	}
	memset(mmpdis,63,sizeof(mmpdis));
	for(it1=mmp.begin();it1!=mmp.end();it1++){
		dijkstra(it1->first);
		for(it2=mmp.begin();it2!=mmp.end();it2++){
			mmpdis[it1->second][it2->second]=dis[it2->first];
		}
	}
	for(I=0,dp[0]=0;I<(1<<mmpidx);I++)if(dp[I]<mx){
		for(i=0;i<mmpidx;i++)if(!(I&(1<<i))){
			for(j=i+1;j<mmpidx;j++)if(!(I&(1<<j)) && i!=j){
				dp[I|(1<<i)|(1<<j)]=min(dp[I|(1<<i)|(1<<j)],dp[I]+mmpdis[i][j]);
			}
			break;
		}
	}
	ans+=dp[(1<<mmpidx)-1];
	printf("%lld",ans);
}	
	
	
	
}cdvs2502;
