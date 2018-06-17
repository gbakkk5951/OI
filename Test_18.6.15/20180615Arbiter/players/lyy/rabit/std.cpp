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

  const int N = 1000 + 5;
  const int M = N * 2 + 5;
  
  int n;
  int m;
  
  int head[N];
  int nxt[M];
  int ver[M];

  void add_edge(int u, int v) {
    static int tot = 0;
    ++tot;
    nxt[tot] = head[u];
    ver[tot] = v;
    head[u] = tot;
  }

  int cnt[N][2];
  int ans;

  vector<int> g[N];

  void dfs_init(int u, int fa) {
    for (int o = head[u]; o; o = nxt[o]) {
      int v = ver[o];
      if (v != fa) {
        dfs_init(v, u);
        g[u] << v;
      }
    }
  }

  void mod(int u, int c, int x) {
    cnt[u][c] = x;
    for (int o = 0; o < (int) g[u].size(); ++o) {
      mod(g[u][o], c, x);
    }
  }

  bool qry(int u, int fa, int tar, int l, int r) {
    if (u == tar) {
      if (l <= cnt[u][0] && cnt[u][0] <= r) {
        ans = max(ans, cnt[u][1]);
      }
      return 1;
    }
    for (int o = head[u]; o; o = nxt[o]) {
      int v = ver[o];
      if (v != fa && qry(v, u, tar, l, r)) {
        if (l <= cnt[u][0] && cnt[u][0] <= r) {
          ans = max(ans, cnt[u][1]);
        }
        return 1;
      }
    }
    return 0;
  }
  
  void _main() {
    cin >> n >> m;
    for (int i = 1, u, v; i < n; ++i) {
      cin >> u >> v;
      add_edge(u, v);
      add_edge(v, u);
    }
    dfs_init(1, 0);
    for (int i = 1; i <= m; ++i) {
      string op;
      cin >> op;
      if (op[0] == 'C') {
        int u, x;
        cin >> u >> x;
        mod(u, op[6] == 'B', x);
      } else {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        ans = 0;
        qry(u, 0, v, l, r);
        cout << ans << endl;
      }
    }
  }
}

int main() {
  // static string s = "";
  // freopen((s + ".in").c_str(), "r", stdin);
  // freopen((s + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  XDYIMCMI0LY::_main();
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
