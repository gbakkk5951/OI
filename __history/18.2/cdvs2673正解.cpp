using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
typedef long long lld;
const int MAXN = 1000010;
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
    int stk[MAXN][2];
    int arr[MAXN];
    int top;
        
    _Main() {
        lld ans = 0;
        int n, i, l;
        read(n);
        for (i = 0; i < n; i++) {
            read(arr[i]);
        }
        for (i = 0; i <= n; i++) {
            l = i;
            while (top && stk[top][0] > arr[i]) {
                ans = max(ans, (lld)stk[top][0] * (i - stk[top][1]));
                l = stk[top][1];
                top--;
            }
            stk[++top][0] = arr[i];
            stk[top][1] = l;
        }
        printf("%lld", ans);
    }
    
    
    
    
}cdvs2673;
