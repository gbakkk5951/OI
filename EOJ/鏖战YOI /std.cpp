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
#include <cassert>
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
const int MXN = 1e5 + 10;
struct _Main {
	int L, R;
	int n;
	int arr[MXN];
	lld ans[MXN];
	lld tag[MXN];
	lld sum[MXN];
	int d[MXN], dh, dt;
	void calc(int l, int r) {
		int mid = l + r >> 1;
		/*向右*/ {
			dh = 0; dt = -1;
			int lidx = l - 1;
			memset(tag + mid, 192, (r - mid + 1) * sizeof(lld));
			sum[l - 1] = 0;
			for (int i = l; i <= r; i++) {
				sum[i] = sum[i - 1] + arr[i];
			}
			for (int i = mid; i <= r; i++) {
				while (i - lidx >= L && lidx < mid) {
					while (dt >= dh && sum[lidx] <= sum[d[dt]]) {
						--dt;
					}
					d[++dt] = lidx++;
				}
				while (dt >= dh && i - d[dh] > R) {
					++dh;
				}
				if (dt >= dh) {
					tag[i] = sum[i] - sum[d[dh]];
				} else {
					tag[i] = -LINF;
				}
			}
			for (int i = r - 1; i >= mid; i--) {
				tag[i] = max(tag[i], tag[i + 1]);
			}
			for (int i = mid; i <= r; i++) {
				ans[i] = max(ans[i], tag[i]);
			}
		}
		/*向左*/ {
			dh = 0; dt = -1;
			int ridx = r + 1;
			memset(tag + l, 192, (mid - l + 1) * sizeof(lld));
			sum[r + 1] = 0;
			for (int i = r; i >= l; i--) {
				sum[i] = sum[i + 1] + arr[i];
			}
			for (int i = mid; i >= l; i--) {
				while (ridx - i >= L && ridx > mid) {
					while (dt >= dh && sum[ridx] <= sum[d[dt]]) {
						--dt;
					}
					d[++dt] = ridx--;
				}
				while (dt >= dh && d[dh] - i > R) {
					++dh;
				}
				if (dt >= dh) {
					tag[i] = sum[i] - sum[d[dh]];
				} else {
					tag[i] = -LINF;
				}
			}
			for (int i = l + 1; i <= mid; i++) {
				tag[i] = max(tag[i], tag[i - 1]);
			}
			for (int i = l; i <= mid; i++) {
				ans[i] = max(ans[i], tag[i]);
			}
		}
		
		if (mid > l) {
			calc(l, mid - 1);
		}
		if (mid < r) {
			calc(mid + 1, r);
		}
	}
	_Main() {
		read(n); read(L); read(R);
		memset(ans + 1, 192, n * sizeof(lld));
		for (int i = 1; i <= n; i++) {
			read(arr[i]); 
		}
		calc(1, n);
		for (int i = 1; i <= n; i++) {
			printf("%lld ", ans[i]);
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
