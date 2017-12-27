/* ‘≠ ¿Ì */ 

using namespace std;
int main(){}
#include<cstdio>
namespace Protector{

typedef long long lld;
const lld mod = 9999991LL;

struct _Main{


lld fastpower(lld base,lld pow){
	lld ans=1;
	while(pow){
		if(pow&1){
			(ans*=base)%=mod;
		}
		(base*=base)%=mod;
		pow>>=1;
	}
	return ans;
}
lld fact(lld goal){
	lld ans=1;
	lld i;
	for(i=2;i<=goal;i++){
		(ans*=i)%=mod;
	}
	return ans;
}
_Main(){
	lld n;
	scanf("%lld",&n);
	printf("%lld",(fact(n-1)*fastpower(n,n-2))%mod);
}	
	
	
}bzoj1430;

}
