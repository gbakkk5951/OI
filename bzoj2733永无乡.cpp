using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
namespace OI{
typedef long long lld;
const int MAXN = 100010;

struct Node {
	Node *s[2];
	int sum;
}pool[140000 * 20 + 100];
int pidx;
Node *new_node() {
	return &pool[pidx++];
}
int f[MAXN];
int getfa(int nd) {
	return f[nd] ? f[nd] = getfa(f[nd]) : nd;
}

Node *root[MAXN];

int idx[MAXN], rank[MAXN], val[MAXN], sorted[MAXN];

void insert(Node* &nd, int val, int l, int r) {
	if (nd == 0) {
		nd = new_node();
	}
	nd->sum++;
	if (l == r) {
		return;
	}
	int mid = l + r >> 1;
	if (val <= mid) {
		insert(nd->s[0], val, l, mid);
	} else {
		insert(nd->s[1], val, mid + 1, r);
	}
}
Node *merge(Node *a, Node *b) {
	if (a == 0) {
		return b; 
	} 
	if (b == 0) {
		return a;
	}
	a->sum = 0;
	for (int i = 0; i < 2; i++) {
		a->s[i] = merge(a->s[i], b->s[i]);
		a->sum += a->s[i] ? a->s[i]->sum : 0;	
	}
	return a;
}
int query(Node *nd, int rank, int l, int r) {
	if (rank > nd->sum) {
		return -1;
	}
	int t;
	while (l != r) { 
		if (rank > (t = (nd->s[0] ? nd->s[0]->sum : 0)) ) {
			nd = nd->s[1]; 
			rank -= t;
			l = (l + r >> 1) + 1;
		} else {
			nd = nd->s[0];
			r = l + r >> 1;
		}
	}
	return idx[l];
}


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

	void link(int a, int b, bool _merge = true) {
		int f1, f2;
		f1 = getfa(a); f2 = getfa(b);
		if (f1 != f2) {
			if (_merge) {
				root[f2] = merge(root[f1], root[f2]);
			}
			f[a] = f[f1] = f2;
		}
		
	}
	int n, m;
	char buf[5];
	_Main() {
		//freopen("data.in", "r", stdin);
		int i, j, k;
		int f1, f2;
		int a, b, c;
		int Q, Qn;
		read(n); read(m);
		for (i = 1; i <= n; i++) {
			read(rank[i]);
			idx[rank[i]] = i;
		}
		for (i = 1; i <= m; i++) {
			read(a); read(b);
			link(a, b, false);
		}
		for (i = 1; i <= n; i++) {
			insert(root[getfa(i)], rank[i], 1, n);
		}
		read(Qn);
		for (Q = 1; Q <= Qn; Q++) {
			scanf("%s", buf);
			read(a); read(b);
			if (buf[0] == 'B') {
				link(a, b);
			} else {
				printf("%d\n", query(root[getfa(a)], b, 1, n));
			}
		}
	}

}bzoj2733;


}
