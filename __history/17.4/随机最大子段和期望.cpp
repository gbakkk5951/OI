#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<algorithm>
using namespace std;
struct _Main{
int num;
_Main(){
	srand(time(0));
	int i,j;
	double ans=0;
	for(j=1;j<=10000;j*=10){
		num=j;
		for(i=0;i<=1000;i++){
			ans+=getans();	
		}
		printf("%d:%f\n",j,(double)ans/1000);
		ans=0;
	}	
}
double getans(){
	double ans=0,now=0;
	int i;
	for(i=0;i<num;i++){
		now+=r();
		if(now<0)now=0;
		ans=max(ans,now);
	}
	return ans;
	
}
double r(){
	long long a=0;
	a|=(unsigned long long)rand();
	a|=(unsigned long long)rand()<<15;
	a|=(unsigned long long)rand()<<30;
	a|=(unsigned long long)rand()<<45;
	a|=(unsigned long long)rand()<<60;
	a%=1000000000000000000;
	return (double)a/1000000000000000000;
}

}instance;int main(){}
