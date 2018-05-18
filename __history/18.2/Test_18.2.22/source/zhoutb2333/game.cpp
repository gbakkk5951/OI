#include<cstdio>
#include<algorithm>
#include<queue>
#define maxn 25
using namespace std;

int mp[maxn][maxn],cur[maxn],ans0[maxn],ans1[maxn],ans=-1,n;
bool vis[maxn];
void dfs(int tmp){
	if(ans==0)
		return;
	if(tmp==n){
		if(mp[cur[n]][cur[1]]){
			printf("%d\n",ans=0);
			for(int i=1;i<=n;i++)
				printf(i==n?"%d":"%d ",cur[i]);
		}
		else{
			ans=1;
			for(int i=1;i<=n;i++)
				ans1[i]=cur[i];
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if((tmp&&!mp[cur[tmp]][i])||vis[i])
			continue;
		vis[i]=true,cur[tmp+1]=i;
		dfs(tmp+1);
		vis[i]=false;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	if(n>10){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&mp[i][j]);
	dfs(0);
	if(ans==1){
		puts("1");
		for(int i=1;i<=n;i++)
			printf(i==n?"%d":"%d ",ans1[i]);
	}
	else if(ans==-1)
		puts("-1");
	return 0;
}
