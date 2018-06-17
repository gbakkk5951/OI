using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <cmath>
namespace OI {
typedef long long lld;
const int MXN = 100000 + 10;
struct _Main {
	int k[51];
	char isp[MXN], mu[MXN];
	int p[9200];
	int pn;
	void getprime(int mx) {
		memset(isp, 1, mx + 1);
		mu[1] = 1;
		int t;
		for (int i = 2; i <= mx; i++) {
			if (isp[i]) {
				p[pn++] = i;
				mu[i] = -1;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				isp[t] = 0;
				if (i % p[j]) {
					mu[t] = -mu[i];
				} else {
					mu[t] = 0;
					break;
				}
			}
		}
	} 
	int sum(int n) {
		int sq = sqrt(n);
		int ret = 0;
		for (int i = 1; i <= sq; i++) {
			ret += mu[i] * (n / i / i);
		}
		return ret;
	}
	int calc(int n) {
					
		unsigned l = n, r = min(n * 10LL, 1644934081LL);
		
		int mid;
		while (l < r) {
			mid = l + r >> 1;
			if (sum(mid) < n) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}
	_Main() {
		int mx = 10;
		int Qn;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(k[Q]); mx = max(mx, (int)sqrt(k[Q]));
		}
		getprime(max(mx * 3, 100));
		int ret = 0;
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%d\n", calc(k[Q]));
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
