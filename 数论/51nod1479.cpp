using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
namespace OI {
typedef __int128 lld;
//typedef long long lld;
struct _Main {
	void exgcd(lld a, lld b, lld &x, lld &y) {
		if (b == 0) {
			x = 1;
			y = 0;
			return;
		}
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
	lld fastpower(lld base, lld pow, lld mod) {
		lld ret = 1;
		while (pow) {
			ret = (pow & 1) ? ret * base % mod : ret;
			base = (pow >>= 1) ? base * base % mod : base;
		}
		return ret;
	}
	_Main() {
		int Qn;
		int m;
		lld a, b, c, x, y, tmp;
		lld a1, a2, a3;

		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(m); read(a); read(b); read(c);
			if (1 << (int)(log(m) / log(2.0) + 1e-6) == m) {
				if (a > 1) {
					a1 = m >> 1; a2 = 1; a3 = 1;
				} else
				if (b > 1) {
					a1 = 1; a2 = m >> 1; a3 = 1;
				} else {
					if (c > 1) {
						a1 = a2 = a3 = m >> 1;
					} else {
						a1 = a2 = 1; a3 = 2;
					}
				}
			} else {
				exgcd(a * b, c, x, y);
				if (x > 0) {
					tmp = (x + a * b - 1) / (a * b);
					x -= tmp * c;
					y += tmp * a * b;
				}
				a1 = fastpower(2, -b * x, m);
				a2 = fastpower(2, -a * x, m);
				a3 = fastpower(2, y, m);
			}
			
			printf("%lld %lld %lld\n", a1, a2, a3);
		/*	out(a1); printf(" ");
			out(a2); printf(" ");
			out(a3); printf("\n");
		*/
		}
	}
	/*
	void out(lld a) {
		lld t;
		if (t = a / 10) {
			out(t);
		}
		printf("%d", (int)(a - t * 10));
		
	}*/
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}nod1479;
}
