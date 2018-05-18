#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int xsum, n, a1, ans;
inline int ran(long long a, long long ans) { return (1714636915ll % mod * (a % mod) % mod + 1681692777ll % mod) % mod * (846930886ll % mod * (ans % mod) % mod + 1804289383ll % mod) % mod; }
priority_queue<int> lrg; // 大根堆
priority_queue<int, vector<int>, greater<int> > sml; // 小根堆
inline int kth(int k) {
    while(lrg.size() > k) {
        sml.push(lrg.top());
        lrg.pop();
    }
    while(lrg.size() < k) {
        lrg.push(sml.top());
        sml.pop();
    }
    return lrg.top();
}
inline void ins(int x) {
    if(lrg.empty() || x <= lrg.top()) lrg.push(x);
    else sml.push(x);
}

namespace n_1e6 {
    void sol() {
        ins(a1), xsum = (ans = kth(1));
        for(int i = 2 ; i <= n ; ++ i) {
            ins(a1 = ran(a1, ans));
            xsum ^= (ans = kth((i + 1) >> 1));
        }
        printf("%d\n", xsum);
    }
}

namespace pianfen {
    void sol() {
        ins(a1), xsum = (ans = kth(1));
        int tot = 0;
        for(int i = 2 ; i <= n ; ++ i) {
            ins(a1 = ran(a1, ans));
            xsum ^= (ans = kth(((i + 1) >> 1) - tot));

            if(i % 1000 == 0) {
                tot += lrg.size();
                while(lrg.size()) lrg.pop();
            }

        }
        printf("%d\n", xsum);
    }
}

int main() {
    scanf("%d%d", &n, &a1);
    
    pianfen :: sol();
    return 0;
    
    if(n <= 1000000) {
        n_1e6 :: sol();
    } else {
        pianfen :: sol();
    }
}