using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

namespace OI {
typedef long long lld;
const int MXP = 21;
const int MXN = 20020;
const lld MOD = 1e9 + 7;
lld com[MXP][MXP];
int n, k;
struct Mlt {
	lld as[MXP];
	lld & operator [] (int idx) {
		return as[idx];
	}
	Mlt operator - (Mlt b) {
		Mlt ret;
		for (int i = 0; i <= k; i++) {
			ret[i] = (as[i] - b[i]) % MOD;
		}
		return ret;
	}
	Mlt operator + (Mlt b) {
		Mlt ret;
		for (int i = 0; i <= k; i++) {
			ret[i] = (as[i] + b[i]) % MOD;
		}
		return ret;
	}
	Mlt operator + (int) {
		Mlt ret;
		for (int i = k; i >= 0; i--) {
			ret[i] = 0;
			for (int j = 0; j <= i; j++) {
				ret[i] += com[i][j] * as[j];
			}
			ret[i] %= MOD;
		}
		return ret;
	}
}sum[MXN];
lld ans[MXN];
const int DST = 0, NXT = 1;
int head[MXN], edge[MXN << 1][2];
int eidx;
void add(int a, int b) {
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
}
void getsum(int nd, int fa) {
	fill(sum[nd].as, sum[nd].as + k + 1, 1);
	int t;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		t = edge[e][DST];
		if (t != fa) {
			getsum(t, nd);
			sum[nd] = sum[nd] + (sum[t] + 1);
		}
	}
}

struct _Main {
	void prepro() {
		int a, b;
		memset(head, 0, (n + 1) * sizeof(int));
		eidx = 0;
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		getsum(1, 0);
	}

	void pprepro() {
		for (int i = 0; i < MXP; i++) {
			com[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
			}
		}
	}
	void getans(int nd, int fa) {
		ans[nd] = sum[nd][k] < 0 ? sum[nd][k] + MOD : sum[nd][k];
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				sum[t] = ((sum[nd] - (sum[t] + 1)) + 1) + sum[t];
				getans(t, nd);
			}
		}
	}
	void solve() {
		while (~scanf("%d%d", &n, &k)) {
			prepro();
			getans(1, 0);
			for (int i = 1; i <= n; i++) {
				printf("%lld\n", ans[i]);
			}
			printf("\n");
		}
	}
	_Main() {
		pprepro();
		solve();
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
}T3;
}
