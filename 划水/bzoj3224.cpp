using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int 
	INS = 1,
	DEL = 2,
	GETRK = 3,
	GETNUM = 4,
	PRE = 5,
	NXT = 6
;
struct _Main {
	_Main() {
		int Qn, op, x;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(x);
			if (op == INS) {
				tree.insert(x);
			} else 
			if (op == DEL) {
				tree.del(x);
			} else 
			if (op == GETRK) {
				printf("%d\n", tree.getrk(x));
			} else 
			if (op == GETNUM) {
				printf("%d\n", tree.getnum(x));
			} else 
			if (op == PRE) {
				printf("%d\n", tree.pre(x));
			} else 
			if (op == NXT) {
				printf("%d\n", tree.nxt(x));
			}
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
}bzoj3224;
}
