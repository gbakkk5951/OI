using namespace std;
int main() {}
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<set>
#include<queue>
#include<cstring>
namespace Protector {
typedef long long lld;
const lld LINF = 0x3f3f3f3f3f3f3f3fLL; 
const int INF = 0x3f3f3f3f;
const double ALPHA = 0.75;
const double EPS = 1e-6;
template <int Dim = 2, typename Type = int>
struct Vec {
public:    
    Type val[Dim];
    Type operator () (int idx) {
        return val[idx];
    }
    Type & operator [] (int idx) {
        return val[idx];
    }
    template<typename Type2>
    bool operator < (const Vec<Dim, Type2> &b) const {
        int i;
        for (i = 0; i < Dim; i++) {
            if (b(i) != val[i]) {
                return b(i) < val[i];
            }
        }
        return false;
    }
};

template <int Dim, typename Type>
struct KDNode;
template <int Dim = 2, typename Type = int>
struct Info {
    Vec<Dim, Type>val;
    KDNode<Dim, Type> *pos;
    int cnt;
    
};

template <int Dim = 2, typename Type = int>
struct NodePointer {
    Vec<Dim, Type> val;
    Info<Dim, Type> * info;
    bool operator < (const Info<Dim, Type> b) const {
        return val < b.val;
    }
};

template <int Dim = 2, typename Type = int>
struct KDNode {
    union {
        KDNode<Dim, Type> *son[2], *fa;
        Info<Dim, Type> *info;
    }pnt;
    Vec<Dim, Type> min, max;
    int size, mid, dim;
    void update() {
        int i;
        KDNode * nd = this;
        if (nd->pnt.son[1]) {
            for (i = 0; i < Dim; i++) {
                nd->max[i] = max (nd->pnt.son[0]->max[i], nd->pnt.son[1]->max[i]);
                nd->min[i] = min (nd->pnt.son[0]->min[i], nd->pnt.son[1]->min[i]);
            }
            nd->pnt.son[1]->fa = nd;
            nd->pnt.son[0]->fa = nd;
            size = nd->pnt.son[0]->size + nd->pnt.son[1]->size;
        } else {
            for (i = 0; i < Dim; i++) {
                nd->max[i] = nd->pnt.info->val[i];
                nd->min[i] = nd->pnt.info->val[i];
            }
            size = 1;
        }
    }
};

template<int Dim, typename Type = int>
class KDTree{
typedef Info<Dim, Type> info;
typedef NodePointer<Dim, Type> Pnt;
typedef KDNode<Dim, Type> Node;
typedef Vec<Dim, Type> vec;
private:
    class Cmp{
    private:
        int dim;
        bool operator () (info *a, info *b) const {
            return a->val(dim) < b->val(dim);
        }
    public:
        void setDim(int new_dim) {
            dim = new_dim;
        }    
    }cmp;
    
    Info <Dim, Type> info_pool[200010];
    int info_idx;
    Info <Dim, Type>*info_arr[200010];
    int info_size;    
    
    KDNode<Dim, Type> node_pool[540010];
    
    int node_idx;
    
    set<NodePointer<Dim, Type> > tree;
    
    Node *root;
    
    queue<Node *>q;
    Node *new_node() {
        if (!q.empty()) {
            Node *ret = q.front();
            q.pop();
            memset(ret, 0 ,sizeof(Node));
            return ret;
        } else if(node_idx < 540010) {
            return &node_pool[node_idx++];
        } else {
            return new Node;
        }
    }
    int getMaxDim(int l, int r) {
        double now_val = 0;
        double avg, sum;
        int now_dim = -1;
        int i, j;
        for (i = 0; i < Dim; i++) {
            avg = sum = 0;
            for (j = l; j <= r; j++) {
                avg += info_arr[j]->val[i];
            }
            avg /= r - l + 1;
            for (j = l; j <= r; j++) {
                sum += pf(avg - info_arr[j]->val[i]);
            }
            if (sum > now_val) {
                now_val = sum;
                now_dim = i;
            }
        }
        return now_dim;
    }

