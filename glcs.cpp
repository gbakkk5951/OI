#include<stdio.h>
#include<cstring>
#include<algorithm>
#define deeper(a) memset(a, -1, sizeof(a))
#define clear(a)  memset(a,  0, sizeof(a))
using namespace std;
const int maxn = 911;
char s[2], a[maxn], b[maxn];
int q[maxn], w[maxn], ban[30], T, lena, lenb, ans;
struct node{
    node *ls, *rs;
    int cmax;
    inline void update(){
        cmax = max(ls->cmax, rs->cmax);
    }
}pool[maxn * maxn * 4], *root[maxn], *tail = pool;
node* build(int lf, int rg){
    node* bt = ++tail;
    if(lf == rg) {bt->cmax = 0; return bt;}
    int mid = (lf + rg) >> 1;
    bt->ls = build(lf, mid), bt->rs = build(mid + 1, rg);
    bt->cmax = 0;
    return bt;
}
void rebuild(node* bt, int lf, int rg){
    if(lf == rg) {bt->cmax = 0; return;}
    bt->cmax = 0;
    int mid = (lf + rg) >> 1;
    rebuild(bt->ls, lf, mid), rebuild(bt->rs, mid + 1, rg);
}
void modify(node* bt, int lf, int rg, int pos, int val){
    if(lf == rg){bt->cmax = val; return;}
    int mid = (lf + rg) >> 1;
    if(pos <= mid) modify(bt->ls, lf, mid, pos, val);
    else modify(bt->rs, mid + 1, rg, pos, val);
    bt->update();
}
int query(node* bt, int lf, int rg, int L, int R){
    if(L <= lf && rg <= R) return bt->cmax;
    int rt1 = 0, rt2 = 0;
    int mid = (lf + rg) >> 1;
    if(L <= mid) rt1 = query(bt->ls, lf, mid, L, R);
    if(R > mid) rt2 = query(bt->rs, mid + 1, rg, L, R);
    return max(rt1, rt2);
}
inline void solve(){
    ans = 0;
    for(int j = 1; j <= lenb; ++j)
        if(b[j] == a[1])
            modify(root[j], 1, lena, 1, 1);
    for(int i = 2; i <= lena; ++i){
        int h = 1, t = 0;
        clear(q), clear(w);
        for(int j = 1; j <= lenb; ++j){
            int val = 0;
            if(b[j] == a[i] && ~ban[a[i] - 'A']){
                while(h <= t && q[h] < j - ban[a[i] - 'A'] - 1) ++h;
            }
            if(ban[a[i] - 'A'] == -1) val = query(root[j], 1, lena, 1, i - 1);
            else val = query(root[j], 1, lena, max(i - ban[a[i] - 'A'] - 1, 1), i - 1);
            if(b[j] != a[i]){
                while(h <= t && w[q[t]] <= val) --t;
                q[++t] = j;
                w[q[t]] = val;
            }
            else{
                ans = max(ans, w[q[h]] + 1);
                modify(root[j], 1, lena, i, w[q[h]] + 1);
                while(h <= t && w[q[t]] <= val) --t;
                q[++t] = j;
                w[q[t]] = val;
            }
        }
    }
    printf("%d ", ans);
}
int main(){
    scanf("%s", a + 1);
    lena = strlen(a + 1);
    scanf("%s", b + 1);
    lenb = strlen(b + 1);
    scanf("%d", &T);
    for(int i = 1; i <= lenb; ++i) root[i] = build(1, lena);
    while(T--){
        deeper(ban);
        for(int i = 1; i <= lenb; ++i) rebuild(root[i], 1, lena);
        int x;
        while(true){
            scanf("%s", s);
            if(s[0] == '$') break;
            scanf("%d", &x);
            ban[s[0] - 'A'] = x;
        }
        solve();
    }
    return 0;
}
