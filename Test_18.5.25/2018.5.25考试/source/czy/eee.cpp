#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fll;

int n, m;

bool isbad(ll x) {
    if(x < 233) return 0;
    while(x % 10 == 3) x /= 10;
    return x == 2;
}

namespace n_4000_m_4000 {
    ll a[N];
    bool has233(int l, int r) {
        for(int i = l ; i <= r ; ++ i) if(isbad(a[i])) return 1;
        return 0;
    }
    void maintain(int l, int r) {
        while(has233(l, r)) for(int i = l ; i <= r ; ++ i) ++ a[i];
    }
    void sol() {
        for(int i = 1 ; i <= n ; ++ i) scanf("%lld", &a[i]);
        for(int i = 1, op, l, r, x ; i <= m ; ++ i) {
            scanf("%d", &op);
            if(op == 1) {
                // 1 i  输出第i个元素
                scanf("%d", &x);
                printf("%lld\n", a[x]);
            } else if(op == 2) {
                // 2 a b x 将[a,b]区间的序列赋值为x
                scanf("%d%d%d", &l, &r, &x);
                if(isbad(x)) ++ x;
                for(int j = l ; j <= r ; ++ j) a[j] = x;
            } else if(op == 3) {
                // 3 a b x 将[a,b]区间的序列加上x
                scanf("%d%d%d", &l, &r, &x);
                for(int j = l ; j <= r ; ++ j) a[j] += x;
                maintain(l, r);
            } else if(op == 4) {
                // 4 a b 将区间[a,b]赋值为[a,b]中的最大值
                scanf("%d%d", &l, &r);
                ll mx = a[l];
                for(int j = l ; j <= r ; ++ j) mx = max(mx, a[j]);
                if(isbad(mx)) ++ mx;
                for(int j = l ; j <= r ; ++ j) a[j] = mx;
            } else if(op == 5) {
                // 5 a b 将区间[a,b]赋值为[a,b]中的最小值
                scanf("%d%d", &l, &r);
                ll mn = a[l];
                for(int j = l ; j <= r ; ++ j) mn = min(mn, a[j]);
                if(isbad(mn)) ++ mn;
                for(int j = l ; j <= r ; ++ j) a[j] = mn;
            } else if(op == 6) {
                // 6 a b 将区间[a,b]赋值为[a,b]中的平均值,平均值向下取整
                scanf("%d%d", &l, &r);
                ll sum = 0;
                for(int j = l ; j <= r ; ++ j) sum += a[j];
                ll avg = sum / (r - l + 1);
                if(isbad(avg)) ++ avg;
                for(int j = l ; j <= r ; ++ j) a[j] = avg;
            }
        }
    }
}

namespace jiazhuangbuhuichuxian233 {

    int lc[N], rc[N], sz[N], fix[N], rt, tot;
    ll val[N], sum[N], mx[N], mn[N], add_tag[N], set_tag[N];

    void push(int x) {
        if(x) {
            if(set_tag[x] != inf) {
                val[x] = set_tag[x];
                sum[x] = sz[x] * set_tag[x];
                mx[x] = mn[x] = set_tag[x];

                set_tag[lc[x]] = set_tag[x], set_tag[rc[x]] = set_tag[x];
                add_tag[lc[x]] = add_tag[rc[x]] = 0;
                set_tag[x] = inf;
            }
            if(add_tag[x]) {
                val[x] += add_tag[x];
                mx[x] += add_tag[x];
                mn[x] += add_tag[x];
                sum[x] += sz[x] * add_tag[x];

                add_tag[lc[x]] += add_tag[x], add_tag[rc[x]] += add_tag[x];
                add_tag[x] = 0;
            }
        }
    }

    void update(int x) {
        sz[x] = sz[lc[x]] + sz[rc[x]] + 1;
        sum[x] = sum[lc[x]] + sum[rc[x]] + val[x];
        mx[x] = max(val[x], max(mx[lc[x]], mx[rc[x]]));
        mn[x] = min(val[x], min(mn[lc[x]], mn[rc[x]]));
    }

