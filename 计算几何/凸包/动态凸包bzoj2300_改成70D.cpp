using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
namespace OI {
struct P;
typedef set<P>::iterator it;
typedef double lf;
typedef long long lld;
const lf EPS = 1e-6;
const int MXQ = 2e5 + 10, MXN = 1e5 + 10;
const int REMOVE = 1, QUERY = 2;
struct P {
	lld x, y, id;
	lld operator * (const P &b) const {
		return x * b.y - b.x * y;
	}
	P operator - (const P &b) const {
		return (P) {x - b.x, y - b.y};
	}
	bool operator < (const P &b) const {
		if (x != b.x) {
			return x < b.x;
		}
		return y < b.y;
	}
};
inline int pf(int a) {
	return a * a;
}
inline lf getdis(const P &a, const P &b) {
	return sqrt(pf(a.x - b.x) + pf(a.y - b.y));
}

struct Convex {
	lf length;
	lf l[MXN], r[MXN];
	set <P> tree;
	inline it getpre(it nd) {
		return nd == tree.begin() ? tree.end() : --nd;
	}
	inline it getnxt(it nd) {
		return ++nd;
	}
	void poppre(const P &nd, it pre) {
		it ppre;
		while (pre != tree.begin()) {
			ppre = getpre(pre);
			if ((nd - *pre) * (*pre - *ppre) <= 0) {
				length -= r[pre->id];
				tree.erase(pre);
				pre = ppre;
			} else {
				break;
			}
		}
		if (pre->x == nd.x) {
			length -= r[pre->id];
			tree.erase(pre);
		}
	}
	void popnxt(const P &nd, it nxt) {
		it nnxt;
		while ((nnxt = getnxt(nxt)) != tree.end()) {
			if ((*nnxt - *nxt) * (*nxt - nd) <= 0) {
				length -= l[nxt->id];
				tree.erase(nxt);
				nxt = nnxt;
			} else {
				break;
			}
		}
	}
	char isinside(const P &nd) {
		it nxt = tree.lower_bound(nd);
		if (nxt != tree.end() && nxt->x == nd.x) return 1; //Õ¸¡À≈–nxt == tree.end() 
		it pre = getpre(nxt);
		if (pre != tree.end() && nxt != tree.end()) {
			if ((*nxt - nd) * (nd - *pre) <= 0) {
				return 1;
			}
			length -= r[pre->id];
		}		
		return 0;
	}
	void insert(const P &nd) {
		it nxt = tree.lower_bound(nd);
		if (nxt != tree.end() && nxt->x == nd.x) return; //Õ¸¡À≈–nxt == tree.end() 
		it pre = getpre(nxt);
		if (pre != tree.end() && nxt != tree.end()) {
			if ((*nxt - nd) * (nd - *pre) <= 0) {
				return;
			}
			length -= r[pre->id];
		}
		if (pre != tree.end()) poppre(nd, pre);
		if (nxt != tree.end()) popnxt(nd, nxt);
		it now = tree.insert(nd).first;
		pre = getpre(now);
		nxt = getnxt(now);
		if (pre != tree.end()) {
			length += r[pre->id] = l[now->id] = getdis(*pre, *now);
		}
		if (nxt != tree.end()) {
			length += r[now->id] = l[nxt->id] = getdis(*nxt, *now);
		}
	}
	
	
}up, low;

struct _Main {
	_Main() {
		int n, m, a, b, Qn;
		int op, x, y;
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(op);
			read(x); read(y);
			if (op == 1) {
				up.insert((P){x, y, Q});
				low.insert((P){x, -y, Q});
			} else {
				if (up.isinside((P){x, y, Q}) && low.isinside((P){x, -y, Q})) {
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
}bzoj2300;
}
