using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

namespace OI {
const int 
	MAXN = 600010,
	MAXLEN = 600005,
	INF = 0x3f3f3f3f
	;
typedef double lf;
typedef long long lld;
int lrand() {
	return rand() & ((1 << 30) - 1);
}
inline lld mul(lld a, lld b, lld mod) {
	lld ret = (a * b - (lld)((lf)a / mod * b) * mod) % mod;
	if (ret < 0) {
		ret += mod;
	}
	return ret;
}

const int HASH_CNT = 1;
const lld mod[HASH_CNT] = {31525197391593467LL/*, 31525197391593473LL*/};
const lld base[HASH_CNT] = {31/*, 41*/};
lld pow[HASH_CNT][MAXN];
struct Hash {
	lld hash[HASH_CNT];
	void zero() {
		memset(this, 0, sizeof(Hash));
	}
	bool operator == (const Hash &b) const {
		return memcmp(this, &b, sizeof(Hash)) == 0;
	}
	
	void operator -= (const Hash &b) {
		for (int i = 0; i < HASH_CNT; i++) {
			hash[i] = hash[i] - b.hash[i];
			if (hash[i] < 0) {
				hash[i] += mod[i];
			}
		}
	}
	void operator += (int val) {
		for (int i = 0; i < HASH_CNT; i++) {
			hash[i] = (hash[i] + (val + base[i] - 1) % (base[i] - 1) + 1) % mod[i];
		}
	}
	void operator <<= (int bit) {
		for (int i = 0; i < HASH_CNT; i++) {
			hash[i] = mul(hash[i], pow[i][bit], mod[i]);
		}
	}
};

Hash qhash[600010], thash[600010];
int mxpow;
void insertHash(Hash &nd, int val) {
	nd = *(&nd + 1);
	nd <<= 1;
	nd += val;
}

void initHash(char *buf, Hash hash[], int len) {
	for (int i = len - 1; i >= 0; i--) {
		insertHash(hash[i], buf[i]);
	}
}
Hash getHash(Hash hash[], int l, int r) {
	Hash ret = hash[l];
	Hash minus = hash[r + 1];
	minus <<= r + 1 - l;
	ret -= minus;
	return ret;
}
int match(Hash a[], Hash b[], int mnlen) {
	int l = 0, r = mnlen, mid;
	while (l < r) {
		mid = (l + r >> 1) + 1;
		if (getHash(a, 0, mid - 1) == getHash(b, 0, mid - 1)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

struct Node {
	Node *s[2], *f, *nxt;
	lf m[2], v;
	int idx, rand, val, size;
	void mark(lf a, lf b) {
		m[0] = a; m[1] = b; v = (a + b) / 2.0;
	}
};

class SuffixTreap {
public:
	Node *root, *head;
	Node pool[MAXN];
	char str[MAXN];
	int pidx;
	Node *node(int val, Node *f = 0) {
		Node *nd = &pool[pidx++];
		nd->val = val;
		nd->idx = hidx;
		str[hidx] = val;
		nd->rand = lrand();
//		printf("%d rand = %d\n", pidx - 1, nd->rand);
		nd->f = f;
		nd->nxt = head;
		head = nd;
		nd->size = 1;
		return nd;
	}
	int hidx;
	SuffixTreap() {
		hidx = MAXLEN - 1;
		root = node(-1);
		root->mark(0, 1);
		thash[hidx] += -1;
	}
	void update(Node *nd) {
		nd->size = 1;
		for (int i = 0; i < 2; i++) {
			nd->size += nd->s[i] ? nd->s[i]->size : 0;
		}
	}
	int cmp(Node *nd, int val) {
		if (val != nd->val) {
			return val > nd->val;
		}
		return head->v > nd->nxt->v;
	}
	void rotate(Node *nd) {
		Node *f = nd->f, *gf = f->f, *s;
		nd->f = gf;
		if (gf) {
			gf->s[gf->s[1] == f] = nd;
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
		hidx--;
		insertHash(thash[hidx], c);
		Node *nd = root;		
		while (1) {
			nd->size++;
			int pos = cmp(nd, c);
			if (nd->s[pos]) {
				nd = nd->s[pos];
			} else {
				nd = nd->s[pos] = node(c, nd);
				break;
			}
		}
		while(nd->f && nd->rand > nd->f->rand) {
			rotate(nd);
		}
		mark_new(nd);
	}
	void mark_new(Node *nd) {
		lf m[2] = {0, 1};
		Node *f = nd->f;
		if (f) {
			int pos = nd == f->s[1];
			m[pos] = f->m[pos];
			m[pos ^ 1] = f->v;
		} else {
			root = nd;
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
		Node *nd = root;
		int m;
		int mnlen;
		int ret = 0;
		while (nd) {
			mnlen = min(MAXLEN - nd->idx, len);
			m = match(qhash, &thash[nd->idx], mnlen);
//			printf("match %lld = %d\n", nd - pool, m);
			if (m == mnlen || str[nd->idx + m] < buf[m]) {
//				printf("+= %d\n", 1 + (nd->s[0] ? nd->s[0]->size : 0));
				ret += 1 + (nd->s[0] ? nd->s[0]->size : 0);
				nd = nd->s[1];
			} else {
				nd = nd->s[0];
			}
		}
//		printf("ret %d\n", ret);
		return ret;
	}
}tree;



struct _Main {

	void decode(char buf[], int len, int mask) {
		for (int i = 0; i < len; i++) {
			mask = (mask * 131 + i) % len;
			swap(buf[i], buf[mask]);
		}
	}
	void rev(char str[], int len) {
		for (int i = 0; i < len >> 1; i++) {
			swap(str[i], str[len - i - 1]);
		}
	}
	char op[20];
	char buf[3000010];
	_Main() {
		int mask = 0;
		int i, j, k;
		int l, r;
		int Q, Qn;
		int len;
		int tot_len = 0;
		int ans;
		for (i = 0; i < HASH_CNT; i++) {
			pow[i][0] = 1;
		}
		mxpow = 0;
		scanf("%d", &Qn);
		for (Q = 0; Q <= Qn; Q++) {
			if (Q == 0) {
				op[0] = 'A'; 
				scanf("%s", buf);
				len = strlen(buf);
			} else {
				scanf("%s%s", op, buf);
				len = strlen(buf);
				decode(buf, len, mask);	
			}
			rev(buf, len);
			for (i = 0; i < len; i++) {
				buf[i] = buf[i] - 'A' + 1;
			}
			if (op[0] == 'A') {
				tot_len += len;
				while (mxpow < tot_len) {
					for (i = 0; i < HASH_CNT; i++) {
						pow[i][mxpow + 1] = base[i] * pow[i][mxpow] % mod[i];
					}
					mxpow++;
				}
				for (i = len - 1; i >= 0; i--) {
					tree.insert(buf[i]);
				}
				continue;
			} 
			ans = 0;
			if (len > tot_len) {
				goto EndFor;
			}
			qhash[len + 1].zero();
			buf[len] = -2;
			initHash(buf, qhash, len + 1);
			/*if (tot_len - len <= 6 * (log(tot_len) + log(len)) / (log(2.0) * log(2.0))) {
				Hash tmp = getHash(qhash, 0, len - 1);
				l = MAXLEN - 1 - len;
				r = l + len - 1;
				for (i = 0; i <= tot_len - len; i++) {
					if (tmp == getHash(thash, l, r)) {
						ans++;
					}
					l--; r--;
				}
			} else {*/
				buf[len] = -2;
				ans = tree.query(buf, len) - tree.query(buf, len + 1);
//			}
			EndFor:
			printf("%d\n", ans);
			mask ^= ans;
		}
		
	}

}bzoj2555;

}
