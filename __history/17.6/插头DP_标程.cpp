#include<iostream>
#include<cstring>
using namespace std;
long long f[2][1<<12],i,j,ps,p=0,c=1,n,m;
int main()
{
	while (scanf("%d%d",&n,&m),n!=0)
	{
	memset(f[c],0,sizeof(f[c]));
	f[c][(1<<m)-1]=1;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
		{
			swap(p,c);memset(f[c],0,sizeof(f[c]));
			for (ps=0;ps<1<<m;ps++)
			if (f[p][ps])
			{
				if (j>0&&(!(ps&(1<<j-1)))&&(ps&(1<<j))) f[c][ps|1<<(j-1)]+=f[p][ps];
				if (!(ps&1<<j)) f[c][ps|1<<j]+=f[p][ps];
				if (ps&1<<j) f[c][ps^1<<j]+=f[p][ps];
			}
		}
	printf("%lld\n",f[c][(1<<m)-1]);
	}
}
