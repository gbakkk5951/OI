#include<cstdio>
#include<cstdlib>
#define ll long long
struct Miller_Rabin{
Miller_Rabin(){
	long long in;
	ll p[]={2,3,5,7,11,13,17,19,23};
	scanf("%lld",&in);
	long long i,j,k,a,b;
	if(in<2){
		printf("composite");
		return ;		
	}

	for(i=0;i<9;i++){
	
		j=in-1;
		do{
			if(in==p[i]){
				printf("prime");
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
				printf("composite");
				return ;
			}
		}while(1);
	}
	printf("prime");
}	
ll mul(ll a,ll b,ll m){
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
