using namespace std;
int main () {}
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
const int limit = 301;
class BlockList {
    private:
    
    int org[305];
    int sorted[305];
    int arr_idx;

    void move_to_pos(int pos) {
        while(pos && sorted[pos - 1] > sorted[pos]) {
            swap(sorted[pos - 1], sorted[pos]);
            pos--;
        }
        while(pos + 1 < arr_idx && sorted[pos + 1] < sorted[pos]) {
            swap(sorted[pos + 1], sorted[pos]);
            pos++;
        }
    }
public:
    BlockList *r;
    void change(int pos, int val);
    void insert(int pos, int val);
    int getSize() {
        return arr_idx;
    } 
    int getVal(int pos) {
        return org[pos - 1];
    }
    void build(int *l, int *r) {
        int i;
        arr_idx = r - l + 1;
        for (i = 0 ; i < arr_idx; i++) {
            org[i] = l[i];
        }
        memcpy(sorted, org, arr_idx * sizeof(int));
        sort(sorted, sorted + arr_idx);
    }
    int upper_bound(int val) {
        return std::upper_bound(sorted, sorted + arr_idx, val) - sorted;
    }
    int upper_bound(int l, int r, int val){
        int ret = 0;
        int i;
        for (i = l; i <= r; i++) {
            if (org[i] <= val) {
                ret++;
            }
        }
        return ret;
    }
    void setR(BlockList *new_r) {
        r = new_r;
    }
    /*
    void print() {
        int i;
        for (i = 0; i < arr_idx; i++) {
            printf("[%d]%d ", i, org[i]);
        }
        printf("\n");
    }*/
}pool[605];
int p_idx;
void BlockList::insert(int pos, int val) {
    int i;
    if (arr_idx >= limit) {
        if (!r || r->arr_idx >= limit) {
            BlockList *new_r = &pool[p_idx++];
            new_r->r = r;
            r = new_r;
        }
        if (pos == limit) {
            r->insert(0, val);
            return;
        }
        
        r->insert(0, org[arr_idx - 1]);
        int sorted_pos = lower_bound(sorted, sorted + arr_idx, org[arr_idx - 1]) - sorted;
        sorted[sorted_pos] = val;
        move_to_pos(sorted_pos);
        for (i = arr_idx ; i > pos; i--) {
            org[i] = org[i - 1];
        }
//        printf("org[%d] = %d\n", pos, val);
        org[pos] = val;
    } else {
        for (i = arr_idx ; i > pos; i--) {
            org[i] = org[i - 1];
        }
        org[pos] = val;
        sorted[arr_idx++] = val;
        move_to_pos(arr_idx - 1);
    }
}

void BlockList::change(int pos, int val) {
    int sorted_pos = lower_bound(sorted, sorted + arr_idx, org[pos]) - sorted;
    org[pos] = val;
    sorted[sorted_pos] = val;
    move_to_pos(sorted_pos);
}

class Solver {
    int org[35500];
    BlockList *root;

    int upper_bound (int x1, int x2, int val) {
        BlockList *nd; 
        int ret = 0;
        int pst = 0;
        for (nd = root; nd; nd = nd->r) {
            if (pst > x2) break;
            if (pst < x1 && pst + nd->getSize() >= x1) {
                ret += nd->upper_bound(x1 - pst, min(nd->getSize() - 1, x2 - pst), val);
            } else if(pst >= x1 && pst + nd->getSize() > x2) {
                ret += nd->upper_bound(0, x2 - pst, val);
            } else if(pst >= x1 && pst + nd->getSize() - 1 <= x2) {
                ret += nd->upper_bound(val);
            }
            pst += nd->getSize();
        }
//        printf("upper(%d, %d, %d) = %d\n", x1, x2, val, ret);
        return ret;
    }    
    
public:   
    void setVal(int pos, int val) {
        org[pos] = val;
    }
    void build(int l, int r) {
        root = &pool[p_idx++];
        BlockList *nd = root, *r_nd;
        for (; l <= r; l += limit){
            nd->build(&org[l], &org[min(r, l + limit - 1)]);
            if (l + limit <= r) {
                r_nd = &pool[p_idx++];
                nd->setR(r_nd);
                nd = r_nd;
            }
        }
    }

    void getPos(BlockList *&nd, int &pos) {
        nd = root;
        while (nd->getSize() < pos) {
            pos -= nd->getSize();
            nd = nd->r;
        }
    }

    void change(int pos, int val) {
//        printf("change(%d, %d)\n", pos, val);
        BlockList * nd;
        getPos(nd, pos);
        nd->change(pos - 1, val);        
    }
    
    void insert(int pos, int val) {
//        printf("insert(%d, %d)\n", pos, val);
        BlockList * nd;
        pos--;
        getPos(nd, pos);
        nd->insert(pos, val);
    }

    
    int getVal(int x1, int x2, int rank) {
//        printf("getVal(%d, %d, %d)\n", x1, x2, rank);
        x1--; x2--;
        int l = 0, r = 70000; 
        int mid;
        while (l < r) {
            mid = l + r >> 1;
            if (upper_bound(x1, x2, mid) >= rank) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

}solver;


struct _Main {
    template<typename Type>
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
        int n;
        int a, b, c;
        int i, j, k;
        char op[10];
        int Q, Qn;
        int lst_ans = 0;
        read(n);
        for (i = 1; i <= n; i++) {
            read(a);
            solver.setVal(i, a);
        }
        solver.build(1, n);
        read(Qn);
        for (Q = 1; Q <= Qn; Q++) {
            BlockList *nd = &pool[0];
            /*for (i = 0; i < p_idx; i++) {
                
                printf("pool_%d_ ",i);
                nd->print();
                nd = nd->r;
            }*/
            
            scanf("%s", op);
            read(a); read(b);
            a ^= lst_ans;
            b ^= lst_ans;
            switch (op[0]) {
                case 'Q': {
                    read(c);
                    c ^= lst_ans;
                    printf("%d\n", lst_ans = solver.getVal(a, b, c));
                	break;
                }
                case 'M': {
                    solver.change(a, b);
                	break;
                }
                case 'I': {  
                    solver.insert(a, b);
                	break;
                }
            }
        }
    }
    
    
    
}bzoj3065;

//当一个函数为多个位置查询服务时，要注意+1 -1的边界问题 
