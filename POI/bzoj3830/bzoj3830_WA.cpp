using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 1e6 + 5;
struct _Main {
	
	lld arr[MXN], bsp[MXN];
	_Main() {
		lld rsum = 0, lst = -1, s, sp, rn, mov;
		lld n, t;
		read(n); read(s);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
			if (i > 1) sp += (bsp[i] = max(arr[i] - arr[i - 1] + 1, 0LL)); 
		}
		for (int i = n - 1; i >= 1; i--) {
			bsp[i] += bsp[i + 1];
		}
		for (int i = 1; i <= n; i++) {
			t = max(arr[i], lst + 1);
			rn = min(sp + t + 1 - lst - s - s, rsum);
			if (rn >= 1) {
				mov = max(0LL, lst + s + s + rn - 1 - t);
			} else {
				rn = 0;
				mov = 0;
			}
			rsum -= rn;
			lst = t + mov;
			rsum++;
			sp = min(sp - mov, bsp[i + 1]);
		}
		printf("%lld", lst + s + s + rsum - 1);
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
}bzoj3830;
}