    long long getDis(Node *nd, const vec &a) {
        int i;
        long long ret = 0;
        for (i = 0; i < Dim; i++) {
            if (a(i) > nd->max[i]) {
                ret += pf(a(i) - nd->max[i]);
            } else if (a(i) < nd->min[i]) {
                ret -= pf(nd->min[i] - a(i));
            }
        }
        return ret;
    }
    long long now_dis;
    Node *high;
    void getMinDis(Node *nd, const vec &point) {
        if (nd->pnt.son[1]) {
            long long dis[2];
            dis[0] = getDis(nd->pnt.son[0], point);
            dis[1] = getDis(nd->pnt.son[1], point);
            int pos = dis[1] < dis[0];
            if (dis[pos] < now_dis) {
                getMinDis(nd->pnt.son[pos], point); 
                if (dis[pos ^ 1] < now_dis) {
                    getMinDis(nd->pnt.son[pos ^ 1], point);
                }
            }
            
        } else {
            now_dis = min(now_dis, getDis(nd, point));
        }
    }
    void gotNode(Node *nd) {
        if (nd->pnt.son[1]) {
            gotNode(nd->pnt.son[0]);
            gotNode(nd->pnt.son[1]);
        } else if(nd->pnt.info->cnt > 0) {
            info_arr[info_size++] = nd->pnt.info;
        }
    }
    Node * rebuild(Node *nd, bool retSetArr = true) {
        if (retSetArr) {
            info_size = 0;
        }
        gotNode(nd);
        recycle(nd);
        return build(0, info_size - 1);
    }
    void recycle(Node *nd) {
        if (nd->pnt.son[1]) {
            recycle(nd->pnt.son[0]);
            recycle(nd->pnt.son[1]);
        } else {
            nd->pnt.info->pos = 0;  
        }
        q.push(nd);
    }
    Node *build(int l, int r) {
        Node *nd = new_node();
        if (l == r) {
            nd->pnt.info = info_arr[l];
        } else {
            nd->dim = getMaxDim(l, r);
            cmp.setDim(nd->dim);
            int mid = l + r >> 1;
            nth_element(info_arr + l,info_arr + mid, info_arr + r + 1);
            nd->mid = info_arr[mid]->val(nd->dim);
            nd->pnt.son[0] = build(l, mid);
            nd->pnt.son[1] = build(mid + 1, r);
        }
        nd->update();
        return nd;
    }
    
    void update_up(Node *nd) {
        while (nd) {
            nd->update();
            if (nd->pnt.son[1] && nd->size * ALPHA + EPS < max(nd->pnt.son[0]->size, nd->pnt.son[1]->size)) {
                high = nd;
            }
            nd = nd->fa);
        }

    }
    void findPos(Node *nd, const vec &point ) {
        int pos;
        while (1) {
            if(point(nd->dim) == point(nd->mid)) {
                nd = nd->son[nd->son[0]->size > nd->son[1]->son[1]];
            } else {
                pos = point(nd->dim) > point(nd->mid);
                if (nd->pnt.son[1] == 0 ||
                    nd->son[pos]->size + 1 > (nd->size + 1) * ALPHA + EPS
                    ) {
                    high = nd;
                    return;
                } else {
                    nd = nd->pnt.son[pos];
                }
            }
        }

        
    }
    
public:

    void insert(const Vec<Dim, Type> &point) {
        Pnt tmp;
        tmp.val = point;
        typename set<Pnt>::iterator it;
        info * now_info;
        it = tree.find(tmp);
        if (it != tree.end()) {
            now_info = it->info;
        } else {
            now_info = &info_pool[info_idx++];
            now_info->val = point;
            tree.insert(Pnt{point, now_info});
        }
        now_info->cnt++;
        Node *nd;
        if (now_info->cnt == 1) {
            info_size = 0;
            info_arr[info_size++] = now_info;
            if (root == 0) {
                root = build(0, 0);
                return ;
            }
            high = 0;
            getPos(root, point);
            if (high == root) {
                root = rebuild(high, false);
            } else {
                Node *nd = high->fa->pnt.son[high->fa->pnt.son[1] == high];
                nd = rebuild(high, false);
                update_up(nd);
            }
        }
    }
    void erase(const Vec<Dim, Type> &point) {
        typename set<Pnt>::iterator it;
        it = tree.find((Pnt){point});
        it->info->cnt--;
        if (it->info->cnt == 0) {
            Node *nd = it->info->pos;
            if (nd == root) {
               recycle(root);
               root = 0; 
            } else {
                int pos = nd == nd->fa->pnt.son[1];
                Node *fa = nd->fa;
                Node *bro = fa->pnt.son[pos ^ 1];
                info *broInfo = fa->pnt.son[pos ^ 1]->info;
                recycle(nd); recycle(bro);
                broInfo->pos = fa;
                fa->pnt.son[1] = 0;
                fa->pnt.info = borInfo;
                high = 0; 
                update_up(nd->fa);  
                if (high) {
                    if (high == root) {
                        root = rebuild(high);
                    } else {
                        int pos = high == high->fa->pnt.son[1];
                        fa->pnt.son[pos] = rebuild(high);
                    }
                }
            }
        }
    }
    long long getMinDis(const Vec<Dim, Type> &point){
        now_dis = LINF;
        getMinDis(root, point);
        return now_dis;
    }

};
KDTree<2, int> tree;
struct _Main{
    
template <typename Type>
    void read(Type &a) {
        char t, f = 1;
        while (!isdigit(t = getchar())) {
            if (t == '0') {
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
    
    _Main() {
        
        
    }
    
}A;



}


