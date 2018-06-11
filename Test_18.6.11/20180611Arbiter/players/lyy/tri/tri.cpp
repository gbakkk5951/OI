#include <bits/stdc++.h>

using namespace std;



namespace XDYIMCMI0LY {
  const int N = 3000000 + 5;
  const int mod = 1e9 + 7;

  int n;
  int m;
  int B;
  int A;

  inline int add(int a, int b) {
    return (a += b) >= mod ? a - mod : a;
  }
  inline int sub(int a, int b) {
    return (a -= b) < 0 ? a + mod : a;
  }
  inline int mul(int a, int b) {
    return (long long) a * b % mod;
  }
  inline int modexp(int a, int x) {
    int res = 1;
    while (x) {
      if (x & 1) {
        res = mul(res, a);
      }
      a = mul(a, a);
      x >>= 1;
    }
    return res;
  }


  inline void inc(int& a, int b) {
    (a + b >= mod) ? a = a + b - mod : a = a + b;
  }
  inline void dec(int& a, int b) {
    (a - b) < 0 ? a = a - b + mod : a = a - b;
  }

  int mu[N];
  int phi[N];
  int sumphi[N];
  int sumkphi[N];
  int sumkkphi[N];

  inline void sieve() {
    mu[1] = 1;
    phi[1] = 1;
    static int tot = 0;
    static int p[N];
    static int not_p[N];
    for (int i = 2; i < N; ++i) {
      if (!not_p[i]) {
        p[++tot] = i;
        mu[i] = sub(0, 1);
        phi[i] = i - 1;
      }
      for (int j = 1; j <= tot; ++j) {
        int k = p[j] * i;
        if (k < N) {
          not_p[k] = 1;
          if (i % p[j] == 0) {
            mu[k] = 0;
            phi[k] = mul(phi[i], p[j]);
            break;
          } else {
            mu[k] = mul(mu[i], mu[p[j]]);
            phi[k] = mul(phi[i], phi[p[j]]);
          }
        } else {
          break;
        }
      }
    }
    for (int i = 1; i < N; ++i) {
      sumphi[i] = add(sumphi[i - 1], phi[i]);
      sumkphi[i] = add(sumkphi[i - 1], mul(i, phi[i]));
      sumkkphi[i] = add(sumkkphi[i - 1], mul(i, mul(i, phi[i])));
    }
  }

  inline int getsum(int a, int b, int n) {
    return mul(mul(add(a, b), n), A);
  }


  inline int ccalc(int x) {
    int res = x;
    res =  mul(res, x - 1);
    res = mul(res, x - 2);
    res = mul(res, B);
    return res;
  }

  inline int calc(int n, int m, int k) {
    register int mk = m / k;
    register int nk = n / k ;
    register int sumn = getsum(1, nk, nk);
    register int summ = getsum(1, mk, mk);
    register int res = mul(mul(mul(n, m), nk), mk);
    dec(res, mul(mul(mul(n, k), nk),  summ));
    dec(res, mul(mul(mul(m, k), mk), sumn));
    inc(res, mul(n, mul(nk, mk)));
    inc(res, mul(m, mul(nk, mk)));
    inc(res, mul(nk, mk));
    inc(res, mul(mul(k, k), mul(summ, sumn)));
    dec(res, mul(k, mul(mk, sumn)));
    dec(res, mul(k, mul(nk, summ)));
    return res;
  }

  inline int calc0(register int nk, register int mk) {
    register int res = mul(mul(mul(n, m), nk), mk);
    inc(res, mul(n, mul(nk, mk)));
    inc(res, mul(m, mul(nk, mk)));
    inc(res, mul(nk, mk));
    return res;
  }

  inline int calc1(register int nk, register int mk) {
    register int sumn = getsum(1, nk, nk);
    register int summ = getsum(1, mk, mk);
    register int res = 0;
    dec(res, mul(mk, sumn));
    dec(res, mul(nk, summ));
    dec(res, mul(mul(n, nk),  summ));
    dec(res, mul(mul(m, mk), sumn));
    return res;
  }

  inline int calc2(register int nk, register int mk) {
    return mul(getsum(1, nk, nk), getsum(1, mk, mk));
  }

  void _main() {
    B = modexp(6, mod - 2);
    A = modexp(2, mod - 2);
    sieve();
    while (scanf("%d %d", &n, &m) && n + m) {
      int ans = ccalc(mul(n + 1, m + 1));
      ans = sub(ans, mul(m + 1, ccalc(n + 1)));
      ans = sub(ans, mul(n + 1, ccalc(m + 1)));
      int tmp = 0;

      if (n > m) {
        swap(n, m);
      }
      for (register int i = 1; i <= n; ++i) {
        int vn = n / i;
        int vm = m / i;
        int nxtn = n / vn;
        int nxtm = m / vm;
        int nxt = min(nxtn, nxtm);
        tmp = add(tmp, mul(sub(sumphi[nxt], sumphi[i - 1]), calc0(vn, vm)));
        i = nxt;
      }

      for (register int i = 1; i <= n; ++i) {
        int vn = n / i;
        int vm = m / i;
        int nxtn = n / vn;
        int nxtm = m / vm;
        int nxt = min(nxtn, nxtm);
        tmp = add(tmp, mul(sub(sumkphi[nxt], sumkphi[i - 1]), calc1(vn, vm)));
        i = nxt;
      }

      for (register int i = 1; i <= n; ++i) {
        int vn = n / i;
        int vm = m / i;
        int nxtn = n / vn;
        int nxtm = m / vm;
        int nxt = min(nxtn, nxtm);
        tmp = add(tmp, mul(sub(sumkkphi[nxt], sumkkphi[i - 1]), calc2(vn, vm)));
        i = nxt;
      }

      tmp = sub(tmp, calc(n, m, 1));
      tmp = mul(tmp, 2);
      ans = sub(ans, tmp);
      printf("%d\n", ans);
    }
  }

}


int main() {
  freopen("tri.in", "r", stdin);
  freopen("tri.out", "w", stdout);
  XDYIMCMI0LY::_main();
  return 0;
}

