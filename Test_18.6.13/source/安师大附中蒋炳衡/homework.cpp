#include<iostream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long LL;
typedef double db;
//const int N=66670;
//const db E=exp(1.0);

int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	
	LL i,n,x=-1;
	cin>>n;db ans=0;
	for(i=n+1;(db)x<=1e12;i++){
		x*=-i;//cout<<i<<' '<<x<<' '<<(db)1.0/x<<endl;
		ans=ans+(db)1.0/x;
	}
	printf("%.4lf\n",ans);
	
	return 0;
}

