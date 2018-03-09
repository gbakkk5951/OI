using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
	int cnt;
	void insert(lld num, int mx) {
		for (int i = mx; i >= 0; i--) {
			if (num >> i & 1) {
				if (base[i]) {
					num ^= base[i];
				} else {
				
				}
			}
		}
	}



struct _Main {
	
}bzoj4568;
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
}
