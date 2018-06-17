#include<stdio.h>
double f[]={0.6321,0.3679,0.2642,0.2073,0.1709,0.1455,0.1268,0.1124,0.1009,0.0916,0.0839,0.0774,0.0718,0.0669,0.0627,0.0590,0.0557,0.0528,0.0502,0.0471,0.0586};
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n<=20)
		printf("%.4lf",f[n]);
	else
		printf("0.0000");
	return 0;
}

