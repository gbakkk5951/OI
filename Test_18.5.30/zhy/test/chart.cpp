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
const lld MASK = (1LL << 38) - 1;
lld base[64];
struct _Main {
	_Main() {
		freopen("chart.out", "w", stdout);
		lld pow[39];
		lld lst = 0;
		int mxbit = 1;
		lld tmp;
		pow[0] = 1;
		for (int i = 1; i <= 38; i++) {
			pow[i] = pow[i - 1] * 10LL & MASK;
		}
		for (int i = 0; i <= 63; i++) {
			base[i] = 0;
			for (int j = 0; j < 6; j++) {
				base[i] = (base[i] + pow[j] * (i >> j & 1)) % MASK;
				
			}
		}
		for (int cnt = 1; cnt <= 900; cnt++) {
			for (lld I = lst + 1; ; I++) {//枚举十进制数 正整数2333
				while (1LL << mxbit <= I) mxbit++;
				tmp = 0;
				for (int i = ((mxbit - 1) / 6) * 6; 1LL << i <= I; i -= 6) {
					tmp = (tmp * pow[6] + base[I >> i & 63]) & MASK;
	//				tmp = (tmp + base[(I >> i) & 63] * pow[i]) % MASK;
	//				tmp = (tmp + pow[i] * (I >> i & 1)) & MASK;
				}
				if ((tmp & ((1LL << mxbit) - 1)) == I) {
					cerr << "got " << cnt << endl;
					lst = I;
					printf("%lld, ", lst);
					break;
				}
				if ((I >> 20 & 1) && !(I & ((1 << 20) - 1))) {
					cerr << I << endl;
				}
			}
		}
		

	}
}chart;
}
