using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
namespace OI {
const int SQ = 20;
const int MXN = 1e5 + 10;
const int BASE = 1 << 17;
struct Tree {
	int node[BASE * 2 + 10];
	void insert(int nd) {
		nd += BASE;
		while (nd > 1) {
			++node[nd];
			nd >>= 1;
		}
	}
	void erase(int nd) {
		nd += BASE;
		while (nd > 1) {
			--node[nd];
			nd >>= 1;
		}
	}
	int pre(int nd) {
		nd += BASE;
		if (node[nd]) return nd - BASE;
		while (nd > 1 && ((~nd & 1) || !node[nd ^ 1])) {
			nd >>= 1;
		}
		if (nd == 1) return 0; 
		nd ^= 1;
		while (nd < BASE) {
			nd <<= 1;
			nd |= node[nd | 1] != 0;
		}
		return nd - BASE; 
	}
	int nxt(int nd) {
		nd += BASE;
		if (node[nd]) return nd - BASE;
		while (nd > 1 && ((nd & 1) || !node[nd ^ 1])) {
			nd >>= 1;
		}
		if (nd == 1) return 0; 
		nd ^= 1;
		while (nd < BASE) {
			nd <<= 1;
			nd |= node[nd] == 0;
		}
		return nd - BASE;
	}
	void clear() {
		memset(node, 0, sizeof(node));
	}
}tree;

struct _Main {
	int arr[MXN];
	_Main() {
		freopen("gap.in", "r", stdin);
		freopen("gap.out", "w", stdout);
		int Tn, a, b;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			int n, mn, ans = 0;
			int h;
			read(n); read(mn);
			for (int i = 1; i <= n; i++) {
				read(arr[i]);
			}
			for (int i = 1; i <= SQ; i++) {
				h = 1;
				for (int j = 1; j <= n; j++) {
					while(1) {
						a = tree.pre(arr[j]); 
						b = tree.nxt(arr[j]);
						if (a && arr[j] - a < i || b && b - arr[j] < i) {
							tree.erase(arr[h++]);
						} else {
							break;
						}
					}
					tree.insert(arr[j]);
					if (j - h + 1 >= mn) {
						ans = max(ans, i * (j - h));
					}
				}
				tree.clear();
			}
			for (int i = 1; i <= n; i++) {
				int now = 1e5 + 10;
				for (int j = i; j <= n; j++) {
					a = tree.pre(arr[j]);
					b = tree.nxt(arr[j]);
					if (a) now = min(now, arr[j] - a);
					if (b) now = min(now, b - arr[j]);
					if (now <= SQ) {
						for (int k = i; k < j; k++) {
							tree.erase(arr[k]);
						}
						break;
					}
					tree.insert(arr[j]);
					if (j - i + 1 >= mn) {
						ans = max(ans, now * (j - i));
					}
					if (j == n) {
						for (int k = i; j <= j; k++) {
							tree.erase(arr[k]);
						}
					} 
				}
			}
			printf("%d\n", ans);
		}
		fclose(stdout);
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}gap;
}

