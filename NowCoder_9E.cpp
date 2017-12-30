using namespace std;
int main() {}
#include<cstdio>
namespace Protector {

const int SQ = 31623;
const int MAXN = (int) 1e9;
int prime[3500],pIdx;
char noPrime[32000];
int getPrime (int maxNum) {
    int i,j;
    for (i = 2; i <= maxNum; i++) {
        if (!noPrime[i]) {
            prime[pIdx++] = i;
        }
        for (j = 0; j < pIdx && i * prime[j] <= maxNum; j++) {
            noPrime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                break;
            }
        }
    }
    
}

struct _Main {
    long long x, y;
    _Main() {
        int i, j;
        scanf("%lld%lld", &x, &y);
        if (x == 1) {
            printf("%d", y);
        } else if(y >= SQ || (long long)x * y > MAXN) {
            printf("0");
        } else {
            int l = y * y, r = MAXN + 1;
            int mid;
            long long tmp;
            getPrime(y - 1);
            while (l < r) {
                mid = l + r >> 1;
                tmp = mid / y;
                for (i = 0; i < pIdx; i++) {
                    tmp -= tmp / prime[i];
                    if(tmp < x) break;
                }
                if (tmp == x) {
                    printf("tmp == %d\n",tmp);
                }
                if (tmp < x) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (l >= MAXN + 1) {
                printf("%d", 0); 
            } else {
                printf("%d", l);
            }
        }
        
    }
    
    
}nowCoder9E;



}
