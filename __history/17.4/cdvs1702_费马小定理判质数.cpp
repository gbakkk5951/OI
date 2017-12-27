#include<cstdio>
#define ll long long
struct _Main{
_Main(){
	ll om;
	scanf("%lld",&om);
	if(pow(2,om-1,om)==1||om==2){
		printf("Yes");
		return;
	}printf("No");
	return;
}
ll mul(ll a,ll b,ll m){
	//return a*b%m;
	a%=m;
	b%=m;
	a= a*b-(ll)((long double)a/m*b)*m;
	if(a<0){
		return a+m;
	}
	return a;
}
ll pow(ll a,ll t,ll m){
	a%=m;
	if(t){
		ll ans=pow(a,t>>1,m);
		ans=mul(ans,ans,m);
		if(t&1){
			ans=mul(ans,a,m);
		}
		return ans;
	}return 1;
}	
	
	
}instance;int main(){}
