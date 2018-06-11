using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
namespace OI {
typedef unsigned char uc;
typedef unsigned int u;
const int SQ = 20;
const int MXN = 1e5 + 10;
struct _8Tree {
	uc nxt[256][8], pre[256][8];
	uc lnxt[256][8], lpre[256][8];//含自己
	u base;
	int cnt[100010];
	_8Tree() {
		//maintain 0 ~ 2^18 - 1, first leaf = base
		base = ((1 << 18) - 1) / 7;
		for (int i = 0; i < 256; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = j + 1; k < 8; k++) {
					if (i >> k & 1) {
						nxt[i][j] = k + 1;
						break;
					}
				}
				for (int k = j - 1; k >= 0; k--) {
					if (i >> k & 1) {
						pre[i][j] = k + 1;
						break;
					}
				}
				for (int k = j; k < 8; k++) {
					if (i >> k & 1) {
						lnxt[i][j] = k + 1;
						break;
					}
				}
				for (int k = j; k >= 0; k--) {
					if (i >> k & 1) {
						lpre[i][j] = k + 1;
						break;
					}
				}
			}
		}
	}
	unsigned char node[37500];
	void clear() {
		memset(node, 0, sizeof(node));
		memset(cnt, 0, sizeof(cnt));
	}
	void insert(int nd) {
		++cnt[nd];
		u s;
		nd += base;
		while (nd--) {
			s = nd & 7;
			nd >>= 3;//神Tm nd = 3
			node[nd] |= 1u << s;
			if (node[nd] != 1u << s) break;//不用上传
		}
	}
	void erase(int nd) {
		--cnt[nd];
		u s;
		nd += base;
		while (nd--) {
			s = nd & 7;
			nd >>= 3;
			if (node[nd] ^= 1u << s) break;//不用上传
		}
	}
	int getnxt(int nd) {
		if (cnt[nd]) return nd;
		u s;
		nd += base;
		while (nd--) {
			s = nd & 7;
			nd >>= 3;
			if (s = nxt[node[nd]][s]) {
				nd = (nd << 3) + s;
				break;
			}
		}
		if (nd == -1) return 0;
		while (nd < base) {
			nd = (nd << 3) + lnxt[node[nd]][0];
		}
		return nd - base;
	}
	int getpre(int nd) {
		if (cnt[nd]) return nd;
		u s;
		nd += base;
		while (nd--) {
			s = nd & 7;
			nd >>= 3;
			if (s = pre[node[nd]][s]) {
				nd = (nd << 3) + s;
				break;
			}
		}
		if (nd == -1) return 0;//这个没更新
		while (nd < base) {
			nd = (nd << 3) + lpre[node[nd]][7];
		}
		return nd - base;
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
						a = tree.getpre(arr[j]); 
						b = tree.getnxt(arr[j]);
	//					printf("%d pre = %d, nxt = %d\n", arr[j], a, b);
						if (a && arr[j] - a < i || b && b - arr[j] < i) {
	//						printf("erase %d\n", arr[h]);
							tree.erase(arr[h++]);
						} else {
							break;
						}
					}
					tree.insert(arr[j]);
	//				printf("ins %d\n", arr[j]);
					if (j - h + 1 >= mn) {
						ans = max(ans, i * (j - h));
					}
				}
	//			printf("clear\n");
				tree.clear();
			}
		//	continue;
			for (int i = 1; i <= n; i++) {
				int now = 1e5 + 10;
				for (int j = i; j <= n; j++) {
					a = tree.getpre(arr[j]);
					b = tree.getnxt(arr[j]);
			//		printf("%d pre = %d, nxt = %d\n", arr[j], a, b);
					if (a) now = min(now, arr[j] - a);
					if (b) now = min(now, b - arr[j]);
					/*if (now <= SQ) {
			//			printf("clear\n");
						for (int k = i; k < j; k++) {
							tree.erase(arr[k]);
						}
						break;
					}
					*/
			//		printf("ins %d\n", arr[j]);
					if (j - i + 1 >= mn) {
						ans = max(ans, now * (j - i));
					}
					if (now <= SQ || j == n) {//忘了清除了
//						printf("clear\n");
						for (int k = i; k < j; k++) {
							tree.erase(arr[k]);
						}
						break;
					}
					tree.insert(arr[j]);
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

