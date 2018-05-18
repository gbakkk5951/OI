using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
namespace OI {
typedef long long lld;
const lld 
    MOD = (7LL << 52) + 1,
    BEG = (7LL << 52), 
    DELTA = 1000; 
struct _Main {
    lld O1mul(lld a, lld b) {
        return ((a * b - (lld)((double)a / MOD * b) * MOD) % MOD + MOD) % MOD;
    }
    
    lld Ologmul(lld a, lld b) {
        lld ret = 0;
        while (a && b) {
            if (a & 1) {
                ret = (ret + b) % MOD;
            }
            a >>= 1;
            b = (b << 1) % MOD;
        }
        return ret;
    }
    _Main() {
       lld i, j, k;
       for (i = BEG; i > DELTA; i-= DELTA) {
           
            for (j = i; j > i - DELTA; j--) {
                for (k = i; k > i - DELTA; k--) {
                    if (O1mul(j, k) != Ologmul(j, k)) {
                        printf("found(%lld, %lld) = {%lld, %lld}\n", j, k, O1mul(j, k), Ologmul(j, k));
                    }
                }
            }
            printf("[%lld - %lld] finished\n", i - DELTA + 1, i);
       }
       
        
    }
    
}tester;

}
