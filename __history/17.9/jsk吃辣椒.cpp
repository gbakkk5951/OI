using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>

const long long mod=1000000007;
struct _Main{
long long rev[100005];
void getrev(int mx){
	rev[0]=rev[1]=1;
	int i;
	for(i=2;i<=mx;i++){
		rev[i]=rev[mod%i]*(mod-mod/i)%mod;
	}
}

template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}	
long long arr[100005];
long long combine;
long long ans;
int num,kind;
_Main(){
	read(num);read(kind);
	int i,j;
	for(i=0;i<num;i++){
		read(arr[i]);
	}sort(arr,arr+num);
	getrev(num-1);
	combine=rev[kind-1];
	for(i=kind-1;i<num;i++){
		combine=combine*i%mod;
		combine=combine*rev[i-(kind-1)]%mod;
		ans=(ans+combine*arr[i])%mod;
	}printf("%lld",ans);
}

	
	
	
}jsk; 
