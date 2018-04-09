using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <algorithm>
const int MXN = 1000010;
namespace OI {
struct _Main {

int log[MXN];
int str[MXN];
int r[MXN];
int st[MXN][20];
int pow;
int n;
void manacher() {
	int k = 0, mr = 0, nl, nr;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i >= j && i + j < n && str[i - j] == str[i + j]; j++) {
			r[i] = j;
		}
	}
}
void getst() {
	for (pow = 0; (1 << pow + 1) <= n; pow++);
	for (int i = 0; i < n; i++) st[i][0] = r[i];
	for (int I = 1; I <= pow; I++) {
		for (int i = 0; i < n; i++) {
			st[i][I] = st[i][I - 1];
			if (i + (1 << I - 1) < n) {
				st[i][I] = max(st[i][I], st[i + (1 << I - 1)][I - 1]);
			}
		}
	}
}
void getlog() {
	log[1] = 0;
	int now = 0;
	for (int i = 2; i <= n; i++) {
		if (i == 1 << now + 1) {
			now++;
		}
		log[i] = now;
	}
}
int inline query(int l, int r) {
//	printf("act [%d, %d]\n", l, r);
	int pow = log[r - l + 1];
	return max(st[l][pow], st[r - (1 << pow) + 1][pow]);
}
_Main() {
	int Qn;
	read(n); read(Qn);
	n += n + 1;
	for (int i = 1; i < n; i += 2) {
		read(str[i]);
	}
	manacher();
	/*
	for (int i = 0; i < n; i++) {
		printf("%2d ", str[i]);
	}
	printf("\n");
	for (int i = 0; i <= n; i++) {
		printf("%2d ", r[i]);
	}
	printf("\n");*/
	getst();
	getlog();
	int ql, qr, l, r, mid;
	for (int Q = 1; Q <= Qn; Q++) {
		read(ql); read(qr);
		l = 1, r = (qr - ql + 1);//ÐÂ´®»ØÎÄ°ë¾¶ 
		while (l < r) {
			mid = (l + r >> 1) + 1;
//			printf("real [%d, %d]\n", ql + mid - 1, qr - mid + 1);
			if (query((ql << 1) - 1 + mid - 1, (qr << 1) - 1 - mid + 1) >= mid) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		printf("%d\n", l);
	}
}
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
}dloj1003;
}
