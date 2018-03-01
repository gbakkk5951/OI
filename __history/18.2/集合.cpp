using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <set>
#include <functional>
namespace Protector {
int in[100005];
int head[100005], nxt[1000005], idx[1000005];
int lidx, eidx;
int edge[500005][3];
const int VAL = 2;
struct Cmp {
    bool operator () (int *a, int *b) {
        if (a[VAL] != b[VAL]) {
            return a[VAL] < b[VAL];
        } 
        if (a[0] != b[0]) {
            return a[0] > b[0];
        }
        if (a[1] != b[1]) {
            return a[1] > b[1];
        }
        return false;
    }
    
};

set<int *, Cmp> tree[10];

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
    void add(int a, int b, int val) {
        eidx++;
        lidx++;
        nxt[lidx] = head[a];
        head[a] = lidx;
        idx[lidx] = eidx;
        lidx++;
        nxt[lidx] = head[b];
        head[b] = lidx;
        idx[lidx] = eidx;
        edge[eidx][VAL] = val;
        edge[eidx][0] = a;
        edge[eidx][1] = b;
    }
    char oper[15];
    
    _Main() {
        int n, m;
        int i, j, k;
        read(n); read(m);
        int a, b, c;
        int Q, Qn;
        int id;
        int eid;
        int pos;
        for (i = 1; i <= m; i++) {
            read(a); read(b); read(c);
            add(a, b, c);
            tree[0].insert(edge[eidx]);
        }    
        read(Qn);
        for (Q = 1; Q <= Qn; Q++) {
            scanf("%s", oper);
            if (oper[0] == 'M') {
                read(a);
                id = oper[4] - 'A'; 
                if (in[a] != id) {
                    for (i = head[a]; i; i = nxt[i]) {

                        eid = max(in[edge[idx[i]][0]], in[edge[idx[i]][1]]) * 3 
                            + min(in[edge[idx[i]][0]], in[edge[idx[i]][1]]);
                        tree[eid].erase(edge[idx[i]]);
                        if (a == edge[idx[i]][0]) {
                            eid = max(id, in[edge[idx[i]][1]]) * 3 
                                + min(id, in[edge[idx[i]][1]]);                          
                        } else {
                            eid = max(id, in[edge[idx[i]][0]]) * 3 
                                + min(id, in[edge[idx[i]][0]]);                                 
                        }
                        tree[eid].insert(edge[idx[i]]);
                    }
                }
                in[a] = id;
            } else {
                eid = max(oper[3] - 'A', oper[4] - 'A') * 3
                    + min(oper[3] - 'A', oper[4] - 'A');
                if (tree[eid].empty()) {
                    printf("No Found!\n");
                } else {
                    printf("%d\n", (*tree[eid].begin())[VAL]);
                }
                
            }
            
        }
    }
    
}jihe;

}
