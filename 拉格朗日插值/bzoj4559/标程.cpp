#include<iostream>
#include<cstdio>
#include<cstring>
#define MN 105
#define mod 1000000007
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
int inv[MN+5],Inv[MN+5],p[MN+5],U[MN+5],R[MN+5],n,m,K,f[MN+5][MN+5];

inline int pow(int x,int k)
{
    int sum=1;
    for(;k;k>>=1,x=1LL*x*x%mod)
        if(k&1) sum=1LL*sum*x%mod;
    return sum;
}
inline int C(int n,int m){return 1LL*p[n]*Inv[m]%mod*Inv[n-m]%mod;}
inline void Re(int&x,int y){x+=y;x>=mod?x-=mod:0;}

inline int Calc(int m,int rk)
{
    if(m<=n+1)
    {
        int res=0;
        for(int i=1;i<=m;++i)
            res=(res+1LL*pow(i,rk)*pow(m-i,n-rk-1))%mod;
        return res;
    }
    int sum=1,res=0,Div=1,S=0;
    for(int i=1;i<=n+1;++i) sum=1LL*sum*(m-i+mod)%mod;
    for(int i=2;i<=n+1;++i) Div=1LL*Div*(1-i+mod)%mod;
    for(int i=1;i<=n+1;++i)
    {
        int t=1LL*sum*pow(m-i+mod,mod-2)%mod;
        S=(S+1LL*pow(i,rk)%mod*pow(m-i,n-rk-1))%mod;
        t=1LL*t*S%mod;
        res=(res+1LL*t*pow(Div,mod-2))%mod;
        Div=1LL*Div*pow(mod-(n-i+1),mod-2)%mod*i%mod;
    }
    return res;
}

int main()
{
    n=read();m=read();K=read();
    for(int i=1;i<=m;++i) U[i]=read();
    for(int i=1;i<=m;++i) R[i]=n-read();
    inv[0]=inv[1]=p[0]=p[1]=Inv[0]=1;
    for(int i=2;i<=MN;++i)
        p[i]=1LL*p[i-1]*i%mod,
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<=MN;++i)
        Inv[i]=1LL*Inv[i-1]*inv[i]%mod;
    f[0][n-1]=1;
    for(int i=1;i<=m;++i)
        for(int j=0;j<=n-1;++j)
            for(int k=0;k<=min(j,R[i]);++k) if(n-1-j>=R[i]-k)
                Re(f[i][k],1LL*f[i-1][j]*C(j,k)%mod*C(n-1-j,R[i]-k)%mod);
    int ans=f[m][K];
    for(int i=1;i<=m;++i) ans=1LL*ans*Calc(U[i],R[i])%mod;
    cout<<ans<<endl;
    return 0;
}
