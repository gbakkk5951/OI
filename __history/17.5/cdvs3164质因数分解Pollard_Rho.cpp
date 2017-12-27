#include<cstdio>
#include<cctype>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;
int main(){
struct _Main{
long long add;
inline long long labs(long long a){
	return a>>63^((a>>63)+a);
}
inline long long lrand(){
	long long a=rand();
	a|=(long long)rand()<<15LL;
	a|=(long long)rand()<<30LL;
	a|=(long long)rand()<<45LL;
	return a;
}		
unsigned long long read(){ 
	unsigned long long a;
	char t;
	while( ! isdigit ( t= getchar()));
	a=t-'0';
	while( isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
	return a;
}
inline long long mul ( long long a, long long b , long long mod ){
	return (a*b-(long long)((long double)a/mod*b)*mod)%mod;
}
long long fast_power(long long a,long long b,long long mod){
	long long ans=1,m=a;
	for(;b;b>>=1){
		if(b&1){
			ans=mul(m,ans,mod);
		}
		m=mul(m,m,mod);
	}
	return ans;
}
inline long long f(long long a,long long mod){
	return (a*a%mod+add)%mod;
}
bool miller(long long a){
	long long i,j,k,l;
	long long prime[]={2,3,5,7,11,13,17,19,23,29};
	for(i=0;i<9 && a> prime[i];i++){
		k=a-1;
		while(1){
			j=fast_power(prime[i],k,a);
			if(j==a-1 || j==-1){
				break;
			}else if(j==1){
				if(k%2){
					break;
				}
				k/=2;
			}else{
				return false;
			} 
		}
	}
	return true;
}
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
int cnt;
void pollard(long long v){
	if(v==1){
		return;
	}
	if(miller(v)){
		cnt++;
		return;
	}
	long long t=lrand();
	long long x=f(t%v,v),y=f(t%v,v);
	y=f(y,v);
	while(1){
		t=gcd(labs(x-y),v);
		if(t!=1&&t!=v){
			break;
		}
		x=f(x,v);
		y=f(f(y,v),v);
		if(x==y){
			x=lrand()%v;
			y=lrand()%v;
		}
	}
	pollard(v/t);
	pollard(t);
}

_Main(){
	int t;
	add=1;
	t=read();
	while(t--){
		cnt=0;
		pollard(read());
		printf("%d\n",cnt);
	}
}
}cdvs3164;
} 
