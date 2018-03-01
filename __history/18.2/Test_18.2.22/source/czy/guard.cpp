//%:pragma GCC optimize(2)
//%:pragma GCC optimize(3)

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int m, num[110], gra[110][110], id[110][110], n, mat[110], hid[110], a, b, c, ans, cc, cnt, ret;

struct E { int c, a, b; };

vector<E> e;

bitset<110> vis;

int dfs(int u) {
	for(int v = 1 ; v <= n ; ++ v)
		if(!hid[v] && gra[u][v] && !vis.test(v) && (vis.set(v), (!mat[v] || dfs(mat[v]))))
			return !!(mat[v] = u);
	return 0;
}

inline int nextc(int c) { return c + 1 > m ? 1 : c + 1; }

int main() {
	freopen("guard.in", "r", stdin), freopen("guard.out", "w", stdout);
	scanf("%d", &m);
	while(scanf("%d%d%d", &a, &b, &c) == 3)
		e.push_back((E) {c, a, b}), num[c] = max(num[c], a), num[nextc(c)] = max(num[nextc(c)], b);
	for(int i = 1 ; i <= m ; ++ i) for(int j = 1 ; j <= num[i] ; ++ j) id[i][j] = ++ n;
	for(int i = 0 ; i < e.size() ; ++ i) c = e[i].c, a = e[i].a, b = e[i].b, gra[ id[c][a] ][ id[nextc(c)][b] ] = 1, gra[ id[nextc(c)][b] ][ id[c][a] ] = 1;
	if(m & 1) {
		for(int i = 1 ; i <= m ; ++ i) (num[i] > 10) || (cc = i);
		for(int s = 0 ; s < (1 << num[cc]) ; ++ s) {
			cnt = 0, ret = 0, memset(hid, 0, sizeof hid), memset(mat, 0, sizeof mat);
			for(int i = 1 ; i <= num[cc] ; ++ i) if((hid[ id[cc][i] ] = 1), (s >> (i - 1)) & 1) 
				for(int j = !!(++ cnt) ; j <= n ; ++ j) (gra[ id[cc][i] ][j]) && (hid[j] = 1);
			for(int i = 1 ; i <= n ; ++ i) hid[i] || (++ cnt, vis.reset(), ret += dfs(i));
			ans = max(ans, cnt - ret / 2);
		}
	} else {
		ans = n;
		for(int i = 1 ; i <= n ; i += 2)
			for(int j = 1 ; j <= num[i] ; ++ j) vis.reset(), ans -= dfs(id[i][j]);
	}
	printf("%d\n", ans);
}

