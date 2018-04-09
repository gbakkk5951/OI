using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
struct _Main {
typedef long long lld;
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
	int gcd(lld a, lld b) {
		if (a > b) {
			swap(a, b);
		}
		if (a == 0 || b / a > 1) {
			return 1;
		}
		return gcd(a, b % a) ^ 1;
	}
	_Main() {
		lld a, b;
		while (1) {
			read(a); read(b);
			if (a == 0 && b == 0) {
				break;
			}
			if (a == b || (gcd(a, b) == 1)) {
				printf("Stan wins\n"); 
			} else {
				printf("Ollie wins\n");
			}
		}
	}

}poj2348;
