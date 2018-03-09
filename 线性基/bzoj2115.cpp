using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>

namespace OI {
typedef long long lld;
const int MXN = 50005, MXE = 200010;
const int DST = 0, NXT = 1, VAL = 2;
class LinearBase {
public:
	lld base[65];
	lld join(lld num) {
		for (int i = 62; i >= 0; i--) {
			if (num >> i & 1) {
				if (base[i]) {
					num ^= base[i];
				} else {
					base[i] = num;
					break;
				}
			}
		}
		return num;
	}
	lld findmax(lld num) {
		for (int i = 62; i >= 0; i--) {
			if ((num >> i & 1) == 0) {
				num ^= base[i];
			}
		}
		return num;
	}
}base;

struct _Main {
	int n;
	char vis[MXN], instk[MXN], inchain[MXN];
	int head[MXN];
	lld edge[MXE][3];
	int chain[MXN], cidx;
	lld sum[MXN];
	int eidx;
	char findchain(int nd) {
		if (nd == n) {
			memset(vis, 0, (n + 1) * sizeof(char));
			chain[++cidx] = nd; //别忘了最后一个 
			inchain[nd] = vis[nd] = instk[nd] = 1;
			return 1;
		}
		int t;
		vis[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (!vis[t = edge[e][DST]]) {
				sum[t] = sum[nd] ^ edge[e][VAL];
				if (findchain(t)) {
					inchain[nd] = vis[nd] = instk[nd] = 1;
					chain[++cidx] = nd;
					return 1;
				}
			}
		}
		return 0;
	}
	void findloop(int nd) {
		int t;
		vis[nd] = instk[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			if (vis[t = edge[e][DST]]) {
				if (instk[t] || inchain[t]) { 
					base.join(sum[nd] ^ edge[e][VAL] ^ sum[t]);
				}
			} else {
				sum[t] = sum[nd] ^ edge[e][VAL]; //忘了赋权值了 
				findloop(t);
			}
		}
		instk[nd] = 0;
	}
	void add(int src, int dst, lld val) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][VAL] = val;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	_Main() {
		int m;
		int a, b; lld v;
		read(n); read(m);
		for (int i = 1; i <= m; i++) {
			read(a); read(b); read(v);
			add(a, b, v); add(b, a, v);
		}
		sum[1] = 0;
		findchain(1);
		for (int i = 1; i <= cidx; i++) {
			findloop(i);
		}
		printf("%lld\n", base.findmax(sum[n]));
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
}bzoj2115;

}
//检查一下第一个和最后一个是否也正确处理 
//检查一下dfs是否在全部情况下处理了“全部”信息 
//检查一下有没有把循环边界当成循环变量来作参数的 
