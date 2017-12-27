using namespace std;
int main(){}
#include<cstdio> 
#include<cctype>
#include<set>
#include<cmath>
struct _Main{
long long exgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;y=0;return a;
	}
	long long ret=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return ret;
}
bool EndFlag;
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar())){
			if(t==EOF){
				EndFlag=true;
				return ;
			}
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
long long x,y,m,n,l,ans,t1,t2,a,b,g;
_Main(){
	
	while(1){
		
		
		read(a);
		if(EndFlag)break;
		read(b);read(m);read(n);read(l);
		
		y=((b-a)%l+l)%l;
		x=((m-n)%l+l)%l;		
		if((b-a)%(g=exgcd(x,l,t1,t2))){
			printf("Impossible\n");
		}else{
			ans=(t1*y%l+l)%l;
			printf("%lld\n",ans/g);
		}
	}
	
	
}	
	
	
	
}ezoj1089;
