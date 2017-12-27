#include<cstdio>
using namespace std;
struct _Main{
int n;
unsigned long long catalan[20];
_Main(){
	int i;
	scanf("%d",&n);
	catalan[0]=1;
	for(i=1;i<=n;i++){
		catalan[i]=catalan[i-1]*(4*i-2)/(i+1);
	}
	printf("%llu",catalan[n]);
}
}cat;
int main(){} 
