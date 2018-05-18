using namespace std;
int main();
#include <cstdio>
#include <algorithm>
namespace OI {
const int MXN = 200010;
int qn;
int Qn;
int srt[MXN];
struct Ques {
	int x, y, val, id;
	bool operator < (const Ques &b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		return id < b.id;
	}
}q[MXN];
void push(int x, int y, int val, int id = 0) {
	qn++;
	srt[qn] = y;
	q[qn] = (Ques){x, y, val, id};
}
int ans[MXN];
struct ArrayTree {
	int node[MXN];
	void add(int nd, int val) {
		for (; nd <= qn; nd += nd & (-nd)) {
			node[nd] += val;
		}
	}
	int query(int nd) {
		int sum = 0;
		for (; nd <= qn; nd -= nd & (-nd)) {
			sum += node[nd];
		}
		return sum;
	}
}tree;

struct _Main {

	_Main() {
		int op, x, y, a, xi, yi, xj, yj, ov;
		int Qn = 0, lst;
		pair<int, int>p;
		read(ov); read(w);
		while (1) {
			if (op == 1) {
				read(x); read(y); read(a);
				push(x, y, a);
			} else
			if (op == 2) {
				++Qn;
				read(xi); read(yi);
				read(xj); read(yj);
				ans[Qn] = (xj - xi + 1) * (yj - yi + 1);
				push(xj, yj, +1, Qn);
				push(xi - 1, yj, -1, Qn);
				push(xj, yi - 1, -1, Qn);
				push(xi - 1, yi - 1, +1, Qn);
			} else {
				break;
			}
		}
		sort(srt + 1, srt + qn + 1);
		for (int i = 1; i <= qn; i++) {
			q[i].y = lower_bound(srt + 1, srt + qn + 1) - srt;
		}
		sort(q + 1, q + qn + 1);
		for (int i = 1; i <= qn; i++) {
			if (q[i].id) {
				ans[q[i].id] += q[i].val * tree.query(q[i].y);
			} else {
				tree.add(q[i].y, q[i].val);
			}
		}
		for (int Q = 1; Q <= Qn; Q++) {
			printf("%d\n", ans[Q]);
		}
	}
	
}bzoj1176;
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

}
