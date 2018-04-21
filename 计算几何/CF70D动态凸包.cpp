using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int ADD = 1, QUERY = 2; 
struct P {
	lld x, y;
	bool operator < (const P &b) const {
		if (x != b.x) {
			return x < b.x;
		}
		return y < b.y;
	}
	P operator - (const P &b) const {
		return (P) {a.x - b.x, a.y - b.y};
	}
	lld operator * (const P &b) const {
		return a.x * b.y - b.x * a.y;
	} 
};
typedef set<P>::iterator it;
struct Convex {
	int cnt;
	set <P> up, low;
	void insert(P val) {
		if (cnt < 2) {
			up.insert(P);
			low.insert(P);
			return;
		}
		//low
		it r = low.lower_bound(val);
		while (nxt(r) != low.end()) {
			
			r = low.lower_bound(val);
		}
		
		low.insert(P);
		//up
		
		
		
	}
	inline it pre(it a) {
		return --a;
	}
	inline it nxt(it a) {
		return ++a;
	}
	char left(P a, P b) { // if a is at left of b
		return a * b < 0;
	}
	char ask(P val) {
		it r, l;
		//边界 low 和 up 的左右端点相等
		r = low.lower_bound(P);
		if (r == low.begin())  {
			if (*r != val) {
				return 0;
			} else {
				return 1;
			}
		}
		if (r == low.end()) {
			return 0;
		}
		// low	
		l = pre(r);
		if (left(*r - *l, val - *l)) {
			return 0;
		}
		// up
		r = up.lower_bound(P);
		l = pre(r);
		if (left(*r - *l, val - *l)) {
			return 0;
		}
		return 1;
	}
	
}convex;
struct _Main {
	_Main() {
		int Qn;
		int op;
		P a;
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(a.x); read(a.y);
			if (op == ADD) {
				tree.add(a);
			} else {
				if (tree.ask(a)) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			}
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
	
};
}
