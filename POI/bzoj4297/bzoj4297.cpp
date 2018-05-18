using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 500010;
const int DST = 0, NXT = 1;
struct _Main {
	int l[MXN], r[MXN];
	int srt[MXN << 1];
	int rsum[MXN << 1];//左边r端点的sum
	int lsum[MXN << 1];//右边l端点的sum
	int la[MXN], ra[MXN];
	lld ans;
	void dfs(int nd, int fa) {
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && t > m) {
				dfs(t, nd);
			}
		}
		int idx = 0, cl = 0;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				++cl;
				la[cl] = l[t];
				ra[cl] = r[t];
//				cl++;
				srt[++idx] = l[t];
				if (l[t] != r[t]) srt[++idx] = r[t];
			}
		}
		sort(srt + 1, srt + idx + 1);
		idx = unique(srt + 1, srt + idx + 1) - srt - 1; //别忘了-1
		memset(lsum, 0, (idx + 2) * sizeof(int));
		memset(rsum, 0, (idx + 2) * sizeof(int));
		for (int i = 1; i <= cl; i++) {
			lsum[lower_bound(srt + 1, srt + idx + 1, la[i]) - srt]++;
		}
		for (int i = 1; i <= cl; i++) {
			rsum[lower_bound(srt + 1, srt + idx + 1, ra[i]) - srt]++;
		}
		for (int i = idx; i >= 1; i--) {
			lsum[i] += lsum[i + 1];
		}
		for (int i = 1; i <= idx; i++) {
			rsum[i] += rsum[i - 1];
		}	
		r[nd] = idx;
		while (r[nd] > 1 && lsum[r[nd]] < rsum[r[nd] - 1]) {
			r[nd]--;
		}
		l[nd] = 1;
		while (l[nd] < idx && rsum[l[nd]] < lsum[l[nd] + 1] ) {
			l[nd]++;
		}
		//神TM各种手造输入结果对了，但过程错了 
		l[nd] = srt[l[nd]];
		r[nd] = srt[r[nd]];
		for (int i = 1; i <= cl; i++) {
			if (la[i] > l[nd] || ra[i] < l[nd]) {
				ans += min(abs(l[nd] - la[i]), abs(l[nd] - ra[i]));
			}
		}
	}
	int head[MXN], edge[MXN << 1][2];
	int n, m, eidx;
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	_Main() {
		read(n); read(m);
		int u, v;
		for (int i = 1; i <= n - 1; i++) {
			read(u); read(v);
			add(u, v); add(v, u);
		}
		for (int i = 1; i <= m; i++) {
			read(l[i]);
		}
		memcpy(r + 1, l + 1, m * sizeof(int));
		if (n == 2) {
			printf("%d", abs(r[1] - r[2]));
			return;
		}
		dfs(m + 1, 0);
		printf("%lld", ans);
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
}bzoj4297;
}
