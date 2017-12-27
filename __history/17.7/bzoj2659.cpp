using namespace std;
int main(){}
#include<cstdio>
struct _Main{
	typedef long long LL;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
LL p,q,ans;	
	_Main(){
		scanf("%lld%lld",&p,&q);
		ans=(((p-1)/2)*((q-1)/2) )+gcd((p-1)/2,(q-1)/2) -1;
		printf("%lld",ans);
	}
}bzoj2659;
