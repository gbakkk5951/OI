#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int x,int y)
{
	if (!y)
		return x;
	return gcd(y,x%y);
}
int h[10][10];
int main()
{
	int n,a,b;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>h[1][i];
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (gcd(h[1][i],h[1][j])==1)
			{
				a=i,b=j;
				break;
			}
				
	
	int x,y;
	for (int i=-2000;i<=2000;i++)
		for (int j=-2000;j<=2000;j++)
			if (h[1][a]*i+h[1][b]*j==1)
			{
				x=i,y=j;
				break;
			}
				
	for (int i=2;i<=n;i++)
		h[i][i]=1;
	h[a][1]=x*(a%2?-1:1);
	h[b][1]=y*(b%2?-1:1);
	for (int i=1;i<=n;i++,cout<<"\n")
		for (int j=1;j<=n;j++)
			cout<<h[i][j]<<" ";
	
	int ans=0,no[6];
	for (int i=1;i<=n;i++)
		no[i]=i;
	do
	{
		int tt=1;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (no[i]>no[j])
					tt=-tt;
		for (int i=1;i<=n;i++)
			tt*=h[i][no[i]];
		ans+=tt;
	}while (next_permutation(no+1,no+n+1));
	cout<<ans<<"\n";
}
