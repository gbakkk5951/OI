using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
namespace OI {
typedef long long lld;
const int 
	MAXN = 2000010,
	ALPHA_SIZE = 26
;
struct Node {
	Node *s[ALPHA_SIZE], *f;
	int mn, mx;
};
class SAM {
public:
	Node *root, pool[MAXN];
	int pidx;
	Node *tail;
	Node* node(int mx, Node *org = 0) {
		Node *nd = &pool[pidx++];
		nd->mx = mx;
		if (org) {
			memcpy(nd->s, org->s, ALPHA_SIZE * sizeof(Node *));
		}
		return nd;
	}
	SAM() {
		tail = root = node(0);
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	void insert(char c) {
		Node *nd = tail->s[c] = node(tail->mx + 1);
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
		if (s->mx == f->mx + 1) {
			ref(nd, s);
			return;
		}
		Node *nf = node(f->mx + 1, s);
		ref(nf, s->f);
		ref(nd, nf);
		ref(s, nf);
		while(f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
	}
	lld calc() {
		int i;
		lld ret = 0;
		for (i = 0; i < pidx; i++) {
			ret += pool[i].mx - pool[i].mn + 1;
		}
		return ret - 1;
	}
}sam;

struct _Main {
	char buf[1000010];
	_Main() {
		scanf("%s", buf);
		int i;
		for (i = 0; buf[i]; i++) {
			sam.insert(buf[i] - 'a');
		}
		printf("%lld", sam.calc());
	}
}hiho1445;


}
