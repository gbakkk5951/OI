#include<stdio.h>
#include<string.h>
int map[310][310];
int main()
{
	int i,j,k,n,p,q,a,b;
	memset(map,0,sizeof(map));
	scanf("%d%d%d",&n,&p,&q);
	for(i=0;i<p;i++)
	{
		scanf("%d%d%d",&k,&a,&b);
		if(k==1)
		{
			map[a][b]=1;
		}
		if(k==2)
		{
			map[b][a]=1;
		}
		if(k==3)
		{
			map[a][b]=2;
			map[b][a]=2;
		}
//		printf("%d %d\n",map[1][3],map[3][1]);
	}
//	for(i=1;i<=n;i++)
//	{
//		map[i][i]=2;
//	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(map[i][j]==2)
				{
					continue;
				}
				else if(map[i][k]==2&&map[k][j]==2)
				{
					map[i][j]=2;
				}
				else if(map[i][k]&&map[k][j])
				{
//					if((i==1&&j==3)||(i==3&&j==1))
//					{
//						printf("#%d map[%d][%d]=%d map[%d][%d]=%d\n",k,i,k,map[i][k],k,j,map[k][j]);
//					}
//					if(i==1&&j==1)
//					{
//						printf("$%d %d %d\n",k,map[i][k],map[k][j]);
//					}
					map[i][j]=1;
				}
			}
		}
	}
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&a,&b);
		if(map[a][b]==2||a==b)
		{
			printf("Balance\n");
		}
		else if(map[a][b])
		{
			printf("Left\n");
		}
		else if(map[b][a])
		{
			printf("Right\n");
		}
		else
		{
			printf("Unknown\n");
		}
	}
	return 0;
}

