using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cstdlib>
namespace OI {
struct _Main {
	int inline lm(int num, int bit) {
		return (num >> 1) | ((num & 1) << bit);
	}
	char confirm() {
		
		
		
	}
	_Main() {
		int pow;
		read(pow);
		int dst = 1 << (pow - 1) * (2 * pow - 1);
		for (int I = 0; I < dst; I++) {
			
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}left;
}
