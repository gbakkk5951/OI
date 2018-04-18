#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
using namespace std;
typedef long long s64;

const int Max = 1000005;
const int ONE = 1000005;

int n,MOD;
int f[Max];
int a[ONE];
int p[Max],p_num;
int C[ONE];

int get()
{
        int res=1,Q=1;    char c;
        while( (c=getchar())<48 || c>57)
        if(c=='-')Q=-1;
        if(Q) res=c-48; 
        while((c=getchar())>=48 && c<=57) 
        res=res*10+c-48; 
        return res*Q; 
}

int Quickpow(int a,int b)
{
		int res=1;
		while(b)
		{
			if(b&1) res=(s64)res*a%MOD;
			a=(s64)a*a%MOD;
			b>>=1;
		}
		return res;
}

void Deal_prime()
{
		for(int i=2;i*i<Max;i++)
		if(!f[i])
		for(int j=2;i*j<Max;j++)
		f[i*j]=1;
		
		for(int i=2;i<=Max-5;i++)
		if(!f[i]) p[++p_num]=i;
}

namespace Is
{
		int Jc[ONE];
		
		void Deal_Jc(int n)
		{
			Jc[0]=1;
			for(int i=1;i<=n;i++)
			Jc[i]=(s64)Jc[i-1]*i%MOD;
		}
		
		int Ci(int m,int n)
		{
		    if(m<n) return 0;
		    int up=Jc[m]%MOD;
		    int down=(s64)Jc[m-n]*Jc[n]%MOD;
		    return (s64)up*Quickpow(down,MOD-2)%MOD;
		}
		
		int Lucas(int n,int m,int MOD)
		{
		    s64 res=1;
		    if(n<m) return 0;
		    while(n && m)
		    {
		        res=(s64)res*Ci(n%MOD,m%MOD)%MOD;
		        n/=MOD; m/=MOD;
		    }
		    return res;
		}
		
		void Deal_C(int n)
		{
			Deal_Jc(n);
			int n_2=n/2;
			for(int i=1;i<=n_2;i++)
			C[i]=Lucas(n,i,MOD);
		}
}

namespace Not
{
		s64 record[Max];
		
		int Quickpow(int a,s64 b)
		{
			int res=1;
			while(b)
			{
				if(b&1) res=(s64)res*a%MOD;
				a=(s64)a*a%MOD;
				b>>=1;
			}
			return res;
		}
		
		int Cnt(int n,int prime)
		{
			int res=0;
			while(n/prime)
			{
				res=(res+(s64)n/prime)%MOD;
				n/=prime;
			}
			return res;
		}
		
		int Make_up(int n,int m)
		{
			s64 cnt;
			int Ans=1;
			for(int i=1;p[i]<=n;i++)
			{
				cnt=record[i]-Cnt(m,p[i]);
				cnt=cnt-Cnt(n-m,p[i]);
				Ans = (s64)Ans*Quickpow(p[i],cnt) % MOD;
				if(!Ans) break;
			}
			return Ans;
		}
	
	
		void Deal_C(int n)
		{
			int n_2=n/2;
			for(int i=1;p[i]<=n;i++) record[i]=Cnt(n,p[i]);
			for(int i=1;i<=n_2;i++)
			C[i] = Make_up(n,i);
		}
}


int main()
{      
    	freopen("magic.in","r",stdin);
    	freopen("magic.out","w",stdout);
    	Deal_prime();
		
		int Ans=0;
		n=get();	MOD=get();
		if(!f[MOD]) Is::Deal_C(n-1);
		else Not::Deal_C(n-1);
		
		for(int i=1;i<=n;i++) a[i]=get();
		
		C[0]=1;
		for(int i=1,j=n; i<=j; i++,j--)
		{
			Ans= (Ans+ (s64)a[i]*C[i-1]%MOD)%MOD;
			if(i!=j) Ans= (Ans+ (s64)a[j]*C[i-1]%MOD)%MOD;
		}
		
		printf("%d",Ans);
		
}
