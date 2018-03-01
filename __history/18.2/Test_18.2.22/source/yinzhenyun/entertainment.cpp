#include<stdio.h>
#include<algorithm>
using namespace std;
int s[1100],e[1100];
int n,k,ms,me;
int mn,mx;
int ans=0;
int sum=0;
int is[1100];
void dfs(int u){
	if(u==n+1){
		int ck=0;
		if(k>n)sum=max(ans,sum);
		else{
			int ok=true;
			for(int i=1;i<=k;i++){
				ck+=is[i];
			}	
			if(ck>mx||ck<mn)ok=false;
			for(int i=1;i<=n-k;i++){
				ck-=is[i];
				ck+=is[i+k];
				if(ck>mx||ck<mn)ok=false;
			}
			if(ok)sum=max(sum,ans);
		}
		return;
	}
	ans+=s[u];
	is[u]=true;
	dfs(u+1);
	is[u]=false;
	ans-=s[u];
	ans+=e[u];
	dfs(u+1);
	ans-=e[u];
}
int main(){
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	scanf("%d%d%d%d",&n,&k,&ms,&me);
	mn=ms;
	mx=k-me;
	if(ms+me>k){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",s[i]);
	for(int i=1;i<=n;i++)scanf("%d",e[i]);
	dfs(1);
	printf("%d",sum);
	return 0;
}
