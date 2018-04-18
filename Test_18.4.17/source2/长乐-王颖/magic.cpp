#include <ctime>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int MaxN = 4e5 + 5;
const int P = 1e6 + 6;
int n, K, cnt, pri[MaxN], ai[MaxN], a[MaxN];
int fac[P], Ifac[P], Wi[P], mod, p;
int pow(int x, int k) {
	int res = 1, r = x;
	for (; k; k >>= 1, r *= r) if (k & 1) res *= r;
	return res;
}
int pow(int x, int k, int mod) {
	ll res = 1, r = x % mod;
	for (; k; k >>= 1, (r *= r) %= mod) if (k & 1) (res *= r) %= mod;
	return res;
}
int Exgcd(int a, int b, ll &x, ll &y) { //ax + by == gcd(a, b);
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	else {
		int g = Exgcd(b, a % b, y, x);
		y -= (ll)(a / b) * x;
		return g;
	}
}
int Ie(int x, int p) { //求x在模p意义下的逆元(x, p互质)
	ll a, b;
	Exgcd(x, p, a, b);
	a %= p;
	if (a < 0) a += p;
	return a;
}
/*
ll calc(int n, int mod, int p) { //求n!在模mod(p^t)意义下的答案 (无视p)
	return fac[n];
}*/
inline ll C(int n, int m) { //求C n取m在模mod(p^t)意义下的答案
	int w = Wi[n] - Wi[m] - Wi[n - m]; //w为p的指数
	return 1ll * pow(p, w, mod) * fac[n] % mod * Ifac[m] % mod * Ifac[n - m] % mod;
}
inline int Lucas(int n, int m) {
	if (n < m) return 0;
	if (n < p && m < p) return (ll)fac[n] * Ifac[m] % p * Ifac[n - m] % p;
	return (ll)Lucas(n / p, m / p) * Lucas(n % p, m % p) % p;
}
ll query(int n, int k) {
	int ans = 0;
	p = pri[k], mod = pow(pri[k], ai[k]);
	if (ai[k] == 1) {
		fac[0] = 1; for (int i = 1; i < p; ++i) fac[i] = (ll)fac[i - 1] * i % p;

		Ifac[p - 1] = pow(fac[p - 1], p - 2, p); for (int i = p - 1; i; --i) Ifac[i - 1] = (ll)Ifac[i] * i % p;
		
		for (int i = 0; i < n; ++i) if ((ans += (ll)a[i] * Lucas(n - 1, i) % p) >= p) ans -= p;
		return ans;
	}
	
	Wi[0] = 0; for (int i = 1; i < n; ++i) Wi[i] = Wi[i / p] + i / p;
	
	int y = 1; fac[0] = 1; 
	for (int i = 1; i < n; ++i) {
		if (i % p) y = (ll)y * i % mod;
		fac[i] = (ll)fac[i / p] * y % mod;
	}
	for (int i = 0; i < n; ++i) Ifac[i] = Ie(fac[i], mod);
	
	for (int i = 0; i < n; ++i) 
		if ((ans += (ll)a[i] * C(n - 1, i) % mod) >= mod) ans -= mod;
	
	return ans;
}
ll solve() {
	ll ans = 0;
	for (int k = 1; k <= cnt; ++k) {
		int mi = pow(pri[k], ai[k]), Mi = K / mi, pi = Ie(Mi, mi); //Mi * pi == 1 (mod mi)
		int Ei = (ll)Mi * pi % K; //Ei满足Ei % mi = 1, Ei % mj = 0
		if ((ans += (ll)Ei * query(n, k) % K) >= K) ans -= K;
	}
	return ans;
}
int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	scanf("%d%d", &n, &K);
	int x = K;
	for (int p = 2; p * p <= x; ++p) 
		if (!(x % p)) {
			pri[++cnt] = p;
			while (!(x % p)) ++ai[cnt], x /= p;
		}
	if (x != 1) pri[++cnt] = x, ai[cnt] = 1; 
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	printf("%d\n", (int)solve());
	fclose(stdin);
	fclose(stdout);
}