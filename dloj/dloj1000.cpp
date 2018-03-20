using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
namespace OI {
typedef long long lld;
const int MXN = 500050;
int ans[MXN], ql[MXN], qr[MXN];
int arr[MXN];
int n, Qn, mx;
struct LS {
	inline int operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	inline int operator [] (int a) {
		return a << 1 | 1;
	}
}rs;

struct Range{
	int l, r, id, bl;
}rg[MXN];
inline bool cmp1(const Range &a, const Range &b) {
	if (a.bl != b.bl) {
		return a.bl < b.bl;
	}
	return a.r < b.r;
}

struct Solver1{//Äª¶Ó
	int nl, nr;
	int cnt[MXN], nowans;
	void solve() {
		int sq = ceil(sqrt(Qn));
		for (int Q = 1; Q <= Qn; Q++) {
			rg[Q].bl = rg[Q].l / sq;
		}
		sort(rg + 1, rg + Qn + 1, cmp1);
		int now = -1, l, r;
		for (int Q = 1; Q <= Qn; Q++) {
			if (now != rg[Q].bl) {
				memset(cnt, 0, (mx + 1) * sizeof(int));
				now = rg[Q].bl;
				l = (rg[Q].bl + 1) * sq;
				r = l - 1;
				nowans = mx + 1;
			}
			while (r < rg[Q].r) {
				if (++cnt[arr[++r]] > cnt[nowans] || cnt[arr[r]] == cnt[nowans] && arr[r] < nowans) {
					nowans = arr[r];
				}
			}
			int org = nowans;
			for (int i = rg[Q].l ; i <= rg[Q].r && i < l; i++) {
				if (++cnt[arr[i]] > cnt[nowans] || cnt[arr[i]] == cnt[nowans] && arr[i] < nowans) {
					nowans = arr[i];
				}
			}
			ans[rg[Q].id] = nowans;
			for (int i = rg[Q].l; i <= rg[Q].r && i < l; i++) {
				--cnt[arr[i]];
			}
			nowans = org;
		}
	}
	
}solver1;

inline bool cmp2(const Range &a, const Range &b) {
	if (a.l != b.l) {
		return a.l < b.l;
	}
	return a.r > b.r;
}

struct Solver2{//½¨Ê÷
	int f[MXN];
	int cnt[MXN];
	char leaf[MXN], vis[MXN];
	
	void solve() {
		int nd = 0;
		int nowans = mx + 1;
		vis[0] = 1;
		sort(rg + 1, rg + Qn + 1, cmp2);
		rg[0].l = 0, rg[0].r = n + 1;
		for (int Q = 1; Q <= Qn; Q++) {
			if (rg[Q].r > rg[nd].r) {
				leaf[nd] = 1;
				do {
					nd = f[nd]; 
				} while (rg[Q].r > rg[nd].r);
			}
			f[Q] = nd;
			nd = Q;
		}
		leaf[Qn] = 1;
		int l, r;
		for (int Q = 1; Q <= Qn; Q++) {
			if (leaf[nd = Q]) {
				l = rg[nd].l; r = l - 1;
				while (!vis[nd]) {
					while (l > rg[nd].l) {
						if (++cnt[arr[--l]] > cnt[nowans] || cnt[arr[l]] == cnt[nowans] && arr[l] < nowans) {
							nowans = arr[l];
						}
					}
					while (r < rg[nd].r) {
						if (++cnt[arr[++r]] > cnt[nowans] || cnt[arr[r]] == cnt[nowans] && arr[r] < nowans) {
							nowans = arr[r];
						}
					}
					vis[nd] = 1;
					ans[rg[nd].id] = nowans;
					nd = f[nd];
				}
				nowans = mx + 1;
				for (int i = l; i <= r; i++) {
					--cnt[arr[i]];
				}
			}
		}
	}	
}solver2;
struct _Main {
	_Main() {
		int Tidx;
		read(Tidx);
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
			mx = max(mx, arr[i]);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(rg[Q].l); read(rg[Q].r);
			rg[Q].id = Q; 
		}
		if (Tidx <= 6) {
//			solver2.solve();
			solver1.solve();
		} else { //tree
			solver2.solve();
		}
		for (int i = 1; i <= Qn; i++) {
			printf("%d ", ans[i]);
		}
		lld lstans = 0;
		int andsum[20];
		lld addsum[20];
		memset(andsum, -1, sizeof(andsum));
		memset(addsum, 0, sizeof(addsum));
		for (int Q = Qn; Q >= 1; Q--) {
			int t = ans[Q];
			for (int I = 0; I == 0 || (1 << I - 1 <= mx); I++) {
				lstans = max(lstans, t + addsum[I] + (t & andsum[I]));
			}
			addsum[0] += t;
			andsum[0] &= t;
			for (int I = 1; 1 << I - 1 <= mx; I++) {
				if ((1 << I - 1) & t) {
					addsum[I] += t;
					andsum[I] &= t;
				} else {
					andsum[I] = -1;
					addsum[I] = 0;
				}
			}
		}
		printf("\n%lld", lstans);
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

}dloj1001;

}
