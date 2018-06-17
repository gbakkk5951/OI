#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cstdlib>
#define e 2.7182818284590452354
using namespace std;
typedef long long ll;
int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	double ans=1.0-1.0/e;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ans=1.0-1.0*i*ans;
	}	
	cout<<ans<<"\n";
	return 0;
}
