using namespace std;
int main(){}
#include<cstdio>

struct dpType{
	int val;
	int root;
	dpType *l,*r;
	int friend operator * (const dpType &a,const dpType &b){
		return a.val*b.val;
	}
	dpType(){
		val=1;
	}
}dp[31][31],ans;
int w[37];
struct _Main{
int n;	
int lst;
_Main(){
	int i;int j;int k;int l;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",w+i);
		dp[i][i].val=w[i];
		dp[i][i].root=i;
		if(dp[i][i].val>ans.val){
			ans=dp[i][i];
		}		
	}
	for(l=2;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j=i+l-1;
				for(k=i;k<=j;k++){
					if(dp[i][k-1]*dp[k+1][j]+w[k] > dp[i][j].val){
						dp[i][j].val=dp[i][k-1]*dp[k+1][j]+w[k];
						dp[i][j].l=&dp[i][k-1];
						dp[i][j].r=&dp[k+1][j];
						dp[i][j].root=k;
						if(dp[i][j].val>ans.val){
							ans=dp[i][j];
						}
					}
				}
		}
	}
	printf("%d\n",ans.val);
	dfs(&ans);
	printf("%d",lst);
}	
void dfs(dpType *nd){
	if(nd == 0 || nd->root == 0) return;
	if(lst) printf("%d ",lst);
	lst=nd->root;
	dfs(nd->l);
	dfs(nd->r);
}
}jsk;
