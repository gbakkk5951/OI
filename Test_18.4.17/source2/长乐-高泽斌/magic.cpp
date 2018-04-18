#include<cstdio>
#include<algorithm>
using namespace std;

int n,pyz;
int a[10000];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	 
	scanf("%d%d",&n,&pyz);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=n;i>1;--i)
	for(int j=1;j<i;++j) a[j]=(a[j]+a[j+1])%pyz;
	printf("%d",a[1]%pyz);
}
