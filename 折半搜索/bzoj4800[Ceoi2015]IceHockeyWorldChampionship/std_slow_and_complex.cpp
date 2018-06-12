using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int PW0 = 1 << 0;
const int PW1 = 1 << 1;
const int PW2 = 1 << 2;
const int PW3 = 1 << 3;
const int PW4 = 1 << 4;
const int PW5 = 1 << 5;
const int PW6 = 1 << 6;
const int PW7 = 1 << 7;
const int PW8 = 1 << 8;
const int PW9 = 1 << 9;
const int PW10 = 1 << 10;
const int PW11 = 1 << 11;
const int PW12 = 1 << 12;
const int PW13 = 1 << 13;
const int PW14 = 1 << 14;
const int PW15 = 1 << 15;
const int PW16 = 1 << 16;
const int PW17 = 1 << 17;
const int PW18 = 1 << 18;
const int PW19 = 1 << 19;
const int PW20 = 1 << 20;
lld a1[(1 << 20) + 47], a2[(1 << 20) + 47];
lld *a, *b;
int ln, rn;

int ef20(lld val) {
	lld* now = a;
	if (now[ln - PW19] <= val) now += ln - PW19;
	if (now[PW18] <= val) now += PW18;
	if (now[PW17] <= val) now += PW17;
	if (now[PW16] <= val) now += PW16;
	if (now[PW15] <= val) now += PW15;
	if (now[PW14] <= val) now += PW14;
	if (now[PW13] <= val) now += PW13;
	if (now[PW12] <= val) now += PW12;
	if (now[PW11] <= val) now += PW11;
	if (now[PW10] <= val) now += PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef19(lld val) {
	lld* now = a;
	if (now[ln - PW18] <= val) now += ln - PW18;
	if (now[PW17] <= val) now += PW17;
	if (now[PW16] <= val) now += PW16;
	if (now[PW15] <= val) now += PW15;
	if (now[PW14] <= val) now += PW14;
	if (now[PW13] <= val) now += PW13;
	if (now[PW12] <= val) now += PW12;
	if (now[PW11] <= val) now += PW11;
	if (now[PW10] <= val) now += PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef18(lld val) {
	lld* now = a;
	if (now[ln - PW17] <= val) now += ln - PW17;
	if (now[PW16] <= val) now += PW16;
	if (now[PW15] <= val) now += PW15;
	if (now[PW14] <= val) now += PW14;
	if (now[PW13] <= val) now += PW13;
	if (now[PW12] <= val) now += PW12;
	if (now[PW11] <= val) now += PW11;
	if (now[PW10] <= val) now += PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef17(lld val) {
	lld* now = a;
	if (now[ln - PW16] <= val) now += ln - PW16;
	if (now[PW15] <= val) now += PW15;
	if (now[PW14] <= val) now += PW14;
	if (now[PW13] <= val) now += PW13;
	if (now[PW12] <= val) now += PW12;
	if (now[PW11] <= val) now += PW11;
	if (now[PW10] <= val) now += PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef16(lld val) {
	lld* now = a;
	if (now[ln - PW15] <= val) now += ln - PW15;
	if (now[PW14] <= val) now += PW14;
	if (now[PW13] <= val) now += PW13;
	if (now[PW12] <= val) now += PW12;
	if (now[PW11] <= val) now += PW11;
	if (now[PW10] <= val) now += PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef15(lld val) {
	lld* now = a;
	if (now[ln - PW14] <= val) now += ln - PW14;
	if (now[PW13] <= val) now += PW13;
	if (now[PW12] <= val) now += PW12;
	if (now[PW11] <= val) now += PW11;
	if (now[PW10] <= val) now += PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef14(lld val) {
	lld* now = a;
	if (now[ln - PW13] <= val) now += ln - PW13;
	if (now[PW12] <= val) now += PW12;
	if (now[PW11] <= val) now += PW11;
	if (now[PW10] <= val) now += PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef13(lld val) {
	lld* now = a;
	if (now[ln - PW12] <= val) now += ln - PW12;
	if (now[PW11] <= val) now += PW11;
	if (now[PW10] <= val) now += PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef12(lld val) {
	lld* now = a;
	if (now[ln - PW11] <= val) now += ln - PW11;
	if (now[PW10] <= val) now += PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef11(lld val) {
	lld* now = a;
	if (now[ln - PW10] <= val) now += ln - PW10;
	if (now[PW9] <= val) now += PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef10(lld val) {
	lld* now = a;
	if (now[ln - PW9] <= val) now += ln - PW9;
	if (now[PW8] <= val) now += PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef9(lld val) {
	lld* now = a;
	if (now[ln - PW8] <= val) now += ln - PW8;
	if (now[PW7] <= val) now += PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef8(lld val) {
	lld* now = a;
	if (now[ln - PW7] <= val) now += ln - PW7;
	if (now[PW6] <= val) now += PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef7(lld val) {
	lld* now = a;
	if (now[ln - PW6] <= val) now += ln - PW6;
	if (now[PW5] <= val) now += PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef6(lld val) {
	lld* now = a;
	if (now[ln - PW5] <= val) now += ln - PW5;
	if (now[PW4] <= val) now += PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef5(lld val) {
	lld* now = a;
	if (now[ln - PW4] <= val) now += ln - PW4;
	if (now[PW3] <= val) now += PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef4(lld val) {
	lld* now = a;
	if (now[ln - PW3] <= val) now += ln - PW3;
	if (now[PW2] <= val) now += PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef3(lld val) {
	lld* now = a;
	if (now[ln - PW2] <= val) now += ln - PW2;
	if (now[PW1] <= val) now += PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef2(lld val) {
	lld* now = a;
	if (now[ln - PW1] <= val) now += ln - PW1;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
int ef1(lld val) {
	lld* now = a;
	if (now[PW0] <= val) now += PW0;
	if (now[PW0] <= val) now += PW0;
	return now - a;
}
struct _Main {
int (*ef) (lld val);
int n;
lld m;
lld cst[45];
lld sum;
int cnt;
void calc(lld *res, int now, int r) {
	if (now > r) {
		res[++cnt] = sum;
		return;
	}
	calc(res, now + 1, r);
	if (sum + cst[now] <= m) {
		sum += cst[now];
		calc(res, now + 1, r);
		sum -= cst[now];
	}
}
	_Main() {
		a = a1; b = a2;
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			read(cst[i]);
			if (cst[i] > m) {
				--i; --n;
			}
		}
		if (n <= 1) {
			printf("%d", n + 1);
			return;
		}
		calc(a, 1, n >> 1);
		ln = cnt;
		cnt = 0;
		calc(b, (n >> 1) + 1, n);
		rn = cnt;
		cnt = 0;
		if (ln < rn) {
			swap(ln, rn);
			swap(a, b);
		}
		sort(a + 1, a + ln + 1);
		int base;
		for (base = 0; 1 << base < ln; ++base);
		if (base == 1) {
			ef = ef1;
		} else
		if (base == 2) {
			ef = ef2;
		} else 
		if (base == 3) {
			ef = ef3;
		} else 
		if (base == 4) {
			ef = ef4;
		} else 
		if (base == 5) {
			ef = ef5;
		} else 
		if (base == 6) {
			ef = ef6;
		} else
		if (base == 7) {
			ef = ef7;
		} else 
		if (base == 8) {
			ef = ef8;
		} else 
		if (base == 9) {
			ef = ef9;
		} else 
		if (base == 10) {
			ef = ef10;
		} else 
		if (base == 11) {
			ef = ef11;
		} else
		if (base == 12) {
			ef = ef12;
		} else 
		if (base == 13) {
			ef = ef13;
		} else 
		if (base == 14) {
			ef = ef14;
		} else 
		if (base == 15) {
			ef = ef15;
		} else 
		if (base == 16) {
			ef = ef16;
		} else
		if (base == 17) {
			ef = ef17;
		} else 
		if (base == 18) {
			ef = ef18;
		} else 
		if (base == 19) {
			ef = ef19;
		} else 
		if (base == 20) {
			ef = ef20;
		} 
		lld ans = 0;
		for (int i = 1; i <= rn; i++) {
			ans += ef(m - b[i]);
		}
		printf("%lld", ans);
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}std;
}
