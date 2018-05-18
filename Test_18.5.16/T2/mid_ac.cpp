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
int nxt[MXN], pre[MXN];
struct _Main {
	int idx;
	int insert(int v) {
		int nd = 1, spo;
		int rk = 1;
		while (1) {
			++node[nd].size;
			if (spo = node[nd].val < v) {
				rk += node[node[nd].s[0]].size + 1;
			}
			if (node[nd].s[spo]) {
				nd = node[nd].s[spo];
			} else {
				nd = node[nd].s[spo] = ++idx;
				node[nd].size = 1;
				node[nd].val = v;
				break;
			}
		}
		return rk;
	}
	int find(int rk) {
		int nd = 1;
		int t;
		while (1) {
			if ((t = node[node[nd].s[0]].size) >= rk) {
				nd = node[nd].s[0];
			} else if (t + 1 == rk) {
				return nd;
			} else {
				rk -= t + 1;
				nd = node[nd].s[1];
			}
		}
	}
	_Main() {
		freopen("mid.in", "r", stdin);
		freopen("mid.out", "w", stdout);
		int ans = 0, n, py = 0, id, rk, tmp;//py没赋初值
		int lstrk, nowrk;
		lld lst = 0, lstans = 0;
		scanf("%d%lld", &n, &lst);
		node[1].val = lst;
		node[1].size = 1;
		lst = node[1].val;
		lstans = 0;
		idx = 1;
		id = 0;
		nxt[0] = 1;
		for (int i = 1; i <= n; i++) {
			lstrk = (i >> 1) + (lst < lstans);
			nowrk = i + 1 >> 1;
			if (lstrk < nowrk) {
				id = nxt[id];
				lstans = node[id].val;
			} else if (lstrk > nowrk) {
				id = pre[id];
				lstans = node[id].val;
			}
			ans ^= lstans;
			lst = (424004033 * lst % MOD * lstans + 769063784 + 778465332 * lst + 634467621 * lstans) % MOD;
			if (i < 100000 || lst > 495000000 && lst < 505000000) {
				rk = insert(lst);
				if (rk != 1) {
					tmp = find(rk - 1);
					nxt[tmp] = idx;
					pre[idx] = tmp;
				}
				if (rk != idx) {
					tmp = find(rk + 1);
					pre[tmp] = idx;
					nxt[idx] = tmp;
				}
			}
			py += i >= 100000 && lst <= 495000000;
		}
		printf("%d", ans);
		fclose(stdout);
	}
}T2;
}
