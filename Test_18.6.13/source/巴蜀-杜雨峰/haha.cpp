#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#define e exp(1)
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	long double f=1.0-1.0/e;
	for (int i=1;i<=n;i++)
		f=1.0-f*i,
		cout<<fixed<<setprecision(4)<<f<<"\n";
	
}
