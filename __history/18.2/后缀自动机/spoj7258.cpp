using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <algorithm>

namespace OI {
const int 
	MAXN = 100000
;

struct Node {
	Node *s[26], *f;
	int mx, mn, id;
};
class SAM {
public:
	Node *root, *tail;
	Node pool[MAXN << 1];
	int size[MAXN << 1];
	int vis [MAXN << 1];
	int idx;
	Node *node(int mx, Node *o = 0) {
		Node *nd = &pool[idx];
		nd->id = idx++;
		nd->mx = mx;
		if (o) {
			memcpy(nd->s, o->s, 26 * sizeof(Node *));
		}
		return nd;
	} 
	SAM() {
		root = tail = node(0);
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	void insert(int c) {
		Node *nd = node(tail->mx + 1);
		tail->s[c] = nd;
		Node *f = tail->f;
		tail = nd;
		while (f && f->s[c] == 0) {
			f->s[c] = nd;
			f = f->f;
		}
		if (f == 0) {
			ref(nd, root);
			return;
		}
		Node *s = f->s[c];
		if (f->mx + 1 == s->mx) {
			ref(nd, s);
			return;
		}
		Node *nf = node(f->mx + 1, s);
		ref(nf, s->f);
		ref(s, nf);
		ref(nd, nf);
		while (f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
	}
	void dfs(int id) {
		int t;
		Node *nd = &pool[id];
		vis[id] = 1;
		size[id] = 1;
		for (int i = 0; i < 26; i++) {
			if (nd->s[i]) {
				if (!vis[t = nd->s[i]->id]) {
					dfs(t);
				}
				size[id] += size[t];
			}
		}
	}
	void getSize() {
		dfs(0);
	}
	
	void getStr(int rem) {
		Node *nd = root;
		while (rem) {
			for (int i = 0; i < 26; i++) {
				if (nd->s[i]) {
					if (rem <= size[nd->s[i]->id]) {
						putchar('a' + i);
						rem--;
						nd = nd->s[i];
						break;
					} else {
						rem -= size[nd->s[i]->id];
					}
				}
			}
		}
	}
}sam;

struct _Main {
	char buf[MAXN];
	_Main() {
		int a, b, c;
		int i, j, k;
		int len;
		scanf("%s", buf);
		len = strlen(buf);
		for (i = 0; i < len; i++) {
			sam.insert(buf[i] - 'a');
		}
		sam.getSize();
		int Qn, Q;
		scanf("%d", &Qn);
		for (Q = 1; Q <= Qn; Q++) {
			scanf("%d", &a);
			sam.getStr(a);
			putchar('\n');
		}
	}
}spoj7258;

}
