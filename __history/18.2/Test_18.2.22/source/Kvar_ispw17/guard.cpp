#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 100 + 5;
const int M = 10000 + 5;
const int INF = 0x7f7f7f7f;

int hd[N], nxt[2 * M], f[2 * M], to[2 * M], tot = 1;

int S, T;

void add(int a, int b, int c) {
	nxt[++tot] = hd[a], to[hd[a] = tot] = b, f[tot] = c;
	nxt[++tot] = hd[b], to[hd[b] = tot] = a, f[tot] = 0;
}

int dis[N], que[N];

bool check() {
	memset(dis, -1, sizeof dis);
	int head = 0, tail = -1;
	dis[que[++tail] = S] = 0;
	while (head <= tail) {
		int u = que[head++];
		for (int e = hd[u]; e; e = nxt[e]) {
			int v = to[e];
			if (dis[v] == -1 && f[e])
				dis[que[++tail] = v] = dis[u] + 1;
		}
	}
	return dis[T] != -1;
}

int argument(int u, int rem) {
	if (u == T) return rem;
	int cnt = 0;
	for (int e = hd[u]; e && rem > cnt; e = nxt[e]) {
		int v = to[e];
		if (dis[u] + 1 == dis[v] && f[e]) {
			int ret = argument(v, std::min(rem - cnt, f[e]));
			f[e] -= ret;
			f[e ^ 1] += ret;
			cnt += ret;
		}
	}
	if (!cnt) dis[u] = -1;
	return cnt;
}

int dinic() {
	int cnt = 0, tmp;
	while (check())	while ((tmp = argument(S, INF))) cnt += tmp;
	return cnt;
}


struct data { int a, b, c; } A[M];
int n, n_tot, Max[55], Sum[55];
int ID(int x, int y) { return Sum[x - 1] + y; }

void solve1() {
	for(int i = 1; i <= n_tot; i++) {
		int a = A[i].a, b = A[i].b, c = A[i].c, d = c % n + 1;
		if(c&1) add(ID(c, a), ID(d, b), 1);
		else add(ID(d, b), ID(c, a), 1);
	}
	S = 0;
	T = Sum[n] + 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= Max[i]; j++) {
			if(i&1) add(S, ID(i, j), 1);
			else add(ID(i, j), T, 1);
		}
	}
	printf("%d\n", Sum[n] - dinic());
}

int del[N], hd2[N], nxt2[2 * M], to2[2 * M], tot2 = 1;
void add2(int a, int b) {
	nxt2[++tot2] = hd2[a], to2[hd2[a] = tot2] = b;
	nxt2[++tot2] = hd2[b], to2[hd2[b] = tot2] = a;
}

void solve2() {
	int mn = INF, mn_id = 0;
	for(int i = 1; i <= n; i++)
		if(Max[i] < mn) mn = Max[i], mn_id = i;
	for(int i = 1; i <= n_tot; i++) {
		int a = A[i].a, b = A[i].b, c = A[i].c, d = c % n + 1;
		add2(ID(c, a), ID(d, b));
	}
	int maxn = (1 << mn) - 1;
	int ans = 0;
	for(int s = 0; s <= maxn; s++) {
		int SUM = Sum[n] - mn;
		for(int i = 0; i <= Sum[n]; i++) hd[i] = del[i] = 0;
		for(int i = 0; i < 2 * M; i++) {
			nxt[i] = to[i] = f[i] = 0;
		}
		int tmp = 0;
		tot = 1;
		for(int i = 1; i <= mn; i++) {
			if((1 << (i - 1)) & s) del[ID(mn_id, i)] = 1;
			else {
				tmp++;
				int u = ID(mn_id, i);
				for(int e = hd2[u]; e; e = nxt2[e]) del[to2[e]] = 1, SUM--;
			}
		}
		for(int i = 1; i <= n_tot; i++) {
			int a = A[i].a, b = A[i].b, c = A[i].c, d = c % n + 1;
			if(del[ID(c, a)] || del[ID(d, b)]) continue;
			int op = c < mn_id ? 1 : 0;
			if((c&1)==op) add(ID(c, a), ID(d, b), 1);
			else add(ID(d, b), ID(c, a), 1);
		}
		S = 0;
		T = Sum[n] + 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= Max[i]; j++) {
				if(del[ID(i, j)] || i == mn_id) continue;
				int op = i < mn_id ? 1 : 0;
				if((i&1)==op)add(S, ID(i, j), 1);
				else add(ID(i, j), T, 1);
			}
		}
		int t = SUM - dinic();
		ans = std::max(ans, t + tmp);
	}
	printf("%d\n", ans);
}

#define JUDGE

int main() {
#ifdef JUDGE
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
#endif
	scanf("%d", &n);
	int ta, tb, tc;
	while(scanf("%d%d%d", &ta, &tb, &tc) != EOF) A[++n_tot] = (data) { ta, tb, tc };
	for(int i = 1; i <= n_tot; i++) {
		int a = A[i].a, b = A[i].b, c = A[i].c;
		Max[c] = std::max(Max[c], a);
		Max[c % n + 1] = std::max(Max[c % n + 1], b);
	}
	for(int i = 1; i <= n; i++) Sum[i] = Sum[i - 1] + Max[i];
	if((n&1) == 0) solve1();
	else solve2();
#ifdef JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
