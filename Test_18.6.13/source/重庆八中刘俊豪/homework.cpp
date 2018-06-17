#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<set>
#include<map>
#include<cmath>
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
}
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int n;
	Read(n);
	long double now=1-exp(-1);
	for(int i=1;i<=n;i++)
		now=1-i*now;
	
	printf("%.4f\n",double(now));
}
