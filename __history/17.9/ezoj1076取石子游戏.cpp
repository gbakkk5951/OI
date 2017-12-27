using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
struct _Main{
	
int gcd(int a,int b){
	int t;
	while(t=a%b){
		a=b;b=t;
	}return b;
}
int T,n,a,b,ans,g;	
_Main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&a,&b);
		g=gcd(a,b);
		ans=n/g;
		if(ans & 1){
			printf("huaye\n");
		}else{
			printf("suantou\n");
		}
	}
}	
	
	
	
}ezoj1076;

