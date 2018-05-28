using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const lld MOD = 998244353;
const lld MXN = 2003;
const int INF = 0x3f3f3f3f;
const int DST = 0, NXT = 1, VAL = 2;
struct _Main {
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD : ret;
		base = (pow >>= 1) ? base * base % MOD : base;
	}
	return ret;
}
lld f[MXN], fr[MXN];
lld com[MXN][MXN];
lld comr[MXN][MXN];
lld ans[MXN];
int size[MXN];
int ques[MXN];
	int A[MXN], B[MXN], C[MXN];
	int h[MXN];
	void dfs(int nd, int fa) {
		h[nd] = h[fa] + 1;
		size[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd);
				size[nd] += size[t];
			}
		}
	}
	_Main() {
		freopen("orient.in", "r", stdin);
		freopen("orient.out", "w", stdout);
		
		int n, Qn, a, b, c;
		read(n); read(Qn);
		
		f[0] = fr[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1] * i % MOD;
			fr[i] = fr[i - 1] * fastpower(i, MOD - 2) % MOD;
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				com[i][j] = f[i] * fr[j] % MOD * fr[i - j] % MOD;
				comr[i][j] = fr[i] * f[j] % MOD * f[i - j] % MOD;
			}
		}
		if (Qn == 0) {
			fclose(stdout); 
			return;
		}
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
			A[i] = a; B[i] = b; C[i] = c;
		}
		
		for (int Q = 1; Q <= Qn; Q++) {
			read(ques[Q]);
		}
		
		dfs(1, 0);
		int fs, ss;
		lld v;
		for (int i = 1; i <= n - 1; i++) {
			if (h[A[i]] > h[B[i]]) swap(A[i], B[i]);
			fs = n - size[B[i]], ss = size[B[i]];
			v = C[i];
			for (int j = 1; j <= n; j++) {
				ans[j] += (com[n][j] - com[fs][j] - com[ss][j]) * v % MOD;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			ans[i] %= MOD;
			ans[i] <<= 1;
			ans[i] %= MOD;
			ans[i] = ans[i] * comr[n][i] % MOD;
			ans[i] += (ans[i] < 0) * MOD;
		}
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%lld\n", ans[ques[Q]]);
		}
		fclose(stdout);
	}
	int head[MXN], edge[MXN << 1][2], eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
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
}orient;
}

