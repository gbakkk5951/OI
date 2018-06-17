#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
double a=1,ans=0; int n;
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d",&n);
	for(int i=n+1;i<=100000;i++){
		a=-a*(1.0/i);
		ans=ans+a;
	}
	printf("%.4lf\n",fabs(ans));
	return 0;
}
