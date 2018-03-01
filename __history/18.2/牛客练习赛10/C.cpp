using namespace std;
int main() {}
#include<cstdio>
#include<cctype>
#include<algorithm>

namespace Protector {
const char DIV = 'Z' + 1;
const long long MOD [2] = {13777777777331179LL, 1377773177339173LL};
const long long BASE [2] = {31LL, 29LL};
long long pow[2][200020];
long long mul(long long a, long long b, long long mod) {
    return (a * b % mod + mod) % mod;
}

struct Hash{
    long long val[2];
    bool operator == (const Hash &b) {
        val[0] == b.val[0];
        val[1] == b.val[1];
    }
    long long & operator [] (int a) {
        return val[a];
    }
    Hash operator << (int bits) {
        Hash ret = *this;
        int i;
        for (i = 0; i < 2; i++) {
            ret[i] = mul(ret[i], pow[i][bits], MOD[i]);
        }
        return ret;
    }
    Hash operator + (int num) {
        Hash ret = *this;
        int i;
        for (i = 0; i < 2; i++) {
            (((ret[i] += num) %= MOD[i]) += MOD[i]) %= MOD[i];
        }
        return ret;
    }
    Hash operator - (const Hash &b) {
        Hash ret = *this;
        int i;
        for (i = 0; i < 2; i++) {
            (((ret[i] -= b.val[i]) %= MOD[i]) += MOD[i]) %= MOD[i];
        }
        return ret;
    }
};
struct _Main {



    int len;
    char s[2][200020];
    int expend[2][200020];
    Hash sum[2][200020]; 
    Hash sum[]
    int ans;
    char equal(Hash *a, int al, int ar, Hash *b, int bl, int br) {
        return (a[ar] - (a[al - 1] << ar - al + 1)) == (b[br] - (b[bl - 1] << br - bl + 1));
    }

    char getAlpha() {
        char t;
        while (!isalpha(t = getchar()));
        return t;
    }
    bool legal(int n) {
        if (! n & 1) {
            n++;
        }
        int i, j, k;
        int l1, r1;
        int l2, r2;
        int mid;
        
        for (l1 = 1, r2 = n, mid = n + 1 >> 1; r2 <= len; l1++, r2++, mid++) {
            for (i = 0; i < 2; i++) {//Ã¶¾Ùmid 
                r1 = mid - expend[i][mid];
                l2 = mid + expend[i][mid];
                if (equal(sum[0], l1, r1, sum[1], l2, r2)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    _Main () {
        int i, j;
        int l, r, mid;
        ans = 3;
        scanf("%d", &len);
        for (i = 0; i < 2; i++) {
            s[i][1] = DIV - 'A' + 1;
            for (j = 1; j <= len; j++) {
                s[i][j << 1] = getAlpha() - 'A' + 1;
                s[i][(j << 1) + 1] = DIV - 'A' + 1;
            }
        }
        len = len * 2 + 1;
        for (i = 0; i < 2; i++) {
            s[i][len + 1] = '\0';
        }
        
        for (i = 0; i < 2; i++) {
            pow[i][0] = 1;
            for (j = 1; j <= len; j++) {
                pow[i][j] = (pow[i][j - 1] * BASE[i]) % MOD[i];
            }
        }
        for (i = 0; i < 2; i++) {
            for (j = 1; j <= len; j++) {
                sum[i][j] = (sum[i][j - 1] << 1) + s[i][j];
            }
        }
    
        for (i = 0; i < 2; i++) {
            for (j = 1; j <= len; j++) {
                printf("%c ", 'A' + s[i][j] - 1);
            }
            printf("\n");
            for (j = 1; j <= len; j++) {
                l = 1; r = min(j, len - j + 1);
                while (l < r) {
                    mid = (l + r >> 1) + 1;
                    if (equal(sum[i], j - mid + 1, j, sum[i], j, j + mid - 1)) {
                        printf("equal([%d, %d], [%d, %d])\n", j - mid + 1, j, j, j + mid - 1);
                        l = mid;  
                    } else {
                        r = mid - 1;
                    }
                }
                expend[i][j] = l;
                printf("exp[%d][%d] = %d\n", i, j, l);
                ans = max(ans, l);
            }
        }
        l = ans;
        r = len;
        while (l < r) {
            mid = (l + r >> 1) + 1;
            if (legal(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = l;
        
        printf("%lld", ans / 2);
    }
}C;

} 
