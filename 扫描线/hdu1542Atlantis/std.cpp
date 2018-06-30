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
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
struct Query {
	lf x1, x2, y;
	char val;
	bool operator < (const Query &b) const {
		return y < b.y;
	}
}q[222];
struct _Main {
	lf srt[222];
	int sn;
	int n;
	lf sum[555];
	int cnt[555];
	void change(int nd, int nl, int nr, int l, int r, int val) {
		if (l <= nl && nr <= r) {
			cnt[nd] += val;
			if (cnt[nd] == 0) {
				if (nl < nr) {
					sum[nd] = sum[ls[nd]] + sum[rs[nd]];
				} else {
					sum[nd] = 0;
				}
			} else {
				sum[nd] = srt[nr + 1] - srt[nl];
			}
			return;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) {
			change(ls[nd], nl, mid, l, r, val);
		}
		if (r > mid) {
			change(rs[nd], mid + 1, nr, l, r, val);
		}
		if (cnt[nd] == 0) {
			sum[nd] = sum[ls[nd]] + sum[rs[nd]];
		}
	}
	_Main() {
		int Qn = 0;
		while (1) {
			read(n);
			++Qn;
			if (n == 0) break;
			lf x1, x2, y1, y2;
			int qidx = 0;
			for (int i = 1; i <= n; i++) {
				scanf("%lf%lf%lf%lf", &x1, &y2, &x2, &y1);
				q[++qidx] = (Query) {x1, x2, y1, 1};
				srt[qidx] = x1;
				q[++qidx] = (Query) {x1, x2, y2, -1};
				srt[qidx] = x2;
			}
			sort(srt + 1, srt + 2 * n + 1);
			sn = unique(srt + 1, srt + 2 * n + 1) - srt - 1;
			for (int i = 1; i <= qidx; i += 2) {
				q[i + 1].x1 = q[i].x1 = lower_bound(srt + 1, srt + sn + 1, q[i].x1) - srt;
				q[i + 1].x2 = q[i].x2 = lower_bound(srt + 1, srt + sn + 1, q[i].x2) - srt - 1;
			}
			sort(q + 1, q + qidx + 1);
			lf lst = 0;
			lf ans = 0;
			for (int i = 1; i <= qidx; i++) {
				ans += sum[1] * (q[i].y - lst);
				lst = q[i].y;
				change(1, 1, sn - 1, q[i].x1, q[i].x2, q[i].val);
			}
			printf("Test case #%d\n", Qn);
			printf("Total explored area: %.2lf\n\n", ans);
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
