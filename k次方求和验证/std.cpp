using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
const int DST = 0, NXT = 1;
struct _Main {
	_Main() {
		int n, Qn, Tn;
		Lf a1 = 0, a2 = 0;
		Lf k = -0.3;
		n = 100000;
		for (int i = 1; i <= n; i++) {
			a1 += pow(i, k);
		}
		printf("a1 = %Lf\n", a1);
		a2 = pow(n, k + 1.0) / (1.0 + k);
		printf("a2 = %Lf\n", a2);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
