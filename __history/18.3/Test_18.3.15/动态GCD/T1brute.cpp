using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
namespace OI {
const int MXN = 100010;
const int DST = 1, NXT = 0;
struct _Main {
	int num[MXN], f[MXN], h[MXN];
	int edge[MXN << 1][2];
	int head[MXN];
	int eidx;
	int gcd(int a, int b) {
		return b ? gcd (b, a % b) : a;
	}
	void add(int src, int dst) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	void dfs(int nd, int fa) {
		f[nd] = fa;
		h[nd] = h[fa] + 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if ((t = edge[e][DST]) != fa) {
				dfs(t, nd);
			}
		}
	}	
	int ask(int a, int b) {
		int ret = num[a];
		if (h[a] < h[b]) swap(a, b);
		while (h[a] != h[b]) {
			ret = gcd(ret, num[a]);
			a = f[a];
		}
		while (a != b) {
			ret = gcd(num[a], ret);
			ret = gcd(num[b], ret);
			a = f[a]; b = f[b];
		}
		ret = gcd(num[a], ret);
		return ret;
	}
	void change(int a, int b, int c) {
		if (h[a] < h[b]) swap(a, b);
		while (h[a] != h[b]) {
			num[a] += c;
			a = f[a];
		}
		while (a != b) {
			num[a] += c;
			num[b] += c;
			a = f[a]; b = f[b];
		}
		num[a] += c;
	}
	char op[5];
	_Main() {
		int n, Qn, a, b, c;
		read(n);
		
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b);
			a++; b++;
			add(a, b); add(b, a);
		}
		for (int i = 1; i <= n; i++) {
			read(num[i]);
		}
		dfs(1, 0);
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			scanf("%s", op);
			if (op[0] == 'C') {
			
				read(a); read(b); read(c);
				a++; b++;
				change(a, b, c);
			} else {
				read(a); read(b);
				a++; b++;
				printf("%d\n", ask(a, b));
			}
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
}T1brute;

}
