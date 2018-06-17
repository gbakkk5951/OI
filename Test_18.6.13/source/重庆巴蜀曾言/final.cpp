#include<iostream>
#include<cstdio>
using namespace std;
int n,i,a,b;
int main()
{
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	cin>>n;
	if(n>2)
	{
		cout<<"no solution";
		return 0;
	}
	else if(n==1)
	{
		cin>>a;
		cout<<a;
		return 0;
	}
	cin>>a>>b;
	for(i=-2000;i<=2000;i++)
	{
		if((a*i-1)%b==0)
		{
			cout<<a<<" "<<b<<"\n";
			cout<<(a*i-1)/b<<" "<<i;
			return 0;
		}
	}
	cout<<"no solution";
	return 0;
}

