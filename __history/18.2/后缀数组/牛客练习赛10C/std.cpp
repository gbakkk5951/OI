#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cctype>
using namespace std;
 
const int N = 400010;
int n, m, all, dif;
char s1[N], s2[N], s[N];
int rk[N], tp[N], SA[N], tong[350], h[N][25], cnt[N];
 
inline void ssort()
{
    for(int i = 0; i <= all; i ++) tong[i] = 0;
    for(int i = 1; i <= n; i ++) tong[rk[tp[i]]] ++;
    for(int i = 1; i <= all; i ++) tong[i] += tong[i-1];
    for(int i = n; i >= 1; i --) SA[tong[rk[tp[i]]] --] = tp[i];
}
inline void getSA()
{
    for(int i = 1; i <= n; i ++) { rk[i] = s[i]; tp[i] = i; }
    all = 300; ssort(); int w = 1, p = 1;
    while(p < n) {
        p = 0;
        for(int i = n-w+1; i <= n; i ++) tp[++ p] = i;
        for(int i = 1; i <= n; i ++) if(SA[i] > w) tp[++ p] = SA[i] - w;
        ssort(); for(int i = 1; i <= n; i ++) tp[i] = rk[i];
        rk[SA[1]] = p = 1;
        for(int i = 2; i <= n; i ++)
            rk[SA[i]] = (tp[SA[i]] == tp[SA[i-1]] && tp[SA[i]+w] == tp[SA[i-1]+w])?p:++ p;
        w <<= 1; all = p;
    }
    int k = 0;
    for(int i = 1; i <= n; i ++) {
        if(k) k --; int j = SA[rk[i]-1];
        for(; i+k <= n && j+k <= n && s[i+k] == s[j+k]; k ++);
        h[rk[i]][0] = k;
    }
}
inline int qry(int x, int y)
{
    x = rk[x]; y = rk[y];
    if(x > y) swap(x, y);
    x ++; int k = 0;
    while((1<<k+1) <= y-x+1) k ++;
    return min(h[x][k], h[y-(1<<k)+1][k]);
}
int main()
{
    scanf("%d%s%s", &n, s1+1, s2+1);
    for(int i = 1; i <= n; i ++) s[i] = s1[i];
    s[n+1] = 'Z'+1;
    for(int i = 1; i <= n; i ++) s[n+1+i] = s1[n-i+1];
    s[2*n+2] = 'Z'+2;
    for(int i = 1; i <= n; i ++) s[2*n+2+i] = s2[i];
    s[3*n+3] = 'Z'+3;
    for(int i = 1; i <= n; i ++) s[3*n+3+i] = s2[n-i+1];
    m = n; n = 4*m+3;
    getSA();
    for(int j = 1; j <= 19; j ++)
        for(int i = 1; i+(1<<j)-1 <= n; i ++) h[i][j] = min(h[i][j-1], h[i+(1<<j-1)][j-1]);
    int ans = 0;
    for(int i = 1; i <= m; i ++) {//在A中枚举中心点
        int tmp = 2*qry(i+1, 2*m+1-(i-1)+1)+1;//串长度为奇数
        int l = i-tmp/2-1, r = i+tmp/2;
        ans = max(ans, tmp + 2*qry(2*m+1-l+1, 2*m+2+r));
        tmp = 2*qry(i, 2*m+1-(i-1)+1);//偶数
        l = i-tmp/2-1, r = i+tmp/2-1;
        ans = max(ans, tmp + 2*qry(2*m+1-l+1, 2*m+2+r));
    }
    for(int i = 2*m+3; i <= 3*m+2; i ++) {//B中枚举中心点
        int tmp = 2*qry(i+1, 4*m+3-(i-1-2*m-2)+1)+1;//奇数
        int l = i-tmp/2, r = i+tmp/2+1;
        ans = max(ans, tmp + 2*qry(2*m+1-(l-2*m-2)+1, r));
        tmp = 2*qry(i, 4*m+3-(i-1-2*m-2)+1);//偶数
        l = i-tmp/2, r = i+tmp/2;
        ans = max(ans, tmp + 2*qry(2*m+1-(l-2*m-2)+1, r));
    }
    printf("%d\n", ans);
    return 0;
}
