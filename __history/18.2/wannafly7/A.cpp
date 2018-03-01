using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
namespace Protector {
typedef long long lld;    
const lld LINF = 0x3f3f3f3f3f3f3f3fLL >> 1;
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
    int bomb_size;
    
    long long getMinBomb(lld len1, lld len2) {
        if (len1 <= 0 || len2 <= 0) {
            return 0;
        }
        if (len1 < bomb_size || len2 < bomb_size) {
            return LINF;
        }
        return ((len1 + bomb_size - 1) / bomb_size) * ((len2 + bomb_size - 1) / bomb_size);
    }
    _Main() {
        int T;
        int n, m, r, c;
        read(T);
        lld ans;
        while (T--) {
            read(n); read(m); read(r); read(c); read(bomb_size);
            ans = 0;
            ans += getMinBomb(r - 1, c - 1);
            ans += getMinBomb(n - r, m - c);
            ans += getMinBomb(r - 1, m - c);
            ans += getMinBomb(n - r, c - 1);    
            if (ans >= LINF) {
                printf("-1\n");
            } else {
                printf("%lld\n",ans);
            }       
        }
        
    }
    
    
    
}A;
}
