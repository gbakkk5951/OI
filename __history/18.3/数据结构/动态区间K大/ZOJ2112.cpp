using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
namespace OI {
const int 
	MXN = 50015
;
struct Node {
	Node *s[2], *f;
	unsigned short size;
	int val;
}pool[60005 * 16 + 100];
int pidx;
Node *new_(int val, Node *f = 0) {
	Node *nd = &pool[pidx++];
	nd->s[0] = nd->s[1] = 0;
	nd->val = val;
	nd->f = f;
	nd->size = 1;
	return nd;
}
class Splay {
public:
Node *root;
void update(Node *nd) {
	nd->size = 1;
	for (int i = 0; i < 2; i++) {
		nd->size += nd->s[i] ? nd->s[i]->size : 0;
	}
}
void rotate(Node *nd) {
	Node *f = nd->f, *gf = f->f, *s;
	nd->f = gf;
	if (gf) {
		gf->s[f == gf->s[1]] = nd;
	}
	int pos = nd == f->s[1];
	s = f->s[pos] = nd->s[pos ^ 1];
	if (s) {
		s->f = f;
	}
	f->f = nd;
	nd->s[pos ^ 1] = f;
	update(f);
	update(nd);
}
void splay(Node *nd) {
	Node *f;
	while (f = nd->f) {
		if (f->f) {
			if ((nd == f->s[1]) == (f == f->f->s[1])) {
				rotate(f);
			} else {
				rotate(nd);
			}
		}
		rotate(nd);
	}
	root = nd;
}



void insert(int val) {
	if (root == 0) {
		root = new_(val);
		return;
	}
	Node *nd = root;
	while (1) {
		nd->size++;
		int pos = val > nd->val;
		if (nd->s[pos]) {
			nd = nd->s[pos];
		} else {
			nd = nd->s[pos] = new_(val, nd);
			break;
		}
	}
	splay(nd);
}
int getsize(int val) {
	Node *nd = root, *lst;
	int ret = 0;
	while (nd) {
		lst = nd;
		if (val > nd->val) {
			ret += (nd->s[0] ? nd->s[0]->size : 0) + 1;
			nd = nd->s[1];
		} else {
			nd = nd->s[0];
		}
	}
	splay(lst);
	return ret;
}
void erase(int val) {
	Node *nd = root;
	while (nd->val != val) {
		nd = nd->s[val > nd->val];
	}
	while (nd->s[0] && nd->s[1]) {
		rotate(nd->s[0]);
	}
	Node *f = nd->f;
	Node *s = nd->s[0] ? nd->s[0] : nd->s[1];
	if (f) {
		f->s[nd == f->s[1]] = s;
		if (s) {
			s->f = f;
		}
		update(f);
		splay(f);
	} else {
		root = s;
		if (s) {
			s->f = 0;
		}
	}
}
Node* build(int arr[], int nl, int nr, Node *f = 0) {
	if (nl > nr) {
		return 0;
	}
	int mid = nl + nr >> 1;
	Node *nd = new_(arr[mid], f);
	nd->s[0] = build(arr, nl, mid - 1, nd);
	nd->s[1] = build(arr, mid + 1, nr, nd);
	nd->size = (nr - nl + 1);
	return nd;
}
};
int arr[MXN], tmp[MXN], org[MXN];
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
class SegmentTree {
public:
	Splay node[132000];
	void merge(int l, int mid, int r) {
		int a = l, b = mid + 1;
		int t = l;
		while (a <= mid && b <= r) {
			if (arr[a] < arr[b]) {
				tmp[t++] = arr[a++];
			} else {
				tmp[t++] = arr[b++];
			}
		}
		while (a <= mid) {
			tmp[t++] = arr[a++];
		}
		while (b <= r) {
			tmp[t++] = arr[b++];
		}
		memcpy(arr + l, tmp + l, (r - l + 1) * sizeof(int));
	}
	void build(int nd, int nl, int nr) {
		if (nl != nr) {
			int mid = nl + nr >> 1;
			build(ls[nd], nl, mid);
			build(rs[nd], mid + 1, nr);
			merge(nl, mid, nr);
		}
		node[nd].root = node[nd].build(arr, nl, nr);
	}
	void clear(int n) {
		pidx = 0;
	}
	void find(int nd, int nl, int nr, int l, int r, Splay*arr[], int &idx) {
		if (l <= nl && r >= nr) {
			arr[idx++] = &node[nd];	
			return;
		}
		int mid = nl + nr >> 1;
		if (l <= mid) {
			find(ls[nd], nl, mid, l, r, arr, idx);
		}
		if (r > mid) {
			find(rs[nd], mid + 1, nr, l, r, arr, idx);
		}
	}
	void init(int n) {
		memcpy(org, arr, (n + 1) * sizeof(int));
		build(1, 1, n);
	}
	void change(int nd, int nl, int nr, int pos, int val) {
		//printf("%d e %d\n", nd, org[pos]);
		node[nd].erase(org[pos]);
		//printf("%d ins %d\n", nd, val);
		node[nd].insert(val);
		if (nl != nr) {
			int mid = nl + nr >> 1;
			if (mid < pos) {
				change(rs[nd], mid + 1, nr, pos, val);
			} else {
				change(ls[nd], nl, mid, pos, val);
			}
		}
		org[pos] = val;
	}
}tree;

struct _Main {
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
	Splay *node[50];
	int mn, mx;
	int org[MXN];
	int getans(int nl, int nr, int rk) {
		int idx = 0;
		tree.find(1, 1, n, nl, nr, node, idx);
		int l = mn, r = mx;
		int mid, sum;
		while (l < r) {
			sum = 0;
			mid = (l + r >> 1) + 1;
			for (int i = 0; i < idx && sum < rk; i++) {
				sum += node[i]->getsize(mid);
			}
			if (sum < rk) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		return l;
	}
	int n;
	char op[5];
	_Main () {
		int Tn;
		int Qn;
		int l, r, rk, pos, val;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			tree.clear(n);
			mx = -1; mn = 1e9;
			read(n); read(Qn);
			for (int i = 1; i <= n; i++) {
				read(arr[i]);
				mx = max(mx, arr[i]);
				mn = min(mn, arr[i]);
			}
			tree.init(n);
			for (int Q = 1; Q <= Qn; Q++) {
				scanf("%s", op);
				if (op[0] == 'Q') {
					read(l); read(r); read(rk);
					printf("%d\n", getans(l, r, rk));
				} else {
					read(pos); read(val);
					mx = max(mx, val); mn = min(mn, val);
					tree.change(1, 1, n, pos, val);
				}
			}
		}
	}
}ZOJ2112;

}
