using namespace std;
int main() {}
#include <cstdio>
#include <cctype>

namespace Protector {




struct _Main {
    template<typename Type>
        void read(Type &a) {
            char t;
            while(!isdigit(t=getchar()));
            a=t-'0';
            while( isdigit(t=getchar())){
                a*=10;a+=t-'0';
            }
        }
    void read_alpha(char &a){
        while(!isalpha(a = getchar()));
    }    
    int pre_sum[1002][1002];
    int inline get_sum(int x1, int x2, int y1, int y2) {
        return pre_sum[x2][y2] + pre_sum[x1 - 1][y1 - 1] - pre_sum[x1 - 1][y2] - pre_sum[x2][y1 - 1];
    }
    
    _Main() {
        int n, m, Qn;
        int Q;
        int i, j, k;
        int a, b;
        char t;
        read(n); read(m); read(Qn);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m ;j++) {
                while (isspace(t = getchar()));          
                if (t == '#') {
                    pre_sum[i][j] = 1;
                }
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m ;j++) {
                pre_sum[i][j] += pre_sum[i][j - 1] + pre_sum[i - 1][j] - pre_sum[i - 1][j - 1];
            }
        }
        for (Q = 1; Q <= Qn; Q++) {
            read(a); read(b); read_alpha(t);
            switch(t) {
                case 'L':{
                    if (get_sum(a, a, 1, b) == 0) {
                        printf("YES\n");
                    } else {
                        printf("NO\n");
                    }
                	break;
                }
                case 'R':{
                    if (get_sum(a, a, b, m) == 0) {
                        printf("YES\n");
                    } else {
                        printf("NO\n");
                    }                    
                	break;
                }
                case 'U':{
                    if (get_sum(1, a, b, b) == 0) {
                        printf("YES\n");
                    } else {
                        printf("NO\n");
                    }                                        
                	break;
                }
                case 'D':{
                    if (get_sum(a, n, b, b) == 0) {
                        printf("YES\n");
                    } else {
                        printf("NO\n");
                    }                          
                	break;
                }
            }
        }
    }
    
    
}A;



}
//记住前缀和传参是开区间还是闭区间 
