#include<cstdio>
#include<cctype>
void exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
} 
 
int main(){
	
	long long a,b,x,y;
	scanf("%lld%lld",&a,&b);
	exgcd(a,b,x,y);
	x%=b;x+=b;x%=b;
	printf("%lld\n",x);
}
