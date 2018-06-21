#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1000000007;
int ipow(int a, int b) {
    int x=1;
    a%=mo;
    for(; b; b>>=1, a=(ll)a*a%mo)
        if(b&1) x=(ll)x*a%mo;
    return x;
}
int d[100005];
int main() {
    int N, K, L, R, MX, flag=0;
    scanf("%d%d%d%d", &N, &K, &L, &R);
    if(L<=K && K<=R) flag=1;
    L=(L-1)/K, R=R/K;
    MX=R-L;
    for(int i=MX; i>=1; --i) {
        int &now=d[i];
        ll l=L/i, r=R/i, t=r-l;
        if(l<r) {
            now=(ipow((t), N)-t+mo)%mo;
            for(int j=i<<1; j<=MX; j+=i) now=(now-d[j]+mo)%mo;
        }
    }
    printf("%d\n", d[1]+flag);
    return 0;
}
