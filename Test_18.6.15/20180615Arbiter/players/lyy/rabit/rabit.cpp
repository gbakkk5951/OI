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
  const int M = 2e5 + 5;
  
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

  set<pair<int, int> > ch;

  int top[N];
  int siz[N];
  int son[N];
  int dfn[N];
  int tar[N];
  int pre[N];
  int dep[N];
  int dfs_cnt;

  void dfs0(int u, int fa) {
    siz[u] = 1;
    pre[u] = fa;
    dep[u] = dep[fa] + 1;
    for (int o = head[u]; o; o = nxt[o]) {
      int v = ver[o];
      if (v != fa) {
        dfs0(v, u);
        siz[u] += siz[v];
        if (son[u] == 0 || siz[v] > siz[son[u]]) {
          son[u] = v;
        }
      }
    }
  }

  void dfs1(int u, int fa, int anc) {
    top[u] = anc;
    dfn[u] = ++dfs_cnt;  
    if (!son[u]) {
      tar[u] = dfs_cnt;
      return;
    }
    dfs1(son[u], u, anc);
    for (int o = head[u]; o; o = nxt[o]) {
      int v = ver[o];
      if (v != fa && v != son[u]) {
        dfs1(v, u, v);
      }
    }
    tar[u] = dfs_cnt;
  }

  const int MAX = N * 4 + 5;
  
  struct sgt {
    int mx[MAX];
    int tag[MAX];

    inline int lc(int x) {
      return x << 1;
    }
    inline int rc(int x) {
      return x << 1 | 1;
    }
    
    void update(int o) {
      mx[o] = max(mx[lc(o)], mx[rc(o)]);
    }
    void set_tag(int o, int t) {
      mx[o] = t;
      tag[o] = t;
    }
    void pushdown(int o) {
      if (tag[o] != -1) {
        set_tag(lc(o), tag[o]);
        set_tag(rc(o), tag[o]);
      }
      tag[o] = -1;
    }

    void modify(int o, int ll, int rr, int l, int r, int x) {
      if (ll != rr) {
        pushdown(o);
      }
      if (ll >= l && rr <= r) {
        set_tag(o, x);
        return;
      }
      int mid = (ll + rr) >> 1;
      if (l <= mid) {
        modify(lc(o), ll, mid, l, r, x);
      }
      if (r > mid) {
        modify(rc(o), mid + 1, rr, l, r, x);
      }
      update(o);
    }

    int query(int o, int ll, int rr, int l, int r) {
      if (ll != rr) {
        pushdown(o);
      }
      if (ll >= l && rr <= r) {
        return mx[o];
      }
      int res = 0;
      int mid = (ll + rr) >> 1;
      if (l <= mid) {
        res = max(res, query(lc(o), ll, mid, l, r));
      }
      if (r > mid) {
        res = max(res, query(rc(o), mid + 1, rr, l, r));
      }
      update(o);
      return res;
    }
        
    
  } t;

  void mod_w(int l, int r, int x) {
    // cerr<<l<<" "<<r<<" "<<x<<endl;
    int lst_col = -1;
    ++r;
    set<pair<int, int> >::iterator it = ch.lower_bound(make_pair(l, 0));
    set<pair<int, int> >::iterator it_bk = it;
	--it_bk;
	lst_col = it_bk->second;
	++it_bk;
    while (it->first <= r) {
      lst_col = it->second;
      it_bk = it;
      ++it;
      ch.erase(it_bk);
    }
    ch.insert(make_pair(l, x));
    ch.insert(make_pair(r, lst_col));
  }

  inline int query2(int l, int r, int v_l, int v_r) {
    // cerr<<l<<" "<<r<<" "<<v_l<<" "<<v_r<<endl;
    int res = 0;
    set<pair<int, int> >::iterator nxt = ch.upper_bound(make_pair(l, 2e9));
    set<pair<int, int> >::iterator it = nxt;
    --it;
    // cerr<<it->first<<endl;
    while (it->first <= r) {
      if (it->second >= v_l && it->second <= v_r) {
        // cerr<<max(it->first, l)<<" "<<min(nxt->first - 1, r)<<endl;
        res = max(res, t.query(1, 1, n, max(it->first, l), min(nxt->first - 1, r)));
      }
      it = nxt;
      ++nxt;
    }
    // cerr<<res<<endl;
    return res;
  }

  inline int query(int u, int v, int l, int r) {
    int res = 0;
    while (top[u] != top[v]) {
      if (dep[top[u]] < dep[top[v]]) {
        swap(u, v);
      }
      res = max(res, query2(dfn[top[u]], dfn[u], l, r));
      u = pre[top[u]];
    }
    if (dep[u] > dep[v]) {
      swap(u, v);
    }
    res = max(res, query2(dfn[u], dfn[v], l, r));
    return res;
  }
  
  void _main() {
    read >> n >> m;
    for (int i = 1, u, v; i < n; ++i) {
      read >> u >> v;
      add_edge(u, v);
      add_edge(v, u);
    }
    ch.insert(make_pair(0, -1));
    ch.insert(make_pair(1, 0));
    ch.insert(make_pair(n + 2, 1));
    dfs0(1, 0);
    dfs1(1, 0, 1);
	// for (int i=1;i<=n;++i) printf("%d ",dfn[i]);printf("\n");
    for (int i = 1; i <= m; ++i) {
      // for (__typeof(ch.begin()) it = ch.begin(); it != ch.end(); ++it) {
      // cerr << "{" << (it->first) << "," << (it->second) << "}" << endl;
      // }
      // cerr <<  "     " << t.query(1, 1, n, 1, n) << endl;
      static char s[8];
      scanf("%s", s);
      if (s[0] == 'C') {
        if (s[6] == 'W') {
          int u, x;
          read >> u >> x;
          mod_w(dfn[u], tar[u], x);
        } else {
          int u, x;
          read >> u >> x;
          // cerr<<dfn[u]<<" "<<tar[u]<<endl;
          t.modify(1, 1, n, dfn[u], tar[u], x);
        }
      } else {
        int u, v, l, r;
        read >> u >> v >> l >> r;
        printf("%d\n", query(u, v, l, r));
      }
    }
  }
  
}

int main() {
  static string s = "rabit";
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  XDYIMCMI0LY::_main();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
