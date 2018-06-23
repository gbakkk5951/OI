#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define PI pair<double,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define pb(a) push_back(a)
const int maxn=5010,maxm=200010;
const double eps=1e-6;
using namespace std;
int n,m,pre[maxm],now[maxn],son[maxm],tot,fa[maxn],root[maxn],ans=1;double maxv,val[maxm],dis[maxn],mind;bool vis[maxn];
struct Edge{int x,y;double v,dta;}E[maxm];
priority_queue<PI,vector<PI>,greater<PI> > q;//用来记录所有序列的堆，first是偏离值之和，second是结束节点
void add(int a,int b,double c){pre[++tot]=now[a],now[a]=tot,son[tot]=b,val[tot]=c;}
bool is0(double a){return fabs(a)<eps;}
vector<int> s[maxn];
struct node{int ch[2],dis,ed;double val;}t[(int)(maxm*15)];

void read(int &x){
	char ch;
	for (ch=getchar();!isdigit(ch);ch=getchar());
	for (x=0;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
}

struct Tltree{
	#define ls t[p].ch[0]
	#define rs t[p].ch[1]
	int tot;
	int newnode(int son,double v){
		t[++tot]=(node){0,0,0,son,v};
		return tot;
	}
	int merge(int x,int y){
		if (!x||!y) return x+y;
		if (t[x].val>t[y].val) swap(x,y);
		int p=++tot;
		t[p]=t[x],rs=merge(y,t[x].ch[1]);
		if (t[ls].dis<t[rs].dis) swap(ls,rs);
		t[p].dis=t[rs].dis+1;
		return p;//返回p，不是tot！！！
	}
}h;//用来存储从每个点自己及祖先出发的边的堆

struct Toppgraph{//预处理出每个点到n的距离
	int pre[maxm],now[maxn],son[maxm],tot;double val[maxm];
	void add(int a,int b,double c){pre[++tot]=now[a],now[a]=tot,son[tot]=b,val[tot]=c;}
	void prework(){
		memset(dis,127,sizeof(dis));
		dis[n]=0,q.push(mp(0,n));
		while (!q.empty()){
			int x=q.top().se;double d=q.top().fi;q.pop();
			for (int y=now[x];y;y=pre[y])
				if (dis[son[y]]>d+val[y]+eps)
					dis[son[y]]=d+val[y],q.push(mp(dis[son[y]],son[y]));
		}
		while (!q.empty()) q.pop();
		mind=dis[1];
	}
}opp;

void dfs(int x){
	bool find=0;
	if (x!=n){
		for (int y=now[x];y;y=pre[y]){
			double delta=dis[son[y]]+val[y]-dis[x];
			if (son[y]==fa[x]&&is0(delta)&&!find) find=1;//如果有权值相同的，都在最短路径树上的边，任取一条即可
			else root[x]=h.merge(root[x],h.newnode(son[y],delta));//否则扔进该点的堆里
		}
	}
	for (int y=opp.now[x];y;y=opp.pre[y]){//从T开始 反着往回建树边
		int v=opp.son[y];
		if (!fa[v]&&is0(dis[x]+opp.val[y]-dis[v]))//如果还没确定是哪条，且该边可能在最短路上，就把它当作树边
			fa[v]=x,root[v]=root[x],dfs(v);
	}
}

int main(){
	//freopen("magic1.in","r",stdin),freopen("magic.out","w",stdout);
	int x,y;double z;t[0].dis=-1;
	scanf("%d%d%lf",&n,&m,&maxv);
	for (int i=1;i<=m;i++) read(x),read(y),scanf("%lf",&z),add(x,y,z),opp.add(y,x,z);
	opp.prework(),root[n]=0,fa[n]=n,dfs(n);
	//for (int i=1;i<=n;i++) printf("i=%d fa=%d %.1lf\n",i,fa[i],dis[i]);
	//for (int i=1;i<=n;i++) printf("i=%d root=%d\n",i,root[i]);
	if (!root[1]) return printf("%d",ans),0;
	memset(vis,0,sizeof(vis)),vis[n]=1;
	
	q.push(mp(t[root[1]].val,root[1]));
	maxv-=dis[1];
	while (!q.empty()&&dis[1]+q.top().fi<=maxv){
		maxv-=dis[1]+q.top().fi;
		PI now=q.top();
		//printf("top=%.1lf\n",q.top().fi);
		q.pop(),ans++;
		for (int i=0;i<2;i++){//可以换成次大的以得到k+1短
			int next=t[now.se].ch[i];
			if (next) q.push(mp(now.fi-t[now.se].val+t[next].val,next));
		}
		int ed=t[now.se].ed;
		if (root[ed]) q.push(mp(now.fi+t[root[ed]].val,root[ed]));//也可以多加一条合法的不在最短路径树中的边得到k+1短
	}
	printf("%d",ans);
	return 0;
}

/*
4 6 14.9
1 2 1.5
2 1 1.5
1 3 3
2 3 1.5
3 4 1.5
1 4 1.5
*/
