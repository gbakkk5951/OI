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
const int BASE = 20005;
const lld MOD = 1e9 + 7;
lld com[MXP][MXP];
lld pow[MXN << 1][MXP];
inline lld getpow(int base, int p) {
	return pow[base + BASE][p];
}
int n, k;
struct Mlt {
	lld as[MXP];
	lld & operator [] (int idx) {
		return as[idx];
	}
	Mlt() {
		zero();
	}
	void zero() {
		memset(this, 0, sizeof(Mlt));
	}
	Mlt operator - (Mlt b) {
		Mlt ret = *this;
		for (int i = 0; i <= k; i++) {
			ret[i] = (ret[i] - b[i]) % MOD;
		}
		return ret;
	}
	Mlt operator + (Mlt b) {
		Mlt ret = *this;
		for (int i = 0; i <= k; i++) {
			ret[i] = (ret[i] + b[i]) % MOD;
		}
		return ret;
	}
	Mlt operator + (lld v) {
		Mlt ret = *this;
		for (int i = k; i >= 0; i--) {
			lld t = 0;
			for (int j = 0; j <= i; j++) {
				t += com[i][j] * getpow(v, i - j) * as[j];
			}
			ret[i] = t % MOD;
		}
		return ret;
	}
	Mlt operator - (lld v) {
		return *this + -v;
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
	sum[nd].zero();
	for (int i = 0; i <= k; i++) {
		sum[nd][i] = 1;
	}
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
		for (int i = -20000; i <= 20000; i++) {
			pow[i + BASE][0] = 1;
			for (int j = 1; j < MXP; j++) {
				pow[i + BASE][j] = pow[i + BASE][j - 1] * i % MOD;
			}
		}
		for (int i = 0; i < MXP; i++) {
			com[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % MOD;
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
