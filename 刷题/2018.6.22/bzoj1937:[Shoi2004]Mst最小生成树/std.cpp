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
#include <complex>
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
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
namespace bi {
	

}
const int MXN = 55, MXM = 805;
struct _Main {
	int src[MXM], dst[MXM], val[MXM];
	int head[MXN], f[MXN], edge[MXN << 1][2];
	int n, m;
	_Main() {
		read(n); read(m);
		for (int i = 1; i <= m; i++) {
			read(src[i]); read(dst[i]); read(val[i]);
		}
		for (int i = 1; i <= n - 1; i++) {
			int a, b;
			read(a); read(b);
			add(a, b); add(b, a);
		}
	}
	
	void add(int a, int b) {
		static int eidx;
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
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
