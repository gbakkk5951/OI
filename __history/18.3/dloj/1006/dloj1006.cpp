using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
namespace OI {
typedef long long lld;
const lld mod = 1e9 + 7;
struct Matrix {
	lld num[6][6];
	Matrix() {
		memset(this, 0, sizeof(Matrix));
	}
	lld & operator () (int a, int b) {
		return num[a][b];
	}
	void operator *=  (Matrix &b) {
		Matrix ret;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					ret(i, j) += num[i][k] * b(k, j);
					ret(i, j) %= mod;
				}
			}
		}
		*this = ret;
	}
}num, trans, pow;
void fastpower(Matrix &ans, Matrix &base, int pow) {
	pow--;
	ans = base;
	while (pow) {
		if (pow & 1) {
			ans *= base;
		}
		if (pow >>= 1) {
			base *= base;
		}
	}
}

struct _Main {
	_Main() {
		int n;
		scanf("%d", &n);
		if (n <= 2) {
			printf("%d\n", n);
			return;
		}
		for (int i = 0; i < 5; i++) {
			num(0, i) = 1;
		}
		num(0, 5) = 2;
		trans(0, 0) = trans(0, 1) = trans(1, 0) = trans(2, 2) = trans(2, 3) = trans(2, 4) = trans(2, 5)
		= trans(3, 2) = trans(3, 5) = trans(5, 5) = trans(4, 4) = 1; //¾ØÕóÂäÁËÒ»¸ö... 
		trans(4, 2) = trans(4, 5) = 2;
		fastpower(pow, trans, n - 2);
		num *= pow;
		printf("%lld\n", num(0, 5));
	}
}dloj1006;
}
