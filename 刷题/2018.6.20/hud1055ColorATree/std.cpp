using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef pair<lf, int>p;
const int DST = 0, NXT = 1;
const int MXN = 1e3 + 10;
int f[MXN];
int getfa(int a) {
	return f[a] ? f[a] = getfa(f[a]) : a;
}
priority_queue<p> hp;
struct Node {
	int time, sum;
}node[MXN];
struct _Main {
	int n, Qn, Tn;
	int root;
	int fa[MXN];
	_Main() {
		int a, b, ans, nd, f;
		while (1) {
			ans = 0;
			read(n); read(root);
			if (n == 0 && root == 0) break;
			for (int i = 1; i <= n; i++) {
				read(node[i].sum);
				node[i].time = 1;
				if (i != root) {
					hp.push((p) {node[i].sum, i});
				}
			}
			for (int i = 1; i <= n - 1; i++) {
				read(a); read(b);
				fa[b] = a;
			}
			while (!hp.empty()) {
				nd = hp.top().second;
				hp.pop();
				if (OI::f[nd]) continue;
				f = getfa(fa[nd]);
				ans += node[f].time * node[nd].sum;
				node[f].time += node[nd].time;
				node[f].sum += node[nd].sum;
				OI::f[nd] = f;
				if (f != root) {
					hp.push((p) {(lf)node[f].sum / node[f].time, f});
				}
			}
			ans += node[root].sum;
			memset(OI::f + 1, 0, n * sizeof(int));
			printf("%d\n", ans);
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
