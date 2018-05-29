#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

const int N=1010;
long long a[N*10][N],b[N*10],c[N],v,k;
int x,y,n,m,s,t;

void pivot(int x,int y){
    k=a[x][y]; b[x]/=k; a[x][y]=1;
    for(int i=1;i<=n;i++) a[x][i]/=k;
    for(int i=1;i<=m;i++)
    if(i!=x&&a[i][y]){
        k=a[i][y]; b[i]-=b[x]*k; a[i][y]=0;
        for(int j=1;j<=n;j++) a[i][j]-=a[x][j]*k;
    }
    k=c[y]; c[y]=0; v+=k*b[x];
    for(int i=1;i<=n;i++) c[i]-=k*a[x][i];
}
void solve(){
    for(int x=0,y=0;1;x=y=0){
        for(int i=1;i<=m;i++) if(b[i]<0) x=i;
        if(!x) break;
        for(int i=1;i<=n;i++) if(a[x][i]<0) y=i;
        if(!y){puts("Infeasible"); return;}
        pivot(x,y);
    }
    for(int x=0,y=0;1;x=y=0){
        for(int i=1;i<=n;i++) if(c[i]>c[x]) x=i;
        if(c[x]<=0) break;
        for(int i=1;i<=m;i++) 
        if(a[i][x]>0&&(!y||b[y]*a[i][x]>b[i]*a[y][x])) y=i;
        if(!y){puts("Unbounded"); return;}
        pivot(y,x);
    }
    printf("%lld\n",v);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(int i=1;i<=m;i++){
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            scanf("%d%d",&s,&t);
            for(int l=s;l<=t;l++) a[i][l]=1;
        }
        scanf("%lld",&b[i]);
    }
    solve();
    return 0;
}

