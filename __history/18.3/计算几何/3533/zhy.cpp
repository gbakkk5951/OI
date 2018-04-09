using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
namespace OI {
typedef long long lld;
typedef double lf;
const lf EPS = 1e-6;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 31 | INF;
bool eq(lf a, lf b) {
	return fabs(a - b) < EPS;
}

struct P {
	lld x, y;
	bool operator < (const P &b) const {
		return eq(x, b.x) ? y < b.y : x < b.x;
	}
	P operator - (const P &b) const {
		P ret = *this;
		ret.x -= b.x; ret.y -= b.y;
		return ret;
	}
};
lld cross(P a, P b) {
//	printf("cross((%d, %d), (%d, %d)) = %lld\n", a.x, a.y, b.x, b.y, a.x * b.y - b.x * a.y);
	return a.x * b.y - b.x * a.y;
}

vector<P>arr;

void make_convex_hull(vector <P> &arr, vector <P> &hull, int &top) {
	hull.resize(arr.size());
	
	for (int i = 0; i < arr.size(); i++) {
		while (top >= 2 && 
			cross(arr[i] - hull[top - 1], hull[top - 1] - hull[top - 2]) <= 0) {
			top--;	
		}
		hull[top++] = arr[i];
	}	
	hull.resize(top);
}
const int 
	UP = 0,
	DOWN = 1
;
struct Node {
	vector<P> hull[2];
	lld mx_x, mx_y, mn_x, mn_y;
	int size[2];
	void merge(const Node &a, const Node &b) {
		mx_x = max(a.mx_x, b.mx_x);
		mx_y = max(a.mx_y, b.mx_y);
		mn_x = min(a.mn_x, b.mn_x);
		mn_y = min(a.mn_y, b.mn_y);
		for (int I = 0; I < 2; I ++) {
			arr.assign(a.hull[I].begin(), a.hull[I].end());
			arr.insert(arr.end(), b.hull[I].begin(), b.hull[I].end());
			sort(arr.begin(), arr.end());
			if (I == DOWN) for (int i = 0; i < arr.size() >> 1; i++) {
				swap(arr[i], arr[arr.size() - i - 1]);
			}						
			make_convex_hull(arr, hull[I], size[I] = 0);
			if (I == DOWN) for (int i = 0; i < hull[I].size() >> 1; i++) {
				swap(hull[I][i], hull[I][hull[I].size() - i - 1]);
			}
		}
	}
	lld ask(lld x, lld y) {
		
		if (x == 0) {
			return max(y * mn_y, y * mx_y);
		}
		if (y == 0) {
			return max(x * mn_x, x * mx_x);
		}
		lf rate = - (lf) x / y;
		int t = y > 0 ? UP : DOWN;
		int l = 0, r = size[t] - 1, mid;
		while (r - l >= 4) {
			mid = ((l + r) >> 1) + 1;
			P v1 = hull[t][mid] - hull[t][mid - 1];
			if (t == DOWN) {
				if ((lf) v1.y / v1.x > rate) {
					r = mid;
				} else {
					l = mid;
				}				
			} else {
				if ((lf) v1.y / v1.x < rate) {
					r = mid - 1;
				} else {
					l = mid;
				}	
			}
		}
		lld ans = -LINF;
		for (int i = l; i <= r; i++) {
//			printf("test (%lld, %lld)\n", hull[t][i].x, hull[t][i].y);
			ans = max(ans, x * hull[t][i].x + y * hull[t][i].y);
		}
		return ans;
	}
	
};

class Tree {
public:
	Node node[1050000];
	int base;
	void init(int n) {
		for (base = 1; base < n + 2; base <<= 1);
	}
	void insert(int pos, lld x, lld y) {
		int nd = pos + base;
		for (int I = 0; I < 2; I++) {
			node[nd].hull[I].push_back((P){x, y});
			node[nd].size[I] = 1;
		}
		node[nd].mx_x = node[nd].mn_x = x;
		node[nd].mx_y = node[nd].mn_y = y;
		while ((nd & 1) && (nd >>= 1)) {
			node[nd].merge(node[nd << 1], node[nd << 1 | 1]);
		}
	}
	lld query(int s, int t, lld x, lld y) {
		lld ans = -LINF;
		for (s = s + base - 1, t = t + base + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
			if (~s & 1) ans = max(ans, node[s ^ 1].ask(x, y));
			if ( t & 1) ans = max(ans, node[t ^ 1].ask(x, y));
		}
		return ans;
	}
}tree;

lld lstans;
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
		a ^= (lstans & 0x7fffffffu);
	}
struct _Main {
	int n;
	char buf[5];
	_Main() {
		int Qn, Q;
		int idx = 1;
		int d = 0;
		int x, y, l, r;
		lld ans;
		read(Qn); scanf("%s", buf);
		d = buf[0] != 'E';
		tree.init(Qn);
		for (Q = 1; Q <= Qn; Q++) {
			scanf("%s", buf);
			read(x); read(y);
			if (buf[0] == 'A') {
				tree.insert(idx++, x, y);
			} else {
				read(l); read(r);
				if (l > r || l <= 0 || r >= idx) return;
				ans = tree.query(l, r, x, y);
				printf("%lld\n", ans);
				if (d) lstans = ans;
			}
		}
		/*
		for (int i = tree.base * 2 + 2; --i; ) {
			printf("\n\ni = %d", i);
			for (int I = 0; I < 2; I++) {
				if (I == 0) printf("\nUP : ");
				else printf("\nDOWN : ");
				for (int j = 0; j < tree.node[i].hull[I].size(); j++) {
					printf("%lld %lld, ",tree.node[i].hull[I][j].x, tree.node[i].hull[I][j].y);
				}
			}
		}
		*/
	}
	
}bzoj3533;

}
