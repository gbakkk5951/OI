#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k,ans,ms,me,s[1005],e[1005],p[1005];
void dfs(int i,int now){//printf("!%d %d",i,now);
	if(i==n+1){ans=max(ans,now);return;}
	int ns=0,ne=0;
	for(int j=i-1;j>=1&&j>i-k;--j){
		if(p[j]==1)ns++;
		if(p[j]==2)ne++;
	}
	if(ns<k-me){p[i]=1;dfs(i+1,now+s[i]);}
	if(ne<k-ms){p[i]=2;dfs(i+1,now+e[i]);}
}
int main(){
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	scanf("%d%d%d%d",&n,&k,&ms,&me);
	for(int i=1;i<=n;++i)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&e[i]);
	dfs(0,0);
	printf("%d",ans);
	return 0;
}
