using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 5e5 + 5;
struct Ques {
	int x, y;
	int id, xishu;
	bool operator < (const Ques &b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		return id < b.id;
	}
}q[MXN * 5];
int n, Qn;
int qn;
struct ArrayTree {
	int node[MXN * 5];
	void add(int nd) {
		for (; nd <= qn; nd += nd & (-nd)) {
			node[nd]++;
		}
	}
	int ask(int nd) {
		int sum = 0;
		for (; nd; nd -= nd & (-nd)) {
			sum += node[nd];
		}
		return sum;
	}
}tree;

struct _Main {
	
	int ans[MXN];
	int srt[MXN * 5];
	inline void push(int x, int y, int id = 0, int xishu = 0) {
		srt[qn] = y;
		q[qn++] = (Ques){x, y, id, xishu};
	}
	_Main() {
		int xi, yi, xj ,yj, x, y;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(x); read(y);
			push(x, y);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(xi); read(yi); read(xj); read(yj);
			push(xj, yj, Q, +1);
			push(xj, yi - 1, Q, -1);
			push(xi - 1, yj, Q, -1);
			push(xi - 1, yi - 1, Q, +1);
		}
		sort(srt, srt + qn);
		for (int i = 0; i < qn; i++) {
			q[i].y = lower_bound(srt, srt + qn, q[i].y) - srt + 1;
		}
		sort(q, q + qn);
		for (int i = 0; i < qn; i++) {
			if (q[i].id) {
				ans[q[i].id] += q[i].xishu * tree.ask(q[i].y);
			} else {
				tree.add(q[i].y);
			}
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
}bzoj1935;
}
