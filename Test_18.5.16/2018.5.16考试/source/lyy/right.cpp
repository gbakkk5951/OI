#include <bits/stdc++.h>

using namespace std;

namespace XDYIMCMI0LY {

    const int N = 1e5 + 5;

    inline int read() {
        int f = 1, x = 0, ch = getchar();
        for (; !isdigit(ch); ch = getchar()) f = (ch == '-') ? -1  : 1;
        for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
        return f * x;
    }

    int n, q, p;

    namespace sol1 {
        int a[N];

        inline int sg(int x) {
            if (p & 1) return x & 1;
            else {
                if ((x + 1) % (p + 1) == 0) return 2;
                else return (x - (x + 1) / (p + 1)) & 1;
            }
        }

        int solve() {
            for (int i = 1; i <= n; ++i) a[i] = read();
            for (int i = 1; i <= q; ++i) {
                int ty = read();
                if (ty == 0) {
                    int l = read(), r = read(), x = read();
                    for (int j = l; j <= r; ++j) a[j] += x;
                } else {
                    int l = read(), r = read(), ans = 0;
                    for (int j = l; j <= r; ++j) ans ^= sg(a[j]);
                    puts(ans == 0 ? "0" : "1");
                }
            }
            return 0;
        }
    }

    const int MAX = N * 4 +4 ;


    namespace sol2 {
        int cnt[MAX][2], sg[MAX], tag[MAX];
        int a[N];
        void up(int o) {
            int lc = o * 2, rc = o * 2 + 1;
            sg[o] = sg[lc] ^ sg[rc];
            cnt[o][0] = cnt[lc][0] + cnt[rc][0];
            cnt[o][1] = cnt[lc][1] + cnt[rc][1];
        }

        void set(int o) {
            swap(cnt[o][0], cnt[o][1]);
            sg[o] = cnt[o][1] & 1;
            tag[o] = 1;
        }

        void down(int o) {
            if (tag[o]) {
                set(o * 2);
                set(o * 2 + 1);
                tag[o] = 0;
            }
        }

        void build(int o, int ll, int rr) {
            if (ll == rr) {
                sg[o] = a[ll] & 1;
                cnt[o][a[ll] & 1] = 1;
                return;
            }
            int mid = (ll + rr) >> 1;
            build(o * 2, ll, mid), build(o * 2 + 1, mid + 1, rr);
            up(o);
        }

        int qry(int o, int ll, int rr, int l, int r) {
            if (ll != rr) down(o);
            if (ll >= l && rr <= r) return sg[o];
            int mid = (ll + rr) >> 1, ret = 0;
            if (l <= mid) ret ^= qry(o * 2, ll, mid, l, r);
            if (r > mid) ret ^= qry(o * 2 + 1, mid + 1, rr, l, r);
            up(o);
            return ret;
        }

        void flip(int o, int ll, int rr, int l, int r) {
            if (ll != rr) down(o);
            if (ll >= l && rr <= r) {
                set(o);
                return;
            }
            int mid = (ll + rr) >> 1;
            if (l <= mid) flip(o * 2, ll, mid, l, r);
            if (r > mid) flip(o * 2 + 1, mid + 1, rr, l, r);
            up(o);
        }

        int solve() {
            for (int i = 1; i <= n; ++i) a[i] = read();
            build(1, 1, n);
            for (int i = 1; i <= q; ++i) {
                int ty = read();
                if (ty == 0) {
                    int l = read(), r = read(), x = read() & 1;
                    if (x) flip(1, 1, n, l, r);
                } else {
                    int l = read(), r = read();
                    puts(qry(1, 1, n, l, r) == 0 ? "0" : "1");
                }
            }
            return 0;
        }
        
    }

    int  solve() {
        n = read(), q = read(), p = read();
        if (n <= 5e4) sol1::solve();
        else if (p & 1) sol2::solve();
        else sol1::solve();
        return 0;
    }
}

int main() { 
    freopen("right.in", "r", stdin);
    freopen("right.out", "w", stdout);
    return XDYIMCMI0LY::solve(); 
}
