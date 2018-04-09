using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {

struct _Main {
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while (isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
	int pipe[10];
	_Main() {
		int i;
		int n;
		while (1) {
			read(n);
			if (n == 0) break;
			for (i = 0; i < n; i++) {
				read(pipe[i]);
			}
			if (n & 1) {
				printf("1\n");
				continue;
			}
			sort(pipe, pipe + n);
			for (i = 0; i < n; i += 2) {
				if (pipe[i] != pipe[i + 1]) {
					printf("1\n");
					break;
				}
			}
			if (i >= n) printf("0\n");
		}
	}
}poj1740;
}
