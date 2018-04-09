#include<bits/stdc++.h>
using namespace std;
const int N=10002,M=100002;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
    return x*f;
}
struct E{int x,y,c,next;}a[M],e[M]; int first[N],fir[N];
int in[N];
queue<int>q;
double f[N],g[N],mx,s[N];
void solve(int x){
    double t=0,d=f[x];
    for(int k=first[x];k;k=a[k].next){
        int y=a[k].y;
        t+=(1+f[y])*a[k].c;
    }
    for(int k=first[x];k;k=a[k].next){
        int y=a[k].y;
        double tt=t-(1+f[y])*a[k].c;
        if(s[x]>a[k].c)d=max(d,tt/(s[x]-a[k].c));
    }
    mx=max(mx,(d-f[x])*g[x]);
}
int main(){
    int n=read(),m=read(),i;
    for(i=1;i<=m;i++){
        int x=read()+1,y=read()+1,c=read(); s[x]+=c;
        a[i]=(E){x,y,c,first[x]},first[x]=i,in[y]++;
    }
    for(i=1;i<=n;i++)if(!in[i])q.push(i);
    g[1]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int k=first[x];k;k=a[k].next){
            int y=a[k].y;
            g[y]+=g[x]*a[k].c/s[x],in[y]--;
            if(!in[y])q.push(y);
        }
    }
    for(i=1;i<=m;i++)
        e[i]=(E){a[i].y,a[i].x,a[i].c,fir[a[i].y]},fir[a[i].y]=i,in[a[i].x]++;
    for(i=1;i<=n;i++)if(!in[i])q.push(i);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int k=fir[x];k;k=e[k].next){
            int y=e[k].y;
            f[y]+=(f[x]+1)*e[k].c/s[y],in[y]--;
            if(!in[y])q.push(y);
        }
    }
    double ans=f[1]; mx=0;
    for(i=1;i<=n;i++)solve(i);
    printf("%.6lf\n",ans+mx);
    return 0;
}
