#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int main(){
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	double f=1-exp(-1);
	cin>>n;
	for(int i=1;i<=n;i++)
		f=1-i*f;
	printf("%.4lf\n", f);
	return 0;
}
