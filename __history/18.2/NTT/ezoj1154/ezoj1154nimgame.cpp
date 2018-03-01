using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

namespace OI {
    
typedef long long lld;
typedef vector <lld>::iterator It;

namespace NTT_Space {
const lld 
    MOD = (15 << 27) + 1,
    PHI = MOD - 1,
    G = 31
;    

lld fastpower (lld base, lld pow) {
    lld ret = 1;
    if (pow < 0) {
        pow += PHI;
    }
    while (pow) {
        if (pow & 1) {
            ret = ret * base % MOD;
        }
        pow >>= 1;
        base = base * base % MOD;
    }
    return ret;
}

void mov_ele (It arr, int len) {
    int i, j, k;
    for (i = 1, j = 0; i < len; i++) {
        for (k = len >> 1; k & j; k >>= 1) {
            j ^= k;
        }
        j |= k;
        if (i < j) {
            swap(arr[i], arr[j]);
        } 
    }
}
void NTT (It arr, int len, int pow = 1) {
    static lld w[32768 + 3];
    It a, b;
    lld wn, y;
    int i, j, k, half;
    w[0] = 1;
    mov_ele(arr, len);
    for (i = 1; 1 << i <= len; i++) {
        wn = fastpower(G, pow * PHI >> i);
        half = 1 << i - 1;
        for (j = half - 2; j > 0; j -= 2) {
            w[j] = w[j >> 1];
        }
        for (j = 1; j < half; j += 2) {
            w[j] = w[j - 1] * wn % MOD;
        }
        for (j = 0; j < len; j += half << 1) {
            a = arr + j; b = a + half;
            for (k = 0; k < half; k++) {
                y = b[k] * w[k];   
                b[k] = (a[k] - y) % MOD;
                a[k] = (a[k] + y) % MOD;
            }
        }
    }
    if (pow == -1) {
        wn = fastpower(len, -1);
        for (i = 0; i < len; i++) {
            arr[i] = arr[i] * wn % MOD;
        }
    }
    
}



}

queue<It> q[18];
vector <lld> pool[140000];
int pidx;

struct Arr {
    int bit;
    int mx;
    It beg;
    bool operator > (const Arr &a) const {
        return mx > a.mx; 
    }
};
priority_queue <Arr, vector <Arr>, greater <Arr> > heap;


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
    lld fact[50010], rev_fact[50010];
    lld com(int n, int m) {
        using NTT_Space:: MOD;
        return fact[n] * rev_fact[m] % MOD * rev_fact[n - m] % MOD;
    }
   
    _Main() {
        using NTT_Space:: MOD;
        using NTT_Space:: fastpower;
        using NTT_Space:: NTT;     
        int n;
        int i, j, k, T, Tn;
        /*
        int arr[3] = {2, 3, 5};
        for (i = 2; i <= 1000000; i++) {
            using NTT_Space:: PHI;
            for (j = 0; j < 3; j++) {
                if (fastpower(i, PHI / arr[j]) == 1) {
                    break;
                }
            }
            if (j == 3) {
                break;
            }
        }printf("%d", i);
        */
        fact[0] = 1;
        for (i = 1; i <= 50000; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        for (i = 0; i <= 50000; i++) {
            rev_fact[i] = fastpower(fact[i], -1);
        }
        for (i = 1; i <= 16; i++) {
            for (j = 1; j <= 1 << (17 - i); j++) {
                pool[pidx].resize((1 << i) + 1);
                q[i].push(pool[pidx].begin());
                pidx++;
            }
        }
        read(Tn);
        for (T = 1; T <= Tn; T++) {
            read(n);
            int HeOne = 0;
            for (i = 1; i <= n; i++) {
                int a, bit; It tmp;
                read(a);
                if (a != 1) {
                    HeOne = 1;
                }
                for (bit = 1; 1 << bit < a + 1; bit++);
                tmp = q[bit].front();
                q[bit].pop();
                tmp[0] = 0;
                for (j = 1; j < 1 << bit; j++) {
                    if (j <= a) {
                        tmp[j] = com(a - 1, j - 1);
                    } else {
                        tmp[j] = 0;
                    }
                }
                heap.push((Arr){bit, a, tmp});
            }
            while (heap.size() > 1) {
                int bit;
                Arr a[2];
                It a_[2];
                for (i = 0; i < 2; i++) {
                    a[i] = heap.top();
                    heap.pop();                
                }
                for (bit = 1; 1 << bit < a[0].mx + a[1].mx + 1; bit++);
                for (i = 0; i < 2; i++) {
                    if (a[i].bit < bit) {
                        a_[i] = q[bit].front();
                        q[bit].pop();
                        for (j = 0; j < 1 << bit; j++) {
                            a_[i][j] = j <= a[i].mx ? a[i].beg[j] : 0;
                        }
                        q[a[i].bit].push(a[i].beg);
                    } else {
                        a_[i] = a[i].beg;
                    }
                    for (j = 1; j <= a[i].mx; j++) {
                        a_[i][j] = a_[i][j] * rev_fact[j] % MOD;
                    }     
                    NTT(a_[i], 1 << bit);
                }
                
                for (i = 0; i < 1 << bit; i++) {
                    a_[0][i] = a_[0][i] * a_[1][i] % MOD;
                }
                
                NTT(a_[0], 1 << bit, -1);
                for (i = 1; i <= a[0].mx + a[1].mx; i++) {
                    a_[0][i] = a_[0][i] * fact[i] % MOD;
                }
                
                heap.push((Arr) {bit, a[0].mx + a[1].mx, a_[0]});
                q[bit].push(a_[1]);
            }
            
            It tmp = heap.top().beg;
            lld ans = 0;
            for (i = 1, ans = 0; i <= heap.top().mx; i += 2) {
                ans += tmp[i];
            }
            printf("%lld ", HeOne ? 1006632961LL : (lld)(n & 1));
            printf("%lld\n", (ans % MOD + MOD) % MOD);
            q[heap.top().bit].push(heap.top().beg);
            heap.pop();
        }
    }
    
}ezoj1154;







}


