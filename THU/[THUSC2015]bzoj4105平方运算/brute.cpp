using namespace std;
int main() {}
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 1e5 + 10;
struct _Main {
int arr[MXN];
	int n, Qn, mod;
	_Main() {
		int op, l, r;
		read(n); read(Qn); read(mod);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(l); read(r);
			if (op == 0) {
				for (int i = l; i <= r; i++) {
					arr[i] = arr[i] * arr[i] % mod;
				}
			} else {
				int sum = 0;
				for (int i = l; i <= r; i++) {
					sum += arr[i];
				}
				printf("%d\n", sum);
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
}brute;	
}
