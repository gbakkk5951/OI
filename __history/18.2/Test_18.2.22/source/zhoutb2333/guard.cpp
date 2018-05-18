#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define maxm 55
#define maxn 10010
#define maxe 100010
#define INF 1<<30
using namespace std;

int stat[maxm],k[maxm],m,mn=INF,mnpos,ans;
int head[maxe],point[maxe],nxt[maxe],flow[maxe],lvl[maxe],tot=1;
int s=0,t=100000,ofs=maxe>>1;
bool mp[maxn][maxn];
queue<int> q;
inline int get(int x,int lv){
	return lv*100+x;
}
inline void Add(int x,int y,int f){
	flow[++tot]=f;
	point[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void add(int x,int y,int f){
	Add(x,y,f),Add(y,x,0);
}
bool bfs(){
	memset(lvl,0,sizeof(lvl));
	lvl[s]=1,q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int j=head[x];j;j=nxt[j]){
			if(!flow[j]||lvl[point[j]])
				continue;
			lvl[point[j]]=lvl[x]+1;
			q.push(point[j]);
		}
	}
	return lvl[t];
}
int dfs(int tmp,int tmpflow){
	if(tmp==t)
		return tmpflow;
	int maxflow=0;
	for(int j=head[tmp];j&&maxflow<tmpflow;j=nxt[j]){
		if(!flow[j]||lvl[point[j]]!=lvl[tmp]+1)
			continue;
		int minflow=dfs(point[j],min(flow[j],tmpflow-maxflow));
		flow[j]-=minflow;
		flow[j^1]+=minflow;
		maxflow+=minflow;
	}
	return maxflow;
}
void solve(int tmp){
	if(tmp==mn){
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		tot=1;
		int tmpans=0,maxflow=0;
		for(int i=1;i<=mn;i++)
			tmpans+=stat[i];
		for(int i=1;i<=m;i++){
			if(i%2==0||i==mnpos)
				continue;
			int pre=i==1?m:i-1,nxt=i==m?1:i+1;
			for(int j=1;j<=k[i];j++){
				for(int l=1;l<=k[pre];l++){
					if(pre==mnpos||!mp[get(j,i)][get(l,pre)])
						continue;	
					add(get(j,i),get(l,pre)+ofs,1);
				}
				for(int l=1;l<=k[nxt];l++){
					if(nxt==mnpos||!mp[get(j,i)][get(l,nxt)])
						continue;
					add(get(j,i),get(l,nxt)+ofs,1);
				}
			}
		}
		bool flag;
		for(int i=1;i<=m;i++){
			if(i==mnpos)
				continue;
			for(int j=1;j<=k[i];j++){
				flag=true;
				for(int l=1;l<=mn;l++){
					if(!stat[l])
						continue;
					if(mp[get(j,i)][get(l,mnpos)])
						flag=false;
				}
				if(!flag)
					continue;
				tmpans++;
				if(i%2)
					add(s,get(j,i),1);
				else
					add(get(j,i)+ofs,t,1);
			}
		}
		while(bfs())
			maxflow+=dfs(s,INF);
		ans=max(ans,tmpans-maxflow);
		return;
	}
	for(int i=0;i<=1;i++){
		stat[tmp+1]=i;
		solve(tmp+1);
	}
}
int main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	int a,b,c;
	scanf("%d",&m);
	while(scanf("%d%d%d",&a,&b,&c)!=EOF&&a){
		k[c]=max(k[c],a),k[c%m+1]=max(k[c%m+1],b);
		mp[get(a,c)][get(b,c%m+1)]=mp[get(b,c%m+1)][get(a,c)]=true;
	}
	for(int i=1;i<=m;i++){
		if(k[i]>=mn)
			continue;
		mn=k[i],mnpos=i;
	}
	solve(0);
	printf("%d\n",ans);
	return 0;
}
