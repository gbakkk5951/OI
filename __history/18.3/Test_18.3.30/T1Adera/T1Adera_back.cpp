using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
namespace OI {
typedef long long lld;
const int MXN = 100010;
int n, Qn;
struct CNode {
	CNode *s[2],
	int sum, id, val;
}p1[MXN * 19], *null;
int pid1;
CNode * newc(int id) {
	CNode *nd = &p1[pid1++];
	nd->s[0] = nd->s[1] = null;
	nd->id = id;
	return nd;
}

struct ChairTree {
typedef CNode Node;
	ChairTree() {
		null = new_(0);
		null->s[0] = null->s[1] = null;
	}
	Node *stk[20];
	inline void update(Node *nd) {
		nd->sum = nd->s[0]->sum + nd->s[1]->sum;
	}
	void insert(Node *root, int id, int pos, int val) {
		int nl = 1, nr = n, mid, spo, top = 0;
		Node *nd = root, *org = root;
		while (nl < nr) {
			stk[++top] = nd;
			mid = nl + nr >> 1;
			if (spo = pos > mid) {
				nl = mid + 1;
			} else {
				nr = mid;
			}
			if (nd->s[spo ^ 1] == null) {
				nd->s[spo ^ 1] = org->s[spo ^ 1];
			}
			if (nd->s[spo]->id != id) {
				nd->s[spo] = newc(id);
			}
			nd = nd->s[spo];
			org = org->s[spo];
		}
		if (nd->val == 0) {
			nd->val = val;
			nd->sum = 1;
			for (int i = top; i >= 1; i--) {
				update(stk[i]);
			}
		}
	}
	void merge(Node *nd, Node *a, Node *b, int id, int nl, int nr) {
		if (nl == nr) {
			nd->val = a->val | b->val;
			nd->sum = 1;
			return;
		}
		Node *as;
		int mid = nl + nr - 1;
		for (int i = 0; i < 2; i++) {
			if (a->s[i] == null) {
				nd->s[i] = b->s[i];
				continue;
			}
			if (b->s[i] == null) {
				nd->s[i] = a->s[i];
				continue;
			}
			as = a->s[i];
			if (nd->s[i]->id != id) {
				nd->s[i] = new_(id);
			}
			if (i) {
				merge(nd->s[i], as, b->s[i], id, mid + 1, nr);	
			} else {
				merge(nd->s[i], as, b->s[i], id, nl, mid);	
			}
		} 
		update(nd);
	}
	void print() {
		
	}
}ctree;

struct TNode {
	TNode *s[26];
	CNode *root;
	int id;
	vector<int> tag;
};

struct Trie {
typedef TNode Node;
	Node pool[MXN];
	int pidx;
	Node *newt() {
		Node *nd = &pool[pidx++];
		nd->id = pidx;
		return nd;
	}
	Node *root;
	Trie() {
		root = newt();
	}
	void insert(int id, char str[]) {
		Node *nd = root;
		for (int i = 0; str[i]; i++) {
			if (nd->s[str[i] - 'a'] == 0) {
				nd->s[str[i] - 'a'] = newt();
			}
			nd = nd->s[str[i] - 'a'];
		}
		nd->tag.push_back(id);
	}
	void build(Node *nd) {
		nd->root = newc();
		for (int i = 0; i < nd->tag.size(); i++) {
			ctree.insert(nd->root, nd->id, rk[nd->tag[i]], nd->tag[i]);
		}
		for (int i = 0; i < 26; i++) {
			if (nd->s[i]) {
				build(nd->s[i]);
				ctree.merge(nd->root, nd->root, nd->s[i]->root, nd->id, 1, n);
			}
		}
	}
	Node *get(char str[]) {
		Node *nd = root;
		for (int i = 0; str[i]; i++) {
			if (nd->s[str[i] - 'a']) {
				nd = nd->s[str[i] - 'a'];
			} else {
				return 0;
			}
		}
		return nd;
	}
}trie;
struct _Main() {
	char str[MXN];
	void prepro() {
		
	}
	void solve() {
		int t, tot;
		TNode *nd;
		for (int Q = 1; Q <= Qn; Q++) {
			read(t); scanf("%s", str);
			nd = trie.get(str);
			if (nd == 0) {
				printf("0\n");
				continue;
			}
			tot = nd->root->sum;
			t = min(t, tot);
			printf("%d\n", tot);
			if (tot) {
				ctree.print(nd->root, tot);
			}
			printf("\n");
		}
	}
	_Main() {
		prepro();
		solve();
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
}

}
