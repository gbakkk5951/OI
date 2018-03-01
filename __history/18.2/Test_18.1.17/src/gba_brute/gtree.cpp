using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <algorithm>

namespace OI{
const int SQ = 31625;
const int NXT = 1;
const int DST = 0;
    int ans;
    char pvis[SQ + 1];
    int prime[4000];
    int pidx;
    int getprime() {
        int i, j, t;
        for (i = 2; i <= SQ; i++) {
            if (!pvis[i]) {
                prime[pidx++] = i;
            }            
            for (j = 0; j < pidx && (t = prime[j] * i) <= SQ; j++) {
                pvis[t] = 1;
                if (i % prime[j] == 0){
                    break;
                }
            }
        }
        return pidx;
    }
    bool vis[100010];
    int fact_list[5000000];
    int fact_n;
    vector<int> fact[100010];
    long long num[100010];
    
class Divider {
    int nd;
    int f(int a, int n) {
        return (long long) (a * a + 1) % n;
    }
    int inline pf(int a) {
        return a * a;
    }
    void div(int n) {
        /*int x = rand(), y = rand();
        x = f*/
        int i;
        for (i = 0; pf(prime[i]) <= n; i++) {
            if (n % prime[i] == 0) {
                fact[nd].push_back(prime[i]);
                do {
                    n /= prime[i];
                } while (n % prime[i] == 0);
            }
        }
        if (n > 1) {
            fact[nd].push_back(n);
        }
    }
    
public:
    void divide (int nd) {
        this->nd = nd;
        div(num[nd]);
        
        
        sort(fact[nd].begin(), fact[nd].end());
        fact[nd].resize(unique(fact[nd].begin(), fact[nd].end()) - fact[nd].begin());
    }
}divider;


    int head[100010];
    int edge[200010][2];
    vector<int>node[1000000]; 
int getAns(int nd, long long fact) {
//    printf("dfs(%d, %lld)\n", nd, fact);
    int longest[3] = {0, 0, 0};
    int i, t;
    vis[nd] = 1;
    for (i = head[nd]; i; i = edge[i][NXT]) {
        if (!vis[t = edge[i][DST]] && num[t] % fact == 0) {
            longest[0] = getAns(t, fact) + 1;
        }
        sort(longest, longest + 3);
    }
    ans = max(ans, longest[1] + longest[2]);
    return longest[2];
}
int eidx;
void inline add(int a, int b) {
    eidx++;
    edge[eidx][DST] = b;
    edge[eidx][NXT] = head[a];
    head[a] = eidx;
}

struct _Main {
template <typename Type>
    void read(Type &a) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
    }
    _Main() {
        freopen("gtree.in", "r", stdin);
        freopen("gtree.out", "w", stdout);
        int n, i, j, k
        , a, b, c;
        int idx = 0;
        getprime();
        read(n);
        for (i = 1; i <= n - 1; i++) {
            read(a); read(b);
            add(a, b);
            add(b, a);
        }
        
        for (i = 1; i <= n; i++) {
            read(num[i]);
            divider.divide(i);
            for (j = 0; j < fact[i].size(); j++) {
                fact_list[idx++] = fact[i][j];
            }
        }
        sort(fact_list, fact_list + idx);
        idx = unique(fact_list, fact_list + idx) - fact_list;
        /*
        for (i = 0; i < idx; i++) {
            printf("%d;", fact_list[i]);
        }
        printf("\n");
        */
        for (i = 1; i <= n; i++) {
            for (j = 0; j < fact[i].size(); j++) {
                node[lower_bound(fact_list, fact_list + idx, fact[i][j]) - fact_list].push_back(i);
            }
        }
        for (i = 0; i < idx; i++) {
            for (j = 0; j < node[i].size(); j++) {
                if (!vis[node[i][j]]) {
                    getAns(node[i][j], fact_list[i]);
                }
            }
            for (j = 0; j < node[i].size(); j++) {
                vis[node[i][j]] = 0;
            }
        }
        printf("%d", ans + 1);
    }
    
    
}T1;

    
    
}


