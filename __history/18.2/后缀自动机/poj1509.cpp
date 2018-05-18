using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

namespace OI {
const int MAXN = 20010;
struct Node {
	Node *s[26], *f;
	int mx, mn, id;
};

class SAM {
public:
	Node *root, *tail;
	Node pool[MAXN << 1];
	int idx;
	int left[MAXN << 1];
	Node *node(int mx, Node *src = 0) {
		Node* nd = &pool[idx];
		nd->mx = mx;
		nd->id = idx++;
		nd->f = 0;
		if (src) {
			memcpy(nd->s, src->s, 26 * sizeof(Node *));
		} else {
			memset(nd->s, 0, 26 * sizeof(Node *));
		}
		return nd;
	}
	
	void init() {
		idx = 0;
		tail = root = node(0);
	}
	void ref(Node *nd, Node *f) {
		nd->mn = f->mx + 1;
		nd->f = f;
	}
	void insert(int c) {
		Node *nd = node(tail->mx + 1);
		left[nd->id] = nd->mx;
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
		left[nf->id] = left[s->id];
		ref(nf, s->f);
		ref(s, nf);
		ref(nd, nf);
		while (f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
	}
	int dfs(int len) {
		Node *nd = root;
		while (len) {
			for (int i = 0; i < 26; i++) {
				if (nd->s[i]) {
					nd = nd->s[i];
					break;
				}
			}
			len--;
		}
		return left[nd->id];
	}
}sam;
struct _Main {
	char buf[MAXN];
	_Main() {
		int i, j, k;
		int Q, Qn;
		int len;
		scanf("%d", &Qn);
		for (Q = 1; Q <= Qn; Q++) {
			scanf("%s", buf);
			len = strlen(buf);
			memcpy(buf + len, buf, (len - 1) * sizeof(char));
			sam.init();
			for (i = 0; i < len + len - 1; i++) {
				sam.insert(buf[i] - 'a');
			}
			printf("%d\n", sam.dfs(len) - len + 1);
		}
	}
	
}poj1509;



}

