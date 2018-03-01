#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

#define maxn 1000
#define maxm 1000000
#define nt(i) ((i)==m?1:(i)+1)
int head[maxn],nxt[maxm],point[maxm],vis[maxn];
int cha[maxn][maxn];
int n,m,tot,ans,lst[maxn];

inline void add(int x,int y){
    point[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dfs(int p){
    if(!vis[p]){vis[p]=1;++ans;}
    for(int i=head[p];i;i=nxt[i]){
	if(!vis[point[i]]){
	    if(vis[p]==1)
		vis[point[i]]=-1;
	    dfs(point[i]);
	}
    }
}

int main(){
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    srand(13232323);
    int x,y,z,k;
    scanf("%d",&m);
    while(~scanf("%d%d%d",&x,&y,&z)){
	//if(x==0)break;
	if(!cha[x][y])cha[x][y]=++n;
	if(!cha[nt(x)][z])cha[nt(x)][z]=++n;
	add(cha[x][y],cha[nt(x)][z]);
	add(cha[nt(x)][z],cha[x][y]);
    }
    for(int i=1;i<=n;++i)lst[i]=i;
    k=rand()%(n<<2);
    for(int i=1;i<=k;++i){
	x=rand()%n+1;
	y=rand()%n+1;
	swap(lst[x],lst[y]);
    }
    for(int i=1;i<=n;++i)
	if(!vis[lst[i]])dfs(lst[i]);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
