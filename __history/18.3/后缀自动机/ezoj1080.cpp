using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <algorithm>

namespace OI {
const int 
	DST = 0,
	NXT = 1
;

struct Node {
	Node *s[26], *f;
	int mx, mn, id;
};

class SAM {
public:
	Node node[200005];
	Node *tail, *root;
	Node *new_(int mx, Node *org = 0) {
		Node *nd = &node[idx];
		nd->id = idx;
		nd->mx = mx;
		if (org) {
			memcpy(nd->s, org->s, 26 * sizeof(Node *));
		} else {
			memset(nd->s, 0, 26 * sizeof(Node *));
		}
	}
	void ref(Node *nd, Node *f) {
		nd->f = f;
		nd->mn = f->mx + 1;
	}
	void insert(int c) {
		Node *nd = new_(tail->mx + 1);
		tail->s[c] = nd;
		Node *f = nd->f;
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
		Node *nf = new_(f->mx + 1, s);
		ref(nf, s->f);
		ref(s, nf);
		ref(nd, nf);
		while (f && f->s[c] == s) {
			f->s[c] = nf;
			f = f->f;
		}
	}
	SAM() {
		clear();
	}
	void clear() {
		memset(head, 0, idx * sizeof(int));
		idx = 0;
		eidx = 0;
		now_id++;
		tail = root = new_(0);
	}
	
	int head[200005], edge[1000005][2];
	int eidx;
	int now_id;
	void add(int src, int dst) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	void build(int mn) {
		for (int i = 0; i < idx; i++) {
			if (i && node[i].f->mx >= mn) {
				add(i, node[i].f->id);
			}
			for (int j = 0; j < 26; j++) {
				if (node[i].s[j]) {
					add(i, node[i].s[j]->id);
				}
			}
		}
	}
	int instk[200005];
	int loopvis[200005];
	int lenvis[200005];
	int mxlen[200005];
	int get_loop(int nd = 0) {
		loopvis[nd] = now_id;
		instk[nd] = 1;
		int loop = 0;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			int t;
			if (loopvis[t = edge[e][DST]] != now_id) {
				loop = get_loop(t);
			} else if (instk[t]) {
				loop = 1;
			}
			if (loop) {
				break;
			}
		}
		instk[nd] = 0;
		return loop;
	}
	int get_mx(int id = 0) {
		lenvis[id] = now_id;
		mxlen[id] = 0;
		Node *nd = &node[id];
		for (int i = 0; i < 26; i++) {
			if (nd->s[i]) {
				if (vis[t = nd->s[i]->id] != vis_id) {
					t = get_mx(t);
				} else {
					t = mxlen[t];
				}
				mxlen[id] = max(mxlen[id], 1 + t);
			}
		}
		return mxlen[id];
	}
	
}sam;
struct _Main {
	_Main() {
		
	}
}ezoj1080;

}
