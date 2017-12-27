using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<queue>
#include<cctype>
#include<bitset>
#include<algorithm>
int n,m;
int num;
struct NetFlow{
int ans;	
int val[65][65];
int idx[65][65];
int nxt[15000];int flow[15000];
int cst[15000];int head[4000 ];
int dis[15000];int from[4000 ];
int dst[4000 ];
int t[15000];
int edx;
int end;

NetFlow(){
	ini();
}

int run(int nd,int limit){
	if(nd==end)return limit;
	int i;
	for(i=head[nd];i;i=nxt[i])if(t[i]==dst[nd] && flow[i]>0){
		limit=run(t[i],min(limit,flow[i]));
		ans+=cst[i]*limit;
		flow[i]-=limit;
		flow[i^1]+=limit;
		break;
	}
	return limit;
}
void buildmap(){
	int cnt=2;
	add(0,1,0,num);
	add(1,0,0,0);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m+i-1;j++){
			idx[i][j]=cnt++;
			cnt++;
		}
	}
	for(i=1;i<=m;i++){
		add(1,idx[1][i],0,1);		
		add(idx[1][i],1,0,0);
	}
	for(i=1;i<n;i++){
		for(j=1;j<=m+i-1;j++){
			add(idx[i][j],idx[i][j]+1,val[i][j],1);
			add(idx[i][j]+1,idx[i][j],-val[i][j],0);
			add(idx[i][j]+1,idx[i+1][j],0,1);
			add(idx[i+1][j],idx[i][j]+1,0,0);
			add(idx[i][j]+1,idx[i+1][j+1],0,1);
			add(idx[i+1][j+1],idx[i][j]+1,0,0);			
		}
	}
	end=cnt++;
	for(i=1;i<=m+n-1;i++){
		add(idx[n][i],idx[n][i]+1, val[n][i],1);
		add(idx[n][i]+1,idx[n][i],-val[n][i],0);		
		add(idx[n][i]+1,end,0,1);
		add(end,idx[n][i]+1,0,0);
	}
	
}

void ini(){
	edx=1;
}
void inline add(int a,int b,int c,int f){
	edx++;
	nxt[edx]=head[a];
	head[a]=edx;
	t[edx]=b;
	flow[edx]=f;
	cst[edx]=c;
}

bool spfa(){
	int nd;int i;
	memset(dis,128,sizeof(dis));
	v.reset();
	q.push(0);
	v[0]=1;
	dis[0]=0;
	while(!q.empty()){
		nd=q.front();q.pop();
		v[nd]=0;
		for(i=head[nd];i;i=nxt[i])if(flow[i]&&dis[t[i]]<dis[nd]+cst[i]  ){
			from[t[i]]=nd;
			dis[t[i]]=dis[nd]+cst[i];
			if(!v[t[i]]){
				v[t[i]]=1;
				q.push(t[i]);
			}
		}
	}
	if(dis[end]>0) getway();
	return dis[end]>0;
}
void getway(){
	int goal=end,beg=from[end];
	int i,j;
	while(1){
		dst[beg]=goal;
		if(beg==0)break;
		goal=beg;
		beg=from[beg];
	}
}

queue<int>q;
bitset<4000>v;
}netflow;

template <typename Type>
	void read(Type	&a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}


struct _Main{
	
	
_Main(){
	int i,j;
	read(n);read(m);read(num);
	for(i=1;i<=n;i++){
		for(j=1;j<=m+i-1;j++){
			read(netflow.val[i][j]);
		}
	}
	netflow.buildmap();
	while(netflow.spfa()) netflow.run(0,1);
	printf("%d",netflow.ans);
}
	
	
}cdvs1033;	
