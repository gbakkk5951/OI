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
const int M = 111;
int n,h[M][M];

ns fc1
{
	void main1()
	{
		for(int i=-2000;i<=2000;i++)
		{
			for(int j=-2000;j<=2000;j++)
			{
				if(h[1][1] * i - h[1][2] * j == 1)
				{
					printf("%d %d\n%d %d\n",h[1][1],h[1][2],j,i);
					return;
				}
			}
		}
		puts("no solution");
	}
}

int main()
{
#ifdef shorn

#else
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[1][i]);
	}
	if(n==2) return fc1::main1(),0;
	puts("no solution");
	return 0;
}

