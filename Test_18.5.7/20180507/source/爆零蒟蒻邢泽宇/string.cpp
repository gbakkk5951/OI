#include<cstdio>
#include<cstring>
#include<algorithm>
typedef unsigned long long int ulli;
const int maxn=5e3+1e1;
const ulli base = 13;

char in[maxn];
ulli h[maxn],pows[maxn];
int li,ans;

inline ulli seg(int l,int r) {
    return h[r] - pows[r-l+1] * h[l-1];
}
inline bool judge(int l,int r) {
    const int mid = ( l + r ) >> 1;
    return seg(l,mid) == seg(mid+1,r);
}

int main() {
    freopen("string.in","r",stdin) , freopen("string.out","w",stdout);
    scanf("%s",in+1) , li = strlen(in+1) , *pows = 1;
    for(int i=1;i<=li;i++) h[i] = h[i-1] * base + in[i] - 'a' + 1 , pows[i] = pows[i-1] * base;
    for(int i=1;i<=li;i++) for(int j=i+1;j<=li;j+=2) if( judge(i,j) ) ans = std::max(ans,j-i+1);
    printf("%d\n",ans);
    return fclose(stdout);
}

