#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>
typedef long long ll;
const int N=10005;
const ll lim=1ll<<62;
int n;
using namespace std;

int main()
{
	freopen ("homework.in","r",stdin);
	freopen ("homework.out","w",stdout);
	scanf ("%d",&n);
	long double ans=0.0;
	long long now=1;
	int i;
	for (i=1;;i++)
	{
		if (lim/now<(i+n)) break;
		now*=(i+n);
		if (i&1) ans+=1.0/now;
		else ans-=1.0/now;
	}
	printf ("%.4lf",(double)ans);
	return 0;
}

