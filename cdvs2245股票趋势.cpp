using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>

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
    void clear() {
        memset(node, 0, base * 2 * sizeof(int));   
    }
    void setSize(int new_size) {
        n = new_size;
        for (base = 1; base < n + 2; base <<= 1);
    }
    void change(int nd, int val) {
        for (nd += base; nd; nd >>= 1) {
            node[nd] = max(node[nd], val);
        }
    }
}tree[810];
class Solver {
public:
char a[MAXN], b[MAXN];
int la, lb;    

    
    
    
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
        
        
        
        
    }
    
};












}
