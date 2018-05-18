#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define ll long long
const int N = 15000005, LN = 500, inf = 2147483647,P=1000000007;
struct heap {
	int a[N], n;
	heap() {n = 0, a[0] = inf;}
	inline void push(int x) {
		int w;
		for (w = ++n; a[w>>1] < x; a[w] = a[w>>1], w >>= 1);
		a[w] = x;
	}
	inline void pop() {pop_heap(a+1, a+n+1), --n;}
	inline int top() {return a[1];}
} L, R;
int buf[N*2], ls = N, le = N-1, cnt = 0,n,a,i,ans,A;
void lins(int x) {
	int p = le;
	while (p>=ls && buf[p]>=x) {
		buf[p+1] = buf[p];
		--p;
	}
	buf[++p] = x;
	++le;
}
inline void movel() {
	buf[--ls] = L.top(); L.pop();
	R.push(-buf[le--]);
}
inline void mover() {
	buf[++le] = -R.top(); R.pop();
	L.push(buf[ls++]);
}
int push(int x) {
	++cnt;
	if (le-ls < LN) lins(x); else
	if (x <= buf[ls]) L.push(x); else
	if (x >= buf[le]) R.push(-x);
	else {
		if (L.n < R.n)
			L.push(buf[ls]), ++ls; else
			R.push(-buf[le]), --le;
		lins(x);
	}
	int k = (cnt + 1) >> 1;
	if (L.n >= k) movel();
	if (R.n>cnt-k) mover();
	return buf[ls+k-L.n-1];
}
int main()
{
	freopen("mid.in","r",stdin);
	freopen("mid.out","w",stdout);
	cin>>n>>a;
	for(i=1;i<=n;i++)
	{
		A^=ans=push(a);
		a=(1714636915LL*a%P+1681692777)*(846930886LL*ans%P+1804289383)%P;
	}
	cout<<A<<endl;
	return 0;
}

