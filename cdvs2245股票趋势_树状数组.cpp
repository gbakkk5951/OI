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
    int node[MAXN];
    int n;
    int base;
    int inline lb(int a) {
        return a & -a;
    }
public:
    int getMax(int s, int t) {
        for (t = 0, s = n - s + 1; s; s -= lb(s)) {
            t = max(t, node[s]);
        }
        return t;
    }
    void setSize(int new_size) {
        n = new_size;
    }
    void setVal(int nd, int val) {
        for (nd = n - nd + 1; nd <= n; nd += lb(nd)) {
            node[nd] = max(node[nd], val);
        }
    }
    void clear() {
        memset(node + 1, 0, n * sizeof(int));
    }
};
char a[MAXN], b[MAXN];
int dis[29];
int la, lb;

class Solver {
private:
    int q[MAXN], head, tail;
    int val[MAXN];
    SegmentTree tree[MAXN];
    int ans;
public:
void init() {
    int i;
    for (i = 1; i <= lb; i++) {
        tree[i].setSize(la);
    }
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
            //由于树状数组只能查前缀，所以必须先取出 
            val[j] = tree[j].getMax(max(1, i - dis[a[i]]), i - 1);
            
            //单调队列维护队头合法 
            if (q[head] < j - dis[a[i]]) {
                head++;
            }
            //更新答案 
            if (a[i] == b[j]) {
                ans = max(ans, val[q[head]] + 1);
                tree[j].setVal(i, val[q[head]] + 1);
            }
            
            //插入第j列[i - dis[a[i]], i - 1]的dp状态 
            
            while (head < tail && val[q[tail - 1]] <= val[j]) {
                tail--;
            }
            q[tail++] = j;
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
