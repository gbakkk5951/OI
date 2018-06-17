#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main(void)
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	
	int n;
	double f;
	
	f=1-1/M_E;
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		f=1-double(i)*f;
	}
	
	printf("%.4lf",f);
	
	return 0;
}
