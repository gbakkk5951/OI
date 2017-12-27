using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<algorithm>

struct _Main{
int n,m;

int dp[328400];
int arr[105];
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
	for(i=1;i<n;i++){
		for(j=0;j<=mx;j++)if(dp[j]<100000){
			for(k=1,tmp=arr[i]+j;k<arr[i+1];k++,tmp+=arr[i]){
				dp[tmp]=min(dp[tmp],dp[j]+k);
			}
		}
		mx+=(arr[i+1]-1)*arr[i];
		mx=min(mx,m);
	}

	for(i=0;i<=mx;i++)if(dp[i]<100000 && (m-i)%arr[n]==0){
		
		ans=min(ans,dp[i]+(m-i)/arr[n]);
	}
	if(ans>m){
		printf("-1");
	}else{
		printf("%d",ans);
	}
}

	
	
	
}jsk;
