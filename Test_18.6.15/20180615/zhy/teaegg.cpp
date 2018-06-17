using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
namespace OI {
typedef long long lld;
lld p, phi;
lld g;
struct _Main {
	lld fact[200000], fn;
	int sq;
	void div_phi() {
		for (int i = 2; i * i <= phi; i++) {
			if (phi % i == 0) {
				fact[++fn] = i;
				if (i * i != phi) {
					fact[++fn] = phi / i;
				}
			}
		}
	}//Ac
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		while (pow) {
			ret = (pow & 1) ? ret * base % p : ret;
			base = (pow >>= 1) ? base * base % p : base;
		}
		return ret;
	}//AC
	void getg() {
		char flag;
		for (g = 2; g < p; g++) {
			flag = 1;
			for (int i = 1; i <= fn; i++) {
				if (fastpower(g, fact[i]) == 1) {
					flag = 0; break;
				}
			}
			if (flag) {
				break;
			}
		}
	}//Ac
	set<int> tree;
	int getlog(int val) {
		if (val == 1) return 0;
		if (val == g) return 1;
		lld now, step;
		int ret = 1;
		tree.clear();
		sq = ceil(sqrt(phi));
		now = val;
		for (int i = 1; i <= sq; i++) {
			tree.insert((int)now);
			now = now * g % p;
		}
		step = fastpower(g, sq);
		now = g;	
		do {
			ret += sq;
			now = now * step % p;
		} while (tree.find((int)now) == tree.end());
		now = now * fastpower(step, phi - 1) % p;
		ret -= sq;
		while (now != val) {
			now = now * g % p;
			++ret;
		}
		return ret % phi;
	}//Ac
	char isprime() {
		for (int i = 2; i * i <= p; i++) {
			if (p % i == 0) return 0;
		}
		return 1;
	}//AC
	lld exgcd(lld a, lld b, lld &x, lld &y) {
		if (b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		lld gcd = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return gcd;
	}//AC
	lld ans[105];
	_Main() {
		freopen("teaegg.in", "r", stdin);
		freopen("teaegg.out", "w", stdout);
		lld a, b, logb, gcd, x, y, lcm, delta, lcma;
		read(a); read(b); read(p);
		if (!isprime()) {
			printf("1\n1");
			fclose(stdout);
			return;
		}
		phi = p - 1;
		div_phi();
		getg();
		logb = getlog(b);
		gcd = exgcd(a, phi, x, y);
		if (logb % gcd != 0) {
			printf("0");
			fclose(stdout);
			return;
		}
		//这有个logb /= gcd 忘了删
		lcma = phi / gcd;
		x = (logb / gcd * x % lcma + lcma) % lcma;
		for (int i = 1; i <= gcd; i++) {
			ans[i] = fastpower(g, x);
			x += lcma;
		}
		sort(ans + 1, ans + gcd + 1);
		printf("%lld\n", gcd);
		for (int i = 1; i <= gcd; i++) {
			printf("%lld ", ans[i]);
		}
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
}std;
}
