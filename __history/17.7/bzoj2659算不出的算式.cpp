using namespace std;
int main(){}
#include<cstdio>

struct _Main{
	
_Main(){
	long long p,q;
	scanf("%lld%lld",&p,&q);
	if(p!=q){
		printf("%lld",(p-1)*(q-1)>>2);
	}else{
		printf("%lld",(p-1)*(p+1)>>2);
	}
}


}bzoj2659;
