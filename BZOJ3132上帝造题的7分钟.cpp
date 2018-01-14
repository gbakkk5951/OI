using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <cstdlib>
namespace Protector {
typedef long long lld;
class ArrTree{
private:
    lld node[2050];
    int n;
    int lb(int a) {
        return a & (-a);
    }
public:
    void setSize(int new_size) {
        n = new_size;
    }
    lld getSum(int nd) {
        lld ret = 0;
        for ( ; nd; nd -= lb(nd)) {
            ret += node[nd];
        }
        return ret;
    }
    void add(int nd, lld val) {
        for ( ; nd <= n; nd += lb(nd)) {
            node[nd] += val;
        }
    }
    
};

class SumTree {
private:
    ArrTree delta;  
    ArrTree sum;
    int n;

public:
    void setSize(int new_size) {
        n = new_size;
    }
    void build() {
        int i;
        delta.setSize(n);
        sum.setSize(n);
    }
    void add(int pos, lld val) {
        delta.add(pos, (pos - 1) * val);
        sum.add(pos, val);
    }
    lld getSum(int pos) {
        return pos * sum.getSum(pos) - delta.getSum(pos);
    }
    void add(int l, int r, lld val) {
        add(l, val);
        add(r + 1, - val);
    }
    lld getSum(int l, int r) {
        return getSum(r) - getSum(l - 1);
    }
    
};


class Sovler{

private:
    int n, m;
    int sq;
    char swp_sig;
public:
    SumTree sig_tree[50];
    SumTree row_tree[2050];
    SumTree sum_tree[50];
    void setSize(int new_n, int new_m) {
        n = new_n; m = new_m;
        if (n > m) {
            swap(n, m);
            swp_sig = 1;
        }
        sq = ceil (sqrt(n));
    }
    
    void build() {
        int i;
        int sqn = ceil((double)n / sq);
        for (i = 1; i <= sqn; i++) {
            sig_tree[i].setSize(m);
            sig_tree[i].build();
            sum_tree[i].setSize(m);
            sum_tree[i].build();
        } 
        for (i = 1; i <= n; i++) {
            row_tree[i].setSize(m);
            row_tree[i].build();
        }
    }
    
    lld getSum(int xi, int yi, int xj, int yj) {
        if (swp_sig) {
            swap(xi, yi);
            swap(xj, yj);
        }
        
        lld ret = 0;
        int now_sq = ceil((double)xi / sq);
        int dst = now_sq * sq;
        int i;
        if (xi > (now_sq - 1) * sq && dst <= xj) {
            for (i = xi; i <= dst; i++) {
                ret += row_tree[i].getSum(yi, yj);
            }
            ret += sig_tree[now_sq].getSum(yi, yj) * (dst - xi + 1);
            xi = dst + 1;
            now_sq++;
            dst = dst + sq;
        }
        while (dst <= xj) {
            ret += sum_tree[now_sq].getSum(yi, yj);
            xi = dst + 1;
            now_sq++;
            dst += sq;
        }
        if (xi <= xj) {
            ret += sig_tree[now_sq].getSum(yi, yj) * (xj - xi + 1);
            for (i = xi; i <= xj; i++) {
                ret += row_tree[i].getSum(yi, yj);
            }
        }
        return ret;
    }
    void add(int xi, int yi, int xj, int yj, lld val) {
        if (swp_sig) {
            swap(xi, yi);
            swap(xj, yj);
        }
        
        int now_sq = ceil((double)xi / sq);
        int dst = now_sq * sq;
        int i;
        if (xi > (now_sq - 1) * sq && dst <= xj) {
            sum_tree[now_sq].add(yi, yj, (dst - xi + 1) * val);
            for (i = xi; i <= dst; i++) {
                row_tree[i].add(yi, yj, val);
            }
            xi = dst + 1;
            now_sq++;
            dst = dst + sq;
        }
        while (dst <= xj) {
            sig_tree[now_sq].add(yi, yj, val);
            sum_tree[now_sq].add(yi, yj, sq * val);
            xi = dst + 1;
            now_sq++;
            dst += sq;
        }
        if (xi <= xj) {
            sum_tree[now_sq].add(yi, yj, (xj - xi + 1) * val);
            for (i = xi; i <= xj; i++) {
                row_tree[i].add(yi, yj, val);
            }
        }
    }
}solver;


struct _Main {



template<typename Type>
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
    char oper[5];
    _Main () {
        int n, m;
        int i, j, k;
        int xi, xj, yi, yj;
        int val;
        read(n); read(m);
        solver.setSize(n, m);
        solver.build();
        while (~scanf("%s", oper)) {
            switch (oper[0]) {
                case 'L': {
                    read(xi); read(yi); read(xj); read(yj);
                    read(val);
                    solver.add(xi, yi, xj, yj, val);
                	break;
                }
                case 'k': {
                    read(xi); read(yi); read(xj); read(yj);
                    printf("%lld\n", solver.getSum(xi, yi, xj, yj));
                	break;
                }
                default: {
                    return;
                }
            }
            
        }
    }

}A;








}
