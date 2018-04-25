using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
namespace OI {
const int ADD = 1, QUERY = 2;
struct P;
typedef long long lld;
typedef set<P>::iterator it;
struct P {
	lld x, y;
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
struct Convex {
	set<P> tree;
	inline it getpre(it a) {
		return --a;
	}
	inline it getnxt(it a) {
		return ++a;
	}
	void poppre(const P &nd, it pre) {
		it ppre;
		while (pre != tree.begin()) {
			ppre = getpre(pre);
			if ((nd - *pre) * (*pre - *ppre) <= 0) {
				tree.erase(pre);
				pre = ppre;
			} else {
				break;
			}
		}
		if (pre->x == nd.x) {
			tree.erase(pre);
		}
	}
	void popnxt(const P &nd, it nxt) {
		it nnxt = getnxt(nxt);
		while (nnxt != tree.end()) {
			if ((*nnxt - *nxt) * (*nxt - nd) <= 0) {
				tree.erase(nxt);
				nxt = nnxt;
				nnxt = getnxt(nxt);
			} else {
				break;
			}
		}
	}
	void insert(const P &nd) {
		it nxt = tree.lower_bound(nd);
		if (nxt != tree.end() && nxt->x == nd.x) return;
		it pre = nxt == tree.begin() ? tree.end() : getpre(nxt);
		if (nxt != tree.end() && pre != tree.end() 
			&& (*nxt - nd) * (nd - *pre) <= 0) {//共线或者在包内
			return;
		}
		if (pre != tree.end()) poppre(nd, pre);
		if (nxt != tree.end()) popnxt(nd, nxt);
		tree.insert(nd);
	}
	char isinside(const P &nd) {
		it nxt, pre;
		nxt = tree.lower_bound(nd);
		if (nxt != tree.end() && nxt->x == nd.x) return 1;
		pre = nxt == tree.begin() ? tree.end() : getpre(nxt);
		if (nxt != tree.end() && pre != tree.end() 
			&& (*nxt - nd) * (nd - *pre) <= 0) {//共线或者在包内
			return 1;
		}
		return 0;
	}
}up, low;
struct _Main {
	_Main() {
		int op, x, y;
		int Qn; 
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			read(op); read(x); read(y);
			if (op == ADD) {
				up.insert((P){x, y});
				low.insert((P){x, -y});
			} else {
				if (up.isinside((P){x, y}) && low.isinside((P){x, -y})) {
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
			a *= 10;
			a += t - '0';
		}
		a *= f;
	}
	
}CF70D;
}
