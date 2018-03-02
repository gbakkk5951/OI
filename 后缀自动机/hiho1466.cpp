using namespace std;
int main() {}
#include <cstdio>
#include <cstring> 
#include <cstdlib>

namespace OI {
typedef long long lld;
const int MAXN = 100010;

struct Node {
	Node *f, *s[26];
	int id, mx, mn;
};
class SAM {
public:
	Node pool[MAXN << 1];
	int pidx;
	int sg[MAXN << 1];
	int vis[MAXN << 1];
	lld sum[MAXN << 1][27];
	Node *root, *tail;
	Node *node(int mx, Node* org = 0) {
		Node *nd = &pool[pidx++];
		nd->mx = mx;
		nd->id = pidx - 1;
		if (org) {
			memcpy(nd->s, org->s, 26 * sizeof(Node *));
		}
		return nd;
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	SAM() {
		tail = root = node(0);
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
	void getSum(int id = 0) {
		Node *nd = &pool[id];
		int t;
		for (int i = 0; i < 26; i++) {
			if (nd->s[i]) {
//				printf("%d ->s[%d] = %d\n", id, i, nd->s[i]->id);
				if (!vis[t = nd->s[i]->id]) {
					getSum(t);
				}
				vis[id] |= 1 << sg[t];
				for (int j = 0; j < 27; j++) {
					sum[id][j] += sum[t][j];
				}
			}
		}
		for (int i = 0; i < 27; i++) {
			if (!(vis[id] & (1 << i))) {
				sg[id] = i;
				break;
			}
		}
//		printf("sg[%d] = %d\n", id, sg[id]);
		sum[id][sg[id]]++;
		/*for (int i = 0; i < 4; i++) {
			printf("sum[%d][%d] = %lld\n", id, i, sum[id][i]);
		}*/
		vis[id] = 1;
	}
}a, b;


struct _Main {
	char buf[MAXN];
	char out[MAXN];
	lld sum[35];
	_Main() {
		lld k;
		scanf("%lld", &k);
		scanf("%s", buf);
		for (int i = 0; buf[i]; i++) {
			a.insert(buf[i] - 'a');
		}
		scanf("%s", buf);
		for (int i = 0; buf[i]; i++) {
			b.insert(buf[i] - 'a');
		}
		a.getSum(); b.getSum();
		lld tot = 0;
		for (int i = 0; i < 27; i++) {
			tot += b.sum[b.root->id][i];
		}
		for (int i = 0; i < 27; i++) {
			sum[i] = tot - b.sum[b.root->id][i];
//			printf("sum[%d] = %lld\n", i, sum[i]);
		}
		
		int len = 0;
		lld rem = k, t;;
		Node *nd = a.root;
		int sg;
		while (1) {
			t = a.sg[nd->id];
			if (sum[t] >= rem) {
				sg = t;
				break;
			}
			rem -= sum[t];
//			printf("nd = %lld, rem = %lld\n", nd - a.pool, rem);
			int i;
			for (i = 0; i < 26; i++) {
				if (nd->s[i]) {
					int id = nd->s[i]->id;
					lld r = rem;
					int j;
					for (j = 0; j < 27; j++) {
						if (sum[j] && a.sum[id][j]) {
							if ((r + sum[j] - 1) / sum[j] <= a.sum[id][j]) {
								break;
							} else {
								r -= sum[j] * a.sum[id][j];
							}
						}
					}
					if (j < 27) {
						out[len++] = i + 'a';
						nd = nd->s[i];
						break;
					} else {
						rem = r;
					}
				}
			}
			if (i == 26) {
				printf("NO");
				return;
			}
		}
//		printf("sg = %d\n", sg);
		
		out[len] = '\0';
		printf("%s\n", out);
		len = 0;
		nd = b.root;
		while (1) {
			rem -= b.sg[nd->id] != sg;
//			printf("nd = %lld rem = %lld\n", nd - b.pool, rem);
			if (rem == 0) break;
			for (int i = 0; i < 26; i++) if (nd->s[i]) {
				tot = 0;
				t = nd->s[i]->id;
				for (int j = 0; j < 27; j++) if(j != sg) {
					tot += b.sum[t][j];
				}
				
				if (tot >= rem) {
					nd = nd->s[i];
					out[len++] = 'a' + i;
					break;
				}
//				printf("tot %d = %lld\n", i, tot);
				rem -= tot;
			}
		}
		out[len] = '\0';
		printf("%s\n", out);
	}
}hiho1466;


}
