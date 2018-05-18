#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[400010],ans,num[20],p[20],pn,t[20];

//---------------------------------------------------------------------------------------- 
int prime[34000],prime_n;         // 第i个素数（从0开始计数）  
bool is_prime[400010];   // is_prime[i]为true表示i是素数  
  
int getprime(int n){     //返回值是n以内素数的个数  
    for(int i = 0; i <= n; i++) is_prime[i] = true;  
    is_prime[0] = is_prime[1] = false;  
    for(int i = 2; i <= n; i++){  
        if(is_prime[i]){  
            prime[prime_n++] = i;  
            for(int j = 2*i; j <= n; j += i)  
                is_prime[j] = false;  
        }  
    }  
    return prime_n;  
}  
long long count(long long x, long long y){  
    long long ret = 0;  
    while(x / y){  
        ret += x/y;  
        x /= y;  
    }  
    return ret;  
}  
long long mod_pow(long long n, long long k, long long p) {  
    if (k == 0) return 1;  
    if (k == 1) return n;  
    long long ans = mod_pow(n * n % p, k>>1, p);  
    if (k&1) ans = ans * n % p;  
    return ans;  
}  
long long solve(long long n, long long m, long long p){  
    long long ans = 1;  
    for(long long i = 0; prime[i] <= n && i < prime_n; i++){  
        long long cnt = count(n, prime[i]) - count(m, prime[i]) - count(n-m, prime[i]);  
        //printf("%d %lld\n",prime[i],cnt);
        ans = ans * mod_pow(prime[i], cnt, p) % p;  
        if(ans == 0) break;  
    }  
    return ans;  
}  
//---------------------------------------------------------------------------------------- 

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","r",stdout);
	scanf("%d%d",&n,&k);
	getprime(n);
	/*for(int i=2;i<=k;i++){
		if(k%i==0)pn++,num[pn]=i,p[pn]=1,k/=pn;
		while(k%i==0)p[pn]++,k/=pn;
	}*/
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	//for(int i=1;i<=pn;i++)t[i]=1;
	for(int i=1;i<=n;i++){
		//ans=ans+t[i]*a[i];
		//t=1ll*t*(n-i)/i;
		ans=(ans+solve(n-1,i-1,k)*a[i]%k)%k;
		//printf("%d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
}

