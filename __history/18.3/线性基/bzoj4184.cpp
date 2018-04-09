#pragma GCC optimize(2)
using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cstring>

namespace OI {
const int MXN = 500010;
const int VAL = 0, NXT = 1;
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

class LinearBase {
public:
	int base[31];
	void insert(int num) {
		for (int i = 30; i >= 0; i--) {
			if (num >> i & 1) {
				if (base[i]) {
					num ^= base[i];
				} else {
					base[i] = num;
					break;
				}
			}
		}
	}
	void copy(LinearBase &b) {
		memcpy(this, &b, sizeof(LinearBase));
	}
	void clear() {
		memset(this, 0, sizeof(LinearBase));
	}
	int getmax() {
		int ret = 0;
		for (int i = 30; i >= 0; i--) {
			if ((ret >> i & 1) == 0 && base[i]) {
				ret ^= base[i];
			}
		}
		return ret;
	}
}base[20];

int ans[MXN];
int head[1050000], edge[8000000][2];
int eidx;
void add(int nd, int v) {
	eidx++;
	edge[eidx][VAL] = v;
	edge[eidx][NXT] = head[nd];
	head[nd] = eidx;
}
class SegmentTree {
public:
	void insert(int nd, int nl, int nr, int l, int r, int val) {
		Beg:
		if (l <= nl && nr <= r) {
			add(nd, val);
			return;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) {
			insert(ls[nd], nl, mid, l, r, val);
		}
		if (r > mid) {
			nd = rs[nd]; nl = mid + 1;
			goto Beg;
		}
	}
	void getans(int nd, int nl, int nr, int layer) {
		Beg:
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			base[layer].insert(edge[e][VAL]);
		}
		if (nl == nr) {
			ans[nl] = base[layer].getmax();
			return;
		}
		int mid = nl + nr >> 1;
		base[layer + 1].copy(base[layer]);
		getans(ls[nd], nl, mid, layer + 1);
		nd = rs[nd]; nl = mid + 1;
		goto Beg;
	}
	
}tree;

struct _Main {
int n;
int arr[MXN], sorted[MXN], cnt[MXN], lst[MXN];
	_Main() {
		int t;
		n = 500000;
		read(n);
		for (int i = 1; i <= n; i++) {
			/*
			if (i <= n / 2)
			arr[i] = i;
			else 
			arr[i] = -(i - n / 2);
			*/
			read(arr[i]); 
			sorted[i] = abs(arr[i]);
		}
		sort(sorted + 1, sorted + n + 1);
		for (int i = 1; i <= n; i++) {
			t = lower_bound(sorted + 1, sorted + n + 1, abs(arr[i])) - sorted;
			if (arr[i] > 0) {
				if (++cnt[t] == 1) {
					lst[t] = i;
				}
			} else { 
				if(--cnt[t] == 0) {
					tree.insert(1, 1, n, lst[t], i - 1, sorted[t]);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (cnt[i]) {
				tree.insert(1, 1, n, lst[i], n, sorted[i]);
			}
		}
		tree.getans(1, 1, n, 0);
		for (int i = 1; i <= n; i++) {
			printf("%d\n", ans[i]);
		}
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
}bzoj4184;
}
//在草稿纸上写好步骤， 然后一个一个检查 
