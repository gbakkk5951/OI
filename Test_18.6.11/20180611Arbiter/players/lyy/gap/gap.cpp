#include <bits/stdc++.h>

using namespace std;



namespace XDYIMCMI0LY {
  const int N = 100000 + 5;

  int n;
  int k;
  int a[N];

  set<pair<int, int> > s;
  multiset<int> det;

  void ins(int x, int p) {
    pair<int, int> elm = make_pair(x, p);
    set<pair<int, int> >::iterator it = s.upper_bound(elm);
    set<pair<int, int> >::iterator post = it;
    --it;
    set<pair<int, int> >::iterator pre = it;
    
    det.erase(det.find(post->first - pre->first));
    det.insert(x - pre->first);
    det.insert(post->first - x);
    s.insert(elm);
  }

  void del(int x, int p) {
    pair<int, int> elm = make_pair(x, p);
    set<pair<int, int> >::iterator it = s.lower_bound(elm);
    --it;
    set<pair<int, int> >::iterator pre = it;
    ++it;
    ++it;
    set<pair<int, int> >::iterator post = it;
    --it;
    det.erase(det.find(it->first - pre->first));

    det.erase(det.find(post->first - it->first));
    det.insert(post->first - pre->first);
    s.erase(it);
  }

  int solve(int k) {
    s.clear();
    det.clear();
    s.insert(make_pair(1e9, 0));
    s.insert(make_pair(-1e9, 0));
    det.insert(2e9);
    
    for (int i = 1; i <= k; ++i) {
      ins(a[i], i);
    }
    int ans = *det.begin();
    for (int i = k + 1; i <= n; ++i) {
      del(a[i - k], i - k);
      ins(a[i], i);
      ans = max(*det.begin(), ans);
    }
    return ans;
  }

  void _main() {
    int T;
    scanf("%d", &T);
    while (T--) {
      scanf("%d %d", &n, &k);
      for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
      }
      long long ans = 0;
      for (int i = k; i <= n; ++i) {
        ans = max(ans, solve(i) * (long long) (i - 1));
      }
      printf("%lld\n", ans);
    }
  }

}


int main()  {
  freopen("gap.in", "r", stdin);
  freopen("gap.out", "w", stdout);

  XDYIMCMI0LY::_main();
  return 0;
}

