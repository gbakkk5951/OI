#include<cstdio>
using namespace std;
struct _main{
long long x,y;long long t;

long long exgcd(long long a,long long b,bool flag=true){
	if(!b){
		x=1;y=0;
		return 0;
	}exgcd(b,a%b,false);
	t=x;x=y;y=t-a/b*y;
	if(flag){
		t=x;
		x=0,y=0;
		if(t<0)t+=b;
		return t;
	}return 0;
}

_main(){
	long long i1,i2,i3,i4;
	long long ans;
	int cnt=0;
	long long mn=23*28*33;
	while(~scanf("%lld%lld%lld%lld",&i1,&i2,&i3,&i4)){
		if(!(i1^i2^i3^i4)&&i1==-1){return;
		}
		cnt++;
		ans=0;
		ans=(ans+i1*mn/23*exgcd(mn/23,23))%mn;
		ans=(ans+i2*mn/28*exgcd(mn/28,28))%mn;
		ans=(ans+i3*mn/33*exgcd(mn/33,33))%mn;
		while(ans<=i4)ans+=mn;
		printf("Case %d: the next triple peak occurs in %lld days.\n",cnt,ans-i4);
	}
}

}instance;int main(){}
