using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;


struct _Main {
	lld mod, n;
	lld p[20], m[20], r[20];
	int pcnt;
	lld fastpower(lld base, lld pow, lld mod) {
		lld ret = 1;
		while (pow) {
			ret = (pow & 1) ? ret * base % mod : ret;
			base = (pow >>= 1) ? base * base % mod : base;
		}
		return ret;
	}
	lld exgcd(lld a, lld b, lld &x, lld &y) {
		if (b == 0) {
			x = 1, y = 0;
			return a;
		}
		lld g = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
	void crt() {
		for (int i = 1; i < pcnt; i++) {
			lld delta, g, x, y;
			delta = r[i] - r[0];
			g = exgcd(m[0], m[i], x, y);
			r[0] = x * (delta / g) % (m[i] / g) * m[0] + r[0];
			m[0] = m[i] / g * m[0];
			r[0] %= m[0];
		}
	}
	lld count(lld fact, lld p) {
		lld ret = 0;
		while (fact >= p) {
			ret += (fact /= p);
		}
		return ret;
	}
	lld getfact(lld fact, lld p, lld mod) {
		lld ans = 1, loop = 1;
		if (fact > 1) {
			int cnt = 0;
			for (int i = 1; i <= mod; i++) {
				if (i % p) {
					loop = loop * i % mod;
					cnt++;
				}
			}
			ans *= fastpower(loop, fact / mod, mod);
			ans = ans * getfact(fact / p, p, mod) % mod;
		}
		fact %= mod;
		for (int i = 1; i <= fact; i++) {//不整除的在上面已经算过了 
			if (i % p) {
				ans = ans * i % mod;
			}
		}
		return ans;
	}
	int mn;
	lld w[7];
	
	lld calc(lld p, lld mod) {
		lld ret = getfact(n, p, mod);
		lld cnt = count(n, p);
		lld x, y;
		for (int i = 1; i <= mn; i++) {
			cnt -= count(w[i], p);
			exgcd(getfact(w[i], p, mod), mod, x, y);
			ret = ret * x % mod;
		}
		ret = ret * fastpower(p, cnt, mod) % mod;
		return ret;
	}
	void getdiv() {
		lld rem = mod;
		for (lld i = 2; i * i <= rem; i++) {
			if (rem % i == 0) {
				p[pcnt] = i;
				m[pcnt] = 1;
				do {
					m[pcnt] = m[pcnt] * i;
					rem /= i;
				} while (rem % i == 0);
				pcnt++;
			}
		}
		if (rem > 1) {
			m[pcnt] = rem;
			p[pcnt] = rem;
			pcnt++;
		}
	}
	
	_Main() {
		read(mod); read(n); read(mn);
		lld sum = 0;
		for (int i = 1; i <= mn; i++) {
			read(w[i]);
			sum += w[i];
		}
		if (sum > n) {
			printf("Impossible"); //神TM大写 
			return;
		}
		if (sum < n) {
			w[++mn] = n - sum;
		}
		getdiv();
		for (int i = 0; i < pcnt; i++) {
			r[i] = calc(p[i], m[i]);
		}
		crt();
		r[0] += r[0] < 0 ? m[0] : 0;
		printf("%lld", r[0]);
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
}cdvs1321;

}


