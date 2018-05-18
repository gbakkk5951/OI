using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
//#define debug
namespace OI {
typedef long long lld;
typedef double lf;
const int 
	MAXN = 600010,
	MAXLEN = 600005,
	HC = 1
;
const lld mod[HC + 2] = {31525197391593473LL, 31525197391593467LL};
const lld base[HC + 2] = {37, 47};
lld pow[HC][MAXN];
lld mul(lld a, lld b, lld mod) {
	lld ret = (a * b - (lld)((lf)a / mod * b) * mod) % mod;
	if (ret < 0) {
		ret += mod;
	}
	return ret;
}
struct Hash {
	lld hash[HC];
	void operator += (int c) {
		for (int i = 0; i < HC; i++) {
			hash[i] = (hash[i] + (c + base[i] - 1) % (base[i] - 1) + 1) % mod[i];
		}
	}
	void operator -= (const Hash &b) {
		for (int i = 0; i < HC; i++) {
			hash[i] = hash[i] - b.hash[i];
			if (hash[i] < 0) {
				hash[i] += mod[i];
			}
		}
	}
	void operator <<= (int bit) {
		for (int i = 0; i < HC; i++) {
			#ifdef debuf
			if (pow[i][bit] == 0) {
				printf("0000\n");
			}
			#endif
			hash[i] = mul(hash[i], pow[i][bit], mod[i]);
		}
	}
	void zero() {
		memset(this, 0, sizeof(Hash));
	}
	bool operator == (const Hash &b) {
		return memcmp(this, &b, sizeof(Hash)) == 0;
	}
};
Hash getHash(Hash a[], int len) {
	Hash minus = a[len];
	minus <<= len;
	Hash ret = a[0];
	ret -= minus;
	return ret;
}
int match(Hash a[], Hash b[], int mnlen) {
	int l = 0, r = mnlen, mid;
	#ifdef debug
	for (int I = 0; I < 2; I++) {
		printf("hs %d = ", I);
		for (int i = 0; i < mnlen; i++) {
			printf("%lld ", (I ? b[i].hash[0] : a[i].hash[0]));
		}
		printf("\n");
	}
	#endif
	while (l < r) {
		mid = (l + r >> 1) + 1;
		if (getHash(a, mid) == getHash(b, mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

Hash ths[MAXN], qhs[MAXN];

struct Node {
	Node *s[2], *f, *nxt;
	lf m[2], v;
	int val, rand, idx, size;
	void mark(lf a, lf b) {
		m[0] = a; m[1] = b; v = (a + b) / 2.0;
	}
};

class SuffixTreap {
public: 
	Node *root, *tail;
	Node p[MAXN];
	char str[MAXN];
	int pidx;
	int hidx;
	Node *node(int val, Node *f = 0) {
		--hidx;
		Node *nd = &p[pidx++];
		for (int i = 0; i < HC; i++) {
			pow[i][pidx] = pow[i][pidx - 1] * base[i] % mod[i];
		}
		nd->val = val;
		nd->f = f;
		nd->size = 1;
		nd->nxt = tail;
		tail = nd;
		nd->idx = hidx;
		str[hidx] = val;
		nd->rand = rand();
		ths[hidx] = ths[hidx + 1];
		ths[hidx] <<= 1;
		ths[hidx] += val;
		return nd;
	}
	
	SuffixTreap() {
		for (int i = 0; i < HC; i++) {
			pow[i][0] = 1;
		}
		hidx = MAXLEN;
		root = node(-1);
		root->mark(0, 1);
	}
	int cmp(int c, Node *nd) {
		if (c != nd->val) {
			return c > nd->val;
		}
		return tail->v > nd->nxt->v;
	}
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
	void insert(int c) {
		Node *nd = root;
		while (1) {
			int pos = cmp(c, nd);
			nd->size++;
			if (nd->s[pos]) {
				nd = nd->s[pos];
			} else {
				nd = nd->s[pos] = node(c, nd);
				break;
			}
		}
		while (nd->f && nd->f->rand > nd->rand) {
			rotate(nd);
		}
		lf m[2];
		Node *f = nd->f;
		if (f) {
			int pos = nd == f->s[1];
			m[pos] = f->m[pos];
			m[pos ^ 1] = f->v;
		} else {
			root = nd;
			m[0] = 0; m[1] = 1;
		}
		remark(nd, m[0], m[1]);
	}
	void remark(Node *nd, lf a, lf b) {
		if (nd) {
			nd->mark(a, b);
			remark(nd->s[0], a, nd->v);
			remark(nd->s[1], nd->v, b);
		}
	}
	int query(char buf[], int len) {
		int ret = 0;
		Node *nd = root;
		while (nd) {
			
			int mnlen = min(len, MAXLEN - nd->idx);
			int m = match(qhs, ths + nd->idx, mnlen);
			#ifdef debug
			printf("%lld match %d\n", nd - p, m);
			printf("l = %lld, r = %lld\n", nd->s[0] - p, nd->s[1] - p);
			#endif
			if (m == mnlen || buf[m] > str[nd->idx + m]) {
				#ifdef debug
				printf("+= %d\n", 1 + (nd->s[0] ? nd->s[0]->size : 0));
				#endif
				ret += 1 + (nd->s[0] ? nd->s[0]->size : 0);
				nd = nd->s[1];
			} else {
				nd = nd->s[0];
			}
		}
		#ifdef debug
		printf("ret %d\n", ret);
		#endif
		return ret;
	}
}tree;

struct _Main {
	void decode(char str[], int len, int msk) {
		for (int i = 0; i < len; i++) {
			msk = (msk * 131 + i) % len;
			swap(str[msk], str[i]);
		}
	}
	void rev(char str[], int len) {
		for (int i = 0; i < len >> 1; i++) {
			swap(str[i], str[len - i - 1]);
		}
	}
	char buf[3000010], op[20];
	_Main() {
		int i, j, k;
		int Q, Qn;
		int len, tot_len;
		int msk = 0;
		int ans;
		scanf("%d", &Qn);
		for (Q = 0; Q <= Qn; Q++) {
			if (Q == 0) {
				op[0] = 'A';
			} else {
				scanf("%s", op);
			}
			scanf("%s", buf);
			len = strlen (buf);
			if (Q) decode(buf, len, msk);
			for (i = 0; i < len; i++) {
				buf[i] = buf[i] - 'A' + 1;
			}
			rev(buf, len);
			if (op[0] == 'A') {
				tot_len += len;
				for (i = len - 1; i >= 0; i--) {
					tree.insert(buf[i]);
				}
				continue;
			}
			ans = 0;
			if (len > tot_len) {
				goto EndFor;
			}
			buf[len] = -2;
			qhs[len + 1].zero();
			for (i = len; i >= 0; i--) {
				qhs[i] = qhs[i + 1];
				qhs[i] <<= 1;
				qhs[i] += buf[i];
			}
			ans = tree.query(buf, len) - tree.query(buf, len + 1);
			EndFor:
			printf("%d\n", ans);
			msk ^= ans;
		}
	}

}bzoj2555;


}
