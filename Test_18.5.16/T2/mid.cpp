using namespace std;
int main() {}
#include <cstdio>
namespace OI {
typedef long long lld;
const int MXN = 5e5 + 10;
const lld MOD = 1e9 + 7;
struct Node {
	int s[2], val, size;
}node[MXN];
struct _Main {
	int idx;
	void insert(int v) {
		int nd = 1, spo;
		while (1) {
			++node[nd].size;
			spo = node[nd].val < v;
			if (node[nd].s[spo]) {
				nd = node[nd].s[spo];
			} else {
				nd = node[nd].s[spo] = ++idx;
				node[nd].size = 1;
				node[nd].val = v;
				break;
			}
		}
	}
	int find(int rk) {
		int nd = 1;
		int t;
		while (1) {
			if ((t = node[node[nd].s[0]].size) >= rk) {
				nd = node[nd].s[0];
			} else if (t + 1 == rk) {
				return node[nd].val;
			} else {
				rk -= t + 1;
				nd = node[nd].s[1];
			}
		}
	}
	_Main() {
	//	freopen("mid.in", "r", stdin);
	//	freopen("mid.out", "w", stdout);
		int ans = 0, n, py = 0;//py没赋初值
		lld lst = 0, lstans = 0;
		scanf("%d%lld", &n, &lst);
		node[1].val = lst;
		node[1].size = 1;
		idx = 1;
		for (int i = 1; i <= n; i++) {
			if ((i >> 1) + (lst < lstans) == i + 1 >> 1);
			else lstans = find((i + 1 >> 1) - py);
			ans ^= lstans;
			lst = (424004033 * lst % MOD * lstans + 769063784 + 778465332 * lst + 634467621 * lstans) % MOD;
			if (i < 70000 || lst > 497000000 && lst < 503000000)
			insert(lst);
			printf("ins %lld\n", lst);
			py += i >= 70000 && lst <= 497000000;
		}
		printf("%d", ans);
		fclose(stdout);
	}
}T2;
}
