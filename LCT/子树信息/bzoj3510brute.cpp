using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int DST = 0, NXT = 1;
const int MXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;//差点忘了 (lld)
int ans;
int fa[MXN];
int getfa(int a) {
	return fa[a] ? fa[a] = getfa(fa[a]) : a;
}
struct _Main {
	char op[5];
	int head[MXN], edge[MXN << 1][2];
	int size[MXN];
	lld sum[MXN];
	lld val;
	int cho;
	int ans, eidx;
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	void dfs1(int nd, int fa) {
		size[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs1(t, nd);
				size[nd] += size[t];
				sum[nd] += sum[t] + size[t];
			}
		}
	}
	void dfs2(int nd, int fa, int tot, lld up) {
		lld tmp = sum[nd] + up;
		if (tmp < val || tmp == val && nd < cho) {
			val = tmp;
			cho = nd;
		}
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs2(t, nd, tot, (sum[nd] - (sum[t] + size[t]) + up) + (tot - size[t]));
			}
		}
	}
	void merge(int a, int b) {
		int ra = getfa(a), rb = getfa(b);
		add(a, b);
		add(b, a);
		ans ^= ra;
		ans ^= rb;
		val = LINF;
		dfs1(a, 0);
		dfs2(a, 0, size[a], 0);
		fa[ra] = fa[rb] = cho;
		fa[cho] = 0;
		printf("%d\n", cho);
		ans ^= cho;
	}
	_Main() {
		int n, Qn;
		int x, y;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			ans ^= i;
		}
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			if (op[0] == 'A') {
				read(x); read(y);
				merge(x, y);
			} else
			if (op[0] == 'Q') {
				read(x);
		//		printf("%d\n", getfa(x));
			} else 
			if (op[0] == 'X') {
		//		printf("%d\n", ans);
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
}bzoj3510;
}

