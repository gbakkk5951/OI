using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
namespace OI {
typedef long long lld;
typedef double lf;
struct _Main {
	_Main() {
		int a, n;
		lf tmp, sum;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(tmp);
			sum += tmp;
		}
		if (sum < 0) printf("???");
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}tester;
}
