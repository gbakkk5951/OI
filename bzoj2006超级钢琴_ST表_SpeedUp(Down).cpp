using namespace std;
int main() {}

#include<cstdio>
#include<cctype>
#include<cstring>
#include<queue>
#include<cstdlib>
namespace Protector {
    
const int MAXN = 500005;
const int TREESIZE = 1050000;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long MOV = (long long) 1e6;

int preSum[MAXN];

template <typename Type> 
    void read(Type &a) {
        char t, f = 1;
        while (! isdigit(t = getchar())) {
            if (t == '-') {
                f = -1;
            }
        }
        a = t - '0';
        while (  isdigit(t = getchar())) {
            a *= 10;
            a += t - '0'; 
        }
        a *= f;
    }


struct Range {
    int l, r;
    int rightPos;
    int minPos;
    int val;    
    bool operator < (const Range &b) const {
        return val < b.val;
    }
};




class MinSegTree {

private :
    
    long long St[TREESIZE][20];
    int size;
    int base;

public:
    void inline setVal(int pos,long long val) {
        St[pos][0] = val;
    }
    void setSize(int newSize) {
        size = newSize;
        for (base = 1; base < size; base <<= 1);
    }
    void buildTree() {
        int i,I;
        for(I = 1; 1 << I <= base; I++){
            for (i = 1; i <= size; i++) {
                St[i][I] = min(St[i][I-1], (i + (1 << I-1) > size) ? -LINF : St[i + (1 << I-1)][I-1]);
            }
        }

    }
    long long queryMin(int l, int r) {
        int I;
        for (I = 0; 1 << I + 1 <= r - l + 1; I++);
        return min(St[l][I], St[r - (1 << I) + 1][I]);
    }
}tree;

priority_queue<Range> heap;


struct _Main {
int n;
int m;
int L,R;
long long ans;

void addRange (int l, int r, int rightPos) {
    if (l > r) {
        return;
    }
    long long leftMin = tree.queryMin(l, r);
    heap.push(Range {l, r, rightPos,(int) abs (leftMin % MOV) ,(int) preSum[rightPos] - (int) (leftMin / MOV)});  
}

_Main() {
    int i, j, k;
    read(n);read(m);read(L);read(R);
    tree.setSize(n + 1);
    tree.setVal(1 , 1); 
    for (i = 1; i <= n; i++) {
        read(preSum[i]);
        preSum[i] += preSum[i-1];
        tree.setVal(i + 1, preSum[i] * MOV + (preSum[i] < 0 ? -1LL : 1LL) * (i + 1));
    }
    tree.buildTree();
    int l, r;
    for (i = L; i <= n; i++) {
        l = max(1, i - R +1);
        r = i - L + 1;
        addRange(l, r, i);    
    }
    Range tmp;
    for (i = 1; i <= m; i++) {
        tmp = heap.top();
        heap.pop();
        ans += tmp.val;
//        printf("add %d %d %d\n", tmp.minPos , tmp.rightPos, tmp.val);
        addRange(tmp.l, tmp.minPos - 1, tmp.rightPos);
        addRange(tmp.minPos + 1, tmp.r, tmp.rightPos);
    }
    printf("%lld", ans);
}

    
    
    
    
}bzoj2006;




}

//插入的是前缀和不是单点
//既然是前缀和那么就是 L-1 到 R-1
//类型改变要改完 例如 node 改为long long ，但在插入时没改 
//long long 要用LINF 
//要查0号点的，应该是WA的，但数据水 

