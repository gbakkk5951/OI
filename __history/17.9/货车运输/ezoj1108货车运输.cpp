using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<functional>



struct Edge{
	int a;int b;
	int c;
	bool friend operator > (const Edge &a,const Edge &b){
		return a.c>b.c;
	}
}edge[50010];

struct _Main{

int fa[10005];
int getfa(int nd){
	if(fa[nd]){
		return fa[nd]=getfa(fa[nd]);
	}
	return nd;
}
int h[10005];
int mn[10005][15];
int lca[10005][15];
void kruskal(){
	sort(edge,edge+m,greater<Edge>());
	int i;
	for(i=0;i<m;i++){
		if(getfa(edge[i].a)!=getfa(edge[i].b)){
			fa[getfa(edge[i].a)]=getfa(edge[i].b);
			add(edge[i].a,edge[i].b,edge[i].c);
			add(edge[i].b,edge[i].a,edge[i].c);
		}
	}
}

int head[10005];
int to[20010];
int val[20010];
int nxt[20010];	
bool vis[10010];
int eidx;
void preproc(int nd,int from){
	h[nd]=h[from]+1;
	lca[nd][0]=from;
	int i;
	vis[nd]=1;
	for(i=1;i<=13;i++){
		mn[nd][i]=min(mn[nd][i-1],mn[lca[nd][i-1]][i-1]);
		lca[nd][i]=lca[ lca[nd][i-1] ][i-1];
	}
	for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
		mn[to[i]][0]=val[i];
		preproc(to[i],nd);
	}
}

void inline add(int a,int b,int c){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
	val[eidx]=c;
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
	
int n,m;	
_Main(){
	freopen("truck3.in","r",stdin);
	freopen("truck.out","w",stdout);
	int q;
	int i,j,k;
	int a,b,c;
	read(n);read(m);
	for(i=0;i<m;i++){
		read(a);read(b);read(c);
		edge[i]=(Edge){a,b,c};
	}
	kruskal();
	for(i=1;i<=n;i++)if(!vis[i]){
		preproc(i,i);
	}
	read(q);
	for(i=0;i<q;i++){
		int ans=10000000;
		read(a);read(b);
		if(getfa(a)!=getfa(b)){
			printf("-1\n");
			continue;
		}
		if(h[a]>h[b])swap(a,b);
		if(h[a]<h[b]){
			for(j=13;j>=0;j--){
				if(h[b]-(1<<j)>=h[a]){
					ans=min(ans,mn[b][j]);
					b=lca[b][j];
				}
			}
		}
		if(a==b){
			printf("%d\n",ans);
			continue;
		}
		for(j=13;j>=0;j--){
			if(lca[a][j]!=lca[b][j]){
				ans=min(ans,mn[a][j]);
				ans=min(ans,mn[b][j]);
				a=lca[a][j];
				b=lca[b][j];
			}
		}
		ans=min(ans,mn[a][0]);
		ans=min(ans,mn[b][0]);
		printf("%d\n",ans);
	}
	fclose(stdout);
}	
	
	
	
}ezoj1108;
