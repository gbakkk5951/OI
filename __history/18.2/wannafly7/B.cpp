using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<algorithm>
namespace Protector {
typedef long long lld;    
const lld LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
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
    int pos, pos_rank;
    int city_pos[100010], city_near[100010];
    int n, m;
    lld getMinTime(int dst) {
        lld rem = m;
        lld ret = 0;
        if (dst >= pos_rank) {
            rem -= dst - pos_rank + 1;
        } else {
            rem -= pos_rank - dst;
        }
        ret = abs(city_pos[dst] - pos);  
        if (rem <= 0){
            return ret;
        } else {
            return ret + rem * city_near[dst];
        }
    }
    _Main() {
        int T;
        int i, j, k;
        int a, b, c;
        lld ans;
        read(T);
        while (T--) {
            ans = LINF;
            read(n); read(m); read(pos);
            for (i = 1; i <= n; i++) {
                read(city_pos[i]);
            }
            sort(city_pos + 1, city_pos + n + 1);
            city_near[1] = min(city_pos[2] - city_pos[1], 2);
            city_near[n] = min(city_pos[n] - city_pos[n - 1], 2);
            for (i = 2; i <= n - 1; i++) {
                city_near[i] = min(city_pos[i + 1] - city_pos[i], city_pos[i] - city_pos[i - 1]);
                city_near[i] = min(city_near[i], 2);
            }
            pos_rank = lower_bound(city_pos + 1, city_pos + n + 1, pos) - city_pos;
            for (i = 1; i <= n; i++) {
                ans = min(ans, getMinTime(i));
            }
            if (n == 1) {
                ans = abs(pos - city_pos[1]) + (m - 1 << 1); 
            }
            printf("%lld\n", ans);
        }
        
    }
    
    
    
}B;

}
