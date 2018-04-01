using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int BASE = 100020;
const int MXN = 100050;
inline int &v(int arr[], int idx) {
	return arr[idx + BASE];
}
inline void clear(int arr[], int tot) {
	memset(arr + BASE - tot, 0, (tot * 2 + 1) * sizeof(int));
}
const int DST = 0, NXT = 1, VAL = 2;
const int SUM = 0, GOT = 1;
struct NDC {
	lld ans;
	int head[MXN];
	int edge[MXN << 1][3];
	int eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	int tot;
	int size[MXN], chose, val;
	int mark[MXN];
	void getsize(int nd, int fa) {
		size[nd] = 1;
		int t, mx = 0;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				getsize(t, nd);
				size[nd] += size[t];
				mx = max(mx, size[t]);
			}
		}
		mx = max(mx, tot - size[nd]);
		if (mx < val) {
			val = mx;
			chose = nd;
		}
	}
	int scnt[MXN << 1], gcnt[MXN << 1], ncnt[MXN << 1];
	int node[MXN][2];
	void getnode(int nd, int fa, int sum, int &idx) {
		node[idx][SUM] = sum;
		node[idx++][GOT] = v(scnt, sum);
		if (sum == 0 && v(scnt, 0)) {//在++之前判断 或者 >1 
			ans++;
		}
		v(scnt, sum)++;
		size[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				getnode(t, nd, sum + edge[e][VAL], idx);
				size[nd] += size[t];
			}
		}
		v(scnt, sum)--;
	}
	void calc(int nd, int _tot) {
		tot = _tot;
		val = 1e9;
		getsize(nd, -1);
		nd = chose;
		mark[nd] = 1;
		int t, idx;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (mark[t]) continue;
			getnode(t, nd, edge[e][VAL], idx = 0);
			for (int i = 0; i < idx; i++) {
				ans += (node[i][GOT] || node[i][SUM] == 0) ? v(ncnt, -node[i][SUM]) : 0;
				ans += v(gcnt, -node[i][SUM]);
			}
			for (int i = 0; i < idx; i++) {
				v(node[i][GOT] ? gcnt : ncnt, node[i][SUM])++;
			}
		}
		clear(gcnt, tot);
		clear(ncnt, tot);
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t] && size[t] > 3) {
				calc(t, size[t]);
			}
		}
	}
	
	
}ndc;

struct _Main {
	int n;
	void prepro() {
		read(n);
		int a, b, c;
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			c = c ? c : -1;
			ndc.add(a, b, c);
			ndc.add(b, a, c);
		}
	}
	void solve() {
		ndc.calc(1, n);
		printf("%lld", ndc.ans);
	}
	_Main() {
		prepro();
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
}bzoj3697;
}
