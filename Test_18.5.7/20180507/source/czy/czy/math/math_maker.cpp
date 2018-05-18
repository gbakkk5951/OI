#include <bits/stdc++.h>

using namespace std;

int main() {
    srand((unsigned long long) new char);
    int n = 100;
    printf("%d\n", n);
    for(int i = 1 ; i <= n ; ++ i) {
        printf("%d ", rand() % n + 1);
    }
    puts("");
}
