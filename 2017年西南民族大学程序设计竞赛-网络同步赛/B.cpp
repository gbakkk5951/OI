#include <cstdio>
#include <cctype>
int main() {
    char t, lst;
    while (!isdigit(t = getchar()));
    lst = t;
    do {
        if (t != lst) {
            printf("NO");
            goto end_main;
        }
        lst = t;
    }while (isdigit(t = getchar()));
    printf("YES");
    end_main:;
}
