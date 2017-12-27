#include<cstdio>
#include<algorithm>
using namespace std;
int main(){}
const char Lost[]="What a pity!",
			Victory[]="Wonderful!";
struct _Main{
_Main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n==0 && m==0)return;
		if(n&m&1){
			printf("%s\n",Lost);
		}else{
			printf("%s\n",Victory);
		}
	}
}	
	
}hdu2147; 
