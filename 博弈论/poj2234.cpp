using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
namespace OI {

struct _Main {
template <typename Type>
	int read(Type &a) {
		char t;
		while (!isdigit(t = getchar())) {
			if (t == EOF) {
				return 0;
			}
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		return 1;
	}
	_Main() {
		int n, a, t;
		while (read(n)) {
			a = 0;
			for (int i = 0; i < n; i++) {
				read(t); a ^= t;
			}
			if (a == 0) {
				printf("No\n"); 
			} else {
				printf("Yes\n");
			}
		}
	}
}poj2234;

}

