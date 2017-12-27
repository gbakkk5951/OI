#include<cstdio>
int map[110][110];
int main()
{
	int n,q;
	scanf("%d",&n);
	int i=0,j=0,k=0,l=0;
	for(j=0;j<n;j++)
	for(i=0;i<n;i++)
	{scanf("%d",&map[i][j]);
	}
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	for(k=0;k<n;k++)
	{
		if(map[j][i]+map[i][k]<map[j][k])
		map[j][k]=map[j][i]+map[i][k];
		
	}
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&j,&k);
		printf("%d\n",map[j-1][k-1]);
		
	}
	
}
