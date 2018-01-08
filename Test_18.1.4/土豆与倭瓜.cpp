using namespace std;
int main (){}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
namespace protector{
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
    char fit[10005];
    char v[20010];
    int match[20010];
    int head[10010];
    int edge[20010][2];
    int e_idx;
    int useful_cnt[2];
    void init() {
        memset(v, 0 ,sizeof(v));
        useful_cnt[1] = useful_cnt[0] = 0;
        memset(fit, 0 ,sizeof(char) * (n + 1));
        memset(head, 0, (n + 1) * sizeof(int));
        e_idx = 0;
        int i;
        int a, b;
        for (i = 1; i <= n; i++) {
            match[n + i] = i;
        }
        for (i = 1; i <= m; i++) {
            read(a); read(b);
            if (a == b) {
                fit[a] = 1;
            }
            if (head[a] == 0) {
                useful_cnt[0]++;
            }
            if (v[b] == 0) {
                v[b] = 1;
                useful_cnt[1]++;
            }
            add(a, b + n);
        }
    }
    void inline add (int a, int b) {
        e_idx++;
        edge[e_idx][1] = head[a];
        head[a] = e_idx;
        edge[e_idx][0] = b;
    }
    char dfs(int nd) {
        int i, t;
        for (i = head[nd]; i; i = edge[i][1]) if(!v[t = edge[i][0]]) {
            v[t] = 1;
            if (!match[t] || dfs(match[t])) {
                match[t] = nd;
                fit[nd] = 1;
                return true;
            }
        }
        return false;
    }
    char augment(int nd) {
        memset(v, 0 ,sizeof(v));
        match[n + nd] = 0;
        return dfs(nd);
    }
    int n, m;
    _Main() {
        int i, j, k;
        while (~scanf("%d%d", &n, &m)) {
            init();
            if (useful_cnt[0] < n || useful_cnt[1] < n) {
                printf("NO\n");
                continue;
            }
            for (i = 1; i <= n; i++) {
                if (!fit[i] && !augment(i)) {
                    break;
                }
            }
            if (i != n + 1) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
            
        }
        
    }
    
    
}T1;


}

