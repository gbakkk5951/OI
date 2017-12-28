int main(){}
using namespace std;
#include<cstdio>
#include<cstring>
#include<cctype>
#include<bitset>
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}	
	}
	
struct _Main{
bitset<5000010>np;
int prime[348600];
int mindiv[5000010];
int cnt;
void getprime(){
	int i,j,t;
	for(i=2;i<=5000000;i++){
		if(!np[i]){
			prime[cnt++]=i;
			mindiv[i]=i;
		}
		for(j=0;j<cnt && (t=prime[j]*i)<=5000000;j++){
			np[t]=1;
			mindiv[t]=prime[j];
			if(i%prime[j]==0){
				break;
			}
		}
	}
}
int fenjie(int num){
	int ans=0;
	while(num!=1){
		ans+=mindiv[num];
		num/=mindiv[num];
	}return ans;
}
_Main(){
	getprime();
	int n;
	while(1){
		read(n);
		if(n==0)break;
		printf("%d\n",fenjie(n));
	}
}	
	
}ezoj;
