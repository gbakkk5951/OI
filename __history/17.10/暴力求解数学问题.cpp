using namespace std;
int main(){}
#include<cstdio>
struct _Main{

	


__int128 fastpower(__int128 pow,__int128 mod){
	static __int128 ans;static __int128 base;
	ans=1;base=2;
	while(pow){
		if(pow&1){
			ans=ans*base%mod;
		}
		if(pow>>=1)
		base=base*base%mod;
	}
	return ans;
}
char stk[50];int idx;
void print(__int128 num){
	while(num){
		stk[idx++]=num%10+'0';
		num/=10;
	}
	while(idx){
		putchar(stk[--idx]);
	}
}
_Main(){
	__int128 i,j;
	for(i=2;i<=5000;i++){
		if(fastpower(i-1,i*i)==1)printf("find "),print(i),printf("\n");
	}
	for(j=2225e8;j<=1e16;j+=1e8){
		printf("----"),print(j);printf("----\n");
		for(i=1+j;i<=j+1e8;i+=2)if(i%3 && i%5 && i%7 && i%11){
			if(fastpower(i-1,i*i)==1)printf("find "),print(i),printf("\n");
		}
	}
}

}problem;
