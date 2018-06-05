using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
namespace OI {
const int INF = 0x3f3f3f3f;
const int MXN = 1e5 + 10;
struct Node {
	Node *l, *r;
	unsigned val, del;
}node[MXN];
struct Cmp {
	bool operator () (Node *a, Node *b) {
		return a->val > b->val;
	}
};
priority_queue<Node*, vector<Node*>, Cmp> heap;
void link(Node *l, Node *r) {
	r->l = l;
	l->r = r;
}
void erase(Node *nd) {
	nd->del = 1;
	nd->l->r = nd->r;
	nd->r->l = nd->l;
}
struct _Main {
	_Main() {
		int n, kn;
		int lst = 0, now;
		int idx = 0;
		link(&node[0], &node[++idx]);
		node[0].val = node[idx].val = INF;
		read(n); read(kn);
		for (int i = 1; i <= n; i++) {
			read(now);
			if (i != 1) {
				++idx;
				node[idx].val = now - lst;
				link(&node[idx - 1], &node[idx]);
				heap.push(&node[idx]);
			}
			lst = now;
		}
		for (int i = 0; i < 2; i++) {
			++idx;
			node[idx].val = INF;
			link(&node[idx - 1], &node[idx]);
		}
		Node *nd;
		int ans = 0;
		while (kn--) {
			do {
				nd = heap.top();
				heap.pop();
			} while(nd->del);
			ans += nd->val;
			nd->val = nd->l->val + nd->r->val - nd->val;
			erase(nd->l); erase(nd->r);
			heap.push(nd);
		}
		printf("%d", ans);
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}std;
}
