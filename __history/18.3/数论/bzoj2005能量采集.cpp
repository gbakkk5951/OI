using namespace std;
int main() {}
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cctype>
namespace OI {
typedef long long lld;

int prime[100000];
int pcnt;
int u[1000015];
int us[1000015];
char vis[1000015];
void getprime(int mx) {
	u[1] = 1;
	int t;
	for (int i = 2; i <= mx; i++) {
		if (!vis[i]) {
			prime[pcnt++] = i;
			u[i] = -1;
		}
		for (int j = 0; j < pcnt && (t = i * prime[j]) <= mx; j++) {
			vis[t] = 1;
			if (i % prime[j]) {
				u[t] = u[i] * -1;
			} else {
				u[t] = 0;
				break;
			}
		}
	}
}

struct _Main {
	void prepro(int mx) {
		getprime(mx);
		for (int i = 1; i <= mx; i++) {
			us[i] = u[i] + us[i - 1];
		}
	}
	lld calc(int n, int m) {//cnt of gcd i j == 1
		int mn = min(m, n);
		lld ret = 0;
		int nx;
		for (int i = 1; i <= mn; i = nx + 1) {
			nx = min(n / (n / i), m / (m / i));
			ret += (lld)(n / i) * (m / i) * (us[nx] - us[i - 1]);
		}
		return ret;
	}
	lld tot_calc(int n, int m) {
		lld ans = 0;
		for (int i = 1; i <= min(n, m); i++) {
			ans += (lld)i * calc(n / i, m / i);
		}
		return ans;
	}
	_Main() {
		int n, m;
		lld ans;
		read(n); read(m);
		prepro(max(n, m));
		ans = tot_calc(n, m);
		ans <<= 1;
		ans -= (lld)n * m; // อüมห(lld) 
		printf("%lld", ans);
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
}bzoj2005;


	
}
