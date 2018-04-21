using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e6 + 5;
struct _Main {
	int arr[MXN];
	_Main() {
		int n;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		sort(arr + 1, arr + n + 1);
		int da = 0, db = 0, ma = 0, mb = 0;
		for (int i = 0; i <= n; i++) {
			da = mb;
			db = ma;
			ma = min(ma, da - arr[i + 1]);
			mb = max(mb, db + arr[i + 1]);
		}
		printf("%d", da);
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
}bzoj2091;
}
