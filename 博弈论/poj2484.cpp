using namespace std;
int main() {}
#include <cstdio>
#include <cctype>

namespace OI {
struct _Main {
	_Main() {
		int n, t;
		while (1) {
			while (!isdigit(t = getchar()));
			n = t - '0';
			while ( isdigit(t = getchar())) {
				n *= 10;
				n += t - '0';
			}
			if (n <= 2) {
				if (n == 0) {
					break;
				}
				printf("Alice\n");
			} else{
				printf("Bob\n");
			}
		}
	}
}poj2484;



}

