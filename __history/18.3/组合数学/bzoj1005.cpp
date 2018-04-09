using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cstdlib>
namespace OI {
typedef long long lld;
const int MXN = 1005; 
const lld mod = 1e9;
struct big {
	lld num[350];
	int high;
	void jw() {
		int nh = 0, t;
		for (int i = 0; i <= high + 1; i++) {
			if (num[i]) {
				nh = i;
				if (num[i] >= mod) {
					num[i + 1] += (t = num[i] / mod);
					num[i] -= t * mod;
				}
			}
		}
		high = nh;
	}
	void operator *= (int c) {
		for (int i = 0; i <= high; i++) {
			num[i] *= c;
		}
		jw();
	}
	void print() {
		printf("%lld", num[high]);
		for (int i = high - 1; i >= 0; i--) {
			printf("%09lld", num[i]);
		}
	}
}one;

struct _Main {
	int d[MXN];
	int fcnt[MXN << 1]; //factor cnt
	int n;
	int ucnt; //unknown cnt
	int gcnt; //known position cnt
	void div(int num, int xishu) {
		for (int i = 2; i * i <= num; i++) {
			while (num % i == 0) {
				num /= i;
				fcnt[i] += xishu;
			}
		}
		if (num > 1) {
			fcnt[num] += xishu;
		}
	}
	void fact(int n, int xishu) {
		for (int i = 2; i <= n; i++) {
			div(i, xishu);
		}
	}
	void com(int n, int m, int xishu) {
		fact(n, xishu);
		fact(m, -xishu);
		fact((n - m), -xishu);
	}
	void power(int base, int pow, int xishu) {
		div(base, pow * xishu);
	}
	char iszero() {
		int sum = 0;
		ucnt = n;
		for (int i = 1; i <= n; i++) if (d[i] != -1) {
			if (n != 1 && d[i] <= 0 || d[i] >= n) {
				return 1;
			}
			gcnt += d[i] - 1;
			sum += d[i];
			ucnt--;
		}
		return 2 * (n - 1) - sum < ucnt;
	}
	
	void calc() {
		if (iszero()) {
			printf("0");
			return;
		}
		if (n <= 2) {
			printf("1");
			return;
		}
		com(n - 2, gcnt, +1);
		fact(gcnt, +1);
		for (int i = 1; i <= n; i++) {
			if (d[i] > 2) {
				fact(d[i] - 1, -1);
			}
		}
		power(ucnt, n - 2 - gcnt, 1);
		one.num[0] = 1;
		for (int i = 2; i <= 1000; i++) {
			while (fcnt[i]--) {
				one *= i;
			}
		}
		one.print();
	}
	_Main() {
		read(n);
		for (int i = 1; i <= n; i++) {
			read(d[i]);
		}
		calc();
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f;
	}
}bzoj1005;
}

