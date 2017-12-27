using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
struct _Main{
int n;
long long inline power (int a){
	return (long long)a*a;
}
_Main(){
	int x=0;int y=0;int l=0,r=0,b=0,t=0;int i;
	scanf("%d",&n);
	scanf("%d%d",&x,&y);
	l=r=x;b=t=y;
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		l=min(l,x);r=max(r,x);
		b=min(b,y);t=max(t,y);
	}
	printf("%lld",power(max(r-l,t-b)));
}	
	
	
}cdvs5840;
