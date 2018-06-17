#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cstdlib>
using namespace std;
int h[6][6];
int Cal(int x,int y)
{
	h[2][1]=x;h[2][2]=y;
	return h[1][1]*h[2][2]-h[1][2]*h[2][1];
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	int n;
	cin>>n;
	if(n==2)
	{
		cin>>h[1][1]>>h[1][2];
		for(int i=-2000;i<=2000;i++)
		{
			for(int j=-2000;j<=2000;j++)
			{
				if(Cal(i,j)==1)
				{
					cout<<h[1][1]<<" "<<h[1][2]<<"\n"<<h[2][1]<<" "<<h[2][2];
					return 0;
				} 
			}
		}
		cout<<"no sulotion";
	}
	else if(n==3)
	{
		cout<<"no sulotion";
//		for(int i=1;i<=n;i++)cin>>h[1][i];
//		int x,y;
//		for(int i=1;i<=n;i++)
//		for(int j=i+1;j<=n;j++)
//		{
//			if(gcd(h[1][i],h[1][j])==1)
//			{
//				x=i;y=j;
//				break;
//			}
//		}
//		work(h[1][x],h[1][y]);
	}
	else cout<<"no sulotion";
	
}
