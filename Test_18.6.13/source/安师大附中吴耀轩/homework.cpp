#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
typedef long double cdb;
const int maxn = 10005;
const cdb eps = 1e-7;
cdb f[maxn];int n;cdb ans,cur=1;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("homework.in","r",stdin);
		freopen("homework.out","w",stdout);
	#endif
	cin>>n;++n;
	for (int i=1;i<=100000;i++)
		ans=ans+cur/(n+1),
		cur=cur/n/(n+1),n+=2;
	printf("%.4lf",(double)ans);
	/*f[0]=1-exp(-1);cin>>n;
	for (int i=1;i<=n;i++) f[i]=1-i*f[i-1];
	printf("%.4lf",(double)f[n]);*/
	return 0;
}
