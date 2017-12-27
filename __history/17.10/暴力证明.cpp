#include<cstdio>

__int128 p,p2;


__int128 fastpower(__int128 pow,__int128 mod){
	__int128 base=2,ans=1;
	while(pow){
		if(pow&1){
			ans=(ans*base)%mod;
		}
		base=base*base%mod;
		pow>>=1;
	}
	return ans;
	
}
void print(__int128 a){
	if(a){
		print(a/10);
		putchar('0'+a%10);
	}
}
int main(){
	__int128 i;
	
	long long num=1;long long mod=3511*3511;
	for(i=1;i<=3510;i++){
		num<<=1;num%=mod;
	}printf("%lld",num);
	
	for(i=2;i<1e16;i++){
		if((i%(__int128)1e8)==0)printf("----"),print(i),printf("----\n");
		if(fastpower(i-1,i*i)==1){
			printf("find ");
			print(i);printf("\n");
		}
	}
	
	
}
