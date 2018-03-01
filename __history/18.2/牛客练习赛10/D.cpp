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
    void readAlpha(char &a) {
        while (!isalpha(a = getchar()));
    }
    char str[105];
    _Main() {
        int n, m;
        int i, j;
        int l, r;
        char a, b;
        read(n); read(m);
        scanf("%s", &str[1]);
        for (i = 1; i <= m; i++) {
            read(l); read(r);
            readAlpha(a); readAlpha(b);
            for (j = l; j <= r; j++) {
                if (str[j] == a) {
                    str[j] = b;
                }
            }
        }
        printf("%s", &str[1]);
    }
        
    
}C;

}
