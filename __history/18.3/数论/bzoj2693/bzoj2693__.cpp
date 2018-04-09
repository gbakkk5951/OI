using namespace std;
int main(){}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int mod = 1e8 + 9;
struct _Main {
	lld calc(int n, int m) {
		lld ans = 0, ret = 0;
		int mn = min(n, m);
		lld s1, e1;
		lld s2, e2;
		lld nn, mm, k;
		for (s1 = 1; s1 <= mn; s1 = e1 + 1) {
			e1 = min(n / (n / s1), m / (m / s1));
			printf("d = %d, %d\n", s1, e1);
			nn = n / e1;
			mm = m / e1;
			ans = 0;
			ans += ((1 + nn) * nn / 2 % mod) * ((1 + mm) * mm / 2 % mod) % mod;
//			printf("+= %lld\n", ans);
			for (s2 = 1; s2 <= nn; s2 = e2 + 1) {
				e2 = min(nn, mm / (mm / s2));
				k = mm / s2;
				ans += - ((k + 1) * k / 2 % mod) * ((s2 + e2) * (e2 - s2 + 1) / 2 % mod) % mod; 
//				printf("[%lld, %lld] -= %lld\n", s2, e2, ((k + 1) * k / 2 % mod) * ((s2 + e2) * (e2 - s2 + 1) / 2 % mod) % mod);
			}
			ans %= mod;
			//////////
			ans = 0;
			//////////
			ret += (s1 + e1) * (e1 - s1 + 1) / 2 % mod * ans % mod;
			ret %= mod;
			printf("ret = %lld\n", ret);
		}
		return ret;
	}
	_Main() {
		int Qn;
		read(Qn);
		int n, m;
		for (int Q = 1; Q <= Qn; Q++) {
			read(n); read(m);
			printf("%lld\n", calc(n, m));
		}
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
}bzoj2693;
}
