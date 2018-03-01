#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define p(i,j) (sum[i-1]+j)
#define debug //printf("%d %s\n",__LINE__,__FUNCTION__);
using namespace std;
const int maxn= 10005;
struct edge{
	int to,next,val;
}e[10002];
int n,cnt=1,h[maxn],dis[maxn];
int floor[55],sum[55];
int from[10005],to[10006],va[10006];
int cur[10006];
int m;
int s,t;
bool vis[10005];
queue<int> q;
int qmin(int a, int b)
{
    int diff = b - a;
    // b < a: a + (diff & -1)
    // b > a: a + (diff &  0)
    return a + (diff & (diff >> 31));
}
inline void add(int from,int to,int val)
{
//	printf("%d-%d-%d\n",from,to,val);
    e[++cnt].next=h[from];
    e[cnt].to=to;
    e[cnt].val=val;
    h[from]=cnt;
    e[++cnt].next=h[to];
    e[cnt].to=from;
    e[cnt].val=0;
    h[to]=cnt;
}
inline bool bfs()
{
    memset(dis,-1,sizeof(dis));
    dis[s]=0;	
    q.push(s);
    int j;
    while(!q.empty()){
        j=q.front();q.pop();
        for(register int i=h[j];i;i=e[i].next)
        {
            int v=e[i].to;
            if(dis[v]<0&&e[i].val>0)
            {
                dis[v]=dis[j]+1;
                q.push(v);
                
            }
        }
    }
    return dis[t]>0;
}
int find(int x,int flow)
{
    if(x==t||flow==0) return flow;
    int a=0;
    int f=0;
    for(register int &i=cur[x];i;i=e[i].next)
    {
        //int v=e[i].to;
        if(e[i].val&&dis[x]<dis[e[i].to])
        {
            f=find(e[i].to,qmin(e[i].val,flow-a));
            e[i].val-=f;
            e[i^1].val+=f;
            a+=f;
            if(a==flow)break;
        }
    }
    if(!a) dis[x]=-1;
    return a;
}
int main(){
	scanf("%d",&n);
	int u,v,w;
	while(scanf("%d%d%d",&u,&v,&w)!=EOF&&u&&v&&w){
		from[++m]=u,to[m]=v,va[m]=w;
		floor[w]=max(floor[w],u);
		if(w==n) w-=n;w++;
		floor[w]=max(floor[w],v);
	}
	for(int i=1;i<=n;i++) sum[i]=floor[i]+sum[i-1];
	t=sum[n]+1;
	if(n&1){
		debug
		int minn=1;
		int res=0;
		for(int i=1;i<=n;i++) if(floor[i]<floor[minn]) minn=i;
		if(n==1) {cout<<floor[1]<<endl;return 0;}
		else {
			int tot=0;
			debug
			for(int i=0;i<(1<<floor[minn]);i++){
				tot=0;
				cnt=1;
				memset(vis,0,sizeof(vis));
				memset(h,0,sizeof(h));
				for(int j=0;j<floor[minn];++j){
					if(i&(1<<j)) vis[p(minn,j+1)]=1,
					tot++;
				}	
				debug
				int w_=minn-1;
				if(!w_) w_=1;
				for(register int j=1;j<=m;j++){
					if(va[j]==minn&&vis[p(minn,from[j])]) {int _w=va[j]+1;if(va[j]==n) _w=1;vis[p(_w,to[j])]=1;continue;}
					if(va[j]==w_&&vis[p(minn,to[j])]) {vis[p(w_,from[j])]=1; continue;}
					int _w=va[j]+1;
					if(va[j]==n) _w=1;
					if(_w&1) add(p(_w,to[j]),p(va[j],from[j]),1000);
					else add(p(va[j],from[j]),p(_w,to[j]),1000);
				}
				debug
				for(int j=1;j<=n;j++){
					if(j!=minn){
						for(int k=1;k<=floor[j];k++){
							if(!vis[p(j,k)]){
								tot++;
								if(j&1) add(s,p(j,k),1);
								else add(p(j,k),t,1);
							}
						}
					}
				}
				debug
				
			//	cout<<tot<<endl;
				while(bfs()){
					//cout<<tot<<endl;
					for(int j=s;j<=t;j++)
						cur[j]=h[j];
					tot-=find(s,0x7fffffff);
				}
				//cout<<tot<<endl;
				res=max(tot,res);
			}
			cout<<res<<endl;
		}
	}
	else{
		int ans=0;  
		t=sum[n]+1;
		for(int i=1;i<=n;i++)for(int j=1;j<=floor[i];j++){
			if(i&1) add(s,p(i,j),1);
			else add(p(i,j),t,1);
		}
		for(int i=1;i<=m;i++){
			int _w=va[i]+1;
			if(va[i]==n) _w=1;
			if(_w&1) add(p(_w,to[i]),p(va[i],from[i]),1);
			else add(p(va[i],from[i]),p(_w,to[i]),1);
		}
		for(register int i=s;i<=t;i++){
			cur[i]=h[i];
		}
		while(bfs()){
			ans+=find(s,0x7fffffff);
		}
		cout<<sum[n]-ans<<endl;
	}
}
			


