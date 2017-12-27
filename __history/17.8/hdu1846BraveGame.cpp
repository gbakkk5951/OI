using namespace std;
int main(){}
#include <cstdio>
struct _Main{
int n,m;
_Main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n%(m+1)){
			printf("first\n");
		}else{
			printf("second\n");
		}
	}
}		


	
}hdu1846;
