#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;

const int maxn = 4E5 + 40;
typedef long long LL;

int n,K,Ans,A[maxn],Fac[maxn],Inv[maxn],C[1010][1010],C_2[10][10],C_5[10][10];

int Mul(const LL &x,const LL &y) {return x * y % K;}
int Add(const int &x,const int &y) {return (x + y) % K;}

int ksm(int x,int y)
{
	int ret = 1;
	for (; y; y >>= 1)
	{
		if (y & 1) ret = Mul(ret,x);
		x = Mul(x,x);
	}
	return ret;
}

int Lucas_2(int N,int M)
{
	if (!M) return 1;
	return Lucas_2(N / 2,M / 2) * C_2[N % 2][M % 2] % 2;
}

int Lucas_5(int N,int M)
{
	if (!M) return 1;
	return Lucas_5(N / 5,M / 5) * C_5[N % 5][M % 5] % 5;
}

int Get_C(int N,int M)
{
	if (M > N) return 0;
	return Mul(Fac[N],Mul(Inv[M],Inv[N - M]));
}

int Lucas(int N,int M)
{
	if (!M) return 1;
	return Mul(Lucas(N / K,M / K),Get_C(N % K,M % K));
}

int Calc(int N,int M)
{
	int a1 = Lucas_2(N,M);
	int a2 = Lucas_5(N,M);
	int k1 = (a2 - a1 + 5) * 3 % 5;
	return (k1 * 2 + a1) % 10;
}

void Solve1()
{
	C[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = Add(C[i-1][j],C[i-1][j-1]);
	}
	for (int i = 0; i < n; i++) Ans = Add(Ans,Mul(A[i],C[n-1][i]));
}

void Solve2()
{
	C_2[0][0] = C_5[0][0] = 1;
	for (int i = 1; i < 5; i++)
	{
		C_2[i][0] = C_5[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			C_2[i][j] = (C_2[i-1][j] + C_2[i-1][j-1]) % 2;
			C_5[i][j] = (C_5[i-1][j] + C_5[i-1][j-1]) % 5;
		}
	}
	for (int i = 0; i < n; i++)
		Ans = Add(Ans,Mul(A[i],Calc(n - 1,i)));
}

void Solve3()
{
	Fac[0] = 1; for (int i = 1; i < K; i++) Fac[i] = Mul(Fac[i - 1],i);
	Inv[K - 1] = ksm(Inv[K - 1],K - 2);
	for (int i = K - 2; i >= 0; i--) Inv[i] = Mul(Inv[i + 1],i + 1);
	for (int i = 0; i < n; i++)
		Ans = Add(Ans,Mul(A[i],Lucas(n - 1,i)));
}

int main()
{
	#ifdef DMC
		freopen("DMC.txt","r",stdin);
	#else
		freopen("magic.in","r",stdin);
		freopen("magic.out","w",stdout);
	#endif
	
	cin >> n >> K;
	for (int i = 0; i < n; i++) scanf("%d",&A[i]);
	if (n <= 1000) Solve1();
	else if (K == 10) Solve2();
	else Solve3();
	cout << Ans << endl;
	return 0;
}
