#include <bits/stdc++.h>

using namespace std;

const int N = 14;

int a[2 * N + 1][1 << N], n, pl[(2 * N + 1) * (1 << N)], flag, seq[N], tmp[N];

int ch_1[2 * N + 1][1 << N][2];
int ch_2[2 * N + 1][1 << N][2];
int ch_3[2 * N + 1][1 << N][2];

int check() {
	for(int i = 0 ; i < (2 * n - 1) ; ++ i) {
		for(int j = 0 ; j < (1 << (n - 1)) ; ++ j) {
			if(n == 1) {

			} else if(n == 2) {

			} else if(n == 3) {

			}
		}
	}
}

void dfs(int x, int y) {
	if(x == 2 * n + 1 && y == (1 << (n - 1))) {
		// end
		if(check()) {
			flag = 1;
			for(int i = 0 ; i < (2 * n - 1) ; ++ i) {
				for(int j = 0 ; j < (1 << (n - 1)) ; ++ j) {
					printf("%d", a[i][j]);
				}
				puts("");
			}
		} else if(y == (1 << (n - 1))) {
			dfs(x + 1, 0);
		} else {
			// a[x][y] = 0
			a[x][y] = 0;
			dfs(x, y + 1);

			if(flag) return ;

			// a[x][y] = 1
			a[x][y] = 1;
			dfs(x, y + 1);
		}
	}
}

void sol() {
	
	puts("-1");

	// flag = 0;
	// dfs(0, 0);
	// if(!flag) puts("-1");
}

int main() {
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 0 ; i < n ; ++ i) scanf("%d", &seq[i]);
		sol();
		puts("");
	}
}