#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
#define LL long long   
#define N 200003  
#define pa pair<int,int>  
using namespace std;  
LL n,m,p,sum;  
LL w[N],prime[N],cnt[N],mod[N],a[N];  
int tot;  
void get_prime()//模数分解成P=p1^c1 * p2^c2 * p3^c3 * … *pt ^ ct，pi为质数的形式   
{  
    LL x=p;  
    for (LL i=2;i*i<=x;i++)  
     if (x%i==0)  
      {  
        prime[++tot]=i; cnt[tot]=0; mod[tot]=1;  
        while (x%i==0)  
         {  
            x/=i;  
            cnt[tot]++; mod[tot]*=i;  
         }  
      }  
    if (x>1)  
     {  
        prime[++tot]=x;  
        cnt[tot]=1;  
        mod[tot]=x;  
     }  
}  
LL quickpow(LL num,LL x,LL m)//快速幂   
{  
    LL ans=1;  
    LL base=num%m;  
    while (x)  
    {  
        if (x&1)  ans=(ans*base)%m;  
        x>>=1;  
        base=(base*base)%m;  
    }  
    return ans%m;  
}  
void exgcd(LL a,LL b,LL &x,LL &y)//扩展欧几里德算法    
//ax=1 (mod b) gcd(a,b)==1 ax+by=1的解，x为a的逆元    
{  
    if (b==0)  
     {  
        x=1; y=0;  
        return;  
     }  
    exgcd(b,a%b,x,y);  
    LL t=y;  
    y=x-(a/b)*y;  
    x=t;  
}  
LL inverse(LL a,LL b)  
{  
    LL x,y;  
    exgcd(a,b,x,y);  
    return (x%b+b)%b;  
}  
pa solve(int k,LL n)// 将当前模数的倍数全部提取出来，这样保证a,b互质，就可以用exgcd求逆元 ，对于倍数直接做减法就可以了   
{  
    if (n==0)  return make_pair(0,1);  
    LL x=n/prime[k],y=n/mod[k];  
    LL ans=1;  
    if (y)  
    {  
        for (LL i=2;i<mod[k];i++)  
         {  
            if (i%prime[k]!=0)  
             ans=(ans*i)%mod[k];  
         }  
        ans=quickpow(ans,y,mod[k]);  
    }  
    for (LL i=y*mod[k]+1;i<=n;i++)  
     if (i%prime[k]!=0)  
      ans=(ans*i)%mod[k];  
    pa t=solve(k,x);  
    return make_pair(t.first+x,ans*t.second%mod[k]);  
}  
LL calc(int k,LL n,LL m)  
{  
    if (n<m)  return 0;  
    pa a=solve(k,n),b=solve(k,m),c=solve(k,n-m);  
    LL t1=quickpow(prime[k],a.first-b.first-c.first,mod[k])*a.second%mod[k];  
    LL t2=inverse(b.second,mod[k])%mod[k];  
    LL t3=inverse(c.second,mod[k])%mod[k];  
    return t1*t2*t3%mod[k];  
}  
LL china()//中国剩余定理   
{  
    LL x,y,ans=0;  
    for(int i=1;i<=tot;i++)  
    {  
        LL r=p/mod[i];   
        exgcd(r,mod[i],x,y);  
        ans=(ans+r*x*a[i])%p;  
    }  
    return (ans+p)%p;  
}  
LL work(LL n,LL m)  
{  
    for (int i=1;i<=tot;i++)  
     a[i]=calc(i,n,m);  
    return china();  
}  
int main()  
{  
    scanf("%lld%lld%lld",&p,&n,&m);  
    for (LL i=1;i<=m;i++)  
     scanf("%lld",&w[i]),sum+=w[i];  
    if (sum>n)  {  
        printf("Impossible\n");  
        return 0;  
    }
    get_prime();   
    LL ans=work(n,sum)%p;   
    for (LL i=1;i<=m;i++)  
    {  
        ans=ans*work(sum,w[i])%p;  
        sum-=w[i];  
    }
    printf("%lld\n",(ans%p+p)%p);  
}  
