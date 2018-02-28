using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cassert>
namespace OI {
typedef long long lld;
typedef double lf;
const int 
	MAXN = 600010,
	MAXLEN = 600005
;

inline lld mul(lld a, lld b, lld mod) {
	lld ret = (a * b - (lld)((lf)a / mod * b) * mod) % mod;
	if (ret < 0) {
		ret += mod;
	}
	return ret;
}
const lld base[2] = {31, 41};
const lld mod[2] = {31525197391593467LL, (7LL << 52) + 1};
lld pow[2][MAXN];
struct Hash {
	lld hash[2];
	void operator -= (const Hash &b) {
		for (int i = 0; i < 2; i++) {
			hash[i] -= b.hash[i];
			if (hash[i] < 0) {
				hash[i] += mod[i];
			}
		}
	}
	void operator += (int val) {
		for (int i = 0; i < 2; i++) {
			hash[i] = (hash[i] + (val + base[i] - 1) % (base[i] - 1) + 1) % mod[i];
		}
	}
	void operator <<= (int bit) {
		for (int i = 0; i < 2; i++) {
			hash[i] = mul(hash[i], pow[i][bit], mod[i]);
		}
	}
	bool operator == (const Hash &b) const {
		return memcmp(this, &b, sizeof(Hash)) == 0;
	}
	void zero() {
		memset(this, 0, sizeof(Hash));
	}
};

Hash ths[MAXN], qhs[MAXN];

struct Node {
	Node *s[2], *f, *nxt;
	lf m[2], v;
	int val, idx, rand, size;
	void mark(lf l, lf r) {
		m[0] = l; m[1] = r; v = (l + r) / 2.0;
	}
};
Hash getHash(Hash a[], int r) {
	Hash ret = a[0];
	Hash minus = a[r + 1];
	minus <<= r + 1;
	ret -= minus;
	return ret;
}

int match(Hash a[], Hash b[], int mnlen) {
	int l = 0, r = mnlen, mid;
	while (l < r) {
		mid = (l + r >> 1) + 1;
		if (getHash(a, mid - 1) == getHash(b, mid - 1)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

class SuffixTreap {
public:
	Node pool[MAXN];
	int pidx;
	int hidx;
	Node *tail, *root;
	Node * node(int val, Node *f = 0) {
		Node *nd = &pool[pidx++];
		for (int i = 0; i < 2; i++) {
			pow[i][pidx] = (pow[i][pidx - 1] * base[i]) % mod[i];
		}
		nd->f = f;
		hidx--;
		nd->val = val;
		nd->idx = hidx;
		str[hidx] = val;
		nd->rand = rand();
//		printf("%d rand = %d\n", pidx - 1, nd->rand);
		nd->size = 1;
		nd->nxt = tail;
		tail = nd;
		ths[hidx] = ths[hidx + 1];
		ths[hidx] <<= 1;
		ths[hidx] += val;
		return nd;
	}
	
	char str[MAXN];
	SuffixTreap() {
		for (int i = 0; i < 2; i++) {
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
		nd->s[pos ^ 1] = f;
		f->f = nd;
		update(f);
		update(nd);
	}
	void insert(int c) {
		Node *nd = root;
		while (1) {
			int pos = cmp(c, nd);
//			printf("cmp %d %d = %d\n", c, nd - pool, pos);
			nd->size++;
			if (nd->s[pos]) {
				nd = nd->s[pos];
			} else {
				nd = nd->s[pos] = node(c, nd);
				break;
			}
		}
		while(nd->f && nd->f->rand > nd->rand) {
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
	void remark(Node *nd, lf l, lf r) {
		if (nd) {
			nd->mark(l, r);
			remark(nd->s[0], l, nd->v);
			remark(nd->s[1], nd->v, r);
		}
	}

	int query(char buf[], int len) {
		int ret = 0;
		Node *nd = root;
		while(nd) {
			int mnlen = min(len, MAXLEN - nd->idx);
			int m = match(qhs, ths + nd->idx, mnlen);
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
	char buf[3000010];
	char oper[20];
	void rev(char *str, int len ) {
		for (int i = 0; i < len >> 1; i++) {
			swap(str[i], str[len - i - 1]);
		}
	}
	void decode(char *str, int len, int mask) {
		for (int i = 0; i < len; i++) {
			mask = (mask * 131 + i) % len;
			swap(str[i], str[mask]);
		}
	}
	
	_Main() {
		int i, j, k;
		int a, b, c;
		int Q, Qn;
		int len;
		int mask = 0;
		int ans = 0;
		int tot_len = 0;
		scanf("%d", &Qn);
		for (Q = 0; Q <= Qn; Q++) {
			if (Q == 0) {
				oper[0] = 'A';
			} else {
				scanf("%s", oper);
			}
			scanf("%s", buf);
			len = strlen(buf);
			 
			if (Q) decode(buf, len, mask);
			rev(buf, len);
			for (i = 0; i < len; i++) {
				buf[i] = buf[i] - 'A' + 1;
			}
			if (oper[0] == 'A') {
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
			qhs[len + 1].zero();
			buf[len] = -2;
			for (i = len; i >= 0; i--) {
				qhs[i] = qhs[i + 1];
				qhs[i] <<= 1;
				qhs[i] += buf[i];
			}
//			printf("%d - %d\n", tree.query(buf, len), tree.query(buf, len + 1));
			ans = tree.query(buf, len) - tree.query(buf, len + 1);
			EndFor:
			printf("%d\n", ans);
			mask ^= ans;
		}
	}


}recode;


}
//交换行可能导致程序的拓扑序被破坏 
//swap不要换下标 
//检查node初始函数 
//root没有mark， 由于随机数的不同导致上一份root必然在第一个字符之后被换掉，所以没体现BUG
//任何剪枝一定要仔细确认不会造成意外影响 
 
