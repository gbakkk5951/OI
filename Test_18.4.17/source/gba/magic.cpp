using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 400010;
typedef long long lld;
struct _Main {
	lld f[MXN], fr[MXN], cnt[MXN];
	lld fastpower(lld base, lld pow, lld mod) {
		lld ret = 1;
		pow += pow < 0 ? mod - 1 : 0;
		while (pow) {
			ret = (pow & 1) ? ret * base % mod : ret; // 不要弄成0了，
			base = (pow >>= 1) ? base * base % mod : base; // 养成好习惯，不要瞎赋0
		}
		return ret;
	}
	lld exgcd(lld a, lld b, lld &x, lld &y) {
		if (b == 0) {
			x = 1, y = 0;
			return a;
		}
		lld ret = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return ret;
	}
	lld m[20], r[20], mod;
	void merge(int, int i) {
		lld delta = r[i] - r[0];
		lld x, y;
		lld g = exgcd(m[0], m[i], x, y);
		r[0] = x * delta / g % (m[i] / g) * m[0] + r[0]; // 虽然g == 1, 但还是加上delta/g比较好 
		m[0] = m[0] / g * m[i];
		r[0] %= m[0];
	}
	lld fact[20], fpow[20], fcnt;
	void divmod() {
		lld rem = mod;
		for (int i = 2; i * i <= rem; i++) {
			if (rem % i == 0) {
				fact[fcnt] = i;
				do {
					rem /= i;
					fpow[fcnt]++;
				} while (rem % i == 0);
				fcnt++;
			}
		}
		if (rem > 1) {
			fact[fcnt] = rem;
			fpow[fcnt] = 1;
			fcnt++;
		}
	}
	lld com(lld n, lld m, lld mod, lld p) { // mod = pow(p, k);
		return f[n] * fr[m] % mod * fr[n - m] % mod 
			 * fastpower(p, cnt[n] - cnt[m] - cnt[n - m], mod) % mod;
	}
	void calc(int id) {
		lld p = fact[id];
		lld mod = m[id] = fastpower(p, fpow[id], 1e9);
		lld ans = 0, t, x, y;
		f[0] = fr[0] = 1;
		for (int i = 1; i <= n - 1; i++) {
			cnt[i] = cnt[i - 1];
			t = i;
			while (t % p == 0) {
				t /= p;
				cnt[i]++;
			}
			f[i] = f[i - 1] * t % mod;
			exgcd(t, mod, x, y);
			fr[i] = fr[i - 1] * x % mod;
		}
		for (int i = 1; i <= n; i++) {
			ans = (ans + arr[i] * com(n - 1, i - 1, mod, p)) % mod;
		}
		r[id] = ans;
	}
	lld arr[MXN];
	int n;
	_Main() {
		freopen("magic.in", "r", stdin);
		freopen("magic.out", "w", stdout);
		read(n); read(mod);
		divmod();
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		for (int i = 0; i < fcnt; i++) {
			calc(i);
		}
		for (int i = 1; i < fcnt; i++) {
			merge(0, i);
		}
		printf("%lld", (r[0] % m[0] + m[0]) % m[0]);
		fclose(stdout);
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
}magic;
}
