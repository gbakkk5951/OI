int main(){}
#include<cstdio>
#define mod 10007
struct _Main{
	
int fastpower(int base,int pow){
	int ret=1;base%=mod;
	while(pow){
		if(pow&1){
			ret=ret*base%mod;
		}
		base=base*base%mod;
		pow>>=1;
	}return ret;
}
int rev[505];
int getcombine(int chose,int from){
	int i;int ret=1;
	if(chose>from/2){
		chose=from-chose;
	}
	for(i=from-chose+1;i<=from;i++){
		ret=ret*i%mod;
	}
	rev[1]=1;
	for(i=2;i<=chose;i++){
		rev[i]=rev[mod%i]*(mod-mod/i)%mod;
		ret=ret*rev[i]%mod;
	}
	return ret;
}




_Main(){
	int p,q,k,a,b;
	int ans=1;
	scanf("%d%d%d%d%d",&p,&q,&k,&a,&b);
	ans=fastpower(p,a)*fastpower(q,b)%mod*getcombine(a,k)%mod;
	printf("%d",ans);
}	
	
	
}jsk;
