#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ns namespace
#define lol long long
using ns std;
int n;
long double d;

int main()
{
#ifdef shorn

#else
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
#endif
	d = 0.6321;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		d = 1.0 - (i * d);
	}
	printf("%.4Lf\n",d);
	return 0;
}

