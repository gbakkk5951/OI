using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
namespace OI {
const int DST = 0, NXT = 1;
const int MXN = 50050;
int gcd(int a, int b) {
	return b ? gcd (b, a % b) : a;
}
struct Block {
	int tag[MXN], mn[MXN]; 
	int num[MXN], gc[MXN]; //除最小之外的gcd
	int id[MXN], st[MXN], ed[MXN];
	int bidx;
	Block () {
		bidx = 1;
		st[0] = ed[0] = 50045;
	}
	void init(int l, int r) {
		if (l > r) swap(l, r);
		int sq = ceil(sqrt(r - l + 1.0));
		for (int i = l; i <= r; i++) {
			id[i] = bidx;
			if ((i - l + 1) % sq == 0) {
				ed[bidx] = i;
				st[++bidx] = i + 1;
			}
		}
		st[id[l]] = l;
		ed[id[r]] = r;
		bidx = id[r] + 1;
		for (int i = id[l]; i <= id[r]; i++) {
			rebuild(i);
		}
	}
	void rebuild(int b) {
		mn[b] = num[st[b]];
		for (int i = st[b] + 1; i <= ed[b]; i++) {
			mn[b] = min(mn[b], num[i]);
		}
		gc[b] = 0;
		for (int i = st[b]; gc[b] != 1 && i <= ed[b]; i++) {
			if (num[i] > mn[b]) {
				gc[b] = gcd(num[i] - mn[b], gc[b]);
			}
		}
	}
	void bradd(int l, int r, int c) {
		for (int i = l; i <= r; i++) {
			num[i] += c;
		}
		rebuild(id[l]);
	}
	void add(int l, int r, int c) {
		if (l > r) swap(l, r);
		if (l > st[id[l]] && ed[id[l]] <= r) {
			bradd(l, ed[id[l]], c);
			l = ed[id[l]] + 1;
		}
		while (ed[id[l]] <= r) {
			tag[id[l]] += c;
			l = ed[id[l]] + 1;
		}
		if (l <= r) {
			bradd(l, r, c);
		}
	}
	void brquery(int &g, int l, int r) {
		for (int i = l; i <= r && g != 1; i++) {
			g = gcd(g, num[i] + tag[id[i]]);
		}
	}
	int query(int &g, int l, int r) {
		if (l > r) swap(l, r);	
		if (g != 1 && l > st[id[l]] && ed[id[l]] <= r) {
			brquery(g, l, ed[id[l]]);
			l = ed[id[l]] + 1;
		}
		while (g != 1 && ed[id[l]] <= r) {
			g = gcd(g, gcd(mn[id[l]] + tag[id[l]], gc[id[l]]));
			l = ed[id[l]] + 1;
		}
		if (g != 1 && l <= r) {
			brquery(g, l, r);
		}
		return g;
	}
	
	
}blk;

int h[MXN], head[MXN], edge[MXN << 1][2], tp[MXN], id[MXN], f[MXN], size[MXN];
int org[MXN];
int chos[MXN];
int eidx;
void add(int src, int dst) {
	eidx++;
	edge[eidx][DST] = dst;
	edge[eidx][NXT] = head[src];
	head[src] = eidx;
}

void dfs1(int nd, int fa) {
	int t;
	f[nd] = fa;
	h[nd] = h[fa] + 1;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if ((t = edge[e][DST]) != fa) {
			dfs1(t, nd);
			size[nd] += size[t];
			if (size[t] > size[chos[nd]]) {
				chos[nd] = t;
			}
		}
	}
	size[nd]++;
}
int idx;
void dfs2(int nd, int top) {
	id[nd] = ++idx;
	blk.num[id[nd]] = org[nd];
	tp[nd] = top;
	if (chos[nd]) {
		dfs2(chos[nd], top);
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if ((t != f[nd]) && (t != chos[nd])) {
				dfs2(t, t);
			}
		}
	} else {
		blk.init(id[nd], id[top]);
	}
}
void add(int a, int b, int c) {
	while (tp[a] != tp[b]) {
		if (h[tp[a]] < h[tp[b]]) {
			swap(a, b);
		}
		blk.add(id[a], id[tp[a]], c);
		a = f[tp[a]];
	}
	blk.add(id[a], id[b], c);
}
int query(int a, int b) {
	int g = 0;
	while (tp[a] != tp[b] && g != 1) {
		if (h[tp[a]] < h[tp[b]]) {
			swap(a, b);
		}
		blk.query(g, id[a], id[tp[a]]);
		a = f[tp[a]];
	}
	blk.query(g, id[a], id[b]);
	return g;
}

struct _Main {
	char op[5];
	_Main() {
		int n, Qn;
		int a, b, c;
		read(n);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			a++; b++;
			add(a, b);
			add(b, a);
		}
		for (int i = 1; i <= n; i++) {
			read(org[i]);
		}
		dfs1(1, 0);
		dfs2(1, 1);
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			read(a); read(b);
			a++; b++;
			if (op[0] == 'C') {
				read(c);
				add(a, b, c);
			} else {
				printf("%d\n", query(a, b));
			}
		}
		
	}
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
}T1;
}
