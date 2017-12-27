#include<cstdio>
using namespace std;
struct _Main{
int n;
unsigned long long catalan[20];
_Main(){
	int i;
	scanf("%d",&n);
	catalan[1]=1;
	for(i=2;i<=n;i++){
		catalan[i]=catalan[i-1]*(4*i-2)/(i+1);
		printf("%lld ",catalan[i]);
	}
	printf("%llu",catalan[n]);
}
	
	
	
	
	
	
	
	
}instance;int main(){}
