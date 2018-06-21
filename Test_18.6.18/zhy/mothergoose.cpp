using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstdio>
namespace OI {
const int MOD = 1e9 + 7;
typedef unsigned char uc;
typedef long long lld;

struct _Main {
	int n, slen, tms, tot;
	char str[5000100];
	int dp[2][128];//0表相同, 1表不同
	uc q[2][128];
	int h[2];
	int pn, len[7], eq;
	void dfs(int i, int nd, int pos, int val, int s, int xorsum) {
		if (nd == pn) {
			if (xorsum == 1) {
				return;
			}
			int it = i & 1;
			if (dp[it][s] == -1) {
				dp[it][s] = val;
				q[it][h[it]++] = s;
			} else {
				dp[it][s] = (dp[it][s] + val) % MOD;
			}
		} else
		if (nd == 0 && eq) {
			if (str[i]) {
				for (int j = 1; j < len[0]; j++) {//部分相等
					dfs(i, nd + 1, pos + len[nd], val, s | (1 << j), xorsum ^ (j & 1));
				}
				dfs(i, nd + 1, pos + len[nd], val, s, xorsum ^ (len[0] & 1));//完全相等
				dfs(i, nd + 1, pos + len[nd], val, s | 1, xorsum);//完全不等
			} else {
				dfs(i, nd + 1, pos + len[nd], val, s, xorsum);
			}
		} else {
			s |= 1 << pos;
			for (int j = 1; j < len[nd]; j++) {//前j个为1，后面的为0
				dfs(i, nd + 1, pos + len[nd], val, s | (1 << pos + j), xorsum ^ (j & 1));
			}
			//完全相同 * 2
			if ((len[nd] & 1) == 0) {
				dfs(i, nd + 1, pos + len[nd], val * 2 % MOD, s, xorsum);
			} else {
				dfs(i, nd + 1, pos + len[nd], val, s, xorsum);
				dfs(i, nd + 1, pos + len[nd], val, s, xorsum ^ 1);
			}
		}
	}
	void decom(int s) {
		eq = s & 1 ^ 1;
		pn = 0;
		int lst = 0;
		for (int i = 1; i < n; i++) {
			if (s >> i & 1) {
				len[pn++] = i - lst;
				lst = i;
			}
			if (i == n - 1) {
				len[pn++] = i - lst + 1;
			}
		}
	}
	void getdp() {
		memset(dp, -1, sizeof(dp));
		int it = 0, s;
		q[it][h[it]++] = 0;
		dp[it][0] = 1;
		for (int i = 1; i <= tot; i++) {
			it ^= 1;
			h[it] = 0;
			for (int j = 0; j < h[it ^ 1]; j++) {
				s = q[it ^ 1][j];
				decom(s);
				dfs(i, 0, 0, dp[it ^ 1][s], 0, 0);
				dp[it ^ 1][s] = -1;
			}
		}
	}
	lld ans;
	_Main () {
		freopen("mothergoose.in", "r", stdin);
		freopen("mothergoose.out", "w", stdout);
		read(n); read(tms);
		if (n == 1) {
			ans = 1;
			goto EndMain;
		} else if (n == 2) {
			goto EndMain;
		}
		scanf("%s", str + 1);
		slen = strlen(str + 1);
		tot = tms * slen;
		for (int i = 1; i <= slen; i++) {
			str[i] -= '0';
		}
		for (int i = 1; i <= tms - 1; i++) {
			memmove(str + 1 + i * slen, str + 1, slen);
		}
		getdp();
		ans = dp[tot & 1][(1 << n) - 1];//不能与原串相同
		
		EndMain: {
			printf("%lld", ans);
			fclose(stdout);
		}
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
}mothergoose;
}
