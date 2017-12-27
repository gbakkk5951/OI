using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>

struct _Main{
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-'){
				f=-1;
			}
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}a*=f;
		
	}
_Main(){
	long long a,b;int n;
	read(n);
	while(n--){
		read(a);read(b);
		printf("%lld\n",a*b);
	}
}

	
	
}cdvs6394;
