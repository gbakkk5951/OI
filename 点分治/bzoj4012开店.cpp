using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <pair>
namespace OI {
typedef pair<int, int> p;

const int DST = 0, NXT = 1, VAL = 2;
const int MXN = 150005;


struct _Main {
	
	vector<p> root[MXN];
	int cho, val;
	void findroot() {
		
	}
	
	
	_Main() {
		int n, Qn, A, a, b, c, u, ans = 0;
		read(n); read(Qn); read(A);
		for (int i = 1; i <= n; i++) {
			read(age[i]);
		}
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
		}
		init();
		for (int Q = 1; Q <= Qn; Q++) {
			read(u); read(a); read(b);
			a = (a + ans) % A; b = (b + ans) % A;
			if (a > b) swap(a, b);
			ans = query(a, b);
			printf("%d\n", ans);
		}
	}
	
	int head[MXN];
	int edge[MXN << 1][3];
	int age[MXN];
	int eidx;
	
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		head[a] = eidx;
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
}bzoj4012;
}
