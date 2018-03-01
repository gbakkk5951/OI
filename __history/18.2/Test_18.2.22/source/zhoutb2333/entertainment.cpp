#include<cstdio>
#include<algorithm>
#define maxn 15
using namespace std;

int tmps[maxn],val[maxn][2],n,k,m[2],ans=0;
void dfs(int tmp){
	if(tmp==n){
		int tmpans=0;
		for(int i=1;i<=n-k+1;i++){
			for(int j=0;j<=1;j++){
				int cnt=0;
				for(int l=i;l<=i+k-1;l++)
					cnt+=tmps[l]==j;	
				if(cnt<m[j])
					return;
			}
		}
		for(int i=1;i<=n;i++)
			tmpans+=val[i][tmps[i]];
		ans=max(ans,tmpans);
		return;
	}
	for(int i=0;i<=1;i++){
		tmps[tmp]=i;
		dfs(tmp+1);
	}	
}
int main(){
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	scanf("%d%d%d%d",&n,&k,&m[0],&m[1]);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i][0]);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i][1]);
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
