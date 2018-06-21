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
namespace OI {
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
const int DST = 0, NXT = 1;
const int MXN = 5e5 + 10;
struct LS {
	inline int operator [] (int a) {
		return a << 1;
	}	
}ls;
struct RS {
	inline int operator [] (int a) {
		return a << 1 | 1;
	}	
}rs;
struct Node {
	Node *s[2];
	int lst, id;
}pool[MXN * 83], *null;
int pidx;
Node *new_(int id, Node *org = 0) {
	Node *nd = &pool[pidx++];
	if (org) {
		*nd = *org;
	} else {
		nd->s[0] = nd->s[1] = null;
	}
	nd->id = id;
	return nd;
}
Node *root[MXN];
struct ChairTree {
	ChairTree() {
		null = new_(0);
		null->s[0] = null->s[1] = null;
		root[0] = null;
	}

}ctree;
struct SegTree {
	int tag[1050000];
	int sum[1050000];
	inline void update(int nd) {
		sum[nd] = sum[ls[nd]] + sum[rs[nd]];
	}
	void change(int nd, int nl, int nr, int l, int r, int val) {
		if (l <= nl && nr <= r) {
			tag[nd] = val;
			sum[nd] = (nr - nl + 1) * val;
			return;
		}
		int mid = nl + nr >> 1;
		if (tag[nd]) {
			tag[ls[nd]] = tag[nd];
			tag[rs[nd]] = tag[nd];
			sum[ls[nd]] = tag[nd] * (mid - nl + 1);//nl不是l
			sum[rs[nd]] = tag[nd] * (nr - mid);//nr不是r
			tag[nd] = 0;
		}
		if (l <= mid) {
			change(ls[nd], nl, mid, l, r, val);
		} 
		if (r > mid) {
			change(rs[nd], mid + 1, nr, l, r, val);
		}
		update(nd);
	}
	int query(int nd, int nl, int nr, int l, int r) {
		if (l <= nl && nr <= r) {
			return sum[nd];
		}
		int mid = nl + nr >> 1;
		if (tag[nd]) {//0只会在叶子有，所以无所谓
			tag[ls[nd]] = tag[nd];
			tag[rs[nd]] = tag[nd];
			sum[ls[nd]] = tag[nd] * (mid - nl + 1);//nl不是l
			sum[rs[nd]] = tag[nd] * (nr - mid);//nr不是r
			tag[nd] = 0;
		}
		int ret = 0;
		if (l <= mid) {
			ret += query(ls[nd], nl, mid, l, r);
		}
		if (r > mid) {
			ret += query(rs[nd], mid + 1, nr, l, r);
		}
		return ret;
	}
}ntree;


struct _Main {
	int val[MXN];
	void driveaway(int id, int pos) {
		Node *nd = root[id] = new_(id, root[id - 1]), *lst;
		int nl = 1, nr = n, mid, spo;
		while (nl != nr) {
			mid = nl + nr >> 1;
			if (spo = pos > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			if (nd->lst) {
				for (int i = 0; i < 2; i++) {
					nd->s[i] = new_(id, nd->s[i]);
					nd->s[i]->lst = nd->lst;
				}
				nd->lst = 0;
			} else {
				nd->s[spo] = new_(id, nd->s[spo]);
			}
			nd = nd->s[spo];
		}
		if (nd->lst == 0) {
			return;
		}
		lst = root[nd->lst - 1];
		nl = 1; nr = n;
		while (nl != nr) {
			if (lst->lst) {
				break;
			}
			mid = nl + nr >> 1;
			if (spo = pos > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			lst = lst->s[spo];
		}
		nd->lst = lst->lst;
		ntree.change(1, 1, n, pos, pos, val[nd->lst]);
	}
	Node* drivein(Node *nd, int id, int nl, int nr, int l, int r) {
		if (nd->id != id) {
			nd = new_(id, nd);
		}
		if (l <= nl && nr <= r) {
			nd->lst = id;
			return nd;
		}
		if (nd->lst) {
			for (int i = 0; i < 2; i++) {
				nd->s[i] = new_(id, nd->s[i]);
				nd->s[i]->lst = nd->lst;
			}
			nd->lst = 0;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) {
			nd->s[0] = drivein(nd->s[0], id, nl, mid, l, r);
		}
		if (r > mid) {
			nd->s[1] = drivein(nd->s[1], id, mid + 1, nr, l, r);
		}
		return nd;
	} 
	int n, Qn, Tn;
	_Main() {
		int qz;
		int lstans = 0;
		int op, x;
		int l, r;
		read(n); read(Qn); read(qz);
		for (int Q = 1; Q <= Qn; Q++) {
			read(op);
			if (op == 1) {//区间询问
				root[Q] = root[Q - 1];
				read(l); read(r);
				l = (l + qz * lstans) % n + 1;
				r = (r + qz * lstans) % n + 1;
				if (l > r) swap(l, r);
				printf("%d\n", lstans = ntree.query(1, 1, n, l, r));
			} else
			if (op == 2) {//开走火车
				read(l);
				l = (l + qz * lstans) % n + 1;
				driveaway(Q, l);
			} else
			if (op == 3) {//区间开入火车
				read(l); read(r); read(x);
				l = (l + qz * lstans) % n + 1;
				r = (r + qz * lstans) % n + 1;
				if (l > r) swap(l, r);
				root[Q] = drivein(root[Q - 1], Q, 1, n, l, r);
				ntree.change(1, 1, n, l, r, x);
				val[Q] = x;
			}
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
