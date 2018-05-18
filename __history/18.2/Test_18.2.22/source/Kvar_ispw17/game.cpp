#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 200 + 5;
const int M = N * N;

int dp[2][N], n;
int hd[2][N], nxt[2][M], to[2][M], tot[2], in[2][N];

void add(int op, int a, int b) {
	nxt[op][++tot[op]] = hd[op][a], to[op][hd[op][a] = tot[op]] = b;
	in[op][b]++;
}


int que[N];
bool is_chain;

void procedure(int op) {
	op ^= 1;
	int head = 1, tail = 0;
	for(int i = 1; i <= n; i++) {
		if(in[op][i] == 0) que[++tail] = i;
	}
	while(head <= tail) {
		int u = que[head++];
		for(int e = hd[op][u]; e; e = nxt[op][e]) {
			int v = to[op][e];
			dp[op^1][v] = dp[op^1][u] + 1;
			if(--in[op][v] == 0) que[++tail] = v;
		}
	}
	if(head != n + 1) is_chain = false;
	else is_chain = true;
}

#define JUDGE

int ans[2][2 * N];

void dfs(int op, int u) {
	for(int e = hd[op][u]; e; e = nxt[op][e]) {
		int v = to[op][e];
		if(dp[op][v] + 1 == dp[op][u]) {
			ans[op][++ans[op][0]] = v;
			dfs(op, v);
			return;
		}
	}
}

int main() {
#ifdef JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			if(i == j) continue;
			if(x == 1) add(0, i, j), add(1, j, i);
			else add(0, j, i), add(1, i, j);
		}
	}
	procedure(0);
	procedure(1);
	int nd = 0;
	for(int i = 1; i <= n; i++)
		if(dp[0][i] + dp[1][i] == n - 1) nd = i;
	if(!is_chain) {
		printf("0\n");
	} else {
		printf("1\n");
		if(nd != 0) {
			dfs(0, nd);
			dfs(1, nd);
			std::reverse(ans[1] + 1, ans[1] + ans[1][0] + 1);
			ans[1][ans[1][0] + 1] = nd;
			for(int i = 1; i <= ans[0][0]; i++)
				ans[1][i + ans[1][0] + 1] = ans[0][i];
			for(int i = 1; i <= ans[0][0] + ans[1][0] + 1; i++) printf("%d ", ans[1][i]);
		} else printf("-1\n");
	}

#ifdef JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
