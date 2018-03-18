using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 55, MXE = 50 * 50;
const int DST = 0, NXT = 1, ID = 2;
struct _Main {
	int n, m;
	int ind[MXN], outd[MXN];
	int del[MXE];
	int out[MXN], in[MXN];
	int edge[MXE * 2][3];
	int eidx;
	int dis(int a) {
		return abs(in_out(a));
	}
	int in_out(int a) {
		return ind[a] - outd[a];
	}
	int calc() {
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(dis(i), mx);
		}
		return mx;
	}
	void cut() {//assert now_ans != 0
		int nd = -1, e = -1, f, beg;
		for (int i = 1; i <= n; i++) {
			if (nd == -1 || dis(i) > dis(nd)) {
				nd = i;
			}
		}
		if (ind[nd] > outd[nd]) {
			f = -1;
			beg = in[nd];
		} else {
			f = 1;
			beg = out[nd];
		}
		for (int i = beg; i; i = edge[i][NXT]) {
			if (!del[edge[i][ID]] && (e == -1 || f * in_out(edge[i][DST]) > f * in_out(edge[e][DST]))) {
				e = i;
			}
		}
		del[edge[e][ID]] = 1;
		if (ind[nd] > outd[nd]) {
			ind[nd]--;
			outd[edge[e][DST]]--;
		} else {
			outd[nd]--;
			ind[edge[e][DST]]--;
		}
	}
	int eid;
	void add(int src, int dst) {
		eid++;
		
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][ID] = eid;
		edge[eidx][NXT] = out[src];
		out[src] = eidx;
		outd[src]++;
		
		eidx++;
		edge[eidx][DST] = src;
		edge[eidx][ID] = eid;
		edge[eidx][NXT] = in[dst];
		in[dst] = eidx;
		ind[dst]++;
	}
	void clear() {
		memset(del + 1, 0, m * sizeof(int));
		memset(in + 1, 0, n * sizeof(int));
		memset(out + 1, 0, n * sizeof(int));
		memset(ind + 1, 0, n * sizeof(int));
		memset(outd + 1, 0, n * sizeof(int));
		eidx = eid = 0;
	}
	
	_Main() {
		int Tn;
		int low;
		int a, b;
		int ans;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			clear();
			read(n); read(m); read(low);
			for (int i = 1; i <= m; i++) {
				read(a); read(b);
				add(a, b);
			}
			ans = calc();
			for (int i = m - 1; i >= low && ans > 0; i--) {
				cut();
				ans = min(ans, calc());
			}
//			ans = calc();
			printf("Case %d: %d\n", T, ans);
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
}jsk;
}
