using namespace std;
int main(){}
#include<cstdio>

struct _Main{
long long n,kth;	
long long prime[10];int pcnt;
long long list[300];int lcnt;
int pn[300];
void fenjie(long long num){
	int i;int rem=num;
	for(i=2;i*i<=num;i++){
		if(rem%i==0){
			prime[pcnt++]=i;
			do{
				rem/=i;
			}while(rem%i==0);
		}
	}
	if(rem>1)prime[pcnt++]=rem;
}
void combine(){
	int s=(1<<pcnt)-1;int ss;int j;int mul;int tpn;
	for(ss=s;ss;ss=(ss-1)&s){
		for(j=0,mul=1,tpn=0;j<pcnt;j++)if(ss&(1<<j)){
			mul*=prime[j];tpn++;
		}
		list[lcnt]=mul;
		pn[lcnt]=tpn;
		lcnt++;
	}
}
long long getnum(long long mx){
	long long ans=mx;
	int i;
	for(i=0;i<lcnt;i++){
		if(pn[i]&1){
			ans-=mx/list[i];
		}else{
			ans+=mx/list[i];
		}
	}
	return ans;
}

_Main(){
	scanf("%lld%lld",&n,&kth);
	fenjie(n);
	combine();long long l,r;long long mid;
	for(l=1LL,r=(1LL<<60LL);l<r;){
		mid=(l+r)>>1LL;
		if(getnum(mid)<kth){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	printf("%lld",l);
	
}


	
}jsk;
