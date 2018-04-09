using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <iostream>
typedef long long lld;
const int MXN = 1000;
struct _Main {

int a[MXN], b[MXN], D[MXN], P[MXN], H[MXN];
int d[20], p[20];
int s[20];
int n, m;

lld calc() {
	lld ret = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i]) {
			cerr <<"+=";
			ret += d[i];
		} else {
			cerr <<"+=";
			ret += p[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		if (s[a[i]] && s[b[i]]) {
			ret += D[i];
		} else if ((!s[a[i]]) && (!s[b[i]])) {
			ret += P[i];
		} else {
			ret -= H[i];
		}
	}
	return ret;
}
_Main() {
	
	lld ans = -2147483648LL * 2147483648LL * 2LL;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		read(p[i]); read(d[i]);
	}
	for (int i = 1; i <= m; i++) {
		read(a[i]); read(b[i]); read(D[i]); read(P[i]);
		read(H[i]);
	}
	for (int I = 0; I < (1 << n); I++) {
		for (int i = 0; i < n; i++) {
			s[i + 1] = I >> i & 1;
		}
		ans = max(ans, calc());
	}
	printf("%lld", ans);
}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f; 
	}
}brute;
