/* 原 理 */
using namespace std;
int main() {}
#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>
namespace Protector {
const long long MOD = 1e9 + 7;    
struct ScoreSum;
typedef ScoreSum Sum;

long long fact[2000010];
void getFact(int max_fact) {
    int i;
    for (fact[0] = 1, i = 1; i <= max_fact; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
}
long long fastpower(long long base, long long pow) {
    long long ret = 1;
    while (pow) {
        if (pow & 1) {
            (ret *= base) %= MOD;
        }
        pow >>= 1;
        (base *= base) %= MOD;
    }
    return ret;
}
long long inline getRev(long long a) {
    return fastpower(a, MOD - 2);
}
long long inline getCombine(int chose, int from){
    if (chose > from || chose < 0 || from < 0) {
        return 0;   
    } else {
        return fact[from] * getRev(fact[chose]) % MOD * getRev(fact[from - chose]) % MOD;
    }
}
struct ScoreSum {
private:    
    vector<int> limits;
    int val;
    int limit_cnt;
    int tot_cnt;    
public:
    void setVal(int new_val){
        val = new_val;
    }
    void insertNum(int idx = 0) {
        tot_cnt++;
    }
    void insertLimit(int new_limit) {
        if (new_limit < val) {
            limits.push_back(new_limit);
            limit_cnt++; 
        }
    }
    long long getSizeOfSchemes() {
        int I, i;
        int chose, from;
        int now_limit_cnt;
        int now_val;
        long long ret = 0;
        for (I = 0; I < 1 << limit_cnt; I++) {
            now_val = val;
            now_limit_cnt = 0;
            for (i = 0; i < limit_cnt; i++) {
                if (I & (1 << i)) {
                    now_limit_cnt++;
                    now_val -= limits[i] + 1;
                }
            }
            (ret += getCombine(tot_cnt - 1, now_val + tot_cnt - 1) * ((now_limit_cnt & 1) ? -1 : 1)) %= MOD; 
        }
        return (ret % MOD + MOD) % MOD;
    }
};
vector<Sum> sum;
int belong[1000010];


struct _Main {
template <typename Type>
    void read(Type &a) {
        char t;
        while (!isdigit(t = getchar()));
        a = t - '0';
        while ( isdigit(t = getchar())) {
            a *= 10;
            a += t - '0';
        }
    }     
    _Main() {
        int n, m;
        int i, j, k;
        int a, b, c;
        long long ans;
        read(n); read(m);
        sum.resize(m + 1);
        int mxfact = 1;
        for (i = 1; i <= m; i++) {
            read(a);
            for (j = 1; j <= a; j++) {
                read(b);
                belong[b] = i;
                sum[i].insertNum(b);
            }
            read(b);
            sum[i].setVal(b);
            mxfact = max(mxfact, a + b - 1);
        }
        getFact(mxfact);
        read(a);
        for (i = 1; i <= a; i++) {
            read(b); read(c);
            sum[belong[b]].insertLimit(c);
        }
        for (ans = 1, i = 1; i <= m; i++) {
            (ans *= sum[i].getSizeOfSchemes()) %= MOD;
        }
        printf("%lld", (ans % MOD + MOD) % MOD);
    }
    
    
    
    
}T3;








}
//数据范围较小 有限制的<=20 考虑 容斥， 
//开区间和闭区间 ，注意闭区间容斥的时候 +1 -1 的问题 

