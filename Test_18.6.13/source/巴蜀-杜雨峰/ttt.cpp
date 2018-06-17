#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	double res=0;
	double cur=1;
	for (int i=1;i<=100;i++)
	{
	
		res+=cur;
		cur/=i;	
	}
	cout<<res;
}
