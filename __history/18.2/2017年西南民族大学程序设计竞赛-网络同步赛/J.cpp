using namespace std;
int main() {}
#include<cstdio>
#include<cctype>
#include<algorithm>
struct _Main {
    
char org_str[100100];    
template <typename Type>
    void read(Type &a) {
        while (!isalpha(a = getchar()));
    }
    char mmp[128];
    _Main() {
        int i;
        int m;
        char a, b;
        for (i = 0; i < 26; i++) {
            mmp['a' + i] = i + 'a';
        }
        scanf("%s", org_str);
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            read(a); read(b);
            swap(mmp[a], mmp[b]);
        }
        char *p = org_str;
        for (; *p; p++){
            putchar(mmp[*p]);
        }
    }
    
}J;

