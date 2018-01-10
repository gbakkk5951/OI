using namespace std;
int main () {}
#include<cstdio>
#include<cctype>
#include<cstring>
namespace Protector {
const long long MOD = 1e9 + 7;
struct Matrix {
    long long val[9][9];
    long long & operator () (int i, int j){
        return val[i][j];
    }
    Matrix() {
        memset(this, 0 ,sizeof(Matrix));
    }
    Matrix operator * (Matrix b) {
        Matrix ret;
        int i, j, k;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                for (k = 0; k < 9; k++) {
                    (ret(i, j) += val[i][k] * b(k, j)) %= MOD;
                }
            }
        }
        return ret;
    }
}trans, org, res;



struct _Main {
    long long ways[9][9];
    char num[3][3]; 
    char vis[9];
    long long dfs(int pos = 0) {
        if (pos == 9) return 1;
        long long ret = 0;
        int i;
        for (i = 0; i < 9; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                (ret += ways[pos][i] * dfs(pos + 1)) %= MOD; 
                vis[i] = 0;
            }
        }
        return ret;
    }
    
    
    void initTrans() {
        
        int i, j;
        char *s;
        s = &num[0][0];
        for (i = 0; i < 9; i++, s++) {
            *s = i;
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                trans(num[i][j], num[i][j]) = 1;
                if (i) {
                    trans(num[i][j], num[i - 1][j]) = 1;
                }
                if (i + 1 < 3) {
                    trans(num[i][j], num[i + 1][j]) = 1;
                }
                if (j) {
                    trans(num[i][j], num[i][j - 1]) = 1;
                }   
                if (j + 1 < 3) {
                    trans(num[i][j], num[i][j + 1]) = 1;
                }                             
            }
        }
    }
    Matrix fastpower(Matrix base, long long pow) {
        pow--;
        Matrix ret = base;
        while (pow) {
            if (pow & 1) {
                ret = ret * base;
            }
            if (pow >>= 1) {
                base = base * base;
            }
        }
        return ret;
    }
    _Main() {
        long long ans;
        int i, j;
        long long n;
        scanf("%lld", &n);
        initTrans();
        trans = fastpower(trans, n);
        for (i = 0; i < 9; i++) {
            org(0, i) = 1;
            res = org * trans;
            for (j = 0; j < 9; j++) {
                ways[i][j] = res(0, j);
            }
            org(0, i) = 0;
        }
        ans = dfs();
        printf("%lld\n", ans);
    }
      
    
    
}stupid;



}
