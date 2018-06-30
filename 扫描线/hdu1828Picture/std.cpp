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
const int MXN = 5e3 + 10;
struct Ques {
	int x1, x2, y, val;
	char operator < (const Ques &b) const {
		return y < b.y;
	}
}q[MXN << 1]; 
struct Node {
	int cnt, num;
	char l, r;
};
struct _Main {
	Node node[66666];
	
	int x1[MXN], x2[MXN], y1[MXN], y2[MXN];
	int n;
	int mnx, mny;
	int mxx, mxy;
	void change(int nd, int nl, int nr, int l, int r, int val) {
		if (l <= nl && nr <= r) {
			node[nd].cnt += val;
			if (node[nd].cnt) {
				node[nd].l = node[nd].r = 1;
				node[nd].num = 1;
			} else {
				if (nl != nr) {
					node[nd].num = node[ls[nd]].num + node[rs[nd]].num 
								 - (node[ls[nd]].r && node[rs[nd]].l);
					node[nd].l = node[ls[nd]].l;
					node[nd].r = node[rs[nd]].r;
				} else {
					node[nd].num = 0;
					node[nd].l = node[nd].r = 0;
				}
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
		if (node[nd].cnt == 0) {
			node[nd].num = node[ls[nd]].num + node[rs[nd]].num 
						 - (node[ls[nd]].r && node[rs[nd]].l);
			node[nd].l = node[ls[nd]].l;
			node[nd].r = node[rs[nd]].r;
		}
	}
	int calc() {
		int ret = 0;
		int qidx = 0;
		for (int i = 1; i <= n; i++) {
			q[++qidx] = (Ques) {x1[i], x2[i], y1[i], +1};
			q[++qidx] = (Ques) {x1[i], x2[i], y2[i], -1};
		}
		sort(q + 1, q + qidx + 1);
		int lst = mny;
		for (int i = 1; i <= qidx; i++) {
			ret += (node[1].num << 1) * (q[i].y - lst);
			lst = q[i].y;
			change(1, 0, mxx - mnx, q[i].x1 - mnx, q[i].x2 - mnx - 1, q[i].val);
		}
		return ret;
	}
	_Main() {
		while (~scanf("%d", &n)) {
			int ans = 0;
			mnx = INF, mny = INF;
			mxx = -INF, mxy = -INF;
			for (int i = 1; i <= n; i++) {
				read(x1[i]); read(y1[i]); read(x2[i]); read(y2[i]);
				mnx = min(mnx, x1[i]);
				mny = min(mny, y1[i]);
				mxx = max(mxx, x2[i]);
				mxy = max(mxy, y2[i]);
			}
			ans += calc();
			for (int i = 1; i <= n; i++) {
				swap(x1[i], y1[i]);
				swap(x2[i], y2[i]);
			}
			swap(mxx, mxy);
			swap(mnx, mny);
			ans += calc();
			printf("%d\n", ans);
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
