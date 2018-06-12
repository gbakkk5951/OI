// pb_ds big CAT
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;
#define RG register
#define IL __inline__ __attribute__((always_inline))
#define For(i, a, b) for(RG int i = a, ___u = b; i <= ___u; ++i)
#define Dor(i, a, b) for(RG int i = b, ___d = a; i >= ___d; --i)
#define Rep(i, a, b) for(RG int i = a, ___u = b; i != ___u; ++i)
#define dmin(a, b) ((a) < (b) ? (a) : (b))
#define dmax(a, b) ((a) > (b) ? (a) : (b))
#define cmin(a, b) ((a) > (b) ? (a) = (b), 1 : 0)
#define cmax(a, b) ((a) < (b) ? (a) = (b), 1 : 0)
#define diff(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
#define dabs(i) ((i) > 0 ? (i) : -(i))
typedef long long ll;

namespace pb_ds
{   
	// 输入输出优化模板从此开始
	namespace io
	{
		const int MaxBuff = 1 << 15;
		const int Output = 1 << 24;
		char B[MaxBuff], *S = B, *T = B;
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
		while(ch = getc(), (ch < '0' || ch > '9') && ch != '-')	 ;
		ch == '-' ? neg = 1 : ans = ch - '0';
		while(ch = getc(), '0' <= ch && ch <= '9') ans = ans * 10 + ch - '0';
		return neg ? -ans : ans;
	}
	template<class Type> IL void print(RG Type x, RG char ch = '\n')
	{
		using namespace io;
		if(!x) *iter++ = '0';
		else
		{
			if(x < 0) *iter++ = '-', x = -x;
			static int S2[100]; RG int t = 0;
			while(x) S2[++t] = x % 10, x /= 10;
			while(t) *iter++ = '0' + S2[t--];
		}
		*iter++ = ch;
	}
	// 输入输出优化模板到此结束
#if 1
	const int MaxN = 1 << 20;
	const ll inf = 1000000000000000000ll;
	int N, K, len[MaxN], gas[MaxN];
	ll old[MaxN], add[MaxN];
	
	struct Pointer{int to; Pointer *next;} *fir[MaxN], mem[MaxN];
	
	#define SonL (i << 1)
	#define SonR (i << 1 | 1)
	#define RanL l, m
	#define RanR m + 1, r
	#define NeedL ql <= m
	#define NeedR m < qr
	#define Def RG int i, RG int l, RG int r
	
	namespace Input
	{
		IL void main()
		{
			RG int (*F)() = read<int>;
			N = F(); K = F();
			Rep(i, 1, N) len[i] = F();
			For(i, 1, N) gas[i] = F();
		}
	}
	
	namespace BuildTree
	{
		ll sum[MaxN];
		int stack[MaxN];
		
		IL void main()
		{
			Rep(i, 1, N) sum[i] = sum[i - 1] + gas[i] - len[i]; 
			RG int top = 0, fai; RG ll tmp;
			stack[top] = N;
			stack[++top] = N - 1;
			RG Pointer *tot = mem;
			Dor(i, 1, N - 1)
			{
				tmp = sum[i - 1];
				while(top && tmp < sum[stack[top]]) --top;
				fai = stack[top];
				add[i] = (top ? sum[i - 1] - sum[fai++] : 0);
				stack[++top] = i - 1;
				*++tot = (Pointer) {i, fir[fai]}; fir[fai] = tot;
			}
		}
	}
	
	struct Data
	{
		ll min_old, max_cur, min_ans, rig_con, min_add;
		ll add;
		IL void do_add(RG ll x)
		{
			add += x;
			max_cur += x;
			min_ans += x;
			rig_con += x;
			min_add += x;
		}
		bool is_leaf;
	}	T[MaxN << 1];
	
	IL void push_down(RG int i)
	{
		if(T[i].add)
		{
			T[SonL].do_add(T[i].add);
			T[SonR].do_add(T[i].add);
			T[i].add = 0;
		}
	}
	
	IL ll query_cut(RG int i, RG ll cut)
	{	
		RG ll ans = inf;
		while(!T[i].is_leaf && cut < T[i].max_cur)
		{
			push_down(i);
			if(cut <= T[SonL].max_cur)
			{
				cmin(ans, T[i].rig_con);
				i = SonL;
			}
			else
			{
				cmin(ans, cut + T[SonL].min_old);
				i = SonR;
			}
		}
		if(cut < T[i].max_cur) cmin(ans, T[i].min_ans);
		cmin(ans, cut + T[i].min_old);
		return ans;
	}
	
