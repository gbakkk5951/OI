using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const lld MOD = 998244353;
const lld MXN = 2003;
const int INF = 0x3f3f3f3f;
const int DST = 0, NXT = 1, VAL = 2;
struct _Main {
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD : ret;
		base = base * base % MOD;
	}
	return ret;
}
lld f[MXN], fr[MXN];
lld com[MXN][MXN];
lld comr[MXN][MXN];
lld dp[2][MXN][MXN]; 
lld ans[MXN];
int size[MXN];
int mx;
int ques[MXN];
int mark[MXN];
int cho, val;	
	void getsize(int nd, int fa, int tot) {
		size[nd] = 1;
		int mx = 0;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t] && t != fa) {
				getsize(t, nd, tot);
				size[nd] += size[t];
				mx = max(mx, size[t]);
			}
		}
		mx = max(mx, tot - size[nd]);
		if (mx < val) {
			val = mx;
			cho = nd;
		}
	}
	int iter[MXN];
	int rate(int tot, int cho, int ptot, int pcho) {
		return com[ptot][pcho] * com[tot - ptot][cho - pcho] % MOD * comr[tot][cho] % MOD;
	}
	void getdp(int nd, int fa) {
		int it = 0, tit;
		int presum = 1;
		int t, val, tsum, sum = 1;
		dp[it][nd][1] = 0;
		lld dpnew*, dpold*, dpt*;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t] && t != fa) {
				it ^= 1;
				getdp(t, nd);
				tsum = size[t];
				sum += tsum;
				val = edge[e][VAL];
				tit = iter[t];
				dpnew = dp[it][nd];
				dpold = dp[it ^ 1][nd];
				dpt = dp[tit][t];
				for (int i = 1; i <= sum; i++) {
					dpnew[i] = 0;
					for (int j = max(1, i - presum); j <= tsum; j++) {
						dpnew[i] += (dpold[i - j] + dpt[j] + val) * rate(sum, i, presum, i - j) % MOD;
					}
				}
				for (int i = 1; i <= presum; i++) {
					dpnew[i] += dpold[i] * com[sum][presum];
				}
				for (int i = 1; i <= sum; i++) {
					dpnew[i] %= MOD;
				}
				presum = sum;
			}
		}
		iter[nd] = it;
	}
	void solve(int nd, int tot) {
		val = INF;
		getsize(nd, 0, tot);
		nd = cho;
		mark[nd] = 1;
		getsize(nd, 0, tot);
		int t;
		int it, tit, sum = size[nd], tsum;
		int val, 
		getdp(nd, 0);
		it = iter[nd];
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t]) {
				tit = iter[t];
				val = edge[e][VAL];
				tsum = size[t];
				for (int j = 1; j <= size[t]; j++) {
					dp[it][nd][j] -= (dp[tit][t][j] + val) * rate(sum, j, tsum, j) % MOD;
				}
			}
		}
		for (int j = 1; j <= sum; j++) {
			dp[it][nd][j] %= MOD;
		}
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t] && size[t] > 1) {
				solve(t, size[t]);
			}
		}
		
	}
	int A[MXN], B[MXN], C[MXN];
	int h[MXN];
	void dfs(int nd, int fa) {
		h[nd] = h[fa] + 1;
		size[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edhe[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd);
				size[nd] += size[t];
			}
		}
	}
	_Main() {
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
		int n, Qn, a, b, c;
		read(n); read(Qn);
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
//		solve(1, n);
		/*
		for (int i = 2; i <= mx; i++) {
			for (int j = 1; j <= n; j++) {
				if (size[j] >= i) {
					ans[i] += dp[iter[j]][j][i] * rate(n, i, size[j], i) % MOD ;
				}
			}
			ans[i] %= MOD;
			ans[i] = ans[i] * 2 % MOD;//树的边权和 * 2
			ans[i] += (ans[i] < 0) * MOD;
		}
		*/
		dfs(1, 0);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - 1; j++) {
				ans[i] += 
				if ()
			}
		}
		
		
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%lld\n", ans[ques[Q]]);
		}
		fclose(stdout);
	}
	int head[MXN], edge[MXN << 1][3], eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
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

