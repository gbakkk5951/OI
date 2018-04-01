using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
namespace OI {
typedef double lf;
const int MXN = 10010, MXM = 100010;
const int DST = 0, NXT = 1, VAL = 2;
const lf EPS = 1e-8;
int head[MXN], edge[MXM << 1][3];
int out[MXN];
int eidx;
void add(int a, int b, int c) {
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][VAL] = c;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
	if (c) out[a]++; //0表示反向边
}
lf a[MXN], b[MXN];
lf dp[MXN][2];
void dfs(int nd) {
	int cnt = 0, t;
	lf ws = 0.0, es = 0.0, delta = 0.0, tmp, mx = 0.0, w;
	out[nd] = -1;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if (edge[e][VAL]) {
			w = edge[e][VAL];
			t = edge[e][DST];
			tmp = w * dp[t][0];
			ws += w;
			mx = max(mx, dp[t][0]);
			es += tmp;
			a[cnt] = tmp;
			b[cnt] = w;
			cnt++;
			delta = max(delta, w * dp[t][1] - tmp);
		}
	}
	printf("delta %d = %lf\n", nd, delta);
	if (cnt) {
		dp[nd][0] = 1.0 + es / ws;
		dp[nd][1] = 1.0 + (es + delta) / ws;
		printf("es = %lf ws = %lf\n", es, ws);
	}
	if (cnt > 1) {
		lf l = (es + delta) / ws, r = mx, mid, mn, sum;
		while (r - l > EPS) {
			mid = (r + l) / 2.0;
			mn = sum = 0;
			for (int i = 0; i < cnt; i++) {
				sum += tmp = a[i] - b[i] * mid;
				mn = min(mn, tmp);
			}
			if (sum - mn > -EPS) {
				l = mid;
			} else {
				r = mid;
			}
		}
		dp[nd][1] = max(dp[nd][1], l + 1.0);
	}
	
	for (int i = 0; i < 2; i++) {
		printf("dp %d %d = %lf\n", nd, i, dp[nd][i]);	
	}
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if (edge[e][VAL] == 0) {
			t = edge[e][DST];
			if (--out[t] == 0) {
				dfs(t);
			}
		}
	}
}

struct _Main {
	_Main() {
		int n, m;
		int a, b, c;
		read(n); read(m);
		for (int i = 1; i <= m; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, 0);
		}
		for (int i = 0; i < n; i++) {
			if (out[i] == 0) {
				dfs(i);
			}
		}
		printf("%.6lf", round(dp[0][1] * 1e6) / 1e6);
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
}T2;
}
