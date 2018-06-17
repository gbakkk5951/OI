using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 100005;
struct _Main {
	char isp[MXN];
	lld p[MXN], pn, dsum[MXN], mndsum[MXN];
	void getprime(int mx) {
		memset(isp, 1, mx + 1);
		dsum[1] = 1;
		mndsum[1] = 1;
		int t;
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				p[pn++] = i;
				dsum[i] = 1 + i;
				mndsum[i] = 1 + i;
			}
			for (int j = 0; j < pn && (t = p[j] * i) <= mx; j++) {
				isp[t] = 0;
				if (i % p[j]) {
					dsum[t] = dsum[i] * (1 + p[j]);
					mndsum[t] = 1 + p[j];
				} else  {
					mndsum[t] = 1 + mndsum[i] * p[j];
					dsum[t] = dsum[i] / mndsum[i] * mndsum[t];
					break;
				}
			}
		}
	}
	_Main() {
		int n = 1e5;
		getprime(n); 
		lld mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, dsum[i]);
		}
		printf("mxsum = %lld\n", mx);
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
}std;
}

