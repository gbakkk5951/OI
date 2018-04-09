#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
const int MXN = 1000005;
int n;
struct ArrayTree {
	int node[MXN];
	void change(int nd, int val) {
		for (; nd <= n; nd += nd & (-nd)) {
			node[nd] += val;
		}
	}
	int query(int nd) {
		int ret = 0;
		for (; nd; nd -= nd & (-nd)) {
			ret += node[nd];
		}
		return ret;
	}
}tree;
struct Rg {
	int l, r, id;
}rg[MXN];
/*struct cmp {
	bool inline operator () (const Rg &a, const Rg &b) {
		return a.r < b.r;
	}
};*/
bool cmp (const Rg &a, const Rg &b) {
	return a.r < b.r;
}
struct _Main {
//	queue<int> pos[MXN]; 一个queue占80byte空间
	vector<int>pos[MXN];// 一个vector 占24byte空间 
	int head[MXN]; 
	int arr[MXN], cnt[MXN], ans[MXN];
	_Main() {
		int Qn;
//		n = Qn = 1e1;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
//			arr[i] = 1;
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(rg[Q].l); read(rg[Q].r);
//			rg[Q].l = 1; rg[Q].r = Q;
			rg[Q].id = Q;
		
		}
		sort(rg + 1, rg + Qn + 1, cmp);
		int now = 0, t, p = 0;
		for (int Q = 1; Q <= Qn; Q++) {
			while (rg[Q].r > now) {
				++cnt[t = arr[++now]];
				pos[t].push_back(now);
				if (cnt[t] >= t) {
					if (cnt[t] > t) {
						if (cnt[t] > t + 1) {
							tree.change(n + 1 - pos[t][head[t] - 1], + 1);//消除新标记的位置变化 
						}
						tree.change(n + 1 - pos[t][head[t]], -2); //-2不是-1, 因为不仅要消除原来标记，还要减去信标 
						head[t]++;
					}
					tree.change(n + 1 - pos[t][head[t]], 1);
				}
			}
			ans[rg[Q].id] = tree.query(n + 1 - rg[Q].l);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%d\n", ans[Q]);
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
}dloj1002;
}

