#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int a[50005];
	int s[50005];
	s[0]=0;
	int n,m;
	scanf("%d",&n);
	int i,j,k,l;
	int zmin,pos;
	
	for(i=0;i<n;i++)
	{
		zmin=2147483647;
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
		scanf("%d",a+j);
		}
		sort(a,a+m);
        for(j=0;j<m;j++)
        s[j+1]=s[j]+*(a+j);
        for(j=0;j<50;j++)
        {
        	int sum;
			int re=(lower_bound(a,a+m,j)-a);
        	sum=-s[re]+re*j;
        	sum+=s[m]-s[re]-j*(m-re);
        	if(sum<zmin)
        	{zmin=sum;
        	pos=j;
			}
		}
		printf("%d %d\n",pos,zmin);
		
	}
	
}
