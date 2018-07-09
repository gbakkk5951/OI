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
#include <cassert>
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
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const int MXN = 2e5 + 10;
struct _Main {
	int cnt[MXN];
	int fa[MXN];
	int arr[MXN];
	int n, m, gap;
	int getfa(int nd) {
		return cnt[nd] < gap ? nd : fa[nd] = getfa(fa[nd]);
	}
	_Main() {
		read(n); read(m);
		gap = n / m;
		lld totcnt = 0;
		int a, dst, nowcnt;
		for (int i = 0; i < m - 1; i++) {
			fa[i] = i + 1;
		}
		fa[m - 1] = 0;
		for (int i = 1; i <= n; i++) {
			read(a); arr[i] = a;
			a %= m;
			dst = getfa(a);
			++cnt[dst];
			nowcnt = (dst - a) < 0 ? dst - a + m : (dst - a);
			totcnt += nowcnt;
			arr[i] += nowcnt;
		}
		cout << totcnt << endl;
		for (int i = 1; i <= n; i++) {
			cout << arr[i] << " ";
		}
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
