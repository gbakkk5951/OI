#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define Int const int &
#define Double const double &

int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x=1; y=0;
		return a;
	}
	int d=exgcd(b, a%b, x, y);
	int t=x;
	x=y;
	y=t-a/b*y;
	return d;
}
int main(void) {
	freopen("final.in", "r", stdin);
	freopen("final.out", "w", stdout);
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int x, y;
	exgcd(a, -b, x, y);
	printf("%d %d\n%d %d", a, b, y, x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
