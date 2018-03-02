using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>

namespace Protector {
const int MAXN = 810;
class SegmentTree {
private:   
    int node[2051];
    int n;
    int base;
public:
    int getMax(int s, int t) {
        int ret = 0;
        for (s += base - 1, t += base + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
            if (~s & 1) {
                ret = max(ret, node[s ^ 1]); 
            }
            if ( t & 1) {
                ret = max(ret, node[t ^ 1]);
            }
        }
        return ret;
    }

    void setSize(int new_size) {
        n = new_size;
        for (base = 1; base < n + 2; base <<= 1);
    }
    void setVal(int nd, int val) {
        for (nd += base; nd; nd >>= 1) {
            node[nd] = max(node[nd], val);
        }
    }
    void clear() {
        memset(node, 0, (base << 1) * sizeof(int));
    }
};
char a[MAXN], b[MAXN];
int dis[29];
int la, lb;

class Solver {
private:
    int q[MAXN], head, tail;
    int val[MAXN];
    SegmentTree tree[810];
    int ans;
public:
void init() {
    int i;
    for (i = 1; i <= lb; i++) {
        tree[i].setSize(la);
    }
}

void push(int pos) {
    while (head < tail && val[q[tail - 1]] <= val[pos]) {
        tail--;
    }
    q[tail++] = pos;
}
void solve() {
    int i, j, k;
    for (i = 1; i <= lb; i++) {
        if (a[1] == b[i]) {
            tree[i].setVal(1, 1);
            ans = 1;
        }
    }
    for (i = 2; i <= la; i++) {
        head = tail = 0;
        q[0] = 0; val[0] = 0;
        for (j = 1; j <= lb; j++) {
            val[j] = tree[j].getMax(max(1, i - dis[a[i]]), i - 1);
            if (q[head] < j - dis[a[i]]) {
                head++;
            }
            if (a[i] == b[j]) {
                ans = max(ans, val[q[head]] + 1);
                tree[j].setVal(i, val[q[head]] + 1);
            }
            push(j);
        }
    }
    
}

int getAns() {
    return ans;
}
    
void clear() {
    int i;
    for (i = 1; i <= lb; i++) {
        tree[i].clear();
    }
    ans = 0;
}
    
}solver;


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
        int i, T;
        int t;
        char tmp;
        scanf("%s%s", a + 1, b + 1);
        la = strlen(a + 1); lb = strlen(b + 1);
        
        for (i = 1; i <= la; i++) {
            a[i] -= 'A';
        }
        for (i = 1; i <= lb; i++) {
            b[i] -= 'A';
        }
        solver.init();
        read(T);
        while (T--) {
            for (i = 0; i < 26; i++) {
                dis[i] = 810;
            }
            while (1) {
                while (isspace(tmp = getchar()));
                if (tmp =='$') {
                    break;
                } else {
                    read(t);
                    dis[tmp - 'A'] = t + 1;
                }
            }
            solver.solve();
            printf("%d ", solver.getAns());
            if (T) {
                solver.clear();
            }
        }
    }
    
}cdvs2245;












}

//注意输出格式 
