using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e5 + 10; 
int sa[MXN << 1], rk[MXN << 1], h[MXN << 1];
int a1[MXN << 2], a2[MXN << 2], xofy[MXN << 1], sum[MXN << 1];
char str[MXN << 1];
int la, lb, lim, len;
void getsa() {
	int *ypo = a1, *xrk = a2, m = 28, p;
	memset(a1 + len, -1, len * sizeof(int));
	memset(a2 + len, -1, len * sizeof(int));//sizeof char?????
	for (int i = 0; i < len; i++) ++sum[xrk[i] = str[i]];
	for (int i = 1; i < m; i++) sum[i] += sum[i - 1];
	for (int i = len - 1; i >= 0; i--) sa[--sum[xrk[i]]] = i;
	memset(sum, 0, m * sizeof(int));
	for (int stp = 1; stp < len; stp <<= 1) {
		p = 0;
		for (int i = len - stp; i < len; i++) ypo[p++] = i;
		for (int i = 0; i < len; i++) ypo[p++] = sa[i] - stp, p -= sa[i] < stp;
		for (int i = 0; i < len; i++) ++sum[xofy[i] = xrk[ypo[i]]];
		for (int i = 1; i < m; i++) sum[i] += sum[i - 1];
		for (int i = len - 1; i >= 0; i--) sa[--sum[xofy[i]]] = ypo[i];
		memset(sum, 0, m * sizeof(int));
		swap(xrk, ypo);
		xrk[sa[0]] = m = 0;
		for (int i = 1; i < len; i++) {
			xrk[sa[i]] = m += ypo[sa[i]] != ypo[sa[i - 1]] || ypo[sa[i] + stp] != ypo[sa[i - 1] + stp];
		}
		if (++m == len) {
			break;
		}
	}
}
void getrk() {
	for (int i = 0; i < len; i++) {
		rk[sa[i]] = i;
	}
}
void geth() {
	for (int i = 0, j, k = 0; i < len; i++) {
		if (rk[i]) {
			j = sa[rk[i] - 1];
			for (k -= k ? 1 : 0; str[i + k] == str[j + k]; ++k);
			h[rk[i]] = k;
		}
	}
}

int st[18][MXN << 1];
int log[MXN << 1];
void getlog() {
	for (int i = 2; i <= len; i++) {
		log[i] = log[i - 1] + (i == 1 << log[i - 1] + 1);
	}
}
void getst() {
	memcpy(st[0], h, len * sizeof(int));
	for (int I = 1; I <= log[len]; I++) {
		for (int i = 0; i + (1 << I) <= len; i++) {
			st[I][i] = min(st[I - 1][i], st[I - 1][i + (1 << I - 1)]);
		}
	}
}
int getmin(int l, int r) {
	if (l > r) swap(l, r);
	++l;
	int lg = log[r - l + 1];
	return min(st[lg][l], st[lg][r - (1 << lg) + 1]);
}
int dp[MXN][102];
bool getdp() {
	for (int i = 1; i <= la; i++) {
		memset(dp[i] + 1, 0, lim * sizeof(int));
	}
	int lcp;
	for (int i = 0; i < la; i++) {
		for (int j = 0; j < lim; j++) {
			if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			lcp = getmin(rk[i], rk[la + dp[i][j] + 1]);//均是从i
			if (dp[i][j] + lcp >= lb) {
				return 1;
			}
			dp[i + lcp][j + 1] = max(dp[i + lcp][j + 1], dp[i][j] + lcp);
		}
	}
	return 0;
}

struct _Main {
	_Main() {//用a拼b
		int Tn;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(la); read(lb); read(lim);
			len = la + lb + 2;
			scanf("%s", str);
			la = strlen(str);
			for (int i = 0; i < la; i++) {
				str[i] -= 'a' - 2;
			}
			str[la] = 1;
			scanf("%s", str + la + 1);
			for (int i = la + 1; i < len; i++) {
				str[i] -= 'a' - 2;
			}
			str[len - 1] = 0;
			getsa();
			getrk();
			geth();
			getlog();
			getst();
			if (getdp()) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
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
}std;
}
