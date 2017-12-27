#include<cstdio>
int main(){}
struct _Main{
long long ans;
long long a,b,c,d;
_Main(){
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	ans=((b/2017) -((a-1)/2017))*(d-c+1)+(b-a+1-((b/2017) -((a-1)/2017)))*(d/2017-(c-1)/2017);
	printf("%lld",ans);
}	
	
	
}cdvs6445;
