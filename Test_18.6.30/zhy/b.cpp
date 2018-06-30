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
const int iMOD = 1e9 + 7;
const lld MOD = 1e9 + 7;
const lld PHI = MOD - 1;
typedef map<vector<char>, int>::iterator itr;
struct _Main {
	map<vector<char>, int> mmp[2];
	lld fastpower(lld base, lld pow) {
		if (pow < 0) pow += PHI;
		lld ret = 1;
		while (pow) {
			ret = (pow & 1) ? base * ret % MOD : ret;
			base = (pow >>= 1) ? base * base % MOD : base;
		}
		return ret;
	}
	_Main() {
		freopen("b.in", "r", stdin);
		freopen("b.out", "w", stdout);
		vector<char> nd;
		int n, k, a;
		read(n); read(k);
		for (int i = 1; i <= n; i++) {
			read(a);
			nd.push_back(a);
		}
		int it = 0;
		mmp[it][nd] = 1;
		for (int i = 1; i <= k; i++) {
			it ^= 1;
			for (itr a = mmp[it ^ 1].begin(); a != mmp[it ^ 1].end(); ++a) {
				nd = a->first;
				int val = a->second;
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						swap(nd[j], nd[k]);
						(mmp[it][nd] += val) %= iMOD;
						swap(nd[j], nd[k]);
					}
				}
			}
			mmp[it ^ 1].clear();
		}
		lld ans = 0;
		lld size = 0, val = 0;
		for (itr a = mmp[it].begin(); a != mmp[it].end(); ++a) {
			nd = a->first;
			int mx = 0, cnt = 0;
			for (int j = 0; j < n; j++) {
				if (nd[j] > mx) {
					++cnt;
					mx = nd[j];
				}
			}
			(size += a->second) %= MOD;
			val = (val + (lld)cnt * a->second) % MOD;
		}
		ans = val * fastpower(size, -1) % MOD;
		printf("%lld", ans);
		fclose(stdout);
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
