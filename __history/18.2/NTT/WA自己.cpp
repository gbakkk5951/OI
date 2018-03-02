using namespace std;
int main() {}
#include <cstdio>
namespace Protector {
//Ä¿±ê 2009071618 
typedef long long lld;
lld pf(lld a) {
    return a * a;
}
struct _Main {
    
    _Main() {
        lld i, j, k;
        for (i = 0; i <= 26; i++) {
            printf("%lld: ", i);
            for (j = i + 1; j <= 26; j++) {
                printf("*%lld = %lld, ", j, i*j*pf(i-j));
            }
            printf("\n");
        }
        
    }
    
    
    
    
}WA;

}
