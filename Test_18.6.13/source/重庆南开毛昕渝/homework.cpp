#include<iostream>
#include<cstdio>
#include<cmath>

#define LL long long
using namespace std;

const LL inf = 1000000000000000LL;
int n;
double ans;

int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int i,j;
	cin>>n;
	LL t = 1;
	for(i=n+1;t<inf;i++){
		t*=i;
		if((n-i+1)&1) ans -= 1.0/(double) t;
		else ans += 1.0/(double) t;
	}
	printf("%.4lf\n",ans);
	return 0;
}
