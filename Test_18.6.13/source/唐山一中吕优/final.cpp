#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[6],n,list[9],cnt;
bool vis[7],flag[7];

void go(int x)
{
	cnt++;flag[x]=1;
	if (!flag[list[x]]) go(list[x]);	
}

void dfs(int x)
{
	if (x==n+1) 
	{
		memset(flag,0,sizeof flag);
		int pd=0;
		for (int i=1;i<=n;i++)
			if (!flag[list[i]]) 
			{
				cnt=0;
				go(list[i]);
				pd+=(cnt-1);
			}
		int goal= pd&1?-1:1;
		int A=a[list[1]],B=a[list[2]];
		for (int i=-2000;i<=2000;i++)
		{
			int tmp=goal+i*B;
			if (tmp%A) continue;
			tmp/=A;
			if (tmp<-2000||tmp>2000) continue;
			for (int j=1;j<=n;j++) printf("%d ",a[j]);puts("");
			for (int j=1;j<=n;j++)		
				if (j==list[1]) printf("%d ",i);
				else if (j==list[2]) printf("%d ",tmp);
				else printf("0 ");
			puts("");
			for (int j=3;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
					if (list[j]==k) printf("1 ");
					else printf("0 ");
				puts("");
			}
			exit(0);
		}
		if (n%2==0) return;
		goal=-goal;
		for (int i=-2000;i<=2000;i++)
		{
			int tmp=goal+i*B;
			if (tmp%A) continue;
			tmp/=A;
			if (tmp<-2000||tmp>2000) continue;
			for (int j=1;j<=n;j++) printf("%d ",a[j]);puts("");
			for (int j=1;j<=n;j++)		
				if (j==list[1]) printf("%d ",i);
				else if (j==list[2]) printf("%d ",tmp);
				else printf("0 ");
			puts("");
			for (int j=3;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
					if (list[j]==k) printf("-1 ");
					else printf("0 ");
				puts("");
			}
			exit(0);
		}
		return;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) 
		{
			vis[i]=1;
			list[x]=i;
			dfs(x+1);
			vis[i]=0;	
		}
}

int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	puts("no solution");
	return 0;	
}
