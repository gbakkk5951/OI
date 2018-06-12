//pb_ds 20160711
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;
#define RG register
#define IL __inline__ __attribute__((always_inline))
#define For(i, a, b) for(RG int i = a, ___u = b; i <= ___u; ++i)
#define Dor(i, a, b) for(RG int i = b, ___d = a; i >= ___d; --i)
#define Rep(i, a, b) for(RG int i = a, ___u = b; i != ___u; ++i)
#define dmin(a, b) ((a) < (b) ? (a) : (b))
#define dmax(a, b) ((a) > (b) ? (a) : (b))
#define cmin(a, b) ((a) > (b) ? (a) = (b) : 1)
#define cmax(a, b) ((a) < (b) ? (a) = (b) : 1)
#define ddel(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
#define dabs(i) ((i) > 0 ? (i) : -(i))
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef long double ld;

#include <queue>
#include <vector>

namespace pb_ds
{   
	// 输入输出优化模板从此开始
	namespace io
	{
		const int MaxBuff = 1 << 15;
		const int Output = 1 << 24;
		char B[MaxBuff], *S = B, *T = B;
		//#define getc() getchar()
		#define getc() ((S == T) && (T = (S = B) + fread(B, 1, MaxBuff, stdin), S == T) ? 0 : *S++)
		char Out[Output], *iter = Out;
		IL void flush()
		{
			fwrite(Out, 1, iter - Out, stdout);
			iter = Out;
		}
	}
	
	template<class Type> IL Type read()
	{
		using namespace io;
		RG char ch; RG Type ans = 0; RG bool neg = 0;
		while(ch = getc(), (ch < '0' || ch > '9') && ch != '-')     ;
		ch == '-' ? neg = 1 : ans = ch - '0';
		while(ch = getc(), '0' <= ch && ch <= '9') ans = ans * 10 + ch - '0';
		return neg ? -ans : ans;
	}
	template<class Type> IL void Print(RG Type x, RG char ch = '\n')
	{
		using namespace io;
		if(!x) *iter++ = '0';
		else
		{
			if(x < 0) *iter++ = '-', x = -x;
			static int s[100]; RG int t = 0;
			while(x) s[++t] = x % 10, x /= 10;
			while(t) *iter++ = '0' + s[t--];
		}
		*iter++ = ch;
	}
	// 输入输出优化模板到此结束
	const int MaxN = 100010;
	struct Pointer{int to, cnt; Pointer *next;} *fir[MaxN];
	
	int n;
	void dfs(RG int i)
	{
		for(RG Pointer* &k = fir[i]; k; k = k->next)
			if(k->cnt--)
			{
				dfs(k->to);
				Print(i, " \n"[i == n]);
				if(!k) break;				
			}
	}
	
	IL void main()
	{
		RG int (*F)() = read<int>;
		n = F();
		RG int m = F(), t = 0;
		static Pointer mem[MaxN << 1];
		RG Pointer *tot = mem;
		for(RG int x, y, v; m--; )
		{
			x = F(), y = F(), v = F();
			if(x == 1) t += v; if(y == 1) t -= v;
			*++tot = (Pointer) {x, v, fir[y]}, fir[y] = tot;
		}
		*++tot = (Pointer) {n, t, fir[1]}, fir[1] = tot;
		dfs(n);
		io::flush();
	}
}

int main()
{
	int size = 180 << 20; 
	char *p = (char*)malloc(size) + size;
    __asm__("movl %0, %%esp\n" :: "r"(p));
	#define FILE "attack"
	//freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
	pb_ds::main();
	fclose(stdin), fclose(stdout);  
}
/*

*/
