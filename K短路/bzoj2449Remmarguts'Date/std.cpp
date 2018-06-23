using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
typedef pair<int, int> p;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const int MXN = 1e3 + 10, MXM = 1e5 + 10;


struct Node {
	Node *l, *r;
	int val, eid, id, npl;
}pool[2000000];
int pidx;
Node *new_(int id, Node *org = 0) {
	Node *nd = &pool[pidx++];
	if (org) memcpy(nd, org, sizeof(Node));
	nd->id = id;
	return nd;
}
Node *merge(Node *a, Node *b, int id) {
	if (!a) return b;
	if (!b) return a;
	if (a->val > b->val) swap(a, b);
	if (a->id != id) a = new_(id, a);
	a->r = merge(a->r, b, id);
	if (a->l == 0) {
		swap(a->l, a->r);
		a->npl = 0;
	} else {
		if (a->l->npl < a->r->npl) {
			swap(a->l, a->r);
		}
		a->npl = a->r->npl + 1;
	}
	return a;
}
struct _Main {
	int S, T, K;
	int src[MXM], dst[MXM], val[MXM];
	int n, m;
	int ord[MXN];//出堆顺序
	int oidx;
	int dis[MXN];
	int f[MXN], fe[MXN];
	priority_queue<p, vector<p>, greater<p> > q;
	void dijkstra() {
		memset(dis + 1, 63, n * sizeof(int));
		dis[T] = 0;
		q.push((p) {0, T});//forgot
		int nd, t, tmp;
		while (!q.empty()) {
			nd = q.top().second;
			if (dis[nd] < q.top().first) {
				q.pop(); continue;
			} q.pop();
			ord[++oidx] = nd;
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				t = edge[e][DST];
				tmp = dis[nd] + edge[e][VAL];
				if (dis[t] > tmp) {
					f[t] = nd; fe[t] = e;
					dis[t] = tmp;
					q.push((p) {dis[t], t});
				}
			}
		}
	}
	Node *root[MXN << 1];
	int nxt[MXN << 1], ridx;
	void build(int nd) {
		Node *ne;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (e != fe[nd]) {
				ne = new_(nd);
				ne->eid = e;
				ne->val = edge[e][VAL];
				root[nd] = merge(root[nd], ne, nd);
			}
		}
		root[nd] = merge(root[nd], root[f[nd]], nd);
	}
	_Main() {
		read(n); read(m);
		for (int i = 1; i <= m; i++) {
			read(src[i]); read(dst[i]); read(val[i]);
			add(i, dst[i], src[i], val[i]);
		}
		read(S); read(T); read(K);
		dijkstra();
		if (dis[S] == INF) {
			printf("-1");
			return;
		}
		memset(head + 1, 0, n * sizeof(int));
		eidx = 0;
		for (int i = 1; i <= m; i++) if (dis[dst[i]] < INF && dis[src[i]] < INF) {
			val[i] = val[i] + dis[dst[i]] - dis[src[i]];
			add(i, src[i], dst[i], val[i]);
		}
		for (int i = 1; i <= oidx; i++) {
			build(ord[i]);
		}
		ridx = n;
		dst[0] = 1; //S 不是 1
		root[0] = new_(0);
		root[0]->eid = 0;
		q.push((p) {0, 0});
		for (int k = 1, v, r; k <= K - 1; k++) {
			if (q.empty()) {
				break;
			}
			v = q.top().first;
			r = q.top().second;
			q.pop();
			//加边
			push(dst[root[r]->eid], v);
			//换边
			if (nxt[r] == 0) {
				++ridx;
				root[ridx] = merge(root[r]->l, root[r]->r, ridx);
				nxt[r] = ridx;
			}
			v -= root[r]->val;
			push(nxt[r], v);
		}
		if (q.empty()) {
			printf("-1");
		} else {
			printf("%d", dis[S] + q.top().first);
		}
	}
	inline void push(int r, int v) {
		if (root[r]) {
			q.push((p) {v + root[r]->val, r});
		}
	}
	int head[MXN], edge[MXM][3], eidx;
	void add(int eidx, int a, int b, int c) {
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
