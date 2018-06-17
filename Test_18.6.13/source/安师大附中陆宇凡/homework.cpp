#include<bits/stdc++.h>
using namespace std;
const double e=2.7182818284590452353602874713527;

int n,i;
double f;

int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	cin>>n;
	if(n<=10)
	{
		f=1-1/e;
		for(i=1;i<=n;i++)
			f=1-1.0*i*f;
		printf("%.4lf\n",f);
	}
	return 0;
}
