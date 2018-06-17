#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define For(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int n;
long double f[10005];

int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	
	scanf("%d",&n);
	f[0]=1-(long double)1/expl(1);
	For(i,1,n) f[i]=1-i*f[i-1];
	printf("%.4Lf\n",f[n]);
	return 0;
}
