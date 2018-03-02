using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstdlib>
namespace OI {
typedef long long lld;
const lld 
    MOD = (7LL << 52) + 1,
    DELTA = 10, 
    BEG = 3743134592LL
    ; 
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
    lld O2mul(lld a, lld b) {
        return ((a * b - (lld)((long double)a / MOD * b) * MOD) % MOD + MOD) % MOD;
    }
    _Main() {
        srand(time(0));
        lld i, j, k, j_, k_;
        lld cnt = 0;
        for (i = BEG; i > DELTA; i-= DELTA) {
            for (j_ = i; j_ > i - DELTA; j_--) {
                j = j_;
//                j = ((lld)rand() << 45 ^ (lld)rand() << 30 | (lld) rand() << 15 | rand() ) % MOD;
//                j = ( (lld)rand() << 30 | (lld) rand() << 15 | rand() ) % MOD;
                /*for (k_ = i; k_ > i - DELTA; k_--) {
                    k = k_;
//                    k = ((lld)rand() << 45 ^ (lld)rand() << 30 | (lld) rand() << 15 | rand() ) % MOD;
                    if (O1mul(j, k) != O2mul(j, k)) {
                        printf("found(%lld, %lld) = {%lld, %lld}\n", j, k, O1mul(j, k), O2mul(j, k));
                        system("pause");
                    }
                }*/
                for (k_ = i; k_ > i - DELTA; k_--) {
//                    k = (((lld)rand() << 45 ^ (lld)rand() << 30 | (lld) rand() << 15 | rand() ) & ((1 << (rand() %60)) - 1)) % MOD;
                    k = k_;
                    if (O1mul(j, k) != O2mul(j, k)) {
                        printf("found(%lld, %lld) = {%lld, %lld}\n", j, k, O1mul(j, k), O2mul(j, k));
                        system("pause");
                    }                    
                }
            }
            if ((BEG - i ) % 5000000 == 0)
            printf("%lld\n", i);
//            printf("(%lld)[%lld] finished\n", ((MOD - i) / DELTA + 1), ((MOD - i) / DELTA + 1) * DELTA);
        }
        printf("finish");
        
    }
    
}tester;

}
