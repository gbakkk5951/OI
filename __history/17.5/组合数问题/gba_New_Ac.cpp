#include<cstdio>
#include<cstring>
using namespace std;
struct _Main{
long long ans[60],temp[60],ntemp[60];

void fast_power(long long n){
	long long i,j;
	n--;
	while(n){
		if(n&1){
			memcpy(ntemp,ans,sizeof(ans));
			memset(ans,0,sizeof(ans));
			for(i=0;i<k;i++){
				for(j=0;j<k;j++){
					ans[(i+j)%k]=(ans[(i+j)%k]+ntemp[i]*temp[j]%p)%p;
				}
			}
		}
		memset(ntemp,0,sizeof(ntemp));
		for(i=0;i<k;i++){
			for(j=0;j<k;j++){
				ntemp[(i+j)%k]+=temp[i]*temp[j];
				ntemp[(i+j)%k]%=p;
			}
		}
		memcpy(temp,ntemp,sizeof(ntemp));
		n>>=1;
		
	}
}	
	
	
long long n,p,k,r;
_Main(){
	scanf("%lld%lld%lld%lld",&n,&p,&k,&r);
	ans[0]++;temp[0]++;
	ans[1%k]++;temp[1%k]++;
	fast_power(n*k);
	printf("%lld\n",ans[r]);
}	
	
	
	
	
	
	
	
	
	
}bzoj4870;int main(){}
