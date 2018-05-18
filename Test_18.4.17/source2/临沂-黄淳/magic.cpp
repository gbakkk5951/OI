#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 400005
#define INF 0x7fffffff

int n, k;
int a[MAXN], prime[MAXN + 1000];
bool is_prime[MAXN + 1000];

inline int read() {
	char ch = getchar(); int res = 0;
	while(ch < '0') ch = getchar();
	while(ch <= '9' && ch >= '0') {res = res * 10 + ch - '0'; ch = getchar();}
	return res;
}

////////////////////////////////////////////////////////////////////////////////////

long long quickMod(long long a, long long b, long long p) {  
    long long ans = 1;  
    a %= p;  
    while(b) {  
        if(b & 1) {  
            ans = ans * a % p;  
            -- b;  
        }  
        b >>= 1;  
        a = a * a % p;  
    }  

    return ans;  
}  
  
long long calc(long long n, long long m, long long p) {  
    if(m > n) return 0;  
    long long ans = 1;  
    for(int i = 1; i <= m; ++ i) {  
        long long a = (n + i - m) % p;  
        long long b = i % p;  
        ans = ans * (a * quickMod(b, p - 2, p) % p) % p;  
    }  
    return ans;  
}  
  
long long Lucas(long long n, long long m, long long p) {  
    if(m == 0) return 1;  
    return calc(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;  
}  

////////////////////////////////////////////////////////////////////////////////////

int getPrime(int n){    
    int p = 0;  
    for(int i = 0; i <= n; i++) is_prime[i] = true;  
    is_prime[0] = is_prime[1] = false;  
    for(int i = 2; i <= n; i++){  
        if(is_prime[i]){  
            prime[p++] = i;  
            for(int j = 2*i; j <= n; j += i)  
                is_prime[j] = false;  
        }  
    }  
    return p;  
}  

long long count(long long x, long long y){  
    long long ret = 0;  
    while(x / y){  
        ret += x/y;  
        x /= y;  
    }  
    return ret;  
}  

long long quickPow(long long n, long long k, long long p) {  
    if (k == 0) return 1;  
    if (k == 1) return n;  
    long long ans = quickPow(n * n % p, k>>1, p);  
    if (k&1) ans = ans * n % p;  
    return ans;  
}  

long long Calc(long long n, long long m, long long p){  
    long long ans = 1;  
    for(long long i = 0; prime[i] <= n; i++){  
        long long cnt = count(n, prime[i]) - count(m, prime[i]) - count(n-m, prime[i]);  
        ans = ans * quickPow(prime[i], cnt, p) % p;  
        if(ans == 0) break;  
    }  
    return ans;  
}  

////////////////////////////////////////////////////////////////////////////////

inline bool check(int x) {
	for(int i = 2; i <= std :: sqrt(x); ++ i) 
		if(!(x % i)) return false;

	return true;
}

inline long long C(int n, int m, int type) {
	if(m == 1 || m == n) return 1;
	else if(m == 2 || m == n - 1) return (n - 1);
	else {
		if(type == 2) return Calc((long long)n - 1, (long long)m - 1, (long long)k);
		else return Lucas((long long)n - 1, (long long)m - 1, (long long)k);
	} 
}

inline void force() {
	//printf("Force Solve\n");
	
	for(int i = n - 1; i; -- i) 
		for(int j = 1; j <= i; ++ j)
			a[j] = ( (a[j] % k) + (a[j + 1] % k) ) % k;

	printf("%d\n", a[1]);
}

inline void solve1() {
	//printf("Solve 1\n");
	
	long long res = 0, tmp = 0;
	for(int i = 1; i <= n; ++ i) {
		//printf("%I64d\n", C(n, i, 1));
		tmp = ((a[i] % k) * (C(n, i, 1))) % k;
		res += tmp , res %= k;
	}

	printf("%I64d\n", res);
}

inline void solve2() {
	//printf("Solve 2\n");
	
	long long res = 0, tmp = 0;
	getPrime(MAXN + 1000);
	for(int i = 1; i <= n; ++ i) {
		//printf("%I64d\n", C(n, i, 2));
		tmp = ((a[i] % k) * (C(n, i, 2))) % k;
		res += tmp , res %= k;
	}

	printf("%I64d\n", res);
}

inline void init() {
	n = read(), k = read();
	for(int i = 1; i <= n; ++ i) a[i] = read();
	
	if(n <= 1000) force();
	else if(check(k)) solve1();
	else solve2();
	
	//force();
	//solve1();
	//solve2();
}

int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	init();
	fclose(stdin);
	fclose(stdout);
}
