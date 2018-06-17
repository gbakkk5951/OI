#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
int n,i;
double a;
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	cin>>n;
	a=1.0-1.0/M_E;
	for(i=1;i<=n;i++) a=1.0-a*i;	
	cout<<fixed<<setprecision(4)<<a;
	return 0;
}

