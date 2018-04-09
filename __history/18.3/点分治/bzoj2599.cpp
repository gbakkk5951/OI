using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>

namespace OI {
const int MXN = 200050;
const int LEN = 0, CNT = 1;
const int DST = 0, NXT = 1, VAL = 2;
struct NDC {
int mnans;
int needlen;
int ans;
NDC() {
	ans = 1e9;
}
int head[MXN], edge[MXN << 1][3];
int eidx;
void add(int src, int dst, int val) {
	eidx++;
	edge[eidx][DST] = dst;
	edge[eidx][VAL] = val;
	edge[eidx][NXT] = head[src];
	head[src] = eidx;
}
int tot, size[MXN];
int chose, val;
int mark[MXN];
void getsize(int nd, int fa) {
	size[nd] = 1;
	int t, mx = 0; 
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa && !mark[t]) {
			getsize(t, nd);
			size[nd] += size[t];
			mx = max(mx, size[t]);
		}
	}
	mx = max(mx, tot - size[nd]);
	if (mx < val) {
		chose = nd;
		val = mx;
	}
}
int node[MXN][2];
int sigm[MXN];
void getnode(int nd, int fa, int len, int cnt, int &idx) {//若有剪枝，一些东西可能会不能弄一块 
	node[idx][LEN] = len;
	node[idx][CNT] = cnt;
	idx++;
	int t;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa && !mark[t] && cnt + 1 < ans && len + edge[e][VAL] <= needlen) {
			getnode(t, nd, len + edge[e][VAL], cnt + 1, idx);
		}
	}
}
void getsigm(int nd, int fa) {
	sigm[nd] = 0;
	size[nd] = 1;
	int t;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa && !mark[t]) {
			getsigm(t, nd);
			size[nd] += size[t];
			sigm[nd] = min(sigm[nd] + sigm[t] + edge[e][VAL], needlen);
		}
	}
}
map <int, int>cnt;
void calc(int nd, int _tot) {
	tot = _tot;
	val = 1e9;
	getsize(nd, -1);
	nd = chose;
	getsigm(nd, -1);
	mark[nd] = 1;
	cnt.clear();
	cnt[0] = 0;
	int t, idx, v;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (!mark[t] && edge[e][VAL] <= needlen) {
			getnode(t, nd, edge[e][VAL], 1, idx = 0);
			for (int i = 0; i < idx; i++) {
				v = needlen - node[i][LEN];
				if (cnt.count(v)) {
					ans = min(ans, node[i][CNT] + cnt[v]);
					if (ans == mnans) return;
				}
			}
			for (int i = 0; i < idx; i++) {
				v = node[i][LEN];
				if (cnt.count(v)) {
					cnt[v] = min(cnt[v], node[i][CNT]);
				} else {
					cnt[v] = node[i][CNT];
				}	
			}
		}
	}
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (!mark[t] && sigm[t] == needlen && size[t] > 1) {
			calc(t, size[t]);
			if (ans == mnans) return;
		}
	}
}

}ndc;
struct _Main {
int n;
int prepro() {
	read(n); read(ndc.needlen);
	int a, b, c, mx = 0, mn = 1e9;
	int sum = 0;
	for (int i = 1; i <= n - 1; i++) {
		read(a); read(b); read(c);
		mn = min(mn, c);
		mx = max(mx, c);
		sum = min(sum + c, ndc.needlen);
		if (c == ndc.needlen) {
			printf("1");
			return 0;
		}
		ndc.add(a, b, c);
		ndc.add(b, a, c);
	}
	if (ndc.needlen < mn || ndc.needlen > sum) {
		printf("-1");
		return 0;
	}
	if (mx != 0) ndc.mnans = ((ndc.needlen + mx - 1) / mx);
	return 1;
}
void solve() {
	ndc.calc(0, n);
	printf("%d", (ndc.ans < n) ? ndc.ans : -1);
}
_Main() {
	if (prepro()) {
		solve();
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
}bzoj2599;
}

