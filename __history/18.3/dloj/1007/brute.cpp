using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
const int MXN = 500005;

int n;

int arr[MXN];

void change(int l, int r, int val) {
	for (int i = l; i <= r; i++) {
		arr[i] ^= val;
	}
}
int query(int l, int r) {
	int ans = 0;
	for (int i = l; i <= r; i++) {
		ans = max(ans, arr[i]);
	}
	return ans;
}
struct _Main {
	_Main() {
		int l, r, op, x;
		int Qn;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(op);
			if (op == 1) {
				read(x); read(l); read(r);
				change(l, r, x);
			} else {
				read(l); read(r);
				printf("%d\n", query(l, r));
			}
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
}dloj1007;

}
