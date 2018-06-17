using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {
const int MXN = 105;
struct _Main {
	char isp[MXN];
	int p[MXN], pn, dn[MXN], mndn[MXN];
	void getprime(int mx) {
		memset(isp, 1, mx + 1);
		dn[1] = 1;
		int t;
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				p[pn++] = i;
				dn[i] = 2;
				mndn[i] = 1;
			}
			for (int j = 0; j < pn && (t = p[j] * i) <= mx; j++) {
				isp[t] = 0;
				if (i % p[j]) {
					dn[t] = dn[i] * 2;
					mndn[t] = 1;
				} else  {
					mndn[t] = mndn[i] + 1;
					dn[t] = dn[i] / (mndn[i] + 1) * (mndn[t] + 1);
					break;
				}
			}
		}
	}
	_Main() {
		int mx;
		read(mx);
		getprime(mx);
		for (int i = 1; i <= mx; i++) {
			printf("%d: %d\n", i, dn[i]);
		}
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
