#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cmath>
using namespace std;
//const double eps =
int main(){
    char t;
    int n;
    int i, j;
    int score;
    while (~scanf("%d", &n)) {
        if (n == 0) {
            return 0;
        }
        score = 0;
        for (i = 1; i <= 13; i++) {
            for (j = 1; j <= 13; j++) {
                while((t = getchar()) != '#' && t != '.');
                if (t == '#') {
                    score += 1 + min((i > 7 ? 14 - i : i) >> 1, (j > 7 ? 14 - j : j) >> 1);
                }
            }
        }
        printf("%.2lf\n", 2.1250000 );        
    }
}
//多组数据记得换行 
// == 0 不要用float等 
