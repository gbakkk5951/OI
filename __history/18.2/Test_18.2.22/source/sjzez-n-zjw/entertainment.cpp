#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,me,ms;
int s[1004],e[10004];
int f[1003][1003];
int main()
{
	freopen("entertainment.in","r",stdin);
	freopen("entertainment.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&ms,&me);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&e[i]);
	for(int i=1;i<=n;i++)
	{
		f[i][0]=f[i-1][0]+e[i];
		f[i][i]=f[i-1][i-1]+s[i]; 
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=max(f[i-1][j]+e[i],f[i-1][j-1]+s[i]);
	for(int i=m+1;i<=n;i++)
		for(int j=i-m;j<=i;j++)
			f[i][j]=max(f[i-1][j]+e[i],f[i-1][j-1]+s[i]);
	int ans=0;
	for(int i=ms;i<=n;i++)
		ans=max(f[n][i],ans);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
