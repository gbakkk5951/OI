using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <algorithm>

namespace OI{
const int SQ = 31625;
const int NXT = 1;
const int DST = 0;
    int ans;
    char pvis[SQ + 1];
    int prime[4000];
    int pidx;
    int getprime() {
        int i, j, t;
        for (i = 2; i <= SQ; i++) {
            if (!pvis[i]) {
                prime[pidx++] = i;
            }            
            for (j = 0; j < pidx && (t = prime[j] * i) <= SQ; j++) {
                pvis[t] = 1;
                if (i % prime[j] == 0){
                    break;
                }
            }
        }
        return pidx;
    }
    bool vis[100010];
    int fact_list[5000000];
    int fact_n;
    vector<int> fact[100010];
    long long num[100010];
    
class Divider {
    int nd;
    int f(int a, int n) {
        return (long long) (a * a + 1) % n;
    }
    int inline pf(int a) {
        return a * a;
    }
    int gcd(int a, int b) {
        return b? gcd(b, a % b) : a;
    }
    
    long long fastpower(long long base, long long pow, long long mod) {
        long long ans = 1;
        base %= mod;
        while (pow) {
            if (pow & 1) {
                (ans *= base) %= mod;
            }
            pow >>= 1;
            (base *= base) %= mod;
        }
        return ans;
    }
    
    bool miller_rabin(int n, int mod) {
        int i, t;
        int pow = mod - 1;
        while (1) {
            t = fastpower(n, pow, mod);
            if (t == 1) {
                if (pow & 1) {
                    pow >>= 1;
                } else {
                    return true;
                }
            } else if (t == mod - 1) {
                return true;
            } else {
                return false;  
            }
        }
        
    }
    
    bool is_prime(int n) {
        int i;
        for (i = 0; i < 9 && n > prime[i]; i++) {
            if (miller_rabin(n, prime[i]) == false) {
                return false;
            }
        }
        return true;
    }
    
    
    /*
    bool is_prime(int n) {
        int i;
        for (i = 0; i < pidx && prime[i] < n; i++) {
            if (n % prime[i] == 0) {
                return false;
            }
        }
        return true;
    }*/
    
    void div(int n) {
        if (n == 1) {
            return;
        }
        if (is_prime(n)) {
            fact[nd].push_back(n);
            return;
        }
        
        if (n <= 1e4) {
            int i;
            for (i = 0; pf(prime[i]) <= n; i++) {
                if (n % prime[i] == 0) {
                    fact[nd].push_back(prime[i]);
                    do {
                        n /= prime[i];
                    } while (n % prime[i] == 0);
                }
            }
            if (n > 1) {
                fact[nd].push_back(n);
            }
            return;
        }
        
//        printf("div %d\n", n);
        int x, y, t, cnt;
        y = x = rand();
        int i;
        while (1) {
            x = rand() % n; y = rand() % n;
            cnt = 0;
            while (x != y && cnt < 150) {
                t = abs(x - y);
                cnt++;
                if (t > 1 && (t = gcd(t, n)) > 1 && t != n) {
                    div(t);
                    do {
                        n /= t;  
                    } while (n % t == 0);
                    div(n);
                    return ;   
                }
                x = f(x, n);
                y = f(f(y, n), n);
            }
        }
    }
    
public:
    void divide (int nd) {
        this->nd = nd;
        int rem = num[nd];
        if (rem > 1e7) {
            int i;
            for (i = pidx - 1; i >= pidx - 100; i--) {
                if (rem % prime[i] == 0) {
                    fact[nd].push_back(prime[i]);
                    do {
                        rem /= prime[i];
                    }while(rem % prime[i] == 0);
                    if (rem < 1e7) {
                        break;
                    }
                }
            }
            div(rem);
        } else {
            div(num[nd]);
        }
        
        
        
        sort(fact[nd].begin(), fact[nd].end());
        fact[nd].resize(unique(fact[nd].begin(), fact[nd].end()) - fact[nd].begin());
    }
    /*
    void tst() {
        int i;
        for (i = 2; i <= 50000; i++) {
            if (is_prime(i)) {
                printf("%d,", i);
            }
        }
        
    }*/
}divider;


    int head[100010];
    int edge[200010][2];
    vector<int>node[1000000]; 
int getAns(int nd, long long fact) {
    int longest[3] = {0, 0, 0};
    int i, t;
    vis[nd] = 1;
    for (i = head[nd]; i; i = edge[i][NXT]) {
        if (!vis[t = edge[i][DST]] && num[t] % fact == 0) {
            longest[0] = getAns(t, fact) + 1;
        }
        sort(longest, longest + 3);
    }
    ans = max(ans, longest[1] + longest[2]);
    return longest[2];
}
int eidx;
void inline add(int a, int b) {
    eidx++;
    edge[eidx][DST] = b;
    edge[eidx][NXT] = head[a];
    head[a] = eidx;
}

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
        srand(156);
        int n, i, j, k
        , a, b, c;
        int idx = 0;
        getprime();
        read(n);
//        n = 100000;
        for (i = 1; i <= n - 1; i++) {
            read(a); read(b);
//            a = i + 1;
  //          b = rand() % (i) + 1;
            add(a, b);
            add(b, a);
        }
        
        for (i = 1; i <= n; i++) {
//            num[i] = (rand() << 15 | rand()) % (int)1e9 + 1;
            read(num[i]);
   //         num[i] = 999002449;
            divider.divide(i);
            for (j = 0; j < fact[i].size(); j++) {
                fact_list[idx++] = fact[i][j];
            }
        }
        sort(fact_list, fact_list + idx);
        idx = unique(fact_list, fact_list + idx) - fact_list;
        for (i = 1; i <= n; i++) {
            for (j = 0; j < fact[i].size(); j++) {
                node[lower_bound(fact_list, fact_list + idx, fact[i][j]) - fact_list].push_back(i);
            }
        }
        for (i = 0; i < idx; i++) {
            for (j = 0; j < node[i].size(); j++) {
                if (!vis[node[i][j]]) {
                    getAns(node[i][j], fact_list[i]);
                }
            }
            for (j = 0; j < node[i].size(); j++) {
                vis[node[i][j]] = 0;
            }
        }
        printf("%d", ans + 1);
    }
    
    
}T1;

    
    
}


