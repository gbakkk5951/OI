using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <ctime>
namespace OI {
typedef long long lld;
const lld 
    MOD = (5LL << 55) + 1,
    DELTA = 2000, 
    BEG = MOD
    ; 
struct _Main {
    lld O1mul(lld a, lld b) {
        return (a * b - (lld)((long double)a / MOD * b) * MOD);
//        return ((a * b - (lld)((double)a / MOD * b) * MOD) % MOD + MOD) % MOD;
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
        lld cnt = 0;
        float ta, tb, tc;
        for (i = BEG; i > DELTA; i-= DELTA) {
            ta = clock();
            for (j = i; j > i - DELTA; j--) {
                for (k = i; k > i - DELTA; k--) {
                    O1mul(j, k); 
                }
            }
            tb = clock();
            printf("O1 uses %f\n", tb - ta);
            for (j = i; j > i - DELTA; j--) {
                for (k = i; k > i - DELTA; k--) {
                    Ologmul(j, k); 
                }
            }    
            tc = clock(); 
            printf("Olog uses %f\n", tc - tb);        
        }
       
        
    }
    
}tester;

}
