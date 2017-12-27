using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<algorithm>

struct _Main{
int n,m;

int dp[328400];
int arr[100005];
int ans;
_Main(){
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	int i;int mx=0;int j,k,tmp;
	scanf("%d%d",&n,&m);ans=m+100;
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}sort(arr+1,arr+n+1);
	n=unique(arr+1,arr+n+1)-arr-1;
	
	for(i=1,mx=0;i<n;i++){
		mx+=arr[i]*(arr[i+1]-1);
	}mx=min(mx,m);
	for(i=1;i<n;i++){
		for(j=arr[i];j<=mx;j++){
			dp[j]=min(dp[j],dp[j-arr[i]]+1);
		}
	}
	for(i=0;i<=mx;i++)if(dp[i]<100000 && ((m-i)%arr[n]==0)){
		ans=min(ans,dp[i]+(m-i)/arr[n]);
	}
	if(ans>m){
		printf("-1");
	}else{
		printf("%d\n",ans);
	}
}

}jsk;
