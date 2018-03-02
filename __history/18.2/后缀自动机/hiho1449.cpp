using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
const int 
	MAXN = 1000010,
	ALPHA_SIZE = 26
;


struct Node {
	Node *s[ALPHA_SIZE], *f;
	int mx, mn, is_pre;
};
class SAM {
public:
	Node pool[MAXN << 1];
	int pidx;
	Node *root, *tail;
	Node *node(int mx, int is_pre, Node *org = 0) {
		Node *nd = &pool[pidx++];
		nd->mx = mx;
		nd->is_pre = is_pre;
		if (org) {
			memcpy(nd->s, org->s, ALPHA_SIZE * sizeof(Node *));
		}
		return nd;
	}
	void ref(Node *nd, Node *f) {
		nd->mn = f->mx + 1;
		nd->f = f;
	}
	SAM() {
		tail = root = node(0, 0);
	}
	void insert(int c) {
		Node *nd = node(tail->mx + 1, 1);
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
		Node *nf = node(f->mx + 1, 0, s);
		ref(nf, s->f);
		ref(s, nf);
		ref(nd, nf);
		while (f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
	}
}sam;

struct _Main {
	char buf[MAXN];
	int cnt[MAXN];
	int f[MAXN << 1];
	int in[MAXN << 1];
	int right[MAXN << 1];
	int len;
	void getCnt() {
		int i;
		for (i = 1; i < sam.pidx; i++) {
			f[i] = sam.pool[i].f - sam.pool;
			in[f[i]]++;
		}
		for (i = 1; i < sam.pidx; i++) {
			if (in[i] == 0) {
				topo(i);
			}
		}
		for (i = 1; i < sam.pidx; i++) {
			cnt[sam.pool[i].mx] = max(cnt[sam.pool[i].mx], right[i]);
		}
		for (i = len; i >= 1; i--) {
			cnt[i] = max(cnt[i], cnt[i + 1]);
		}
	}
	void topo(int nd) {
		in[nd] = -1;
		int i;
		right[nd] += sam.pool[nd].is_pre;
		right[f[nd]] += right[nd];
		if (--in[f[nd]] == 0) {
			topo(f[nd]);
		}
	}
	_Main() {
		int i, j, k;
		scanf("%s", buf);
		for (i = 0; buf[i]; i++) {
			sam.insert(buf[i] - 'a');
		}
		len = i;
		getCnt();
		for (i = 1; i <= len; i++) {
			if (i > 1) {
				puts("");
			}
			printf("%d", cnt[i]);
		}
	}


}hiho1449;
}
