using namespace std;
int main(){}
#include<cstdio>
struct _Main{
long long ans,n;	
_Main(){
	long long a,b;
	scanf("%lld",&n);
	for(a=1;a<=n;a=b){
		b=n/(n/a)+1;
		ans+=(b-a)*(n/a);
	}
	printf("%lld",ans);
}
	
}ezoj1187;
