#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
int main(){}
int n;
struct _Main{
	
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}


int arr[64];
bool vis[64];
_Main(){
	int i,j,k;
	int sum;
	while(1){
		read(n);sum=0;
		if(n==0)return;
		for(i=0;i<n;i++){
			read(arr[i]);
			sum+=arr[i];
		}
		sort(arr,arr+n,greater<int>());
		if(arr[0]==arr[n-1]){
			printf("%d\n",arr[0]);
			continue;
		}
		memset(vis,0,sizeof(vis));
		for(i=arr[0];i<sum;i++) if(sum%i==0){
			
			if(dfs(i)){
				printf("%d\n",i);
				break;
			}
		}
		if(i==sum){
			printf("%d\n",sum);
		}
	}
	
}
bool dfs(int tot,int idx=0,int left=n){
	int i,j,k;
	if(idx==0){
		for(i=0;i<n;i++){
			if(!vis[i]){
				vis[i]=true;
				if(dfs(tot,tot-arr[i],i)){
					return true;
				}else{
					vis[i]=false;
					return false;
				}
			}
		}
		if(i==n)return true;
	}else{
		int lst=-1;
		for(i=left+1;i<n;i++) if(!vis[i] && arr[i]!=lst && arr[i]<=idx){
			vis[i]=true;
			if(dfs(tot,idx-arr[i],i)){
				return true;
			}
			vis[i]=false;
			lst=arr[i];
		}
		return false;
	}
}
	
	
	
	
}stick;
 
