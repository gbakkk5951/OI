#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=1005;
const int INF=0x3f3f3f3f;

int a[maxn],K,n,ans=-INF,val[3][maxn],m1,m2;

inline void calc(){
	int n1=0,n2=0,sum=0;
	for(int i=1;i<=K;i++){
		if(a[i]==1) n1++;
		else if(a[i]==2) n2++;
		sum+=val[a[i]][i];
	}
	if(n1<m1 || n2<m2) return;
	for(int i=K+1;i<=n;i++){
		if(a[i]==1) n1++;
		else if(a[i]==2) n2++;
		if(a[i-K]==1) n1--;
		else if(a[i-K]==2) n2--;
		if(n1<m1 || n2<m2) return;
		sum+=val[a[i]][i];
	}
	ans=max(ans,sum);
}

inline void dfs(int p){
	if(p>n){calc();return;}
	a[p]=0;dfs(p+1);a[p]=1;dfs(p+1);a[p]=2;dfs(p+1);
}

int main(){
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	scanf("%d%d%d%d",&n,&K,&m1,&m2);
	for(int i=1;i<=n;i++){
		scanf("%d",&val[1][i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&val[2][i]);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
