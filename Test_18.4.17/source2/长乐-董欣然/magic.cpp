#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
using namespace std;
int n,K,b[400005];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d%d",&n,&K);
	for (int i=1; i<=n; ++i){
		scanf("%d",&b[i]);
		//work();
		for (int j=i-1; j; --j)	b[j]=(b[j]+b[j+1])%K;
	}
	printf("%d",b[1]);
}
