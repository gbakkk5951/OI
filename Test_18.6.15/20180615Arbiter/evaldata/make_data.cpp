#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<utility>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define INF 1111111111
#define N 11111
#define eps 1e-9
using namespace std;
typedef long long LL;
int getint()
{
	char ch;
	do
	{
		ch=getchar();
	}while (ch!='-'&&(ch<'0'||ch>'9'));
	int ans=0,f=0;
	if (ch=='-') f=1; else ans=ch-'0';
	while (isdigit(ch=getchar())) ans=ans*10+ch-'0';
	if (f) ans*=-1;
	return ans;
}
char name[22];
int a[33][33];
void solve(int n,int m,int k,int A,int tA,int B,int tB,int id)
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) a[i][j]=-1;
	for (int i=1;i<=tA;i++)
	{
		int x=rand()%n+1,y=rand()%m+1;
		a[x][y]=a[x-1][y]=a[x+1][y]=a[x][y-1]=a[x][y+1]=rand()%A+1;
		a[x-1][y-1]=a[x-1][y+1]=a[x+1][y-1]=a[x+1][y+1]=a[x][y];
	}
	for (int i=1;i<=tB;i++) 	
	{
		int x=rand()%n+1,y=rand()%m+1;
		a[x][y]=rand()%B+A+1;
	}
	printf("%d %d %d\n",n,m,k);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (id==1) printf("%d ",rand()%200+1);
			else if (id==2) printf("%d ",rand()%100000+1);
			else printf("%d ",rand()%5*1000+rand()%5+1);
		}
		printf("\n");
	}
	return ;
}
void make_data(int id)
{
	int test=20;
	printf("%d\n",test);
	if (id<=2) 
	for (int i=1;i<=test;i++) solve(4,5,5,0,0,20,20,rand()%3+1);
	else if (id<=6)
	for (int i=1;i<=test;i++) solve(25,25,5,3,100,5,20,rand()%3+1);
	else 
	for (int i=1;i<=test;i++) solve(25,25,5,3,100,30,30,rand()%3+1);
} 
int main()
{
	srand(time(0));
	for (int i=1;i<=10;i++)
	{
		sprintf(name,"chocolate%d.in",i);
		freopen(name,"w",stdout);
		make_data(i);
		fclose(stdout);
	} 
	return 0;
}
