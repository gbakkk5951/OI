using namespace std;
int main(){}
#include<cstdio>
struct _Main{
int mod,r;
void exgcd(int a,int b,int &x,int &y)	{
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
_Main(){
	int a,b,x,y;
	scanf("%d%d",&a,&b);
	exgcd(a,b,x,y);
	x%=b;
	if(x<0)x+=b;
	printf("%d",x);
}	
	
	
	
	
	
}ezoj1136;
