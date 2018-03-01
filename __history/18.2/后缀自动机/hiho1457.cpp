using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <algorithm>
namespace OI {
typedef long long lld;
const int 
	MAXN = 2000010,
	MOD = 1e9 + 7,
	ALPHA_SIZE = 11
;
struct Node {
	Node *s[11], *f;
	int mx, mn, idx, val;
};

class SAM {
public:
	Node *root, *tail;
	Node pool[MAXN << 1];
	int in[MAXN << 1];
	lld sum[MAXN << 1];
	lld cnt[MAXN << 1];
	int pidx;
	lld ans;
	SAM() {
		tail = root = node(0, -1);
	}
	
	Node *node(int mx, int val, Node *org = 0) {
		Node *nd = &pool[pidx];
		nd->idx = pidx++;
		nd->mx = mx;
		nd->val = val;
		if (org) {
			memcpy(nd->s, org->s, ALPHA_SIZE * sizeof(Node *));
		}
		return nd;
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	void insert(int c) {
		Node *nd = node(tail->mx + 1, c);
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
		Node *nf = node(f->mx + 1, c, s);
		ref(nf, s->f);
		ref(s, nf);
		ref(nd, nf);
		while (f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
	}
	void topo(int id) {
		in[id] = -1;
		Node *nd = &pool[id];
		int t;
		for (int i = 0; i < 10; i++) {
			if (nd->s[i]) {
				t = nd->s[i]->idx;
				cnt[t] = (cnt[t] + cnt[id]) % MOD;
				sum[t] = (sum[t] + (sum[id] * 10LL + i * cnt[id]) % MOD) % MOD;
				if (--in[t] == 0) {
					topo(t);
				}
			}
		}
		ans = (ans + sum[id]) % MOD;
	}
	
	lld getAns() {
		Node *t;
		for (int i = 0; i < pidx; i++) {
			for (int j = 0; j < 10; j++) {
				if (t = pool[i].s[j]) {
					in[t->idx]++;
				}
			}
		}
		cnt[0] = 1;
		for (int i = 0; i < pidx; i++) {
			if (in[i] == 0) {
				topo(i);
			}
		}
		return ans;
	}
}sam;

struct _Main {
	char buf[MAXN];
	_Main() {
		int n, len, i, j, k, tmp;
		len = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			scanf("%s", buf + len);
			tmp = strlen(buf + len);
			len += tmp;
			buf[len++] = '0' + 10;
		}
		for (i = 0; i < len; i++) {
			sam.insert(buf[i] - '0');
		}
		printf("%lld", sam.getAns());
	}

}hiho1457;

}

//即使对答案贡献为0，为了保证算法的运行，也不能剪掉（除非去除地彻底） 
