#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define maxn 1000
int n,cha[maxn][maxn],mat[maxn],outp[maxn],tp,ans,vis[maxn];
int used[maxn],ansi[maxn],tot;

int dfs2(int p){
    int tmp;
    if(p==0)return 1;
    if(used[p])return 0;
    used[p]=1;
    outp[++tp]=p;
    tmp=dfs2(mat[p]);
    if(tmp==0)return 0;
    return 1;
}

void ck(){
    tp=0;
    memset(used,0,sizeof(used));
    ans=dfs2(1);
    for(int i=1;i<=n;++i)
	if(!used[i]){ans=-1;return;}
    for(int i=1;i<=tp;++i)ansi[++tot]=outp[i];
}

bool dfs(int p){
    if(p>n){
	ck();
	if(ans==0)return true;
	return false;
    }
    for(int i=1;i<=n;++i)
	if(cha[p][i]&&!vis[i]){
	    mat[p]=i;vis[i]=1;
	    if(dfs(p+1))return true;
	    vis[i]=0;
	}
    if(p==n){
	ck();
	if(ans==1&&n>100)return true;
    }
    return false;
}

inline int readin(){
    int x=0,s=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')s=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*s;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int cnt=0,cnt2=0;
    n=readin();ans=-1;
    for(int i=1;i<=n;++i){
	cnt=0;
	for(int j=1;j<=n;++j)cha[i][j]=readin(),cnt+=cha[i][j];
	cnt2+=(!cnt);
    }
    if(cnt2>=2){puts("-1");return 0;}
    dfs(1);
    printf("%d\n",ans);
    if(ans>=0){
	for(int i=1;i<=tot;++i)printf("%d ",ansi[i]);
	puts("");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
