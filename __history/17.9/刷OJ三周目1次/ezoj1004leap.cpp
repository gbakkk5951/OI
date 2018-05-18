#include<cstdio>
int main(){}
struct _Main{

int getfactor(long long n,int mod){
	int ret=1; int i;
	if(n==mod-1){
		return mod-1;
	}else if(n>=mod){
		return 0;
	}
	for(i=3;i<=n;i++){//终止于N 故不能直接右跳一格 
		ret=(long long)ret*i%mod;
	}
	return ret;
}	
_Main(){
	long long n;int p;
	scanf("%lld%d",&n,&p);
	printf("%d",getfactor(n-1,p));
}
	
	
	
	
}ezoj1004;