	IL void push_up(RG int i)
	{
		RG Data *p = T + i;
		if(T[SonL].max_cur >= T[SonR].max_cur)
		{
			p->max_cur = T[SonL].max_cur;
			p->rig_con = T[SonL].max_cur + T[SonR].min_old;
		}
		else
		{
			p->max_cur = T[SonR].max_cur;
			p->rig_con = query_cut(SonR, T[SonL].max_cur);
		}
		p->min_add = dmin(T[SonL].min_add, T[SonR].min_add);
		p->min_ans = dmin(T[SonL].min_ans, p->rig_con);
	}
	
	void build(Def)
	{
		if(l == r)
		{
			T[i] = (Data) {-old[l], old[l], inf, inf};
			T[i].is_leaf = 1;
		}
		else
		{
			RG int m = (l + r) >> 1;
			build(SonL, RanL);
			build(SonR, RanR);
			T[i].min_old = dmin(T[SonL].min_old, T[SonR].min_old);
			push_up(i);
		}
	}
	
	int ql, qr, qp; ll qv, qmax;
	void modify(Def) // [ql, qr] += qv
	{
		if(ql <= l && r <= qr)
			return T[i].do_add(qv);
		RG int m = (l + r) >> 1;
		push_down(i);
		if(NeedL) modify(SonL, RanL);
		if(NeedR) modify(SonR, RanR);
		push_up(i);
	}
	void query_max(Def)
	{
		if(ql <= l && r <= qr)
			return (void) cmax(qmax, T[i].max_cur);
		RG int m = (l + r) >> 1;
		push_down(i);
		if(NeedL) query_max(SonL, RanL);
		if(NeedR) query_max(SonR, RanR);
	}
	void find(Def)
	{
		if(qp || T[i].min_add > K) return;
		if(l == r) return (void) (qp = l);
		RG int m = (l + r) >> 1;
		push_down(i);
		if(!qp && NeedR) find(SonR, RanR);
		if(!qp && NeedL) find(SonL, RanL);
	}
	void query(Def, RG ll qc)
	{
		if(ql <= l && r <= qr)
		{
			RG ll qv = query_cut(i, qc);
			if(qv > K) {return;}
			if(l == r) {qp = l; return;}
		}
		RG int m = (l + r) >> 1;
		push_down(i);
		// right first
		if(!qp && NeedR) 	
		{
			if(ql <= l) 		query(SonR, RanR, dmax(qc, T[SonL].max_cur));
			else if(m < ql)		query(SonR, RanR, qc);
			else				{qmax = qc; query_max(SonL, RanL); query(SonR, RanR, qmax);}
		}
		if(!qp && NeedL) 	query(SonL, RanL, qc);
	}
	
	int ans = 1, out[MaxN];
	void dfs_make(RG int p)
	{
		ql = qr = p; qmax = -inf;
		query_max(1, 1, N);
		
		ql = p; qr = N; qp = 0;
		find(1, 1, N);
		
		if(qp && p != N)
		{
			ql = p + 1; qr = qp + 1; qp = 0;
			query(1, 1, N, qmax);
			cmax(ans, qp - p + 1);
		}
		out[p] = qp ? qp : p;
		for(RG Pointer *k = fir[p]; k; k = k->next)
		{
			ql = p - 1; qr = N;
			qv = add[k->to];
			modify(1, 1, N);
			
			dfs_make(k->to);
			
			ql = p - 1; qr = N;
			qv = -add[k->to];
			modify(1, 1, N);
		}
	}
	
	IL void main()
	{
		Input::main();
		BuildTree::main();
		For(i, 1, N) old[i] = old[i - 1] + gas[i] - len[i - 1];	
		build(1, 1, N);
		dfs_make(N);
		//print(ans);
		//#ifndef ONLINE_JUDGE
		For(i, 1, N) print(out[i], " \n"[i == N]);
		//#endif
	}	
	
#endif
}

int main()
{
	#define FILE "bin"
	// freopen(FILE ".in", "r", stdin); freopen(FILE ".out", "w", stdout);
	pb_ds::main();
	pb_ds::io::flush();
	fclose(stdin); fclose(stdout);  
}

#if 0
#endif
