using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <map>
namespace OI {
typedef long long lld;
const int MXN = 5e6 + 10;
struct _Main {
map<int, lld> phmp;
map<int, int> mump;
	int q[11];
	int mx;
	lld getphs(int n) {
		if (n <= mx) {
			return phs[n];
		}
		if (phmp.count(n)) {
			return phmp[n];
		}
		lld ret = 0;
		unsigned t;
		for (unsigned st = 2, ed; st <= n; st = ed + 1) {
			ed = n / (t = n / st);
			ret -= (ed - st + 1LL) * getphs(t);
		}
		return phmp[n] = ((1LL + n) * n >> 1) + ret;
	}
	lld getmus(int n) {
		if (n <= mx) {
			return mus[n];
		}
		if (mump.count(n)) {
			return mump[n];
		}
		lld ret = 0;
		unsigned t;
		for (unsigned st = 2, ed; st <= n; st = ed + 1) {
			ed = n / (t = n / st);
			ret -= (ed - st + 1LL) * getmus(t);
		}
		return mump[n] = 1 + ret;
	}
	_Main () {
		int Qn;
		scanf("%d", &Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%d", &q[Q]);
			mx = max(mx, min(q[Q], MXN - 5));
		}
		getprime(mx);
		for (int Q = 1; Q <= Qn; Q++) {
			phmp.clear();
			mump.clear();
			printf("%lld %lld\n", getphs(q[Q]), getmus(q[Q]));
		}
	}
	char isp[MXN], mu[MXN];
	int p[350000], pn, phi[MXN], mus[MXN];
	lld phs[MXN];
	void getprime(int mx) {
		mu[1] = phi[1] = 1;
		memset(isp + 2, 1, mx);
		int t;
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				p[pn++] = i;
				mu[i] = -1;
				phi[i] = i - 1;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {//< mx还行
				isp[t] = 0;
				if (i % p[j]) {
					mu[t] = -mu[i];
					phi[t] = phi[i] * (p[j] - 1);
				} else {
					mu[t] = 0;
					phi[t] = phi[i] * p[j];
					break;
				}
			}
		}
		for (int i = 1; i <= mx; i++) {
			phs[i] = phs[i - 1] + phi[i];
			mus[i] = mus[i - 1] + mu[i]; 
		}
	}
}std;
}

