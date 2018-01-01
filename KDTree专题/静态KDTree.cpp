using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>

namespace Protector {
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int KDNODE_SIZE = 555000;
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
template<typename Type>    
Type inline pf(Type a) {
    return a * a;
}    
template <int dimension, typename Type = int>
struct Vec {
    Type val[2];
    Type & operator [] (int a) {
        return val[a];
    }
    Type operator () (int a) const {
        return val[a];
    }
};
template<int Dim>
struct KDNode{
private:
union Val{
    int mid;
    int pos;
};
public:
    KDNode *son[2];
    Vec<Dim>max,min;
    int dim;
    Val val;
};
KDNode<2> kdnode_pool[KDNODE_SIZE];
int kdnode_idx;
KDNode<2> * new_kdnode() {
    if (kdnode_idx < KDNODE_SIZE) {
        return &kdnode_pool[kdnode_idx++];
    } else {
        return new KDNode<2>;
    }
}
template <int Dim>
class KDTree {

private:

    class Cmp {
        int dim;
    public:
        void setDim(int new_dim) {
            dim = new_dim;
        }    
        bool operator () (const Vec<Dim> &a, const Vec<Dim> &b) {
            return a(dim) < b(dim);
        }
    }cmp;
    
    int getMaxDim (int l, int r) {
        int nowAns = -1;
        double nowVal = 0;
        double avg = 0;
        double sum;
        int i, j;
        for (i = 0; i < Dim; i++) {
            avg = 0; sum = 0;
            for (j = l; j <= r; j++) {
                avg += val[j][i];
            }
            avg /= r - l + 1;
            for (j = l; j <= r;j++) {
                sum += pf(val[j][i] - avg);
            }
            if(sum > nowVal) {
                nowAns = i;
                nowVal = sum;
            }
        }
        return nowAns;
    }
    void setDimRange(KDNode<Dim> *nd, int l, int r) {
        int i, j;
        for (j = 0; j < Dim; j++) {
            nd->max[j] = -LINF;
            nd->min[j] = LINF;
        }
        for (i = l; i <= r; i++) {
            for (j = 0; j < Dim; j++) {
                nd->max[j] = max(nd->max[j], val[i][j]);
                nd->min[j] = min(nd->min[j], val[i][j]);
            }
        }
        
//        char tmp[250];
//        for (i = 0; i < Dim; i++) {
//            sprintf(tmp, "[%d, %d] max[%d] = %lld; min[%d] = %lld;\n", l, r, i, nd->max[i], i, nd->min[i]);
//            cerr<<tmp;
//        }
        
    }
    void setFaDimRange(KDNode<Dim> *nd) {
        int i, j;
        for (j = 0; j < Dim; j++) {
            nd->max[j] = -LINF;
            nd->min[j] = LINF;
        }
        for (i = 0; i < 2; i++) {
            for (j = 0; j < Dim; j++) {
                nd->max[j] = max(nd->max[j], nd->son[i]->max[j]);
                nd->min[j] = min(nd->min[j], nd->son[i]->min[j]);
            }
        }        
    }
    
    long long getDis(const Vec<Dim>&point, KDNode<Dim> *nd) {
        long long ret = 0;
        int i;
        for (i = 0; i < Dim; i++) {
            if (point(i) < nd->min[i]) {
                ret += pf((long long)nd->min[i] - point(i));
            } else if(point(i) > nd->max[i]) {
                ret += pf((long long)point(i) - nd->max[i]);
            }
        }
        return ret;
    }
    Vec<Dim> val[110000];
    int size;
    KDNode<2> *root;
    KDNode<2> * build(int l, int r) {
//        printf("build(%d, %d)", l, r);
        KDNode<Dim> * nd = new_kdnode();
        //setDimRange(nd, l, r); 
        if (l == r) {
            nd->val.pos = l;
            setDimRange(nd, l, r); 
            return nd;
        }
        int mid =r + l >> 1;
        int maxDim = getMaxDim(l, r);
        if (maxDim == -1) {
            nd->val.pos = l;
            setDimRange(nd, l, l); 
            return nd;
        }
        cmp.setDim(maxDim);
        nth_element(&val[l], &val[mid], &val[r+1], cmp);
        /*while (mid - 1 >= l && val[mid - 1](maxDim) == val[mid](maxDim)) {
            mid--;
        }*/
        nd->dim = maxDim;
        nd->val.mid = val[mid](maxDim);
        nd->son[0] = build(l, mid);
        nd->son[1] = build(mid + 1, r);
        setFaDimRange(nd);
        return nd;
    }
    long long getDis(const Vec<Dim> &a, const Vec<Dim> &b) {
        long long ret = 0;
        int i;
        for (i = 0; i < Dim; i++) {
            ret += pf((long long)a(i) - b(i));
        }
        return ret;
    }
    
    long long now_ans;
    
    void findMinDis(const Vec<Dim> &point, KDNode<Dim> *nd) {
       
        if (!(nd->son[0] || nd->son[1])) {
//            printf("min = %lld\n", nd->val.pos );
            now_ans = min(now_ans, getDis(point, nd));
            return;
        }
        long long dis[2];
        dis[0] = getDis(point, nd->son[0]);
        dis[1] = getDis(point, nd->son[1]);
        int pos = dis[1] < dis[0];
        if(dis[pos] < now_ans){
            findMinDis(point, nd->son[pos]);
        }
        if (dis[pos^1] < now_ans) {
            findMinDis(point, nd->son[pos^1]);
        }
    }
public:
    void setSize(int new_size) {
        size =  new_size;
    }
    void inline setVal(int pos, int dim, int new_val) {
        val[pos][dim] = new_val;
    }
    int & getVal(int pos, int dim) {
        return val[pos][dim];
    }
    void build() {
        if (size == 0) {
            cerr<<"Size He set"<<endl;
        }
        root = build(1, size );
    }
    long long inline findMinDis(const Vec<Dim> &point) {
        now_ans = LINF;
        findMinDis(point, root);
        return now_ans;
    }
};
    
KDTree<2> tree;





struct _Main {
    
_Main() {
//    freopen("data0.in","r",stdin);
    int n, m;
    int i, j, k;
    int Q, Qn;
    int a, b, c;
    Vec<2> point;
    read(n); read(Qn);
    tree.setSize(n);
    for (i = 1; i <= n; i++) {
        read(a); read(b);
        tree.setVal(i, 0, a);
        tree.setVal(i, 1, b);
    }
    tree.build();
//    for (i = 1; i <= n; i++) {
//        printf("%d %d\n", tree.getVal(i, 0), tree.getVal(i, 1));
//    }
    for (Q = 1; Q <= Qn; Q++) {
        read(point[0]); read(point[1]);
        printf("%lld\n", tree.findMinDis(point));
    }
}    
    
    
}static_KDTree;








}
