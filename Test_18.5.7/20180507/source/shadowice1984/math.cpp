#include<cstdio>
#include<algorithm>
using namespace std;const int N=25;
int a[N];int res;int n;int up;
inline int gcd(int a,int b){int c;while(b){c=a%b;a=b;b=c;}return a;}
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%d",&n);up=1<<n;
	for(int i=0;i<n;i++){scanf("%d",&a[i]);}
	for(int i=1;i<up;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(((i>>j)&1)==0)continue;
			for(int k=j+1
			;k<n;k++)
			{if(((i>>k)&1)&&(gcd(a[j],a[k])!=1)){goto ed;}}
		}res++;ed:;
	}printf("%d",res);
	fclose(stdin);fclose(stdout);return 0;
}
