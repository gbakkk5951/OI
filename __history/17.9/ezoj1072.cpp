using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
bool EndFlag;
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar())){
			if(t==EOF){
				EndFlag=true;
				return;
			}
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
	
struct _Main{
_Main(){

	int n;int i;int rem;int phi;long long ans;
	while(1){
		read(n);
		if(EndFlag)return;
		phi=n;rem=n;
		for(i=2;i*i<=rem;i++)if(rem%i==0){
			phi-=phi/i;
			do{
				rem/=i;
			}while(rem%i==0);
		}
		if(rem>1)phi-=phi/rem;
		if(n>2)
		ans=(long long)phi*n/2;
		else ans=1;
		
		printf("%lld\n",ans);
	}
	
	
	
}


}ezoj1072;	
