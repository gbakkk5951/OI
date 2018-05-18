using namespace std;
int main() {}
#include <cctype>
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
	void change(int nd, int val) {
		for (; nd <= qn; nd += nd & (-nd)) {
			node[nd] += val;
		}
	}
	int query(int nd) {
		int sum = 0;
		for (; nd; nd -= nd & (-nd)) {
			sum += node[nd];
		}
		return sum;
	}
}tree;
Ques tmp[MXN];
int dl[MXN], didx;
struct _Main {
	void cdq(int l, int r) {
		if (l == r) {
			return;
		}
		int mid = l + r >> 1;
		cdq(l, mid);
		cdq(mid + 1, r);
		int idx = 0;
		for (int i = l; i <= mid; i++) {
			if (q[i].id == 0) {
				tmp[idx++] = q[i];
			} 
		}
		for (int i = mid + 1; i <= r; i++) {
			if (q[i].id) {
				tmp[idx++] = q[i];
			}
		}
		sort(tmp, tmp + idx);
		didx = 0;
		for (int i = 0; i < idx; i++) {
			if (tmp[i].id) {
				ans[tmp[i].id] += tmp[i].val * tree.query(tmp[i].y);
			} else {
				tree.change(tmp[i].y, tmp[i].val);
				dl[didx++] = i;
			}
		}
		for (int i = 0; i < didx; i++) {
			tree.change(tmp[dl[i]].y, -tmp[dl[i]].val);
		}
	}
	_Main() {
		int op, x, y, a, xi, yi, xj, yj, ov;
		int Qn = 0;
		read(ov); read(a);
		while (1) {
			read(op);
			if (op == 1) {
				read(x); read(y); read(a);
				push(x, y, a);
			} else
			if (op == 2) {
				++Qn;
				read(xi); read(yi);
				read(xj); read(yj);
				ans[Qn] = ov * (xj - xi + 1) * (yj - yi + 1);
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
			q[i].y = lower_bound(srt + 1, srt + qn + 1, q[i].y) - srt;
		}
		cdq(1, qn);
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
}bzoj1176;


}
