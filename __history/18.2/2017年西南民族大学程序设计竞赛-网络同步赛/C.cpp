using namespace std;
int main() {}
#include <algorithm>
#include <cstdio>
#include <cctype>
namespace Protector {
struct _Main {
    template<typename Type>
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
    
    int dif[2][100005];
    int size[2];
    long long ans;
    int val[100005][2];
    int mor_need;
    _Main() {
        int n;
        int i, j;
        read(n); read(mor_need);
        for (j = 0; j <= 1; j++) {
            for (i = 1; i <= n; i++) {
                read(val[i][j]);
            }
        }
        for (i = 1; i <= n; i++) {
            if (val[i][0] > val[i][1]) {
                dif[0][size[0]++] = val[i][0] - val[i][1];
                ans += val[i][0];
            } else {
                dif[1][size[1]++] = val[i][1] - val[i][0];
                ans += val[i][1];                
            }
        }
        if (mor_need > size[0]){
            nth_element(dif[1], dif[1] + mor_need - size[0] - 1, dif[1] + size[1]);
            for (i = 0; i < mor_need - size[0]; i++) {
                ans -= dif[1][i];
            }            
            
        } else if(mor_need < size[0]){
            nth_element(dif[0], dif[0] + size[0] - mor_need - 1, dif[0] + size[0]);
            for (i = 0; i < size[0] - mor_need; i++) {
                ans -= dif[0][i];
            }
        }
        printf("%lld", ans);
    }  
    
}C;

}
