#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[6][6];
bool check(int a,int b,int c,int d)
{
	int res=1;
	if(!a&&!c) return 0;
	if(!a)
	{
		swap(a,c); swap(b,d);
		res=-1;
	}
	return res*(a*d-b*c)==1;
}
int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	scanf("%d",&n);
	if(n==2)
	{
		int a,b; scanf("%d%d",&a,&b);
		for(int c=-2000;c<=2000;++c)
		for(int d=-2000;d<=2000;++d)
		if(check(a,b,c,d))
		{
			printf("%d %d\n%d %d\n",a,b,c,d);
			return 0;
		}
	}
	puts("no solution");
	return 0;
}
