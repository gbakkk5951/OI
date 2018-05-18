    #include <cstdio>  
    #include <cstring>  
    #include <iostream>  
    #include <algorithm>  
    #define M 10001000  
    #define MOD 100000009  
    using namespace std;  
    typedef long long ll;  
    int prime[1001001],tot;  
    bool not_prime[M];  
    ll h[M],sum[M];  
    void Linear_Shaker()  
    {  
        int i,j;  
        h[1]=1;  
        for(i=2;i<M;i++)  
        {  
            if(!not_prime[i])  
            {  
                prime[++tot]=i;  
                h[i]=(i-(ll)i*i)%MOD;  
            }  
            for(j=1;prime[j]*i<M;j++)  
            {  
                not_prime[prime[j]*i]=1;  
                if(i%prime[j]==0)  
                {  
                    h[prime[j]*i]=(prime[j]*h[i])%MOD;  
                    break;  
                }  
                h[prime[j]*i]=(h[prime[j]]*h[i])%MOD;  
            }  
        }  
        for(i=1;i<M;i++)  
            sum[i]=(sum[i-1]+h[i])%MOD;  
    }  
    inline ll Sum(ll x,ll y)  
    {  
        x%=MOD;y%=MOD;  
        ll re1=(x*(x+1)>>1)%MOD;  
        ll re2=(y*(y+1)>>1)%MOD;  
        return re1*re2%MOD;  
    }  
    int Query(int n,int m)  
    {  
        int i,last,re=0;  
        if(n>m) swap(n,m);  
        for(i=1;i<=n;i=last+1)  
        {  
            last=min(n/(n/i),m/(m/i));  
            re+=Sum(n/i,m/i)*(sum[last]-sum[i-1])%MOD;  
            re%=MOD;  
        }  
        return (re+MOD)%MOD;  
    }  
    int main()  
    {  
        int T,n,m;  
        Linear_Shaker();  
        for(cin>>T;T;T--)  
        {  
            scanf("%d%d",&n,&m);  
            printf("%d\n", Query(n,m) );  
        }  
    }  
