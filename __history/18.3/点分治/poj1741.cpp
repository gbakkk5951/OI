using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <cstring>

namespace OI {
typedef long long lld;
const int MXN = 10050;
struct Node {
	Node *s[2], *f;
	int sum, val, cnt;
};
struct Splay {
	Node pool[MXN], *null;
	int pidx;
	Node *new_(int val, Node *f) {
		Node *nd = &pool[pidx++];
		nd->s[0] = nd->s[1] = null;
		nd->f = f;
		nd->val = val;
		nd->sum = nd->cnt = 1;
		return nd;
	}
	
	Node *root;
	
	Splay() {
		init();
	}
	void init() {
		pidx = 0;
		null = new_(-1, 0);
		null->s[0] = null->s[1] = null->f = null;
		null->sum = null->cnt = 0;
		root = null;
	}
	void update(Node *nd) {
		nd->sum = nd->cnt;
		for (int i = 0; i < 2; i++) {
			nd->sum += nd->s[i]->sum;
		}
	}
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (gf != null) {
			gf->s[f == gf->s[1]] = nd;
		}
		int pos = nd == f->s[1];
		s = f->s[pos] = nd->s[pos ^ 1];
		if (s != null) {
			s->f = f;
		}
		nd->s[pos ^ 1] = f;
		f->f = nd;
		update(f);
		update(nd);
	}
	void splay(Node *nd) {
		Node *f = nd->f;
		//update(nd); //本身不是根所以不必要
		while ((f = nd->f) != null) {
			if (f->f != null) {
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
		if (root == null) {
			root = new_(val, null);
			return;
		}
		Node *nd = root;
		int spo;
		while (1) {
			if (nd->val == val) {
				nd->cnt++;
				break;
			}
			spo = val > nd->val;
			if (nd->s[spo] != null) {
				nd = nd->s[spo];
			} else {
				nd = nd->s[spo] = new_(val, nd);
				break;
			}
		}
		splay(nd);
	} 
	int getsize(int val) {
		int ret = 0;
		Node *nd = root, *lst;
		while (nd != null) {
			lst = nd;
			if (nd->val <= val) {
				ret += nd->s[0]->sum + nd->cnt;
				nd = nd->s[1];
			} else {
				nd = nd->s[0];
			}
		}
		splay(lst);
		return ret;
	}
	
}tree;
const int DST = 1, NXT = 0, VAL = 2;
struct Nodediv{
	int ans;
	int tot;
	int head[MXN], edge[MXN << 1][3];
	int eidx;
	void add(int src, int dst, int val) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][VAL] = val;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	int mark[MXN], deep[MXN], size[MXN];
	int chose, val;
	int mxlen;
	void clear() {
		memset(mark, 0, (eidx / 2 + 2) * sizeof(int)); //n-1条边 所以要+2 
		memset(head, 0, (eidx / 2 + 2) * sizeof(int));
		ans = eidx = 0;
	}
	void getsize(int nd, int fa) {
		size[nd] = 1;
		int mx = 0, t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				getsize(t, nd);
				size[nd] += size[t];
				mx = max(mx, size[t]);
			}
		}
		mx = max(mx, tot - size[nd]);
		if (mx < val) {
			chose = nd;
			val = mx;//没更新val 
		}
	}
	void getdeep(int nd, int fa, int dis, int &idx) {
		deep[idx++] = dis;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				getdeep(t, nd, dis + edge[e][VAL], idx);
			}
		}
	}
	void calc(int nd, int _tot) {
		if (_tot <= 1) return;
		tot = _tot;
		val = 1e9;
		getsize(nd, 0);
		nd = chose;
		getsize(nd, 0);
		mark[nd] = 1;
		int t, idx;
		tree.init();
		tree.insert(0);
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t]) {
				getdeep(t, nd, edge[e][VAL], idx = 0);
				for (int i = 0; i < idx; i++) {
					if (deep[i] <= mxlen)
					ans += tree.getsize(mxlen - deep[i]);
				}
				for (int i = 0; i < idx; i++) {
					if (deep[i] < mxlen) {
						tree.insert(deep[i]);
					}
				}
			}
		}
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t]) {
				calc(t, size[t]);
			}
		}
	}
}nodediv;


struct _Main {
	int n, mxlen;
	int prepro() {
		int a, b, c;
		nodediv.clear();
		read(n); read(mxlen);
//		n = 10000; mxlen = 5000;
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
//			a = rand() % i + 1;
//			c = rand() % 5000; 
			nodediv.add(a, b, c);
			nodediv.add(b, a, c);
		}
		nodediv.mxlen = mxlen;
		return n != 0 || mxlen!= 0;
	}
	void solve() {
		nodediv.calc(1, n);
		printf("%d\n", nodediv.ans);
	}
	_Main() {
		while (prepro()) {
			solve();
		}
	}
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
}poj1741;
}
