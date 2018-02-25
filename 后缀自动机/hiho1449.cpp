using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
const int 
	MAXN = 1000010,
	ALPHA_SIZE = 26,
	DST = 0,
	NXT = 1
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
			memcpy(this->s, org->s, ALPHA_SIZE * sizeof(int));
		}
		return nd;
	}
	void ref(Node *nd, Node *f) {
		nd->mn = f->mx + 1;
		nd->f = f;
	}
	
	SAM() {
		tail = root = node(mx, 0);
	}
	void insert(char c) {
		Node *nd = node(tail->mx + 1, 1);
		Node *f = tail->f;
		tail = nd;
		while (f && f->s[c] == 0) {
			f->s[c] = nd;
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
		Node *nf = node(s->mx + 1, 0, s);
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
	int head[MAXN << 1];
	int edge[MAXN << 1][2];
	int in[MAXN << 1];
	int cnt[MAXN];
	int right[MAXN];
	int eidx;
	int len;
	void getCnt() {
		int i;
		for (i = 1; i < sam.pidx; i++) {
			add(i, sam.pool[i]->f - pool);
		}
		for (i = 1; i < sam.pidx; i++) {
			if (in[i] == 0) {
				topo(i);
			}
		}
		for (i = 1; i < sam.idx; i++) {
			cnt[pool[i].mx] = max(cnt[pool[i].mx], right[i]);
		}
		for (i = len; i >= 1; i--) {
			cnt[i] = max(cnt[i], cnt[i + 1]);
		}
	}
	void topo(int nd) {
		in[nd] = -1;
		int i, t;
		right[nd] += sam.pool[nd].is_pre;
		for (i = head[nd]; i; i = edge[i][NXT]) {
			right[t = edge[i][DST]] += right[nd];
			if (--in[t] == 0) {
				topo(t);
			}
		}
	}
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
		in[b]++;
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
			printf("%d\n", cnt[i]);
		}
	}


}hiho1449;
}
