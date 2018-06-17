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

  vector<int> &operator << (vector<int> &v, int &x) {
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
    out << endl;
    return out;
  }

  const int N = 20 + 5;
  const int M = 20 + 5;

  int n;
  int m;
  int lim;

  int k[N][N];
  int a[N][N];

  int x[N];
  int y[N];

  int exi[N][N];
  int vis[N][N];
  int cnt[N];


  void dfs(int x, int y, int &kd, int &val) {
    static int xx[] = {0, 0, -1, 1};
    static int yy[] = {1, -1, 0, 0};
    if (!exi[x][y]) {
      return;
    }
    if (!vis[x][y]) {
      vis[x][y] = 1;
      if (k[x][y] == -1) {
        kd = -1e9;
        return;
      }
      if (cnt[k[x][y]] == 0) {
        ++kd;
      }
      ++cnt[k[x][y]];
      val += a[x][y];
      for (int o = 0; o < 4; ++o) {
        int tx = x + xx[o];
        int ty = y + yy[o];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
          dfs(tx, ty, kd, val);
        }
      }
    }
  }

  int sol(int s) {
    memset(exi, 0, sizeof(exi));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n * m; ++i) {
      if (s & (1 << i)) {
        exi[x[i]][y[i]] = 1;
      }
    }
    int kd = 0;
    int val = 0;
    for (int i = 0; i < n * m; ++i) {
      if (s & (1 << i)) {
        dfs(x[i], y[i], kd, val);
        break;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (exi[i][j] && !vis[i][j]) {
          return INT_MAX;;
        }
      }
    }
    if (kd < lim) {
      return INT_MAX;
    }
    return val;
  }
  
  
  void _main() {
    int T;
    read >> T;
    while (T--) {
      read >> n >> m >> lim;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          read >> k[i][j];
        }
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          read >> a[i][j];
        }
      }
      int tot = 0;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          x[tot] = i;
          y[tot++] = j;
        }
      }
      int ans = INT_MAX;
      for (int i = 1; i < (1 << (n * m)); ++i) {
        ans = min(ans, sol(i));
      }
      cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    
  }
}

int main() {
  static string s = "chocolate";
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  XDYIMCMI0LY::_main();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
