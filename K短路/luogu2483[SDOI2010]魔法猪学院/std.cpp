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
#include <complex>
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
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const int MXN = 5e3 + 10, MXM = 2e5 + 10;
struct Node {
	Node *l, *r;
	int id, eid, npl;
	lf val;//Shen Tm int val;
}pool[8192];
Node *end = pool + 8192, *now = pool;
Node *new_(int id, Node *org = 0) {
	if (now == end) {
		now = (Node *)new Node[8192];
		end = now + 8192;
	}
	if (org) {
		memcpy(now, org, sizeof(Node));
	}
	now->id = id;
	return now++;
}
Node *merge(Node *a, Node *b, int id) {
	if (!a) return b;
	if (!b) return a;
	if (a->val > b->val) swap(a, b);
	if (a->id != id) a = new_(id, a);
	a->r = merge(a->r, b, id);
	if (a->l == 0) {
		swap(a->r, a->l);
		a->npl = 0;
	} else {
		if (a->l->npl < a->r->npl) {
			swap(a->r, a->l);
		}
		a->npl = a->r->npl + 1;
	}
	return a;
}
Node *root[MXN];

struct _Main {
	int n, m;
	int src[MXM], dst[MXM];
	lf dis[MXN];
	int fe[MXN], f[MXN];
	int ord[MXN], oid;
	void dijkstra() {
		fill(dis + 1, dis + n + 1, (lf)INF * 2);
		typedef pair<lf, int> p;
		priority_queue<p, vector<p>, greater<p> > q; 
		dis[n] = 0;
		q.push((p) {0, n});// 0, n 不是 0, 0
		while (!q.empty()) {
			int nd = q.top().second;
			if (q.top().first > dis[nd]) {
				q.pop();
				continue;
			}
			q.pop();
			ord[++oid] = nd;
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				int t = edge[e][DST];
				lf tmp = dis[nd] + val[e];
				if (tmp < dis[t]) {
					dis[t] = tmp;
					fe[t] = e;
					f[t] = nd;
					q.push((p) {tmp, t});
				}
			}
		}
	}
	void build(int nd) {
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (e == fe[nd]) continue;
			int t = edge[e][DST];
			Node *ne = new_(nd);
			ne->eid = e;
			ne->val = val[e];
			root[nd] = merge(root[nd], ne, nd);
		}
		root[nd] = merge(root[nd], root[f[nd]], nd);
	}
	_Main() {
		lf tot;
		read(n); read(m);
		scanf("%lf", &tot);
		for (int i = 1; i <= m; i++) {
			read(src[i]); read(dst[i]); scanf("%lf", val + i);
			if (src[i] == n) {
				--m; --i; continue;
			}
			add(i, dst[i], src[i], val[i]);
		}
		dijkstra();
		memset(head + 1, 0, n * sizeof(int));
		for (int i = 1; i <= m; i++) {
			if (dis[dst[i]] < INF && dis[src[i]] < INF) {
				add(i, src[i], dst[i], val[i] + dis[dst[i]] - dis[src[i]]);
			}
		}
		for (int i = 1; i <= oid; i++) {
			build(ord[i]);
		}
		int ans = 0;
		root[0] = new_(0);
		dst[0] = 1;
		q.push((p) {0.0, root[0]});
		while (!q.empty() && !(q.top().first + dis[1] > tot)) {//没加括号!的优先级比+要高
			lf v = q.top().first;
			Node *nd = q.top().second;
			q.pop();
			++ans;
			tot -= v + dis[1];
			int e = nd->eid;
			//加边
			push(v, root[dst[e]]);
			//换边
			push(v - val[e], nd->l);
			push(v - val[e], nd->r);
		}
		printf("%d", ans);
	}
	typedef pair<lf, Node*> p;
	priority_queue<p, vector<p>, greater<p> > q;
	inline void push(lf v, Node *r) {
		if (r) {
			q.push((p) {v + val[r->eid], r});
		}
	}
	
	int head[MXN], edge[MXM][2];
	lf val[MXM];
	inline void add(int eid, int a, int b, lf c) {
		edge[eid][DST] = b;
		edge[eid][NXT] = head[a];
		head[a] = eid;
		val[eid] = c;
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
