#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=105;
const int maxm=55;
const int maxe=maxn*maxn;
const int INF=0x3f3f3f3f;

int head[maxn],tot,nex[maxe*2],to[maxe*2],f[maxn][2],h[maxm],id[maxm][maxn],cnt,
eu[maxe],ev[maxe],ei[maxe];
bool vis[maxn],linked[maxn],cho[maxn],hase[maxn];

inline void add(int x,int y){
//	printf("%d-%d\n",x,y);
	nex[++tot]=head[x];
	to[tot]=y;
	head[x]=tot;
}

inline void dp(int u){
	int v;
	f[u][1]=1;
	f[u][0]=0;
	if(cho[u]==true) f[u][1]=-INF;
	vis[u]=true;
	for(int i=head[u];i;i=nex[i]){
		v=to[i];
		if(!vis[v]){
			dp(v);
		//	printf("u=%d v=%d\n",u,v);
			if(f[v][0]!=-INF && f[u][1]!=-INF) f[u][1]+=f[v][0];
			else f[u][1]=-INF;
			if((f[v][0]!=-INF || f[v][1]!=-INF) && f[u][0]!=-INF) f[u][0]+=max(f[v][0],f[v][1]);
			else f[u][0]=-INF;
		}
	}
}

int main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	int m,a,b,c,etot=0;
	scanf("%d",&m);
	while(scanf("%d%d%d",&a,&b,&c)!=EOF){
		eu[++etot]=a;ev[etot]=b;ei[etot]=c;
		h[c]=max(h[c],a);h[c%m+1]=max(h[c%m+1],b);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=h[i];j++){
			id[i][j]=++cnt;
		//	printf("i=%d j=%d id=%d\n",i,j,cnt);
		}
	}
	for(int i=1;i<=etot;i++){
		c=ei[i];a=eu[i];b=ev[i];
		add(id[c][a],id[c%m+1][b]);
		add(id[c%m+1][b],id[c][a]);
		linked[id[c][a]]=linked[id[c%m+1][b]]=true;
	}
	int ans=0;
	if(m%2==0){
		for(int i=1;i<=cnt;i++){
			if(!vis[i]){
				dp(i);
				ans+=max(f[i][0],f[i][1]);
			}
		}
		printf("%d",ans);
	}
	else{
		int x=1;
		for(int i=1;i<=m;i++){
			if(h[x]>h[i]) x=i;
		}
		int w=h[x],sum;
		bool jum=false;
		for(int i=0;i<(1<<w);i++){
			sum=0;
			jum=false;
			memset(vis,false,sizeof(vis));
			memset(cho,false,sizeof(cho));
			for(int j=1;j<=w;j++){
				int u=id[x][j];
				vis[u]=true;
				if((i>>(j-1))&1){
					sum++;
				//	printf("j=%d sum++\n",j);
					for(int k=head[u];k;k=nex[k]){
						int v=to[k];
						cho[v]=true;
					}
				}
				else if(head[u]==0){
					jum=true;
					break;
				}
			}
			if(jum) continue;
			for(int j=1;j<=cnt;j++){
				if(!vis[j]){
					dp(j);
				//	printf("f[%d]:1=%d 0=%d\n",j,f[j][1],f[j][0]);
					if(f[j][0]!=-INF || f[j][1]!=-INF) sum+=max(f[j][0],f[j][1]);
					else sum=-INF;
				}
			}
		//	printf("i=%d sum=%d\n",i,sum);
			ans=max(ans,sum);
		}
		printf("%d",ans);
	}
	return 0;
}
