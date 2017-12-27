using namespace std;
int main(){}
#include<cstdio>
namespace Protector{
	
struct _Main{
long long n,m,k,x;

long long fastpower(long long base,long long pow){
	long long ans=1;
	while(pow){
		if(pow&1){
			ans=ans*base%n;
		}
		base=base*base%n;
		pow>>=1;
	}
	return ans;
}	
_Main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	long long ans=(m*fastpower(10,k)%n+x)%n;	
	printf("%lld",ans);
}	
	
	
}ezoj1138;
	
	
	
}
