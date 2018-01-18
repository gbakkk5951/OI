using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstring>

namespace OI {
const int NXT = 1;
const int DST = 0;
int got[2][2005];
int ans;
int sum;
int head[2005];
int val[2005];
vector<int> node[2005][2];
struct _Main {

template <typename Type>
    void read(Type &a) {
        char t, f = 1;
        while (!isdigit(t = getchar())) {
            if (t == '-') {
                f = -1;
            }
        }
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
        a *= f;
    }    
    void dfs(int nd, int fa) {
        int i, j, t;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < node[nd][i].size(); j++) {
                if (got[i ^ 1][t = node[nd][i][j]]) {
                    sum += val[t];
                }
                got[i][t] = 1;
            }
        }
        
        for (i = head[nd]; i; i = edge[i][NXT]) {
            if ((t = edge[i][DST]) != fa) {
                dfs(t, nd);
            }
        }
        ans = max(ans, sum);
        for (i = 0; i < 2; i++) {
            for (j = 0; j < node[nd][i].size(); j++) {
                if (got[i ^ 1][t = node[nd][i][j]]) {
                    sum-= val[t];
                }
                got[i][t] = 0;
            }
        }
    }
    
int eidx;
int edge[40010][2];
    void inline add(int a, int b) {
        eidx++;
        edge[eidx][DST] = b;
        edge[eidx][NXT] = head[a];
        head[a] = eidx;
    }
    _Main() {
        int i, j, k;
        int n, m;
        int T, Tn;
        int a, b;
        read(Tn);
        for (T = 1; T <= Tn; T++) {
            if (T > 1) {
                for (i = 1; i <= n; i++) {
                    for (j = 0; j < 2; j++) {
                        node[i][j].clear();
                    }
                }
                memset(head, 0, (n + 1) * sizeof(int));
                ans = 0;
                eidx = 0;
            }
            read(n); read(m);
            for (i = 1; i <= n - 1; i++) {
                read(a); read(b);
                add(a, b); add(b, a);
            }            
            for (i = 1; i <= m; i++) {
                read(a); read(b); read(val[i]);
                node[a][0].push_back(i);
                node[b][1].push_back(i);
            }
            for (i = 1; i <= n; i++) {
                dfs(i, 0);
            }
            printf("Case #%d: %d\n", T, ans);
            
        }
    }
}T2;

}
