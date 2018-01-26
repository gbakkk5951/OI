using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>
namespace OI {
struct _Main {
    template <typename Type>
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
    int arr[100100];
    _Main() {
        int a, b;
        int n;
        int i, j, k;
        int ans = 0;
        read(n);
        for (i = 1; i <= n; i++) {
            read(a); read(b);
            if (a > b) {
                swap(a, b);
            }
            arr[i] = -b - a;
            ans += a;
        }
        nth_element(arr + 1, arr + (n >> 1), arr + n + 1);
        for (i = 1; i <= (n >> 1); i++) {
            ans += arr[i];
        }
        printf("%d", ans);
    }
    
    
}card;

}
