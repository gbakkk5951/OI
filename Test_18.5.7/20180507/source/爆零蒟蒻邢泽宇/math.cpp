#include<cstdio>
const int maxn=22;

int in[maxn],sel[maxn],g[maxn][maxn],n,ans;

inline int gcd(int x,int y) {
    return y ? gcd(y,x%y) : x;
}
inline bool judge(int t) {
    for(int i=1;i<t;i++) if( sel[i] && g[i][t] != 1 ) return 0;
    return 1;
}
inline void dfs(int pos) {
    if( pos > n ) return void(++ans);
    if( judge(pos) ) sel[pos] = 1 , dfs(pos+1);
    sel[pos] = 0 , dfs(pos+1);
}

int main() {
    freopen("math.in","r",stdin) , freopen("math.out","w",stdout);
    scanf("%d",&n); for(int i=1;i<=n;i++) scanf("%d",in+i);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j] = gcd(in[i],in[j]);
    dfs(1) , printf("%d\n",ans-1);
    return fclose(stdout);
}

