using namespace std;
#include<cstdio>
#include<cctype>
#include<algorithm>
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
int main(){
	long long i,j,k;
	long long a1,a2;
	long long n,m;
	while(1){
		a1=a2=0;
		read(n);read(m);
		for(i=1;i<=n-1;i++){
			for(j=1;j<=m-1;j++){
				if(gcd(i,j)==1){
					a1+=(n-i)*(m-j);
					a2+=max(n-2*i,0LL)*max(m-2*j,0LL);
				}
			}
		}
		
		
		
		printf("ans = ( %lld - %lld )¡Á2 + %lld = %lld\n",a1,a2,m+n,(a1-a2)*2+m+n);
	}
	
	
	
	
	
}
