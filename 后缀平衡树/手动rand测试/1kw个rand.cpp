#pragma GCC optimize(2)
using namespace std;
int main() {}
#include <cstdio>
#include <ctime>
#include <cstdlib>
namespace OI {
const int MXN = 5e7;
const int MOD = 497 << 21 | 1;
const int G = 3;
struct _Main {
	inline int rand() {
		static int val = 1;
		return val = val * G % MOD;
	}
	_Main() {
		float t1, t2;
		int c = 0;
		t1 = clock();
		for(int i = 0; i < MXN; i++) {
			if (rand() == 0) c++;
		}
		t2 = clock();
		printf("%lfms", (t2 - t1) / 1000.0);
	}
}test;
}
