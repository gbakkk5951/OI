#include<cstdio>
#include<cmath>

using namespace std;

long long bn=1,n[20];
long long a[20];
int  nu;
long long qa,qb;
long long mn;



long long ax;


long long exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0)
	{
	x=1;y=0;
	return a;
	}int ans=exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return ans;
	
}
int main(){

	int i,j,k,l;
	scanf("%d%lld%lld",&nu,&qa,&qb);
	for(i=0;i<nu;i++)
	{scanf("%lld%lld",&n[i],&a[i]);
	bn*=n[i];
	}
	for(i=0;i<nu;i++){
		long long tx,ty;
		exgcd(bn/n[i],n[i],tx,ty);
		if(tx<0)
		tx+=n[i];
		ax=(ax+(a[i]*(bn/n[i])*tx))%bn;
	}
	if(ax<qa)
	{
		ax+=((int)(qa-ax)/bn)*bn;
		if(ax<qa)
		ax+=bn;
	}
	if(ax>qb)
	printf("0\n0");
	else{
		printf("%lld\n%lld",1+(qb-ax)/bn,ax);
		
		
	}
	
	
}
