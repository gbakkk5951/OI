#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define Int const int &
#define Double const double &

const int N=12345;

long double f[N]={1-1/2.718281828459};

int main(void) {
	freopen("homework.cpp", "r", stdin);
	freopen("homework.cpp", "w", stdout);
	int n;
	scanf("%d", &n);
	for (register int i=1; i<=n; i++) {
		f[i]=1-(long double)i*f[i-1];
	}
	cout<<setprecision(4)<<fixed<<f[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
