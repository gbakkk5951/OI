#include <ext/pb_ds/priority_queue.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds; 


namespace XDYIMCMI0LY {
  __gnu_pbds::priority_queue <int, less <unsigned int>, pairing_heap_tag> U;
  __gnu_pbds::priority_queue <int, greater <unsigned int>, pairing_heap_tag> D;;
  
  int solve() {
    int n, t;
    scanf("%d %d", &n, &t);
    int a = t, nw = t, ans = t, siz;
    U.push(a);
    for (register int i = 2; i <= n; ++i) {
      a  = (1714636915ll * a % 1000000007 + 1681692777ll) % 1000000007ll * (846930886ll * nw % 1000000007 + 1804289383ll) % 1000000007ll;
      a <= nw ? U.push(a) : D.push(a);
      siz = (i + 1) >> 1;
      while (U.size() < siz) U.push(D.top()), D.pop();
      while (U.size() > siz) D.push(U.top()), U.pop();
      nw = U.top(), ans ^= nw;
    }
    cout << ans << endl;
    return 0;
  }
  
}

int main() { 
    freopen("mid.in", "r", stdin);
    freopen("mid.out", "w", stdout);
    return XDYIMCMI0LY::solve(); 
}
