#include <bits/stdc++.h>

using namespace std;

namespace XDYIMCMI0LY {

  struct reader {
    reader &operator >> (int &buf) {
      buf = 0;
      int f = 1;
      char ch = getchar();
      for (; !isdigit(ch); ch = getchar()) {
        f = (ch == '-') ? -1 : 1;
      }
      for (; isdigit(ch); ch = getchar()) {
        buf = buf * 10 + (ch & 15);
      }
      buf *= f;
      return *this;
    }
  } read;

  template <typename T> 
  vector<T> &operator << (vector<T> &v, T x) {
    v.push_back(x);
    return v;
  }

  ostream &operator << (ostream &out, vector<int> &v) {
    for (int i = 0; i < (int) v.size(); ++i) {
      if (i) {
        out << " ";
      }
      out << v[i];
    }
    return out;
  }

  const int N = 1e5 + 5;

  int fac[N];
  int fac_cnt;
  
  inline int modexp(int a, long long x, int p) {
    int res = 1;
    while (x) {
      if (x & 1) {
        res = (long long) res * a % p;
      }
      a = (long long) a * a % p;
      x >>= 1;
    }
    return res;
  }

  bool is_prime(int p) {
    for (int i = 2; i * i <= p; ++i) {
      if (p % i == 0) {
        return 0;
      }
    }
    return 1;
  }

  inline int phi_(int x) {
    int res = x;
    for (int i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
        while (x % i == 0) {
          x /= i;
        }
        res -= res / i;
      }
    }
    if (x > 1) {
      res -= res / x;
    }
    return res;
  }


  void fac_get(int x) {
    for (int i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
        fac[++fac_cnt] = i;
        while (x % i == 0) {
          x /= i;
        }
      }
    }
    if (x > 1) {
      fac[++fac_cnt] = x;
    }
  }
 
  int gmn_get(int mod) {
    int phi = phi_(mod);
    fac_get(phi);
    for (int i = 1; i < mod; ++i) {
      bool ok = 1;
      for (int j = 1; j <= fac_cnt; ++j) {
        if (modexp(i, phi / fac[j], mod) == 1) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        return i;
      }
    }
    return -1;
  }

  int bsgs(int a, int b, int p) {
    static map<int, int> mp;
    int m = sqrt(p) + 1;
    int nw = 1;
    for (int i = 1; i <= m; ++i) {
      nw = (long long) nw * a % p;
      mp[nw] = i;
      if (nw == b) {
        return i;
      }
    }
    int res = m;
    int fac = nw;
    for (int i = 1; i <= m; ++i) {
      int right = (long long) b * modexp(fac, p - 2, p) % p;
      if (mp[right] != 0) {
        return res + mp[right];
      }
      res += m;
      fac = (long long) fac * nw % p;
    }
    return res;
  }

  int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
  }

  void exgcd(int a, int b, long long &x, long long &y) {
    if (!b) {
      x = 1;
      y = 0;
      return;
    }
    exgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  
  void find_ans(int a, int b, int p, int gg, int pp) {
    int g = gcd(a, p);
    if (b % g) {
      cout << 0 << endl;
      exit(0);
    }
    // cerr<<gg<<endl;
    // cerr<<a<<" "<<b<<" " <<p<<endl;
    // cerr<<g<<endl;
    long long x, y;
    exgcd(a / g, p / g, x, y);
    // cerr<<x<<""<<y<<endl;
    long long X = b / g * x;
    long long D = (long long) a * p / g / a;
    // cerr<<X<<" "<<D<<endl;
    D = (D % p + p) % p;
    X = (X % p + p) % p;
    vector<long long> ep;
    for (int i = 0; i <= 2000/*233*/; ++i) {
      ep << X;
      X += D;
      X %= p;
      // cerr<<X<< endl;
    }
    vector<int> ans;
    for (int i = 0; i <= 2000; ++i) {
      ans << modexp(gg, ep[i], pp);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    if (ans.size()) {
      cout << ans  << endl;
    }
  }
 
  void solve1(int a, int b, int p) {
    int g = gmn_get(p);
    int phip = phi_(p);
    int k = bsgs(g, b, p);
    find_ans(a, k, phip, g, p);
  }

  void solve2(int a, int b) {
    b %= 2;
    vector<int> ans;
    for (int i = 0; i < 2; ++i) {
      if (modexp(i, a, 2) == b) {
        ans << i;
      }
    }
    cout << ans.size() << endl;
    if (ans.size()) {
      cout << ans << endl;
    }
  }
  
  void _main() {
    int a, b, p;
    read >> a >> b >> p;
    if (p == 1) {
      cout << 1 << endl << 1 << endl;
      return;
    }
    if (is_prime(p)) {
      solve1(a, b, p);
    } else {
      solve2(a, b);
    }
  }
  
}

int main() {
  static string s = "teaegg";
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  XDYIMCMI0LY::_main();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
