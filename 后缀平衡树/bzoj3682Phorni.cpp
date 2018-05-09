using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
namespace OI {
typedef double lf;
const int INF = 0x3f3f3f3f;
struct Node {
	Node *s[2], *nxt;
	lf m[2], v;
	int val;
	inline void mark(lf l, lf r) {
		m[0] = l; m[1] = r; v = (l + r) / 2.0;
	}
}node[300010];
Node *lst;
inline Node* new_(int val) {
	static Node* now = node;
	now->val = val;
	now->nxt = lst;
	lst = now;
	++now;
	return lst;
}

struct SuffixBST {
	Node *root;
	SuffixBST() {
		root = new_(-INF);
		root->mark(0, 2);
	}
	void insert(int val) {
		Node *nd = root, *s;
		int spo;
		while (1) {
			spo = val == nd->val ? lst->v > nd->nxt->v : val > nd->val;
			if (nd->s[spo]) {
				nd = nd->s[spo];
			} else {
				s = nd->s[spo] = new_(val);
				break;
			}
		}
		s->m[spo] = nd->m[spo];
		s->m[spo ^ 1] = nd->v;
		s->v = (s->m[0] + s->m[1]) / 2.0;
	}
}suffix_tree;
int pos[500010];
int getmin(int a, int b) {
	return pos[a] == pos[b] ? (a < b ? a : b) : (node[pos[a]].v < node[pos[b]].v ? a : b);
}
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
struct SegTree {
	int node[1050000];
	int base;
	void init(int n) {
		for (base = 1; base < n + 2; base <<= 1);
		for (int i = 1; i <= n; i++) {
			node[base + i] = i;
		}
		for (int nd = base - 1; nd >= 1; nd--) {
			node[nd] = getmin(node[ls[nd]], node[rs[nd]]);
		}
	}
	void update(int nd) {
		int t, org = nd;
		for (nd = nd + base >> 1; nd; nd >>= 1) {
			t = node[nd];
			if ((node[nd] = getmin(node[ls[nd]], node[rs[nd]])) == t && t != org) {
				break;
			}
		}
	}
	int query(int s, int t) {
		int ret = s;
		for (s = s + base, t = t + base + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
			if (~s & 1) ret = getmin(ret, node[s ^ 1]);
			if ( t & 1) ret = getmin(ret, node[t ^ 1]);
		}
		return ret;
	}
}segtree;

struct _Main{
	char str[100005];
	char op[5];
	_Main() {
		int lstans = 0;
		int n, Qn, len, type, a, b;
		read(n); read(Qn); read(len); read(type);
		scanf("%s", str);
		for (int i = 1; i <= n; i++) {
			read(pos[i]);
		}
		for (int i = len - 1; i >= 0; i--) {
			suffix_tree.insert(str[i] - 'a');
		}
		segtree.init(n);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			if (op[0] == 'I') {
				read(a);
				suffix_tree.insert((a ^ lstans * type));//差点因为 +1 WA了
			} else
			if (op[0] == 'C') {
				read(a); read(b);
				pos[a] = b;
				segtree.update(a);
			} else {
				read(a); read(b);
				printf("%d\n", lstans = segtree.query(a, b));
			}
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
}bzoj3682;

}
