using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
namespace OI {
const int MXN = 2e4 + 10;
const int MXV = 1e5 + 10;
int n[MXN], m[MXN], a[MXN];
int qid[MXN];

char cmp(int a, int b) {
	return OI::a[a] < OI::a[b];
}
int dsum[MXV];
int dsid[MXV];
char cmp2(int a, int b) {
	return dsum[a] < dsum[b];
}
struct _Main {
	int mx;
	int ans[MXN];
	int node[MXV];
	int Qn;
	int query(int nd) {
		int ret = 0;
		for (; nd; nd -= nd & (-nd)) {
			ret += node[nd];
		}
		return ret;
	}
	void add(int nd, int val) {
		for (; nd <= mx; nd += nd & (-nd)) {
			node[nd] += val;
		}
	}
	_Main() {
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(n[Q]); read(m[Q]); read(a[Q]);
			qid[Q] = Q;
			mx = max(mx, min(n[Q], m[Q]));
		}
		getprime();
		for (int i = 1; i <= mx; i++) {
			dsid[i] = i;
		}
		sort(dsid + 1, dsid + mx + 1, cmp2);
		sort(qid + 1, qid + Qn + 1, cmp);
		int now = 1, mn, nn, mm;
		int st, ed, t1, t2;
		for (int Q = 1; Q <= Qn; Q++) {
			while (now <= mx && dsum[dsid[now]] <= a[qid[Q]]) {
				for (int j = dsid[now], k = 1; j <= mx; j += dsid[now], k++) {
					add(j, dsum[dsid[now]] * mu[k]);
				}
				++now;
			}
			nn = n[qid[Q]], mm = m[qid[Q]];
			mn = min(nn, mm);
			for (st = 1; st <= mn; st = ed + 1) {
				ed = min(nn / (t1 = nn / st), mm / (t2 = mm / st));
				ans[qid[Q]] += t1 * t2 * (query(ed) - query(st - 1));
			}
		}
		for (int Q = 1; Q <= Qn; Q++) {
			if (ans[Q] < 0) (++ans[Q]) += 2147483647;
			printf("%d\n", ans[Q]);
		}
	}
	char isp[MXV], mu[MXV];
	int p[3200], pn;
	int mndsum[MXV];
	void getprime() {
		memset(isp, 1, mx + 1);
		mu[1] = 1;
		dsum[1] = mndsum[1] = 1;
		int t;
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				mu[i] = -1;
				dsum[i] = 1 + i;
				mndsum[i] = 1 + i;
				p[pn++] = i;//神Tm这句忘了
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				isp[t] = 0;
				if (i % p[j]) {
					mu[t] = -mu[i];
					dsum[t] = (1 + p[j]) * dsum[i];
					mndsum[t] = 1 + p[j];
				} else {
					mu[t] = 0;
					mndsum[t] = 1 + mndsum[i] * p[j];
					dsum[t] = dsum[i] / mndsum[i] * mndsum[t];
				}
			}
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
