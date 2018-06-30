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
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
const int MXN = 1e3 + 10;
struct _Main {
	
	int sum[MXN];
	int dp1[2][MXN];
	int dp2[2][MXN];
	int n, k;
	int getdp() {
		int ans = 0;
		memset(dp1, 192, sizeof(dp1));
		memset(dp2, 192, sizeof(dp2));
		for (int I = 1; I <= k; I++) {
			int *dp1 = this->dp1[I & 1];
			int *dp2 = this->dp2[I & 1];
			int *ldp1 = this->dp1[~I & 1];
			int *ldp2 = this->dp2[~I & 1];
			if (I == 1) {
				for (int i = 1; i <= n; i++) {
					dp1[i] = max(dp1[i - 1], -sum[i] + sum[i - 1]);
				}
				for (int i = 1; i <= n; i++) {
					dp2[i] = sum[i];
				}
			} else
			if (I != k) {
				for (int i = 1; i <= n; i++) {
					int si = sum[i];
					int d1 = dp1[i - 1];
					int d2 = dp2[i - 1];
					for (int j = i - 1; j >= 0; j--) {
						int sj = sum[j];
						d1 = max(d1, ldp1[j]);
						d1 = max(d1, (-si << 1) + (sj << 1) + ldp2[j]);
						d2 = max(d2, (si << 1) - (sj << 1) + ldp1[j]);
						d2 = max(d2, ldp2[j]);
					}
					dp1[i] = d1;
					dp2[i] = d2;
				}
			} else {
				for (int i = 1; i <= n; i++) {
					int si = sum[i];
					for (int j = i - 1; j >= 0; j--) {
						int sj = sum[j];
						ans = max(ans, si - sj + ldp1[j]);
						ans = max(ans, -si + sj + ldp2[j]);
					}
				}
			}
		}
		
		return ans;
	}
	_Main() {
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
		read(n); read(k);
		for (int i = 1; i <= n; i++) {
			read(sum[i]);
			sum[i] += sum[i - 1];
		}
		printf("%d", getdp());
		fclose(stdout);
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
