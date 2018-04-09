using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cmath>
namespace OI {
typedef long long lld;
const int MXN = 200005, SQ = 460, SQN = 460;

int getsq(int n) {
	return ceil(sqrt(2 * n));
}
class Block {
public:
	int arr[MXN];
	int sq;
	vector <int> bl[SQN];
	void init(int n) {
		sq = getsq(n);
		build(n);
	}
	void build(int n) {
		int idx = 0, j = 0;
		bl[0].resize(sq); //初始化 
		for (int i = 1; i <= n; i++) {
			bl[idx][j++] = arr[i];
			if (i % sq == 0) {
				j = 0;
				bl[++idx].resize(min(sq, n - i));
			}
		}
	}
	void rebuild() {
		int idx = 0;
		for (int i = 0; bl[i].size(); i++) {
			for (int j = 0; j < bl[i].size(); j++) {
				arr[++idx] = bl[i][j];
			}
		}
		build(idx);
	}
	void insert(int pos, int val) {
		int nd;
		for (nd = 0; bl[nd].size() < pos; nd++) {
			pos -= bl[nd].size();
		}
		bl[nd].insert(bl[nd].begin() + pos - 1, val);
		if (bl[nd].size() > 3 * sq) {
			rebuild();
		}
	}
	int query(int pos) {
		int nd;
		for (nd = 0; bl[nd].size() < pos; nd++) {
			pos -= bl[nd].size();
		}
		return bl[nd][pos - 1];
	}
}data;

struct _Main {
	_Main() {
		/*
		int t, sq = 0, sqn = 0;
		for (int i = 1; i <= (int)1e5; i++) {
			t = getsq(i);
			sq = max(t, sq);
			sqn = max(sqn, (int)ceil((double)i / sq));
		}
		printf("sq = %d, sqn = %d\n", sq, sqn);
		*/
		int n, op, l, r, c;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(data.arr[i]);
		}
		data.init(n);
		for (int Q = 1; Q <= n; Q++) {
			read(op); read(l); read(r); read(c);
			if (op == 0) {
				data.insert(l, r);
			} else {
				printf("%d\n", data.query(r));
			}
		}
	}
	template <typename Type>
		void read(Type &a) {
			char t, f = 1;
			while (!isdigit(t = getchar())) {
				if (t == '-') f = -1;
			}
			a = t - '0';
			while ( isdigit(t = getchar())) {
				a *= 10;
				a += t - '0';
			}
			a *= f;
		}
}loj6281;
}
//分块的第一个块和最后一个块要特别考虑 
//计算数据范围时要考虑修改 
