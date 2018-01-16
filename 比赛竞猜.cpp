using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>


struct Rson{
    int operator [] (int a) {
        return a << 1 | 1;
    }
}rson;
struct Lson{
    int operator [] (int a) {
        return a << 1;
    }
}lson;

struct Data{
    int sum[2];
    int& operator[] (int a) {
        return sum[a];
    }
    Data operator + (const Data &b) {
        Data ret = *this;
        int i;
        for (i = 0; i < 2; i++) {
            ret[i] += b.sum[i];
        }
        return ret;
    }
    Data() {
        
    }
    Data(int a, int b) {
        sum[0] = a, sum[1] =b;
    }
};

struct Node {
    int sig;
    Data sum;
};
class SegmentTree {
private:    
    Node node[270000];
    int arr[100010];
    int n;
    void addSig(int nd, int sig) {
        node[nd].sig = sig;
        node[nd].sum[sig] = node[nd].sum[0] + node[nd].sum[1];
        node[nd].sum[sig ^ 1] =0;         
    }
    void pushSig(int nd) {
        int sig;
        if ((sig = node[nd].sig) != -1) {
            addSig(lson[nd], sig);
            addSig(rson[nd], sig);
            node[nd].sig = -1;
        }
    }
    void update(int nd) {
        node[nd].sum = node[lson[nd]].sum + node[rson[nd]].sum;
    }
    
    void change(int nd, int l, int r, int nl, int nr, int val) {
        if (l > nr || r < nl) {
            return;
        }
        if (l <= nl && nr <= r) {
            addSig(nd, val);
            return;
        }
        pushSig(nd);
        change(lson[nd], l, r, nl, nl + nr >> 1, val);
        change(rson[nd], l, r, (nl + nr >> 1) + 1, nr, val);
        update(nd);
    }
    Data query(int nd, int l, int r, int nl, int nr) {
        if (l > nr || r < nl) {
            return Data(0,0);
        }
        if (l <= nl && nr <= r) {
            return node[nd].sum;
        } 
        if (node[nd].sig != -1) {
            Data ret(0,0);
            ret[node[nd].sig] = min(r, nr) - max(l, nl) + 1;
            return ret;   
        }
        return query(lson[nd], l, r, nl, nl + nr >> 1)
              +query(rson[nd], l, r, (nl + nr >> 1) + 1, nr);
    }
    void build(int nd, int nl, int nr) {
        node[nd].sig = -1;
        if (nl == nr) {
            node[nd].sum[arr[nl]] = 1;
            return;
        }
        build(lson[nd], nl, nl + nr >> 1);
        build(rson[nd], (nl + nr >> 1) + 1, nr);
        update(nd);
    }
public:
    void build() {
        build(1, 1, n);
    }
    
    void setVal(int nd, int val) {
        arr[nd] = val;
    }
    
    void setSize(int new_n) {
        n = new_n;
    }
    
    void change(int pos, int val) {
        change(1, pos, pos, 1, n, val);
    }
    void change(int l, int r, int val) {
        change(1, l, r, 1, n, val);
    }
    Data query(int l, int r) {
        return query(1, l, r, 1, n);
    }
    Data query(int l) {
        return query(1, l, l, 1, n);
    }    
}tree;

struct _Main {
    string buf;
    int idx, len;
    char nxtchar() {
        if (idx >= len ){
            return -1;
        } else {
            return buf[idx++];
        }
    }
    void getLine() {
        idx = 0;
        getline(cin, buf);
        len = buf.length();
    }
    template<typename Type>
        char read(Type &a) {
            char t;
            while (!isdigit(t = nxtchar())) {
                if (t == -1) {
                    return -1;
                }
            }
            a = t - '0';
            while ( isdigit(t = nxtchar())) {
                a *= 10;
                a += t - '0';
            }
            return 0;
        }
        
    _Main() {
        int i, j, k;
        int n, m;
        int Q, Qn;
        int a, b, c;
        int avgr[5];
        Data tmp;
        std::ios::sync_with_stdio(false);
        cin.tie(0);
        getLine();
        read(n); read(Qn);
        tree.setSize(n);
        getLine();
        for (i = 1; i <= n; i++) {
            read(a);
            tree.setVal(i, a - 1);
        }
        tree.build();
        for (Q = 1; Q <= Qn; Q++) {
            getLine();
            for (i = 0 ; i < 3; i++) {
                if (read(avgr[i])) {
                    break;
                }
            }        
            if (buf[0] == 'C'){
                if (i == 3) {
                    tree.change(avgr[0], avgr[1], avgr[2] - 1);
                } else {
                    tmp = tree.query(avgr[0]);
                    if (tmp[0]) {
                        tree.change(avgr[0], 1);
                    }else {
                        tree.change(avgr[0], 0);
                    }
                }
            } else {
                if (i == 2) {
                    tmp = tree.query(avgr[0], avgr[1]);
                    printf("%d %d\n", tmp[0], tmp[1]);
                } else {
                    tmp = tree.query(avgr[0]);
                    if (tmp[0]) {
                        printf("1\n");
                    } else if (tmp[1]){
                        printf("2\n");
                    }  
                }             
                   
            }
        }
    }
}race;
