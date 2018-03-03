using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
namespace OI {
const int MAXN = 100005;
const int 
	NXT = 1,
	DST = 0,
	VAL = 2
;
int K;


struct Node {
	Node *s[26], *f;
	int mx, mn, id;
};
queue<Node *> sq, tq;
void push(Node *t, Node *s) {
	sq.push(s); tq.push(t);
}
struct Trie {
public:
	Node *root;
	Node node[MAXN];
	int idx;
	Node *new_() {
		Node *nd = &node[idx];
		nd->id = idx++;
		memset(nd->s, 0, 26 * sizeof(Node *));
		return nd;
	}
	void insert(char str[], int len) {
		Node *nd = root;
		for (int i = 0; i < len; i++) {
			if (nd->s[str[i]] == 0) {
				nd->s[str[i]] = new_();
			}
			nd = nd->s[str[i]];
		}
	}
	void init() {
		idx = 0;
		root = new_();
	}
}trie;

struct SAM {
	Node node[MAXN << 1];
	Node *root;
	int idx;
	Node *new_(int mx, Node *org = 0) {
		head[idx] = 0;
		Node *nd = &node[idx];
		nd->id = idx++;
		nd->mx = mx;
		if (org) {
			memcpy(nd->s, org->s, 26 * sizeof(Node *));
		} else {
			memset(nd->s, 0, 26 * sizeof(Node *));
		}
		return nd;
	}
	void init() {
		eidx = idx = 0;
		root = new_(0);
		now_id++;
	}
	int now_id;
	int head[MAXN << 1];
	int edge[MAXN * 54][3];
	int eidx;
	void add(int src, int dst, int val) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		edge[eidx][VAL] = val;
		head[src] = eidx;
	}
	int vis[MAXN << 1];
	int instk[MAXN << 1];
	void initmap() {
		for (int i = 0; i < idx; i++) {
			for (int j = 0; j < 26; j++) {
				if (node[i].s[j]) {
					add(i, node[i].s[j]->id, 1);
				}
			}
			if (i && node[i].f->mx >= K - 1) {
				add(i, node[i].f->id, 0);
			}
		}
	}
	
	int getloop(int nd) {
		instk[nd] = 1;
		vis[nd] = now_id;
		int t;
		int loop = 0;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (vis[t = edge[e][DST]] != now_id) {
				loop |= getloop(t);
			} else if(instk[t]) {
				loop = 1;
			}
			if (loop) break;
		}
		instk[nd] = 0;
		return loop;
	}
	int lvis[MAXN << 1];
	int mxlen[MAXN << 1];
	int getlen(int nd) {
		if (lvis[nd] != now_id) {
			lvis[nd] = now_id;
			mxlen[nd] = 0;
			for (int i = head[nd]; i; i = edge[i][NXT]) {
				mxlen[nd] = max(mxlen[nd], edge[i][VAL] + getlen(edge[i][DST]));
			}
		}
		
		return mxlen[nd];
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	Node *insert(Node *tail, int c) {
		Node *nd = new_(tail->mx + 1);
		tail->s[c] = nd;
		Node *f = tail->f;
		while (f && f->s[c] == 0) {
			f->s[c] = nd;
			f = f->f;
		}
		if (f == 0) {
			ref(nd, root);
			return nd;
		}
		Node *s = f->s[c];
		if (f->mx + 1 == s->mx) {
			ref(nd, s);
			return nd;
		}
		Node *nf = new_(f->mx + 1, s);
		ref(nf, s->f);
		ref(s, nf);
		ref(nd, nf);
		while (f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
		return nd;
	}
}sam;

struct _Main {
	void build() {
		Node *t, *s;
		while (!tq.empty()) {
			t = tq.front(); s = sq.front(); 
			tq.pop(); sq.pop();
			for (int i = 0; i < 26; i++) {
				if (t->s[i]) {
					push(t->s[i], sam.insert(s, i));
				}
			}
		}
	}
	char buf[MAXN];
	_Main() {
		int n;
		int i, j, k;
		while (~scanf("%d%d", &n, &K)) {
			sam.init();
			trie.init();
			for (i = 0; i < n; i++) {
				scanf("%s", buf);
				for (j = 0; buf[j]; j++) {
					buf[j] -= 'a';
				}
				trie.insert(buf, j);
			}
			push(trie.root, sam.root);
			build();
			sam.initmap();
			if (sam.getloop(sam.root->id)) {
				printf("INF\n");
			} else {
				printf("%d\n", max(sam.getlen(sam.root->id), K - 1));
			}
		}
	}


}ezoj1080;

}
