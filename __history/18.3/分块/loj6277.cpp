using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
namespace OI {
typedef long long lld;
const int MXN = 50005, SQ = 230;
class Block {
public:
	int sq;
	lld bl[SQ];
	lld arr[MXN];
	int id[MXN + SQ], ed[MXN + SQ];
	void change(lld arr[], int l, int r, int add) {
		for (int i = l; i <= r; i++) {
			arr[i] += add;
		}
	}
	lld query(int pos) {
		return bl[id[pos]] + arr[pos];
	}
	void init(int n) {
		sq = ceil(sqrt(n));
		int idx = 0;
		for (int i = 1; i <= n + sq; i++) {
			id[i] = idx;
			if (i % sq == 0) {
				ed[idx] = i;
				idx++;
			}
		}
	}
	void change(int l, int r, int add) {
		int t;
		if (r >= ed[id[l]]) {
			change(arr, l, ed[id[l]], add);
			l = ed[id[l]] + 1;
		}
		if (r >= ed[id[l]]) {
			change(bl, id[l], t = id[r] - (r != ed[id[r]]), add);
			l = ed[t] + 1;
		}
		if (r >= l) {
			change(arr, l, r, add);
		}
	}
}data;
struct _Main {
	_Main() {
		int n;
		int op, l, r, c;
		read(n);
		data.init(n);
		for (int i = 1; i <= n; i++) {
			read(data.arr[i]);
		}
		for (int Q = 1; Q <= n; Q++) {
			read(op); read(l); read(r); read(c);
			if (op == 0) {
				data.change(l, r, c);
			} else {
				printf("%lld\n", data.query(r));
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
}loj6277;


}