    int nd(ll x) {
        val[++ tot] = x;
        update(tot);
        fix[tot] = rand();
        set_tag[tot] = inf;
        return tot;
    }

    typedef pair<int, int> p;

    int merge(int x, int y) {
        push(x), push(y);
        if(!x || !y) return x | y;
        if(fix[x] < fix[y]) {
            rc[x] = merge(rc[x], y);
            update(x);
            return x;
        } else {
            lc[y] = merge(x, lc[y]);
            update(y);
            return y;
        }
    }

    p split(int x, int k) {
        p rs;
        push(x);
        if(!x) return rs;
        if(sz[lc[x]] >= k) {
            rs = split(lc[x], k);
            lc[x] = rs.second;
            rs.second = x;
        } else {
            rs = split(rc[x], k - sz[lc[x]] - 1);
            rc[x] = rs.first;
            rs.first = x;
        }
        update(x);
        return rs;
    }

    void sol() {
        srand((unsigned long long) new char);
        mn[0] = inf, mx[0] = -inf;
        for(int i = 1, x ; i <= n ; ++ i) {
            scanf("%d", &x);
            rt = merge(rt, nd(x));
        }
        for(int i = 1, op, l, r, x ; i <= m ; ++ i) {
            scanf("%d", &op);
            if(op == 1) {
                // 1 i  输出第i个元素
                scanf("%d", &x);
                p a = split(rt, x - 1);
                p b = split(a.second, 1);
                push(b.first), printf("%lld\n", val[b.first]);
                rt = merge(a.first, merge(b.first, b.second));
            } else if(op == 2) {
                // 2 a b x 将[a,b]区间的序列赋值为x
                scanf("%d%d%d", &l, &r, &x);
                if(isbad(x)) ++ x;
                p a = split(rt, r);
                p b = split(a.first, l - 1);
                add_tag[b.second] = 0;
                set_tag[b.second] = x;
                rt = merge(merge(b.first, b.second), a.second);
            } else if(op == 3) {
                // 3 a b x 将[a,b]区间的序列加上x
                scanf("%d%d%d", &l, &r, &x);
                p a = split(rt, r);
                p b = split(a.first, l - 1);
                add_tag[b.second] += x;
                rt = merge(merge(b.first, b.second), a.second);
            } else if(op == 4) {
                // 4 a b 将区间[a,b]赋值为[a,b]中的最大值
                scanf("%d%d", &l, &r);
                p a = split(rt, r);
                p b = split(a.first, l - 1);
                push(b.second), x = mx[b.second];
                if(isbad(x)) ++ x;
                add_tag[b.second] = 0;
                set_tag[b.second] = x;
                rt = merge(merge(b.first, b.second), a.second);
            } else if(op == 5) {
                // 5 a b 将区间[a,b]赋值为[a,b]中的最小值
                scanf("%d%d", &l, &r);
                p a = split(rt, r);
                p b = split(a.first, l - 1);
                push(b.second), x = mn[b.second];
                if(isbad(x)) ++ x;
                add_tag[b.second] = 0;
                set_tag[b.second] = x;
                rt = merge(merge(b.first, b.second), a.second);
            } else if(op == 6) {
                // 6 a b 将区间[a,b]赋值为[a,b]中的平均值,平均值向下取整
                scanf("%d%d", &l, &r);
                p a = split(rt, r);
                p b = split(a.first, l - 1);
                push(b.second), x = sum[b.second] / (r - l + 1);
                if(isbad(x)) ++ x;
                add_tag[b.second] = 0;
                set_tag[b.second] = x;
                rt = merge(merge(b.first, b.second), a.second);
            }
        }
    }
}

int main() {
    freopen("eee.in", "r", stdin);
    freopen("eee.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if(n <= 4000 && m <= 4000) {
        n_4000_m_4000 :: sol();
    } else {
        jiazhuangbuhuichuxian233 :: sol();
    }
}