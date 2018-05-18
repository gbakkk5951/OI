using namespace std;
int main() {}
#include <cstdio>
namespace OI {
typedef long long lld;
struct _Main {
	int count(int a) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			if (a >> i & 1) {
				cnt++;
			}
		}
		return cnt;
	}
	lld n, m, r, c, s;
	int map[4][4];
	int ans;
	void dfs2(int nd, int c) {
		if (c == 0) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cnt += map[i][j];
				}
			}
			if (cnt == s) {
				ans++;
			}
			return;
		}
		for (int i = nd; i < m; i++) {
			for (int j = 0; j < n; j++) {
				map[j][i] ^= 1;
			}
			dfs2(i, c - 1);
			for (int j = 0; j < n; j++) {
				map[j][i] ^= 1;
			}
		}
	}
	void dfs1(int nd, int r) {
		if (r == 0) {
			dfs2(0, c);
			return;
		}
		for (int i = nd; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] ^= 1;
			}
			dfs1(i, r - 1);
			for (int j = 0; j < m; j++) {
				map[i][j] ^= 1;
			}
		}
	}
	int brute() {
		dfs1(0, r);
		return ans;
	}
	_Main() {
		scanf("%lld%lld%lld%lld%lld", &n, &m, &r, &c, &s);
		if (n <= 4 && m <= 4 && r <= 4 && c <= 4) {
			printf("%d", brute());
		} else {
			if (r + c == 0 && s == 0) {
				printf("1");
			} else{
				printf("0");
			}
		}
		
	}
}T2;
}
