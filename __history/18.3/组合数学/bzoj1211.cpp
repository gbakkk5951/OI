using namespace std;
int main() {}
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
const int MXN = 400;
struct _Main {
	int cnt[MXN];
	void div(int num, int xishu) {
		for (int i = 2; i * i <= num; i++) {
			while (num % i == 0) {
				num /= i;
				cnt[i] += xishu;
			}
		}
		if (num > 1) {
			cnt[num] += xishu;
		}
	}
	int d[MXN];
	int n;
	char iszero() {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += d[i];
			if (n != 1 && d[i] <= 0 || d[i] >= n) { // 若n == 1则d[1] 可以=0 
				return 1;
			}
		}
		return sum != 2 * (n - 1);
	}
	long long calc() {
		if (iszero())return 0;
		if (n <= 2) return 1;
		//div(n - 2, +1); //n-2 ! 不是n-2 
		for (int i = 2; i <= n - 2; i++) {
			div(i, +1);
		}
		for (int i = 1; i <= n; i++) { //d[i]-1 ! 不是d[i] - 1 
			for (int j = 2; j <= d[i] - 1; j++) {
				div(j, -1);
			}
		}
		long long ret = 1;
		for (int i = 2; i <= 150; i++) {
			while (cnt[i]) {
				cnt[i]--;
				ret *= i;
			}
		}
		return ret;
	}
	_Main() {
		read(n);
		for (int i = 1; i <= n; i++) {
			read(d[i]);
		}
		printf("%lld", calc());
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
}bzoj1211;
//忘写阶乘了	 
