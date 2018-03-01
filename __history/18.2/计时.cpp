#include <ctime>
#include <cstdio>
using namespace std;


int main () {
    float a, b;
    int i;
    a = clock();
    for (i = 1; i <= 1000000000; i++);
    b = clock();
    printf("%f\n", b - a);
    a = clock();
    for (i = 1; i <= 1000000000; ++i);
    b = clock();    
    printf("%f\n", b - a);
}
