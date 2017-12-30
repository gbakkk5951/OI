using namespace std;
int main() {}
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<vector>
namespace Protector{
const long long SQ = 317 ;
const long long MOD = 1e9 + 7;
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
struct Query {
    int block,l,r,idx;
    bool operator < (const Query &b) const {
        if (block != b.block) {
            return block < b.block; 
        } else {
            return r < b.r; 
        }
    }
}ques[100010];
int ans[100010];
//long long fact[2000010];
vector <int> primeFac[100010];
long long mul = 1, div = 1;

long long fastpower(long long base, long long pow) {
    long long ret = 1;
    while (pow) {
        if (pow&1) {
            (ret *= base) %= MOD;
        }
        (base *= base) %= MOD;
        pow >>= 1;
    }
    return ret;
}
long long inline getRev(long long a) {
    return fastpower(a, MOD - 2LL);
}
int prime[80000], pIdx;
char noPrime[1000005];
int minDivIdx[1000050];
void getPrime(int maxn) {
    int i, j, t;
    for (i = 2; i <= maxn; i++) {
        if (noPrime[i] == 0) {
            prime[pIdx] = i; 
            minDivIdx[i] = pIdx++;
        }
        for (j = 0; j < pIdx && (t = prime[j] * i) <= maxn; j++) {
            noPrime[t] = 1;
            minDivIdx[t] = j;
            if (prime[j] % i == 0) {
                break;
            }
        }
    }
    
}
struct _Main {
int n,Qn;
int cnt[1000005];
void init() {
    read(n); read(Qn);
    int i, j, k;
    int a;

    getPrime(1000000);
    for (i = 1; i <= n; i++) {
        read(a);  
        while (a != 1) {
            primeFac[i].push_back(minDivIdx[a]);
            a /= prime[minDivIdx[a]];
        }
    }
    for (i = 1; i <= Qn; i++) {
        read(ques[i].l); read(ques[i].r);
        ques[i].idx = i; ques[i].block = ques[i].l / SQ;
    }
    sort(ques + 1, ques + Qn + 1);
}

void insertNum(int pos, long long &mul, long long &div) {
    int i, nowFac;
    for(i = 0; i < primeFac[pos].size(); i++) {
        nowFac = primeFac[pos][i];
        (div *= cnt[nowFac] + 1) %= MOD;
        cnt[nowFac]++;
        (mul *= cnt[nowFac] + 1) %= MOD;
    }
}
void eraseNum(int pos, long long &mul, long long &div) {
    int i, nowFac;
    for(i = 0; i < primeFac[pos].size(); i++) {
        nowFac = primeFac[pos][i];
        (div *= cnt[nowFac] + 1) %= MOD;
        cnt[nowFac]--;
        (mul *= cnt[nowFac] + 1) %= MOD;
    }
}
void dealQues() {
    int Q;
    int l = 0, r = 0;
    long long mul = 1, div = 1;
    for (Q = 1; Q <= Qn; Q++) {
        while (l > ques[Q].l) {
            insertNum(--l, mul, div);
        }
        while (r < ques[Q].r) {
            insertNum(++r, mul, div);
        }        
        while (l < ques[Q].l) {
            eraseNum(l++, mul, div);
        }        
        while (r > ques[Q].r) {
            eraseNum(r--, mul, div);
        }
        ans[ques[Q].idx] = mul * getRev(div) % MOD;
    }
}

void output() {
    int i;
    for (i = 1; i <= Qn; i++) {
        printf("%d\n", ans[i]);
    }
}
    
_Main() {
    init();
    dealQues();
    output();
}
    
    
}nowCoder9F;


}
//一开始要想好计算式，写错的话浪费很多时间（预处理阶乘什么的） 
//看好时间限制， 
