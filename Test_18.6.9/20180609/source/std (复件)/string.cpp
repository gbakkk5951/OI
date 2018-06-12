#include <cstdio>
#include <cstring>
#include <cassert>
#define IL __inline__ __attribute__((always_inline))
#define RG register
#define cmax(a, b) ((a) < (b) ? (a) = (b) : 0)
const int mod = 1e9 + 7;
const int MaxN = 2005;
const int MaxM = 1005;
int happy, N, M;
struct Accepted
{
	int next[MaxM][2], fail[MaxM], Q[MaxM], v[MaxM], tot;
	bool fuck[MaxM];
	IL int extend(RG int p, RG bool w) {return next[p][w] ? next[p][w] : next[p][w] = ++tot;}
	IL int step(RG int p, RG bool w) {return next[p][w];}
	IL bool move(RG int &p, RG int w) {return fuck[p = next[p][w]] ? p = 0, 1 : 0;}
	IL void accept()
	{
		RG int l = 1, r = 1, p, f;
		if(next[0][0]) Q[r++] = next[0][0];
		if(next[0][1]) Q[r++] = next[0][1];
		while(l != r)
		{
			p = Q[l++], f = fail[p]; fuck[p] |= fuck[f];
			(next[p][0] ? fail[Q[r++] = next[p][0]] : next[p][0]) = next[f][0];
			(next[p][1] ? fail[Q[r++] = next[p][1]] : next[p][1]) = next[f][1];
		}
	}
	IL void make_v()
	{
		RG int p; for(RG int i = 1; i <= tot; ++i) p = Q[i], v[p] |= v[fail[p]];
	}
} S, T;
char str[MaxM][MaxM];
int len[MaxM];
bool ban[MaxM][MaxM];
const int HashMod = 3333331;
struct Hash{unsigned val; int cnt; Hash *next;} *fir[HashMod], mem[1 << 22], *tot = mem;
bool res;
IL int& find(RG unsigned  s)
{
	RG int h = s % HashMod;
	for(RG Hash *k = fir[h]; k; k = k->next)
		if(k->val == s) return res = 1, k->cnt;
	*++tot = (Hash) {s, 0, fir[h]}, fir[h] = tot;
	return res = 0, tot->cnt;
}
int dp(RG int len, RG int a, RG int b, RG int cnt)
{
	if(!len) return cnt || !ban[a][b];
	RG int &V = find((((unsigned) ((len + 1) >> 1) << 10 | (unsigned) a) << 10 | (unsigned) b) << 1 | (unsigned) cnt);
	if(res) return V;
	for(RG int w = 0; w != 2; ++w)
	{
		RG int Len = len, A = a, B = b, Cnt = cnt;
		             --Len, Cnt -= S.move(A, w);
		if(len != 1) --Len, Cnt -= T.move(B, w);
		if(Cnt >= 0) (V += dp(Len, A, B, Cnt)) %= mod;
	}
	return V;
}
int main()
{
	#define FILE "string"
	freopen(FILE ".in", "r", stdin), freopen(FILE ".out", "w", stdout);
	happy = scanf("%d%d", &N, &M);
	for(RG int i = 0; i != M; ++i)
	{
		happy = scanf("%s", str[i]);
		len[i] = strlen(str[i]);
		RG int p = 0, q = 0, L = len[i];
		for(RG int k = 0; k != L; ++k)
		{
			p = S.extend(p, str[i][k        ] == '1');
			q = T.extend(q, str[i][L - k - 1] == '1');
		}
		S.fuck[p] = T.fuck[q] = 1;
	}
	S.accept();
	T.accept();
	for(RG int i = 0; i != M; ++i)
	{
		memset(S.v, 0, (S.tot + 1) << 2);
		memset(T.v, 0, (T.tot + 1) << 2);
		RG int p = 0, q = 0, L = len[i];
		for(RG int k = 0; k != L - 1; ++k)
		{
			S.v[p = S.step(p, str[i][k        ] == '1')] |= 1 << (k + 1);
			T.v[q = T.step(q, str[i][L - k - 1] == '1')] |= 1 << (L - k - 1);
		}
		S.make_v();
		T.make_v();
		RG int tmp;
		for(RG int a = 0; a != S.tot; ++a) if(S.v[a])
		{
			tmp = S.v[a];
			for(RG int b = 0; b != T.tot; ++b) 
				if(T.v[b] & tmp) ban[a][b] = 1;
		}	
	}
	printf("%d\n", dp(N, 0, 0, 1));
}
