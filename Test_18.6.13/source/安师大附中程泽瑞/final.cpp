#include <bits/stdc++.h>
#define ll long long
using namespace std;
int p[121][6],t[6],n,cnt=0;
int a[6][6];bool vis[6];
void get_per(int pos)
{if (pos==n+1)
{cnt++;
for (int i=1;i<=n;i++)
{p[cnt][i]=t[i];}
p[cnt][0]=0;
for (int i=1;i<=n;i++)
{for (int j=1;j<i;j++)
{if (t[i]<t[j]) {p[cnt][0]^=1;}
}
}
return;
}
for (int i=1;i<=n;i++)
{if (!vis[i])
{vis[i]=1;
t[pos]=i;
get_per(pos+1);
vis[i]=0;
}
}
return;
}
int main (){
	freopen ("final.in","r",stdin);
	freopen ("final.out","w",stdout);
	scanf ("%d",&n);
	if (n==2)
	{int i,j,a,b;
	scanf ("%d%d",&a,&b);
	printf ("%d %d\n",a,b);
	for (i=-2000;i<=2000;i++)
	{for (j=-2000;j<=2000;j++)
	{if ((a*j-b*i)==1)
	{printf ("%d %d\n",i,j);return 0;}
	}
	}
	printf ("no solution\n");
	return 0;
	}
	int i,j,k;
	for (i=1;i<=n;i++)
	{scanf ("%d",&a[1][i]);}
	get_per(1);
	srand((unsigned long long)new char);
	while (((double)(clock()))/CLOCKS_PER_SEC<0.9)
	{for (i=2;i<=n;i++)
	{for (j=1;j<=n;j++)
	{a[i][j]=(rand()%4001)-2000;}
	}
	ll xs=0,num=1;
	for (i=1;i<=cnt;i++)
	{if (p[i][n]==n)
	{ll tp=1;
	for (j=1;j<=n-1;j++)
	{tp*=((ll)(a[j][p[i][j]]));}
	if (p[i][0]==0) {xs+=tp;}
	else {xs-=tp;}
	}
	else
	{ll tp=1;
	for (j=1;j<=n;j++)
	{tp*=((ll)(a[j][p[i][j]]));}
	if (p[i][0]==0) {num-=tp;}
	else {num+=tp;}
	}
	}
	if (xs==0) {continue;}
	if (num%xs==0)
	{if (num/xs>=-2000&&num/xs<=2000)
	{a[n][n]=num/xs;
	for (i=1;i<=n;i++)
	{for (j=1;j<=n;j++)
	{printf ("%d ",a[i][j]);}
	printf ("\n");
	}
	return 0;
	}
	}
	}
	printf ("no solution\n");
	return 0;
}
