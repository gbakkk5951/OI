int main(){}
using namespace std;
#include<cstdio>
#include<bitset>
#include<algorithm>
bitset<4500100>v;
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}	
struct _Main{
long long arr[10005];
_Main(){
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld",arr+i);
		arr[i]=gcd(arr[i],m);
	}sort(arr,arr+n);
	n=unique(arr,arr+n)-arr;
	for(i=0;i<n-1;i++)if(arr[i]!=-1){
		for(j=i+1;j<n;j++){
			if(arr[j]%arr[i]==0){
				arr[j]=-1;
			}
		}
	}
	for(i=0;i<n;i++)if(arr[i]==-1){
		swap(arr[i],arr[n-1]);
		i--;n--;
	}sort(arr,arr+n);
	for(i=0;i<n;i++){
		printf("arr[%d]=%lld\n",i,arr[i]);
		for(j=arr[i];j<m;j+=arr[i]){
			v[j]=1;
		}
	}
	long long ans=0;
	for(i=1;i<m;i++)if(v[i]){
		ans+=i;
	}
	printf("%lld",ans);
}	
}bruteforce;
