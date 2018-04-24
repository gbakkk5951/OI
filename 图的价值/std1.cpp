#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1000005,p=998244353,g=3;
int n,k,ans;
int s[N],a[N],fac[N],fac_inv[N],facn[N],w[N],w_inv[N],pos[N];

int Pow(int x,ll y)
{
    int res=1;
    for(;y;y>>=1,x=(ll)x*x%p)
        if(y&1)res=(ll)res*x%p;
    return res;
}

void NTT(int f[],int len,int on)
{
    for(int i=1;i<len;i++)pos[i]=(i&1)?pos[i>>1]>>1|(len>>1):pos[i>>1]>>1;
    for(int i=1;i<len;i++)if(i<pos[i])swap(f[i],f[pos[i]]);
    for(int i=1,num=1;i<len;i<<=1,num++)
    {
        int wn=on==1?w[num]:w_inv[num];
        for(int j=0;j<len;j+=(i<<1))
        {
            int wi=1;
            for(int k=j;k<j+i;k++)
            {
                int u=f[k],v=(ll)wi*f[k+i]%p;
                f[k]=(u+v)%p,f[k+i]=(u-v+p)%p;
                wi=(ll)wi*wn%p;
            }
        }
    }
    if(on==-1)for(int i=0;i<len;i++)f[i]=(ll)f[i]*w_inv[0]%p;
}

void multi(int f1[],int f2[])
{
    int len=1,num=0;
    while(len<=(k<<1))
    {
        len<<=1;
        w[++num]=Pow(g,(p-1)/len);
        w_inv[num]=Pow(w[num],p-2);
    }
    w_inv[0]=Pow(len,p-2);
    NTT(f1,len,1);
    NTT(f2,len,1);
    for(int i=0;i<len;i++)f1[i]=(ll)f1[i]*f2[i]%p;
    NTT(f1,len,-1);
}

int main()
{
    //freopen("lx.in","r",stdin);
    //freopen("lx.out","w",stdout);
    scanf("%d%d",&n,&k);n--;
    fac[0]=fac_inv[0]=facn[0]=1;
    for(int i=1;i<=k;i++)fac[i]=(ll)fac[i-1]*i%p;
    fac_inv[k]=Pow(fac[k],p-2);
    for(int i=k-1;i;i--)fac_inv[i]=(ll)fac_inv[i+1]*(i+1)%p;
    for(int i=1;i<=k;i++)facn[i]=(ll)facn[i-1]*(n-i+1)%p;
    for(int i=0;i<=k;i++)s[i]=(((i&1)?-1:1)*fac_inv[i]+p)%p;
    for(int i=0;i<=k;i++)a[i]=(ll)Pow(i,k)*fac_inv[i]%p;
    multi(s,a);
    for(int i=0;i<=n&&i<=k;i++)ans=(ans+(ll)s[i]*fac[i]%p*facn[i]%p*fac_inv[i]%p*Pow(2,n-i))%p;
    ans=(ll)ans*(n+1)%p*Pow(2,(ll)n*(n-1)/2)%p;
    printf("%d",ans);
    return 0;
}
