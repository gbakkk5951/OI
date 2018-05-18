#include <bits/stdc++.h>

using namespace std;

namespace XDYIMCMI0LY {
    
    const int N = 15;
    const int M = 25;
    int p[N], f[N];

    bool ok[M];

    void do3() {
        static int tr0[] = {0, 4, 1, 5, 2, 6, 3, 7};
        for (int i = 0; i < 8; ++i) f[tr0[i]] = p[i];
        memcpy(p, f, sizeof(f));
        if (ok[1]) swap(p[0], p[4]);
        if (ok[2]) swap(p[1], p[5]);
        if (ok[3]) swap(p[2], p[6]);
        if (ok[4]) swap(p[3], p[7]);

        static int tr1[] = {0, 2, 1, 3, 4, 6, 5, 7};
        for (int i = 0; i < 8; ++i) f[tr1[i]] = p[i];
        memcpy(p, f, sizeof(f));
        if (ok[5]) swap(p[0], p[2]);
        if (ok[6]) swap(p[1], p[3]);
        if (ok[7]) swap(p[4], p[6]);
        if (ok[8]) swap(p[5], p[7]);

        for (int i = 0; i < 8; ++i) f[tr1[i]] = p[i];
        memcpy(p, f, sizeof(f));
        if (ok[9]) swap(p[0], p[2]);
        if (ok[10]) swap(p[1], p[3]);
        if (ok[11]) swap(p[4], p[6]);
        if (ok[12]) swap(p[5], p[7]);


        static int tr2[] = {0, 2, 4, 6, 1, 3, 5, 7};
        for (int i = 0; i < 8; ++i) f[tr2[i]] = p[i];
        memcpy(p, f, sizeof(f));
        if (ok[13]) swap(p[0], p[2]);
        if (ok[14]) swap(p[4], p[6]);
        if (ok[15]) swap(p[1], p[3]);
        if (ok[16]) swap(p[5], p[7]);

        if (ok[17]) swap(p[0], p[1]);
        if (ok[18]) swap(p[2], p[3]);
        if (ok[19]) swap(p[4], p[5]);
        if (ok[20]) swap(p[6], p[7]);        
    }


    void do1() {
        if (ok[1]) swap(p[0], p[1]);
    }

    void do2() {
        static int tr0[] = {0, 2, 1, 3};
        for (int i = 0; i < 4; ++i) f[tr0[i]] = p[i];
        memcpy(p, f, sizeof(f));
        if (ok[1]) swap(p[0], p[2]);
        if (ok[2]) swap(p[1], p[3]);

        for (int i = 0; i < 4; ++i) f[tr0[i]] = p[i];
        memcpy(p, f, sizeof(f));
        if (ok[3]) swap(p[0], p[2]);
        if (ok[4]) swap(p[1], p[3]);

        if (ok[5]) swap(p[0], p[1]);
        if (ok[6]) swap(p[2], p[3]);
    }

    int tar[N];
    int n;

    string ans;
    bool flg = 0;

    char ch(int x) { return x + '0'; }

    void dfs(int nw) {
        if (nw == (n == 1 ? 2 : (n == 2 ? 7 : 21))) {
            for (int i = 0; i < (1 << n); ++i) p[i] = i;
            if (n == 1) do1();
            else if (n == 2) do2();
            else do3();
            for (int i = 0; i < (1 << n); ++i) if (p[i] != tar[i]) return;
            string ret;
            if (n == 1) ret = ret + (char)(ok[1] + '0') + '\n';
            else if (n == 2) {
                ret = ret + ch(ok[1]) + ch(ok[2]) + '\n';
                ret = ret + ch(ok[3]) + ch(ok[4]) + '\n';
                ret = ret + ch(ok[5]) + ch(ok[6]) + '\n';
            } else {
                ret = ret + ch(ok[1]) + ch(ok[2]) + ch(ok[3]) + ch(ok[4]) + '\n';
                ret = ret + ch(ok[5]) + ch(ok[6]) + ch(ok[7]) + ch(ok[8]) + '\n';
                ret = ret + ch(ok[9]) + ch(ok[10]) + ch(ok[11]) + ch(ok[12]) + '\n';
                ret = ret + ch(ok[13]) + ch(ok[14]) + ch(ok[15]) + ch(ok[16]) + '\n';
                ret = ret + ch(ok[17]) + ch(ok[18]) + ch(ok[19]) + ch(ok[20]) + '\n';
            }
            if (!flg) {
                flg = 1;
                ans = ret;
            } else ans = min(ans, ret);
            return;
        }
        ok[nw] = 1;
        dfs(nw + 1);
        ok[nw] = 0;
        dfs(nw + 1);
    }

    int solve() {
        while (scanf("%d", &n) && n) {
            for (int i = 0; i < (1 << n); ++i) scanf("%d", &tar[i]);
            flg = 0, dfs(1);
            if (!flg) puts("-1\n");
            else cout << ans << endl;
        }
        return 0;
    }
}

int main() { 
    freopen("left.in", "r", stdin);
    freopen("left.out", "w", stdout);
    return XDYIMCMI0LY::solve(); 
}
