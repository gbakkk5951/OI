using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
struct _Main{
bool end;
template<typename Type1>
void read(Type1 &a){
	char t;
	while(!isdigit(t=getchar())){
		if(t==EOF){
			end=true;
			return;
		}
	}
	a=t-'0';
	while(isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
	
}
long long calc(long long a,long long b,long long c,long long n){
	long long ans=0;
	long long temp[2];
	while(n>0){
		ans+=(a/c)*n*(n-1)/2+b/c*n;
		temp[0]=a;
		a=c;
		temp[1]=b;
		b=((temp[0]*n+b)%c);
		n=((temp[0]%c)*n+(temp[1]%c))/c;
		c=temp[0]%c;
	}


	
	
	return ans;
}


_Main(){
	int i;
	long long x,y,z;
	while(1){
		long long ans=0;
		read(x);read(y);read(z);
		if(end) break;
		for(i=0;i<32;i++){
			ans|=( (calc(z,x,1LL<<i,(y-x)/z+1)&1)<<i);	
		}
		printf("%lld\n",ans);
	}
}
	
	
	
	
	
}poj3495;
