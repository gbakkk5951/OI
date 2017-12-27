using namespace std;
int main(){}
#include<cstdio>
#define mod 1000000007
struct _Main{
int n,m;
long long rev[100005];

void getrev(int mx){
	rev[0]=rev[1]=1;
	int i;
	for(i=2;i<=mx;i++){
		rev[i]=rev[mod%i]*(mod-mod/i)%mod;
	}
}
long long getcombine(int chose,int from){
	if(chose>from-chose){
		chose=from-chose;
	}
	getrev(from-chose);
	int i;long long ret=1;
	for(i=from-chose+1;i<=from;i++){
		ret=ret*i%mod;
	}
	for(i=1;i<=chose;i++){
		ret=ret*rev[i]%mod;
	}
	return ret;
}

_Main(){
	scanf("%d%d",&n,&m);n--;m--;
	long long ans=getcombine(n,n+m);
	printf("%lld",ans);
}



	
}jsk;
