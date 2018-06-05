using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cstdio>
#include <iostream>
namespace OI {
typedef long long lld;
const lld MASK = (1LL << 40) - 1;
const int MXN = (1 << 20) - 1;
lld base[(1 << 20) + 97];
struct _Main {
	_Main() {
		freopen("chart.out", "w", stdout);
		lld pow[41];
		lld lst = 0;
		int mxbit = 1;
		lld tmp;
		pow[0] = 1;
		for (int i = 1; i <= 40; i++) {
			pow[i] = pow[i - 1] * 10LL & MASK;
		}
		for (int i = 0; i < MXN; i++) {
			base[i] = 0;
			for (int j = 0; j < 20; j++) {
				base[i] = (base[i] + pow[j] * (i >> j & 1)) % MASK;
			}
		}
		for (int cnt = 1; cnt <= 7000; cnt++) {
			for (lld I = lst + 1; ; I++) {//枚举十进制数 正整数2333
				while (1LL << mxbit <= I) mxbit++;
				tmp = 0;
				for (int i = ((mxbit - 1) / 18) * 18; 1LL << i <= I; i -= 18) {
					tmp = (tmp * pow[18] + base[I >> i & 262143]) & MASK;
	//				tmp = (tmp + base[(I >> i) & 63] * pow[i]) % MASK;
	//				tmp = (tmp + pow[i] * (I >> i & 1)) & MASK;
				}
				if ((tmp & ((1LL << mxbit) - 1)) == I) {
					lst = I;
					printf("%lld, ", lst);
					break;
				}
			}
		}
		

	}
}chart;
}
