using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e5 + 10;
int mx;
struct ArrayTree {
	int node[MXN];
	int query(int nd) {
		int ret = 0;
		for (; nd; nd -= nd & (-nd)) {
			ret += node[nd];
		}
		return ret;
	}
	void change(int nd, int val) {
		for (; nd <= mx; nd += nd & (-nd)) {
			node[nd] += val;
		}
	}
}tree;

struct Ques {
	int id, xishu, r, v;
	bool operator < (const Ques &b) const {
		return r < b.r;
	}
}qs[MXN << 1];
int ans[MXN];
struct _Main {
	int arr[MXN];
	_Main() {
		int n, Qn;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
			mx = max(mx, arr[i]);
		}
		int idx = 0;
		for (int Q = 1; Q <= Qn; Q++) {
			read(qs[++idx].r); 
			qs[idx].r--;
			qs[idx].id = Q;
			qs[idx].xishu = -1;
			
			read(qs[++idx].r);
			qs[idx].id = Q;
			qs[idx].xishu = 1;
			
			read(qs[idx].v);
			qs[idx - 1].v = qs[idx].v;
		}
		sort(qs + 1, qs + idx + 1);
		int r = 0;
		for (int Q = 1; Q <= idx; Q++) {
			while (qs[Q].r > r) {
				tree.change(arr[++r], 1);
			}
			ans[qs[Q].id] += qs[Q].xishu * tree.query(qs[Q].v);
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
}dloj1005;
}
