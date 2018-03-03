using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
namespace OI {
typedef long long lld;
const int 
	MAXN = 100010,
	NXT = 1,
	DST = 0
	;
int cnt;
struct Node {
	Node *f, *s[10];
	int mx, id, mn;
};

Node node[MAXN * 40];
int idx;
queue<Node *>q;
Node *new_(int mx = 0, Node *org = 0) {
	Node *nd;
	if (!q.empty()) {
		nd = q.front();
		q.pop();
		if (org == 0) memset(nd->s, 0, cnt * sizeof(Node *));
	} else {
		nd = &node[idx];
		nd->id = idx++;
	}
	nd->mx = mx;
	if (org) {
		memcpy(nd->s, org->s, cnt * sizeof(Node *));
	}
	return nd;
}
void erase(Node *nd) {
	q.push(nd);
}
class SAM {
public:
	Node *root;
	SAM() {
		root = new_();
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	Node* insert(Node *tail, int c) {
//		printf("ins %d %d\n", tail->id, c);
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
	int vis[MAXN * 40];
	lld getAns(Node *nd) {
		vis[nd->id] = 1;
		lld ans = 0;
		Node *s;
		for (int i = 0; i < cnt; i++) if (s = nd->s[i]) {
			if (!vis[s->id]) {
				ans += getAns(s);
			}
		}
		ans += nd->mx - nd->mn + (nd != root);
		return ans;
	}
}sam;


struct Trie {
	Node *root;
	Trie() {
		root = new_();
	}
	int insert(int f, int c) {
		if (node[f].s[c] == 0) {
			node[f].s[c] = new_();
		}
		return node[f].s[c]->id;
	}
}trie;


struct _Main {
	template <typename Type>
		void read(Type &a) {
			char t;
			while (!isdigit(t = getchar()));
			a = t - '0';
			while ( isdigit(t = getchar())) {
				a *= 10;
				a += t - '0';
			}
		}
	void dfs(int nd, int tid, int fa) {
		int t;
//		printf("dfs %d %d %d\n", nd, tid, fa);
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if ((t = edge[e][DST]) != fa) {
				dfs(t, trie.insert(tid, c[t]), nd);
			}
		}
	}
	queue <Node *>trieq, samq;
	void build() {
		Node *nd, *f;
		while (!trieq.empty()) {
			nd = trieq.front();
//			printf("nd = %d\n", nd->id);
			f = samq.front();
			trieq.pop();
			samq.pop();
			for (int i = 0; i < cnt; i++) {
				if (nd->s[i]) {
//					printf("%d -> %d\n", nd->id, i);
					trieq.push(nd->s[i]);
					samq.push(sam.insert(f, i));
				} else {
					
				}
			}
			erase(nd);
		}
	}
	int eidx;
	int head[MAXN];
	int edge[MAXN << 1][2];
	int deg[MAXN];
	int c[MAXN];
	void add(int src, int dst) {
		eidx++;
		deg[src]++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	_Main() {
		int n;
		int a, b;
		read(n); read(cnt);
		for (int i = 1; i <= n; i++) {
			read(c[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			read(a); read(b);
			add(a, b);
			add(b, a);
		}
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 1) {
				dfs(i, trie.insert(trie.root->id, c[i]), -1);
			}
		}
		trieq.push(trie.root);
		samq.push(sam.root);
		build();
		printf("%lld", sam.getAns(sam.root));
	}
}bzoj3926;

}
