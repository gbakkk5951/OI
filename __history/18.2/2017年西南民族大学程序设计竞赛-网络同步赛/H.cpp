#include<cstdio>
const char str1[] = "gu...";
const char str2[] = "The story is so boring. And I am so hungry!";
int main() {
    int n;
    
    while (~scanf("%d", &n)) {
        while (n--) {
            printf("%s", str1);
        }
        printf("\n%s\n",str2);
    }
    
}
