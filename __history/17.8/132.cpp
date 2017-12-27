#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int p[10][10],hang[10],lie[10],gong[10],test;
char str[10];
bool dfs(int dep)
{
	int x=(dep-1)/9+1,y=(dep-1)%9+1;
	if (dep==82) return 1;
	if (p[x][y])
	if (dfs(dep+1)) return 1;
	else return 0;
	int temp=hang[x]|lie[y]|gong[(x-1)/3*3+(y-1)/3+1];
	for (int i=1;i<=9;i++)
	if ((temp&(1<<(i-1)))==0)
	{
		hang[x]^=1<<(i-1);
		lie[y]^=1<<(i-1);
		gong[(x-1)/3*3+(y-1)/3+1]^=1<<(i-1);
		p[x][y]=i;
		if (dfs(dep+1)) return 1;
		else
		{ 
			hang[x]^=1<<(i-1);
			lie[y]^=1<<(i-1);
			gong[(x-1)/3*3+(y-1)/3+1]^=1<<(i-1);
			p[x][y]=0;
		}
	}
	return 0;
}
void op()
{
	for (int i=1;i<=9;i++)
	{
		for (int j=1;j<=9;j++)
		cout<<p[i][j];
		cout<<endl;
	}
}
int main()
{
	cin>>test;
	while (test--)
	{
		memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));
		memset(gong,0,sizeof(gong));
		for (int i=1;i<=9;i++)
		{
			scanf("%s",str+1);
			for (int j=1;j<=9;j++)
			p[i][j]=str[j]-'0';
		}
		for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
		if (p[i][j])
		{
			hang[i]^=1<<(p[i][j]-1);
			lie[j]^=1<<(p[i][j]-1);
			gong[(i-1)/3*3+(j-1)/3+1]^=1<<(p[i][j]-1);
		}
		if (dfs(1)) op();
	}
	system("pause");
	return 0;
}
