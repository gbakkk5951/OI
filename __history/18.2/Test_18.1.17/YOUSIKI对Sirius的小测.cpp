using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>

namespace OI {
typedef long long lld;




struct _Main {
    char vis[2200];
    int idx[2200];
    int prime[400];
    int pidx;
    int getprime() {
        int i, j, t;
        for (i = 2; i <= 2000; i++) {
            if (!vis[i]) {
                prime[idx[i] = pidx++] = i;
            }            
            for (j = 0; j < pidx && (t = prime[j] * i) <=2000; j++) {
                vis[t] = 1;
                if (i % prime[j] == 0){
                    break;
                }
            }
        }
        return pidx;
    }
    int cnt[400];
    long long num[20];
    vector <int> fact[20];
    
    
    _Main() {
        
        int i, j, k;
        int I;
        int a, b, c;
        int n;
        int ans = 0;
        int cnt = 0;
        int rem;
        int Tn;
        int T;
        getprime();
        scanf("%d", &Tn);
        for (T = 1; T <= Tn; T++) {
            ans = 0;
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                scanf("%lld", &num[i]);
            }
            for (i = 0; i < n; i++) {
                fact[i].clear();
                rem = num[i];
                for (j = 0; j < pidx; j++) {
                    if (rem % prime[j] == 0) {
                        cnt = 0;
                        do {
                            rem /= prime[j];
                            cnt ^= 1;
                        } while(rem % prime[j] == 0);
                        if (cnt == 1) {
                            fact[i].push_back(j);
                        }
                    }
    
                }
            }
            
            for (I = 1; I < (1 << n); I++) {
                cnt = 0;
                for (i = 0; i < n; i++) {
                    if (I & (1 << i)) {
                        for (j = 0; j < fact[i].size(); j++) {
                            if (this->cnt[fact[i][j]]) {
                                cnt--;
                            } else{
                                cnt++;
                            }
                            this->cnt[fact[i][j]] ^= 1;
                        }
                    }   
                }
                memset(this->cnt, 0, 400 * sizeof(int));
                if (cnt == 0) {
                    ans++;
                }
            }
            printf("Case #%d:\n%d\n", T, ans);            
            
        }

    }
}T3;



}

