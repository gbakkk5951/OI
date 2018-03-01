#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210;

int mp[N][N], n, visA[N], visB[N];

vector<int> vA;

int dfsA(int u) {
	if(visA[u]) return 0;
	visA[u] = 1;
	vA.push_back(u);
	for(int v = 1 ; v <= n ; ++ v) {
		if(mp[u][v] == 1) {
			if(!dfsA(v)) {
				return 0;
			}
			break;
		}
	}
	return 1;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; ++ i) {
		for(int j = 1 ; j <= n ; ++ j) {
			scanf("%d", &mp[i][j]);
		}
	}
	dfsA(1);
	if(vA.size() != n) {
		puts("-1");
	} else {
		int u = * vA.begin(), v = * -- vA.end();
		if(mp[v][u]) {
			// circle
			puts("0");
			for(int i = 0 ; i < vA.size() ; ++ i) {
				printf("%d ", vA[i]);
			}
		} else {
			// line
			puts("-1");
			for(int i = 0 ; i < vA.size() ; ++ i) {
				printf("%d ", vA[i]);
			}
		}
	}
}
