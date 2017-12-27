#include<cstdio>
int dp[42][42][42][42];
int card[5];
int n,m;
int i,j,k,h;
int score[360];
int main()
{

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&score[i]);
	}
	for(i=1;i<=m;i++)
	{scanf("%d",&j);
	card[j]++;
	}
	dp[0][0][0][0]=score[1];
	int max=0;
	for(i=0;i<=card[1];i++)
	{	for(j=0;j<=card[2];j++)
		{	for(k=0;k<=card[3];k++)
			{	for(h=0;h<=card[4];h++)
				{
				max=0;
				if(i>0&&dp[i-1][j][k][h]+score[1+(i)+2*j+3*k+4*h]>max)
				max=dp[i-1][j][k][h]+score[1+(i)+2*j+3*k+4*h];
				if(j>0&&dp[i][j-1][k][h]+score[1+(i)+2*j+3*k+4*h]>max)
				max=dp[i][j-1][k][h]+score[1+(i)+2*j+3*k+4*h];
				if(k>0&&dp[i][j][k-1][h]+score[1+(i)+2*j+3*k+4*h]>max)
				max=dp[i][j][k-1][h]+score[1+(i)+2*j+3*k+4*h];
				if(h>0&&dp[i][j][k][h-1]+score[1+(i)+2*j+3*k+4*h]>max)
				max=dp[i][j][k][h-1]+score[1+(i)+2*j+3*k+4*h];
				if(!(i||j||k||h))
				max=score[1];
				dp[i][j][k][h]=max;
				}	
			}	
		}
	}
	printf("%d",dp[card[1]][card[2]][card[3]][card[4]]);
}
