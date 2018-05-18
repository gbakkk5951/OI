#include <bits/stdc++.h>
using namespace std;
const int N = 3e7 + 10;
const int mod = 1000000007;
int xsum, n, a1, ans;

inline int ran(long long a, long long ans) { return (1714636915ll % mod * (a % mod) % mod + 1681692777ll % mod) % mod * (846930886ll % mod * (ans % mod) % mod + 1804289383ll % mod) % mod; }

struct HEAP { // 小根堆
    int t, bak[N];
    inline void insert(int x) {
        for(int d ; x != 1 ; x >>= 1)
            if(bak[x >> 1] > bak[x]) swap(bak[x], bak[d = x >> 1]);
            else break;
    }
    inline void del(int x) {
        for(int d = x, f = 0 ; (x << 1) <= t && !f ; ) {
            if(bak[x] > bak[x << 1] && (x << 1) <= t) d = x << 1;
            if(bak[x] > bak[x << 1 | 1] && bak[x << 1 | 1] < bak[x << 1] && (x << 1 | 1) <= t) d = x << 1 | 1;
            if(x != d) swap(bak[x], bak[d]), x = d;
            else break;
        } 
    }
    inline void push(int x) {
        bak[++ t] = x;
        insert(t);
    }
    inline int pop() {
        int x = bak[1];
        bak[1] = bak[t --];
        del(1);
        return x;
    }
} lrg, sml;

inline int kth(int k) {
    while(lrg.t > k) sml.push(-lrg.pop());
    while(lrg.t < k) lrg.push(-sml.pop());
    return -lrg.bak[1];
}
inline void ins(int x) {
    if(!lrg.t || x <= -lrg.bak[1]) lrg.push(-x);
    else sml.push(x);
}

int main() {
    scanf("%d%d", &n, &a1);
    ins(a1), xsum = ans = kth(1);
    for(int i = 2 ; i <= n ; ++ i) {
        ins(a1 = ran(a1, ans));
        xsum ^= (ans = kth((i + 1) >> 1));
    }
    printf("%d\n", xsum);
}