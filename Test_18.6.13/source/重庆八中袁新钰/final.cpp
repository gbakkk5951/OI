#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define fir first
#define sec second
#define pb push_back
#define tm ndhsfjk
#define y1 cjdksl
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-') f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f) x=-x;
			return ;
		}
}
//*********************************************

int n,a[10][10];

int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	
	Read(n);
	for(int i=1;i<=n;i++)
		Read(a[1][i]);
	if(n==2){
		for(int i=-2000;i<=2000;i++)
			for(int j=-2000;j<=2000;j++)
				if(a[1][1]*j-a[1][2]*i==1){
					printf("%d %d\n%d %d\n",a[1][1],a[1][2],i,j);
					return 0;
				}
		puts("no solution");
	}else puts("no solution");
	return 0;
}
