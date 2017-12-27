using namespace std;
int main(){}
#include<cstdio>
namespace Protector{
struct _Main{
_Main(){
	int I,i,ans;
	long long n,m;
	long long val[21];
	long long sum;
	ans=0;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld",&val[i]);
	}
	for(I=0;I<(1<<n);I++){
		for(i=0,sum=0;i<n;i++){
			if(I&(1<<i)){
				sum+=val[i];
			}
		}
		if(sum>=m)continue;
		for(i=0;i<n;i++){
			if(!(I&(1<<i))){
				if(val[i]+sum<m){
					break;
				}
			}
		}
		if(i==n){
			ans++;
		}
	}
	
	printf("%d",ans);
	
	
}	
	
	
}lock;



}


//I从0开始循环，交之前可以试着构造反例
//可以在源代码开头打上/* 原 理 */ 
