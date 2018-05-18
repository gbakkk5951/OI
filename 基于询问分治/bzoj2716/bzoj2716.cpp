using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

namespace OI {
const int INF = 0x3f3f3f3f;
const int MXN = 500050;
const int ADD = 1, QUERY = 2;
int lrand(int l, int r) {
	return l + (rand() << 15 | rand()) % (r - l + 1);
}
struct LS {
	int operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
int mx;
struct SegTree {

	int tag[2100000], node[2100000];
	SegTree () {
		clear(1);
	}
	void inline push(int nd) {
		if (tag[nd]) {
			clear(ls[nd]);
			clear(rs[nd]);
			tag[nd] = 0;
		}
	}
	void clear(int nd) {
		node[nd] = INF;
		tag[nd] = 1;
	}
	void change(int pos, int v) {
		int nd = 1, nl = 1, nr = mx;
		while (1) {
			node[nd] = min(node[nd], v);
			if (nl == nr) {
				return;
			}
			push(nd);
			int mid = nl + nr >> 1;
			if (pos <= mid) {
				nd = ls[nd]; nr = mid;
			} else {
				nd = rs[nd]; nl = mid + 1;
			}
		}
	}
	int query(int mx) {
		int nd = 1, nl = 1, nr = OI::mx; // ÃüÃû³åÍ» 
		int ret = INF;
		while (1) {
			if (node[nd] >= ret) break;
			if (nr <= mx) {
				ret = min(ret, node[nd]);
				break;
			}
			push(nd);
			int mid = nl + nr >> 1;
			if (mx <= mid) {
				nd = ls[nd]; nr = mid;
			} else {
				ret = min(ret, node[ls[nd]]);
				nd = rs[nd]; nl = mid + 1;
			}
		}
		return ret;
	}
	void clear() {
		clear(1);
	}
}tree;

int ans[MXN];

struct Ques {
	int id, tp, x, y;
	bool operator < (const Ques &b) const {
		if (x != b.x) {
			return x < b.x;
		}
		if (y != b.y) {
			return y < b.y;
		}
		return tp < b.tp;
	}
};
Ques arr[MXN << 1];
Ques tmp[MXN << 1];
void cdq(int l, int r) {
	int a1 = 0, a2 = 0, q1 = 0, q2 = 0;
	int mid = l + r >> 1;
	int idx = 0;
	for (int i = l; i <= mid; i++) {
		if (arr[i].tp == ADD) {
			tmp[idx++] = arr[i];
			a1++;
		} else {
			q1++;
		}
	}
	for (int i = mid + 1; i <= r; i++) {
		if (arr[i].tp == QUERY) {
			tmp[idx++] = arr[i];
			q2++;
		} else {
			a2++;
		}
	}
	if (a1 && q2) {
		sort(tmp, tmp + idx);
		for (int i = 0; i < idx; i++) {
			if (tmp[i].tp == ADD) {
				tree.change(tmp[i].y, -tmp[i].x - tmp[i].y);
			} else {
				ans[tmp[i].id] = min(ans[tmp[i].id], tmp[i].x + tmp[i].y + tree.query(tmp[i].y));
			}
		}
		tree.clear();
		for (int i = 0; i < idx; i++) {
			if (tmp[i].tp == ADD) {
				ans[tmp[i].id] = min(ans[tmp[i].id], tmp[i].x + tmp[i].y + tree.query(tmp[i].y));
			}
		}
	}
	if (a1 && q1) {
		cdq(l, mid);
	}
	if (a2 && q2) {
		cdq(mid + 1, r);
	}
}


struct _Main {
	int qidx, aidx;
	int op[MXN << 1], x[MXN << 1], y[MXN << 1];
	_Main() {
		int n, Qn;
//		n = 3e5; Qn = 3e5;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			++qidx;
			op[qidx] = ADD;
//			x[qidx] = lrand(0, 1e6);
//			y[qidx] = lrand(0, 1e6);
			read(x[qidx]); read(y[qidx]);
		}
		
		for (int Q = 1; Q <= Qn; Q++) {
			++qidx;
//			op[qidx] = lrand(1, 2);
//			x[qidx] = lrand(0, 1e6);
//			y[qidx] = lrand(0, 1e6);
			read(op[qidx]); 
			read(x[qidx]); read(y[qidx]);
			
			if (op[qidx] == QUERY) {
				aidx++;
			}
		}
		memset(ans + 1, 63, aidx * sizeof(int));
		for (int i = 1; i <= qidx; i++) {
			x[i]++; y[i]++;
			mx = max(mx, y[i]);
			mx = max(mx, x[i]);
		}
		for (int I = 0; I < 4; I++) {
			aidx = 0;
			for (int i = 1; i <= qidx; i++) {
				if (op[i] == ADD) {
					arr[i] = (Ques) {0, op[i], x[i], y[i]};
				} else {
					arr[i] = (Ques) {++aidx, op[i], x[i], y[i]};
				}
			}
			cdq(1, qidx);
			if (I == 3) break;
			if (I & 1) {
				for (int i = 1; i <= qidx; i++) {
					y[i] = mx - y[i] + 1;
				}
			} else {
				for (int i = 1; i <= qidx; i++) {
					x[i] = mx - x[i] + 1;
				}
			}
		}
		
		for (int i = 1; i <= aidx; i++) {
			printf("%d\n", ans[i]);
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}bzoj2716;
}
