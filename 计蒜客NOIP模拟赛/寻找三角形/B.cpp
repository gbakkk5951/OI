using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <cmath>
namespace OI {
typedef double lf;
const int MXN = 100010;
const int DST = 0, NXT = 1;
int n, m;

int id[MXN], mark[MXN];
int deg[MXN], head[MXN];
int edge[MXN << 1][2];
int eidx;
void add(int a, int b) {
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
	deg[a]++;
}
int sq;

bitset<MXN> bit[65], tmp;
int bidx, ans;
int vis[MXN];
void getbit(int nd) {
	id[nd] = ++bidx;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		bit[id[nd]][edge[e][DST]] = 1;
	}
}
void getvis(int nd) {
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		vis[edge[e][DST]] = 1;
	}
}
void devis(int nd) {
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		vis[edge[e][DST]] = 0;
	}
}
void calcvv(int nd) {
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if (vis[edge[e][DST]]) {
			ans = edge[e][DST];
			return;
		}
	}
}
void calcvb(int nd, int id) {
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if (bit[id][edge[e][DST]]) {
			ans = edge[e][DST];
			return;
		}
	}
}
void calcbb(int ia, int ib) {
	tmp = bit[ia] & bit[ib];
	if (tmp.count() == 1) {
		for (int i = 1; i <= n; i++) {
			if (tmp[i]) {
				ans = i;
				return;
			}
		}
	}
}
struct _Main {
	
	
	_Main() {
		int arr[3], t, a, b;
		read(n); read(m);
		sq = ceil(pow((lf)n, 3.0 / 4.0));
		for (int i = 1; i <= m; i++) {
			read(a); read(b);
			add(a, b); add(b, a);
		}
		for (int i = 1; i < n; i++) {
			if (head[i] == 0) continue;
			arr[0] = i;
			mark[i] = 1;
			if (deg[i] >= sq) {
				if (!id[i]) getbit(i);
				for (int e = head[i]; e; e = edge[e][NXT]) {
					t = edge[e][DST];
					if (!mark[t]) {
						arr[1] = t;
						if (deg[t] >= sq) {
							if (!id[t]) getbit(t);
							calcbb(id[i], id[t]);
						} else {
							calcvb(t, id[i]);
						}
						if (ans) break;
					}
				}
			} else {
				getvis(i);
				for (int e = head[i]; e; e = edge[e][NXT]) {
					t = edge[e][DST];
					if (!mark[t]) {
						arr[1] = t;
						if (deg[t] >= sq) {
							if (!id[t]) getbit(t);
							calcvb(i, id[t]);
						} else {
							calcvv(t);
						}
						if (ans) break;
					}
				}
				devis(i);
			}
			if (ans) break;
		}
		arr[2] = ans;
		sort(arr, arr + 3);
		for (int i = 0; i <= 2; i++) {
			printf("%d ", arr[i]);
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
}B;
}
