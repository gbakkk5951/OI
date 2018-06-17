#include<bits/stdc++.h>
using namespace std;

bool zg[6];
int n,i,j,h[6][6],tt,s1;
int lis[6],B[125][6],ss,s2,T=1000000;

void dfs(int a)
{
	if(a>n)
	{
		int i,j;tt++;
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				if(lis[i]>lis[j])
					++B[tt][0];
		for(i=1;i<=n;i++)
			B[tt][i]=lis[i];
		return;
	}
	int i;
	for(i=1;i<=n;i++)
		if(!zg[i])
		{
			zg[i]=true;
			lis[a]=i;
			dfs(a+1);
			zg[i]=false;
		}
}

int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	scanf("%d",&n);//cerr<<n<<endl;
	for(i=1;i<=n;i++)
		scanf("%d",&h[1][i]);
	dfs(1);
	if(n==1)
	{
		printf("%d",h[1][1]);
		return 0;
	}
	if(n==2)
	{
//		cerr<<1<<endl;
		for(i=-2000;i<=2000;i++)
		{
			j=(1+h[1][2]*i)/h[1][1];
			if(abs(j)<=2000 && j*h[1][1]==1+h[1][2]*i)
			{
				printf("%d %d\n",h[1][1],h[1][2]);
				printf("%d %d\n",i,j);
				return 0;
			}
		}
		printf("no solution\n");
		return 0;
	}
	while(T--)
	{
		for(i=2;i<=n;i++)
			for(j=1;j<=n;j++)
				h[i][j]=(rand()*rand()%4001-2000);
		for(i=1,ss=0;i<=tt;i++)
			if(B[i][n]==n)
			{
				if(B[i][0]%2)s2=-1;
				else s2=1;
				for(j=1;j<n;j++)
					s2*=h[i][B[i][j]];
				s1+=s2;
			}
			else
			{
				if(B[i][0]%2)s2=-1;
				else s2=1;
				for(j=1;j<=n;j++)
					s2*-h[i][B[i][j]];
				ss+=s2;
			}
		h[n][n]=(1-ss)/s1;
		if(abs(h[n][n])<=2000&&h[n][n]*s1==1-ss)
		{
			for(i=1;i<=n;i++,printf("\n"))
				for(j=1;j<=n;j++)
					printf("%d ",h[i][j]);
			return 0;
		}
	}
	printf("no solution\n");
	return 0;
}
