#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define ivorysi
#define fi first
#define se second
#define mp make_pair
#define inf (1LL << 55)
#define space putchar(' ')
#define enter putchar('\n')
using namespace std;
typedef long long int64;
int N,M1,M2,tot,p1,p2;
int64 dis[55][105];
pair<int64,int> P[100005];
template<class T> 
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
        out(x / 10);
    }
    putchar('0' + x % 10);
}

struct Line {
    int64 L,R,k,b;
    int64 f(int64 x) {
        return k * x + b;
    }
}L1[10005],L2[10005];
int id;
void insert(int64 L,int64 R) {
    P[++tot] = mp(L,1);
    P[++tot] = mp(R + 1,-1);
}
int64 up(int64 A,int64 B) {
    if(B < 0) B = -B,A = -A;
    int64 C = A / B;
    return C + (C * B < A);
}
int64 down(int64 A,int64 B) {
    if(B < 0) B = -B,A = -A;
    int64 C = A / B;
    return C - (C * B > A);
}
void push(Line *a,int &len,Line t) {
    while(len && t.f(a[len].L) <= a[len].f(a[len].L)) --len;
    if(len) {
        int64 B = -(a[len].b - t.b),K = (a[len].k - t.k);
        t.L = down(B,K) + 1;
        a[len].R = t.L - 1;
    }
    a[++len] = t;
}
void check(Line U,Line D) {
    int64 L = max(U.L,D.L),R = min(U.R,D.R);
    if(L > R) return;
    Line t;t.k = U.k - D.k,t.b = U.b - D.b;
    if(t.f(L) >= 0) {
        if(t.f(R) >= 0) insert(L,R);
        else insert(L,down(-t.b,t.k));
    }
    else if(t.f(R) >= 0) {insert(up(-t.b,t.k),R);}
}
struct node{
    int s,t,k;int64 b;
    void update() {
        for(int i = 0 ; i <= 2 * N ; ++i) {
            if(i + k >= 0 && i + k <= 2 * N) {
                dis[t][i + k] = min(dis[s][i] + b,dis[t][i + k]);
            }
        }
    }
    void calc() {
        p1 = 0,p2 = 0;
        for(int i = N * 2 ; i >= 0 ; --i) {
            if(dis[s][i] < inf / 2) 
                push(L1,p1,(Line){(int64)N,inf,(int64)(i - N + k),dis[s][i] + b});
            if(dis[t][i] < inf / 2) 
                push(L2,p2,(Line){(int64)N,inf,(int64)(i - N),dis[t][i]});
        }
        int t1 = 1,t2 = 1;
        for( ;t1 <= p1 && t2 <= p2 ;) {
            check(L1[t1],L2[t2]);
            if(L1[t1].R <= L2[t2].R) ++t1;
            else ++t2;
        }
    }
}E[10005];
int sumE;
void Solve() {
    read(N);read(M1);read(M2);
    for(int i = 0 ; i <= N ; ++i) {
        for(int j = 0 ; j <= 2 * N ; ++j) dis[i][j] = inf;
    }
    dis[0][N] = 0;
    sumE = 0;
    int s,t;int64 d;
    for(int i = 0 ; i < N ; ++i) {
        int s = i,t = (i + 1) % N;
        E[++sumE] = (node){t,s,(t < s),-1}; 
    }
    for(int i = 1 ; i <= M1 ; ++i) {
        read(s);read(t);read(d);
        E[++sumE] = (node){t,s,(t < s),-d};
    }
    for(int i = 1 ; i <= M2 ; ++i) {
        read(s);read(t);read(d);
        E[++sumE] = (node){s,t,-(t < s),d};
    }
    for(int i = 1 ; i <= N ; ++i) {
        for(int j = 1 ; j <= sumE ; ++j) {
            E[j].update();
        }
    }
    tot = 0;
    for(int j = 1 ; j <= sumE ; ++j) id = j,E[j].calc();
    P[++tot] = mp(inf + 1,0);
    sort(P + 1,P + tot + 1);
    s = 0;
    int64 ans = 0;
    for(int i = 1 ; i <= tot ; ++i) {
        s += P[i].se;
        if(s == sumE) {
            ans += P[i + 1].fi - P[i].fi;
        }
    }
    if(ans > (inf / 4)) ans = -1;
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    int T;
    read(T);
    while(T--) {
        Solve();
    }   
}
