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
struct _Main {
	int arr[2][19];
	int *dp[2];
	char a[15], b[15];
	int pow[10];
	int getdp(int n) {
		int ans = 0;
		memset(arr, 0, sizeof(arr));
		int lst = 0, t;
		for (int i = 1; i <= n; i++) {
			memset(arr[i & 1], 0, sizeof(arr[i & 1]));
			//贴边
			if (lst != -INF) {
				if (lst > -1000000) {
					lst <<= 1;
				}
				for (int j = 0; j < b[i]; j++) {
					t = lst + j - a[i];
					if (t < -9) {
						ans += pow[n - i];
					} else
					if (t <= 9) {
						dp[i & 1][t] += 1;//i & 1
					} else {
						break;
					}
				}
				lst += b[i] - a[i];
				if (lst > 9) {
					lst = -INF;
				}
			}
			//不贴边
			for (int j = -9; j <= 9; j++) {
				if (dp[~i & 1][j]) {
					for (int k = 0; k <= 9; k++) {
						t = (j << 1) + k - a[i];
						if (t < -9) {
							ans += dp[~i & 1][j] * pow[n - i];
						} else
						if (t <=  9) {
							dp[i & 1][t] += dp[~i & 1][j];
						} 
					}
				}
			}
		}
		if (lst <= 0 && lst != -INF) ans++;
		for (int i = -9; i <= 0; i++) {
			ans += dp[n & 1][i];
		}
		return ans;
	}
	_Main() {
		int Qn;
		pow[0] = 1;
		for (int i = 1; i <= 9; i++) {
			pow[i] = pow[i - 1] * 10;
		}
		for (int i = 0; i < 2; i++) {
			dp[i] = arr[i] + 9;
		}
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			scanf("%s%s", a + 1, b + 1);
			int l1, l2;
			l1 = strlen(a + 1), l2 = strlen(b + 1);
			for (int i = 1; i <= l1; i++) {
				a[i] -= '0';
			}
			for (int i = 1; i <= l2; i++) {
				b[i] -= '0';
			}
			if (l1 < l2) {
				for (int i = l2; i > l2 - l1; i--) {
					a[i] = a[l1 - (l2 - i)];
				}
				for (int i = l2 - l1; i >= 1; i--) {
					a[i] = 0;
				}
			} else
			if (l2 < l1) {
				for (int i = l1; i > l1 - l2; i--) {
					b[i] = b[l2 - (l1 - i)];
				}
				for (int i = l1 - l2; i >= 1; i--) {
					b[i] = 0;
				}
			}
			int ans = getdp(max(l2, l1));
			printf("Case #%d: %d\n", Q, ans);
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
