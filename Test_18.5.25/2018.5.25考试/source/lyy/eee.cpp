#include <bits/stdc++.h>

using namespace std;

namespace XDYIMCMI0LY {

    inline int read() {
        int f = 1, x = 0, ch = getchar();
        for (; !isdigit(ch); ch = getchar()) f = (ch == '-') ? -1 : 1;
        for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
        return f * x;
    }

    const int N = 4000 + 5;
 
    int n;
    
    long long a[N];
    long long num[] = {0, 0, 0, 233ll, 2333ll, 23333ll, 233333ll, 2333333ll,  23333333ll, 233333333ll, 2333333333l, 23333333333ll, 233333333333ll, 2333333333333ll, 23333333333333ll, 233333333333333ll, 2333333333333333ll, 23333333333333333ll, 233333333333333333ll, 2333333333333333333ll};

    inline int getbit(long long x) {
        int ret = 0;
        while (x) x /= 10, ++ret;
        return ret;
    }

    inline bool check(int l, int r) {
        for (int i = l; i <= r; ++i) if (num[getbit(a[i])] == a[i]) return true;
        return false;
    }
    
    int _main() {
        
        n = read();
        int q = read();
        for (int i = 1; i <= n; ++i) a[i] = read();
        while (q--) {
            int op = read();
            int l, r;
            long long x;
            switch (op) {
            case 1:
                x = read();
                printf("%lld\n", a[x]);
                break;
            case 2:
                l = read(), r = read(), x = read();
                for (int i = l; i <= r; ++i) a[i] = x;
                while (check(l, r)) for (int i = l; i <= r; ++i) ++a[i];
                break;
            case 3:
                l = read(), r = read(), x = read();
                for (int i = l; i <= r; ++i) a[i] += x;
                while (check(l, r)) for (int i = l; i <= r; ++i) ++a[i];
                break;
            case 4:
                l = read(), r = read();
                x = LLONG_MIN;
                for (int i = l; i <= r; ++i) x = max(x, a[i]);
                for (int i = l; i <= r; ++i) a[i] = x;
                while (check(l, r)) for (int i = l; i <= r; ++i) ++a[i];
                break;
            case 5:
                l = read(), r = read();
                x = LLONG_MAX;
                for (int i = l; i <= r; ++i) x = min(x, a[i]);
                for (int i = l; i <= r; ++i) a[i] = x;
                while (check(l, r)) for (int i = l; i <= r; ++i) ++a[i];
                break;
            case 6:
                l = read(), r = read();
                x = 0;
                for (int i = l; i <= r; ++i) x += a[i];
                x = x / (r - l + 1);
                for (int i = l; i <= r; ++i) a[i] = x;
                while (check(l, r)) for (int i = l; i <= r; ++i) ++a[i];
                break;
            }
        }
        return 0;
    }
}

int main() {
    
        freopen("eee.in", "r", stdin);
        freopen("eee.out", "w", stdout);
    return XDYIMCMI0LY::_main();
}
