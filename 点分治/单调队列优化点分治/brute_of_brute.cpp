using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
namespace OI {
const int MXN = 500010, DST = 0, NXT = 1, VAL = 2;
const int INF = 0x3f3f3f3f;
struct _Main {
	int edge[MXN << 1][3];
	int head[MXN];
	int eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	int ans;
	void dfs(int nd, int fa = -1, int sum = 0, int len = 0) {
		if (len >= L) ans = ans > sum ? ans : sum;
		int t;
		if (len < R) for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd, sum + edge[e][VAL], len + 1);
			}
		}
	}
	int L, R;
	_Main() {
		int n, a, b, c;
		ans = -INF;
		read(n); read(L); read(R);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
		}
		for (int i = 1; i <= n; i++) {
			dfs(i);
		}
		printf("%d", ans);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f;
	}
}bob;
}

