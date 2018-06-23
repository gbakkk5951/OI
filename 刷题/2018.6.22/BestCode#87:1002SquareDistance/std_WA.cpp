using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <complex>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const int MXN = 505;
struct _Main {
	char str[MXN << 1];
	char gx[MXN], up, down;
	int Tn, n, m;
	int use[2];
	char now[2][MXN];
	void print(char str[]) {
		for (int i = 1; i <= n; i++) {
			printf("%c", str[i]);
		}
		for (int i = 1; i <= n; i++) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
	void lose() {
		printf("Impossible\n");
	}
	_Main() {
		read(Tn);
		int nuse[2];
		char nc[2], *up, *down;
		for (int T = 1; T <= Tn; T++) {
			use[0] = 0;
			read(n); read(m);
			scanf("%s", str + 1);
			n >>= 1;
			up = str, down = str + n;
			for (int i = 1; i <= n; i++) {
				if (up[i] != down[i]) {
					gx[i] = 1;
					++use[0];
				} else {
					gx[i] = 0;
				}
				now[0][i] = min(up[i], down[i]);
			}
			if (use[0] > m) {
				lose();
				continue;
			}
			if (use[0] == m) {
				print(now[0]);
				continue;
			}
			//字典序最小
			for (int i = 1; i <= n && use[0] < m; i++) {
				if (now[0][i] != 'a') {
					if (gx[i] == 1) {
						gx[i] = 2;
						++use[0];
						now[0][i] = 'a';
					} else
					if (gx[i] == 0) {
						if (use[0] + 2 <= m) {
							for (int c = 'a'; c <= 'z'; c++) {
								if (up[i] != c && down[i] != c) {
									now[0][i] = c;
									break;
								}
							}
							gx[i] = 2;
							use[0] += 2;
						}
					}
				}
			}
			if (use[0] == m) {
				print(now[0]);
				continue;
			}
			
			//增大字典序
			memcpy(now[1] + 1, now[0] + 1, n * sizeof(char));
			use[1] = -INF;
			if (use[0] & 1) {
				swap(use[0], use[1]);
			}
			for (int i = n; i >= 1; i--) {
				if (up[i] == down[i]) {
					if (gx[i] == 2) {//改成了'a'
						continue;
					} 
					//原来就是'a';
					for (int I = 0; I < 2; I++) {
						nuse[I] = use[I] + 2;
						nc[I] = 'b';
					}
				} else {
					if (gx[i] == 2) {
						for (int I = 0; I < 2; I++) {
							nuse[I ^ 1] = use[I] - 1;
							nc[I ^ 1] = min(up[I], down[I]);
						}
					} else
					if (gx[i] == 1) {
						for (int c = 'a'; c <= 'z'; c++) {
							if (c != up[i] && c != down[i]) {
								for (int I = 0; I < 2; I++) {
									nuse[I ^ 1] = use[I] + 1;
									nc[I ^ 1] = c;
								}
								break;
							}
						}
					}
				}
				for (int I = 0; I < 2; I++) {
					if (nuse[I] > use[I] && nuse[I] <= m) {
						now[I][i] = nc[I];
						use[I] = nuse[I];
					}
				}
				if (use[0] == m || use[1] == m) {
					break;
				}
			}
			if (use[0] == m) {
				print(now[0]);
			} else
			if (use[1] == m) {
				print(now[1]);
			} else {
				lose();
			}
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
