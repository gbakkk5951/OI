#include<cstdio>
#include<cstring>
struct _Main{
long long mem[40][60][2];
long long n,p,k,r;		
long long combine(long long chose,long long from,int iter,int flag=0){
	if(from==1){
		if(chose<=1){
			return 1;
		}
	}
	if(chose>from){
		return 0;
	}
	if(chose==from){
		return 1;
	}
	if(mem[iter][chose][flag]){
		return mem[iter][chose][flag]-1;
	}
	long long i,j;
	long long ans=0,t;
	for(i=0;i<k;i++){
		j=(chose+k-i)%k;
		t=combine(i,from>>1LL,iter+1);
		ans+=t*combine(j,from>>1LL,iter+1)%p;
		ans%=p;
	}
	if(from&1){
		ans+=combine(chose-1LL>=0LL?chose-1LL:k-1LL,from-1LL,iter,1);
		ans%=p;
	}
	mem[iter][chose][flag]=ans+1;
	printf("c[%lld][%lld][%d]=%lld\n",chose,from,flag,ans);
	return ans;
}	
_Main(){
	freopen("data.in","r",stdin);
	freopen("gba.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&p,&k,&r);
	long long ans=combine(r,n,0);
	printf("%lld\n",ans);
}	
}bzoj4870;int main(){}
