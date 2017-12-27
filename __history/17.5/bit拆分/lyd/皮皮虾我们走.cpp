#include<cstdio>
#include<iostream>
#define int long long
using namespace std;
int te;
int dp[70][70][70],rem[70][70];//最小数为2^i，被分解数为2^j，最大数为2^k时的方案数 
inline int lowbit(int a){
	return a&(-a);
}
int dfs(int n,int lst)
{
	//printf("%I64d__",n);
	int ans=0,j,i,lb,k,fz;
	j=lowbit(n);
	for(lb=0;(1LL<<lb)!=j;lb++);
	
	if(j==n)
	{//printf("*250*"); 
		for(i=lst;i<=lb;i++)
		{
	
			for(k=i;k<=lb;k++)
			{

				ans+=dp[i][lb][k];
				ans%=1000000000;
			}
		}
		return ans;
	}
	for(k=lst;k<=lb;k++)
	{
		fz=0;
		if(!rem[lb][k])
		{
			rem[lb][k]=dfs(n-j,k)+1;
		}
		for(i=lst;i<=k;i++)
		{
//				if(i>te||lb>te||k>te){
//					printf("51");
//				}
			fz+=dp[i][lb][k];
			fz%=1000000000;
		}
		ans+=(rem[lb][k]-1)*fz;
		ans%=1000000000;
	}
	return ans;
}

signed main()
{
	int n,i,k,p,q,j,ub;
	scanf("%lld",&n);
	dp[0][0][0]=1;
	for(ub=62;(1LL<<ub)>n;ub--);

	for(j=1;j<=ub;j++)
	{
		dp[j][j][j]=1;
		for(i=0;i<=j;i++)
		{
			for(k=i;k<=j;k++)
			{
				for(p=i;p<=k;p++)
				{
					for(q=p;q<=k;q++)
					{
						dp[i][j][k]+=dp[i][j-1][p]*dp[q][j-1][k];
						dp[i][j][k]%=1000000000;
					}
				}
			}
		}
	}
	printf("%lld\n",dfs(n,0));
}
