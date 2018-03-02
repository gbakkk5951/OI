using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
namespace Protector {
const int MAXN = 1000010;

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
    int stk[MAXN];
    int stk_top;
    int ans[MAXN];
    int ans_idx;
    char in[MAXN];
    char out[MAXN];
    int now_max;
    
    _Main() {
        int n;
        int i;
        int a;
        int t;
        read(n);
        now_max = n;    
        for (i = 1; i <= n; i++) {
            read(a);
            if (a == now_max) {
                ans[++ans_idx] = a;
                now_max--;
                while (in[now_max]) {
                    t = stk[stk_top--];
                    ans[++ans_idx] = t;
                    out[t] = 1;
                    while(out[now_max] && now_max > 0) {
                        now_max--;
                    }
                }
            } else {
                in[a] = 1;
                stk[++stk_top] = a;
            }
        }
        for (i = 1; i <= n; i++) {
            printf("%d",ans[i]);
            if (i != n) {
                putchar(' ');
            }
        }
    }
        
    
}B;

}
