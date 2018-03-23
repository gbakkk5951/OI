using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <queue>
namespace OI {
const int MXN = 20021;
const int VAL = 2, DST = 0, NXT = 1;
int size[MXN], mxsize[MXN];
int chose;
int org[MXN], val[MXN];
int mark[MXN];
int head[MXN], edge[MXN << 1][3], eidx;
void getsize(int nd, int sum, int fa) {
	int t;
	mxsize[nd] = 0;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa && !mark[t]) {
			getsize(t, sum, nd);
			size[nd] += size[t];
			mxsize[nd] = max(mxsize[nd], size[t]);
		}
	}
	size[nd]++;
	if (mxsize[nd] > mxsize[chose]) {
		chose = nd;
	}
}
struct hpNode {
	int bl, sum;
	bool operator < (const hpNode &b) const {
		return sum < b.sum;
	}
};
struct tNode {
	int saf, sum;
}arr[MXN];

void getnode(int nd, int fa, int &idx, int saf, int sum) {
	sum += val[nd];
	arr[idx++] = {saf, sum};
	int t;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa && !mark[t]) {
			getnode(t, nd, idx, saf + edge[e][VAL], sum);
		}
	}
}
int id[MXN], st[MXN], ed[MXN];
struct SegTree {
	priority_queue<hpNode> heap[MXN];
	void insert(int nd, int nl, int nr, int pos, const hpNode &val) {

		
	}
}tree;
int getans(int top, int sum, int al, int ar) {
	getsize(top, sum, 0);
	int nd = chose;
	getsize(nd, sum, 0);
	arr[al] = (tNode){0, val[nd]};
	id[al] = nd;
	st[nd] = ed[nd] = al;
	int nowl = al + 1, lst;
	int t;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		st[t] = lst = nowl;
		getnode(t, nd, nowl, saf, sum);
		for (int i = lst; i <= nowl; i++) {
			id[i] = t;
		} 
		ed[t] = nowl - 1;
	}
	for (int i = al; i <= ar; i++) {
		tree.insert(1, 0, n - 1, arr[i].saf, (hpNode){id[i], arr[i].sum});
	}
	for (int i = al; i <= ar; i = ed[id[i]] + 1) {
		for (int j = i; j <= ed[id[i]]; j++) {
			tree.erase(1, 0, n - 1, arr[j].saf, id[i]);
		}
		for (int j = i; j <= ed[id[i]]; j++) {
			if (arr[j].saf > R) continue;
			if (tree.query(1, 0, n - 1, max(L - arr[j].saf, 0), R - arr[j].saf)) {
				return 1;
			}
		}
		for (int j = i; j <= ed[id[i]]; j++) {
			tree.insert(1, 0, n - 1, arr[j].saf, (hoNode){id[i], arr[j].sum});
		}
	}
	mark[nd] = 1;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if ()
	}
	
	return 0;
}

struct _Main {
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	int n, L, R; 
	int m;
	_Main() {
		int mn = 2147483647, mx = -1;
		read(n); read(L); read(R);
		int x, y, v;
		for (int i = 1; i <= n; i++) {
			read(org[i]);
			mn = min(mn, org[i]);
			mx = max(mx, org[i]);
		}
		while (read(x)) {
			m++;
			read(y); read(v);
			add(x, y, v);
			add(y, x, v);
		}
		int mid;
		while(l < r) {
			mid = (l + r >> 1) + 1;
			for (int i = 1; i <= n; i++) {
				val[i] = org[i] >= mid;
			}
			if (confirm()) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		printf("%d", l);
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar())) {
			if (t == EOF) return 0;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		return 1;
	}
}T3;
}

