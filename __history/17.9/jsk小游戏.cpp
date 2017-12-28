using namespace std;
int main(){}
#include<cstdio>
const long long mod=1e9;
struct _Main{
long long ans;
long long pow[250];
long long n;
long long getans(int set){
	int cnt=0;int i,j,k;
	set<<=1;
	for(i=0,k=0;i<n-1;i++){
		if(set&(1<<(i+1)))k++;
		for(j=i+1;j<n;j++){
			if(set&(1<<j)){
				break;	
			}
			if(gcd(i+1,j+1)==1)cnt++;
		}
	}
	return (k&1)?-pow[cnt]:pow[cnt];
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

_Main(){
	int i,j,k;int s,ss;int cnt;
	scanf("%d",&n);
	for(i=1,pow[0]=1;i<=(n*(n-1))>>1;i++){
		pow[i]=pow[i-1]*2%mod;
	}
	for(i=1,cnt=0;i<n;i++){
		for(j=i+1;j<=n;j++){
			if(gcd(j,i)==1)cnt++;
		}
	}
	ans=pow[cnt];
	s=(1<<(n-1))-1;
	for(ss=s;ss;ss=(ss-1)&s){
		ans+=(i=getans(ss));
	}ans=(ans%mod+mod)%mod;
	
	printf("%lld",ans);

}


	
}jsk;
