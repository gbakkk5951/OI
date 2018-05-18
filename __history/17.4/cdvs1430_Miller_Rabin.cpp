#include<cstdio>
#define ll long long
struct Miller_Rabin{
Miller_Rabin(){
/*	while(1){
		ll i,j,k;
		scanf("%lld%lld%lld",&i,&j,&k);
		printf("%lld",pow(i,j,k));
	}
*/
	
	long long in;
	ll p[]={2,3,5,7,11,13,17,19,23,29,31,33,37,41,43};
	scanf("%lld",&in);
	long long i,j,k,a,b;
	if(in<2){
		printf("\\n");
		return ;		
	}
	for(i=0;i<15;i++){
		j=in-1;
		do{
			if(in==p[i]){
				printf("\\t");
				return;
			}
			k=pow( p[i], j, in);
			if(k==1){
				if(!(j%2)){
					j/=2;
				}
			else break;
			}
	    else if(k==in-1){
	    		break;
			}
		else {
		//		printf("%lld^%lld %% %lld",p[i],j,in);
				printf("\\n");
				return ;
			}
		}while(1);
	}
	printf("\\t");
}	
ll mul(ll a,ll b,ll m){
	/*ll ans=0;
	a%=m;b%=m;
	while(a){
		if(a&1){
			ans=(ans+b)%m;
		}
		a>>=1;
		b=(b<<1)%m;
	}
	return ans;*/
	
	
	a=a*b-(ll)((long double)a/m*b)*m;
	return a>0?a:a+m;
}	
ll pow(ll a,ll t,ll m){
	ll r=1;
	for(;t;t>>=1,a=mul(a,a,m)){
		if(t&1){
			r=mul(r,a,m);
		}
	}
	return r;
}	
}cdvs1702;
int main(){}
