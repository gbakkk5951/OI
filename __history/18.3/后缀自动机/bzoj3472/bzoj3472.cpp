#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,k;
string s[N>>1];
char ss[N>>1];
struct node{
    int ch[26],par,val;
    int cou,cur;
}t[N];
int sz=1,root=1,last=1;
void extend(int c){
    int p=last,np=++sz;
    t[np].val=t[p].val+1;
    for(;p&&!t[p].ch[c];p=t[p].par) t[p].ch[c]=np;
    if(!p) t[np].par=root;
    else{
        int q=t[p].ch[c];
        if(t[q].val==t[p].val+1) t[np].par=q;
        else{
            int nq=++sz;
            t[nq]=t[q];t[nq].val=t[p].val+1;
            t[q].par=t[np].par=nq;
            for(;p&&t[p].ch[c]==q;p=t[p].par) t[p].ch[c]=nq;
        }
    }
    last=np;
}
int c[N],a[N];
ll f[N];
void RadixSort(){
    for(int i=1;i<=sz;i++) c[t[i].val]++;
    for(int i=1;i<=sz;i++) c[i]+=c[i-1];
    for(int i=sz;i>=1;i--) a[c[t[i].val]--]=i;
}
void solve(){
    int u;ll ans;
    for(int i=1;i<=n;i++){//printf("i %d\n",i);
        u=root;
        for(int j=0;j<s[i].size();j++){
            u=t[u].ch[s[i][j]-'a'];//printf("u %d  %d  %d\n",u,t[u].cou,j);
            int p=u;
            for(;p&&t[p].cur!=i;p=t[p].par) t[p].cou++,t[p].cur=i;
        }
    }
    RadixSort();
    for(int i=1;i<=sz;i++) u=a[i];
    t[1].cou=0;
    for(int i=1;i<=sz;i++) u=a[i],f[u]=f[t[u].par]+(t[u].cou>=k?t[u].val-t[t[u].par].val:0);
    for(int i=1;i<=n;i++){
        u=root;ans=0;
        for(int j=0;j<s[i].size();j++){
            u=t[u].ch[s[i][j]-'a'];
            ans+=f[u];
        }
        printf("%lld ",ans);
    }
}
int main(){
    freopen("in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",ss),s[i]=string(ss);
        last=root;
        for(int j=0;j<s[i].size();j++) extend(s[i][j]-'a');
    }
    solve();
}
