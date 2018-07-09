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
const int MXN = 2e3 + 10;
const lf EPS = 1e-8;
struct _Main {
	int n, p, u;
	lf pi[MXN], ui[MXN];
	
	_Main() {
		read(n); read(p); read(u);
		for (int i = 1; i <= n; i++) {
			scanf("%lf", pi + i);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lf", ui + i);
		}
		lf pl = 0, pr = 1.0;
		lf ans[2] = {0, 0};
		int pn[2] = {0, 0};
		lf ul = 0, ur = 1.0;
		int un[2] = {0, 0};
		while (pr - pl > EPS) {
			lf pmid = (pr + pl) / 2.0;
			ul = 0; ur = 1.0;
			while (ur - ul > EPS) {
				lf umid = (ur + ul) / 2.0;
				un[0] = un[1] = pn[1] = pn[0] = 0;
				ans[0] = ans[1] = 0;
				int it = 0;
				for (int i = 1; i <= n; i++) {
					it ^= 1;
					lf tmp;
					//什么都不放
					ans[it] = ans[it ^ 1];
					un[it] = un[it ^ 1];
					pn[it] = pn[it ^ 1];
					//放u
					tmp = ans[it ^ 1] + ui[i] - umid;
					if (tmp > ans[it]) {
						ans[it] = tmp;
						un[it] = un[it ^ 1] + 1;
						pn[it] = pn[it ^ 1];
					}
					//放p
					tmp = ans[it ^ 1] + pi[i] - pmid;
					if (tmp > ans[it]) {
						ans[it] = tmp;
						un[it] = un[it ^ 1];
						pn[it] = pn[it ^ 1] + 1;
					}
					//放up
					tmp = ans[it ^ 1] + 1 - (1 - pi[i]) * (1 - ui[i]) - umid - pmid;
					if (tmp > ans[it]) {
						ans[it] = tmp;
						pn[it] = pn[it ^ 1] + 1;
						un[it] = un[it ^ 1] + 1;
					}
					ans[it ^ 1] = 0;
					un[it ^ 1] = 0;
					pn[it ^ 1] = 0;
				}
				if (un[n & 1] > u) {// = 还不能判错了
					ul = umid;
				} else if (un[n & 1] < u){
					ur = umid;
				} else {
					ur = ul = umid;
				}
			}
			if (pn[n & 1] > p) {// =还不能判错了
				pl = pmid;
			} else if (pn[n & 1] < p) {
				pr = pmid;
			} else {
				pl = pr = pmid;
			}
		}
		printf("%.6lf", ans[n & 1] + ul * u + pl * p);
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
