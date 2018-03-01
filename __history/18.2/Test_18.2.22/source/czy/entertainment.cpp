#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, k, ms, me, ans, val[3][N], c[N];

void dfs(int dy) {
	if(dy == n + 1) {
		for(int i = 1 ; i + k - 1 <= n ; ++ i) {
			int slp = 0, et = 0;
			for(int j = i ; j <= i + k - 1 ; ++ j) {
				slp += c[j] == 1;
				et += c[j] == 2;
			}
			if(slp < ms || et < me) return;
		}
		int ret = 0;
		for(int i = 1 ; i <= n ; ++ i) {
			ret += val[c[i]][i];
		}
		ans = max(ans, ret);
	} else {
		// sleep
		c[dy] = 1;
		dfs(dy + 1);
		// eat
		c[dy] = 2;
		dfs(dy + 1);
	}
}

int main() {
	freopen("entertainment.in", "r", stdin);
	freopen("entertainment.out", "w", stdout);

	scanf("%d%d%d%d", &n, &k, &ms, &me);
	for(int i = 1 ; i <= n ; ++ i) scanf("%d", &val[1][i]);
	for(int i = 1 ; i <= n ; ++ i) scanf("%d", &val[2][i]);
	dfs(1);
	printf("%d\n", ans);
}
