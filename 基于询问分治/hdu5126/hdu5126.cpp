using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int ADD = 1, QUERY = 2;
struct ArrayTree {
	int node[100010];
	int n;
	int query(int nd) {
		int ret = 0; //神TM = 1 
		for (; nd; nd -= nd & (-nd)) {
			ret += node[nd];
		}
		return ret;
	}
	void add(int nd, int v) {
		for (; nd <= n; nd += nd & (-nd)) {
			node[nd] += v;
		}
	}
	void clear() {
		memset(node + 1, 0, n * sizeof(int));
	}
}tree;
struct Ques {
	int id, xishu, x, y, z, tp;
	bool operator < (const Ques &b) const {
		if (x != b.x) {
			return x < b.x;
		}
		if (y != b.y) {
			return y < b.y;
		}
		if (z != b.z) {
			return z < b.z;
		}
		return tp < b.tp;
	}
};
int ans[50005];
Ques tmp[400010];
Ques subarr[400010];
Ques arr[400010];
bool subcmp(const Ques &a, const Ques &b) {
	if (a.y != b.y) {
		return a.y < b.y;
	}
	if (a.z != b.z) {
		return a.z < b.z;
	}
	return a.tp < b.tp;
}
void subcdq(int l, int r) {
	int mid = l + r >> 1;
	int idx = 0, a1 = 0, q1 = 0, a2 = 0, q2 = 0;
	for (int i = l; i <= mid; i++) {
		if (subarr[i].tp == ADD) {
			tmp[idx++] = subarr[i];
			++a1;
		} else {
			++q1;
		}
	}
	for (int i = mid + 1; i <= r; i++) {
		if (subarr[i].tp == QUERY) {
			tmp[idx++] = subarr[i];
			++q2;
		} else {
			++a2;
		}
	}
	if (a1 && q2) {
		sort(tmp, tmp + idx, subcmp);
		for (int i = 0; i < idx; i++) {
			if (tmp[i].tp == ADD) {
				tree.add(tmp[i].z, 1);
			} else {
				ans[tmp[i].id] += tmp[i].xishu * tree.query(tmp[i].z);
			}
		}
		if (a1 * 16 > tree.n) {
			tree.clear();
		} else 
		for (int i = 0; i < idx; i++) {
			if (tmp[i].tp == ADD) {
				tree.add(tmp[i].z, -1);
			}
		}
	}
	if (a1 && q1) {
		subcdq(l, mid);
	}
	if (a2 && q2) {
		subcdq(mid + 1, r);
	}
}
void cdq(int l, int r) {
	int mid = l + r >> 1;
	int idx = 0, a1 = 0, q1 = 0, a2 = 0, q2 = 0;
	for (int i = l; i <= mid; i++) {
		if (arr[i].tp == ADD) {
			subarr[idx++] = arr[i];
			++a1;
		} else {
			++q1;
		}
	}
	for (int i = mid + 1; i <= r; i++) {
		if (arr[i].tp == QUERY) {
			subarr[idx++] = arr[i];
			++q2;
		} else {
			++a2;
		}
	}
	if (a1 && q2) {
		sort(subarr, subarr + idx);
		subcdq(0, idx - 1);
	}
	if (a1 && q1) {
		cdq(l, mid);
	}
	if (a2 && q2) {
		cdq(mid + 1, r);
	}
}

struct _Main {
	int ansidx;
	int srt[400010], qidx, sidx;
	void push(int id, int xishu, int x, int y, int z, int tp) {
		if (x && y && z) {
			srt[++sidx] = z;
			arr[++qidx] = Ques {id, xishu, x, y, z, tp};
		}
	}
	_Main() {
		int Tn, Qn;
		int op, x1, x2, y1, y2, z1, z2;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			read(Qn);
			for (int Q = 1; Q <= Qn; Q++) {
				read(op);
				if (op == ADD) {
					read(x1); read(y1); read(z1);
					push(Q, 0, x1, y1, z1, ADD);
				} else
				if (op == QUERY) {
					++ansidx;
					read(x1); read(y1); read(z1);
					read(x2); read(y2); read(z2);
					
					push(ansidx, 1, x2, y2, z2, QUERY);
					push(ansidx, -1, x1 - 1, y2, z2, QUERY);
					push(ansidx, -1, x2, y1 - 1, z2, QUERY);
					push(ansidx, +1, x1 - 1, y1 - 1, z2, QUERY);
					
					push(ansidx, -1, x2, y2, z1 - 1, QUERY);
					push(ansidx, +1, x1 - 1, y2, z1 - 1, QUERY);
					push(ansidx, +1, x2, y1 - 1, z1 - 1, QUERY);
					push(ansidx, -1, x1 - 1, y1 - 1, z1 - 1, QUERY);
				}
			}
			sort(srt + 1, srt + sidx + 1);
			sidx = unique(srt + 1, srt + sidx + 1) - srt - 1; // - 1; uniq return值是开区间 
			tree.n = sidx;
			for (int i = 1; i <= qidx; i++) {
				arr[i].z = lower_bound(srt + 1, srt + sidx + 1, arr[i].z) - srt;
			}
			cdq(1, qidx);
			for (int i = 1; i <= ansidx; i++) {
				printf("%d\n", ans[i]);
			}
			if (T != Tn) {
				memset(ans + 1, 0, ansidx * sizeof(int));
				ansidx = qidx = sidx = 0;
			}
		}
		
		
	}
	
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}instance;

}


