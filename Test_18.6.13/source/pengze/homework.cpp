#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define si scanf
#define so printf
#define N 
#define M 
#define INF  
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0; 
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp=='-')	mns=1;
		if(tmp==EOF)	return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	if(mns)	r=-r;
	return 1;
} 
int n;
long double f;
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	rd(n);
	f=1-exp(-1);
	for(int i=1;i<=n;++i)
		f=1-i*f;
	so("%.4Lf\n",f);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
