#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
vector<int> queue;

int n;
int ans1,ans2;
int data[20];
int dp[25];
int main(){
	int i=0,j,k;
	while(~scanf("%d",&data[i]))
	i++;
	n=i;
//	queue.resize(n); 
	dp[0]=30011;
	int *po;
	for(i=0;i<n;i++){
		po=lower_bound(dp,dp+n,data[i],greater<int>());
		if(*po>=data[i])
		{
		po++;	
		}
		*po=max(*po,data[i]);
	}
	for(i=n;i;i--){
		if(dp[i])
		{
			printf("%d\n",i);
			break;
		}
	}
	vector<int>::iterator it;
	for(i=0;i<n;i++){
		it=lower_bound(queue.begin() ,queue.end() ,data[i]);
		if(it==queue.end()){
			queue.push_back(data[i]); 
		}else{
			*it=data[i];	
		}
	}
	printf("%d",queue.size() );
}
