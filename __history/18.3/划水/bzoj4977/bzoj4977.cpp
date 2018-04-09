#pragma GCC optimize(2)
using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>

namespace OI {
typedef long long lld;

const int MXN = 100010;
struct E {
	int am, sc;
};
struct C1 {//比敌弹
	char inline operator () (const E &a, const E &b) {
		return a.am < b.am;
	}
};

struct C2 {//比分数 大根 
	char inline operator () (const E &a, const E &b) {
		return a.sc - a.am < b.sc - b.am;
	}
};

struct C3 {//比分数 小根 
	char inline operator () (const E &a, const E &b) {
		return a.sc - a.am > b.sc - b.am;
	}
};
template <typename Type, typename CMP>
class Heap {
public:
	CMP cmp;
	Type node[MXN];
	int n;
	inline const Type & top() {
		return node[1];
	}
	
	void swim(int nd) {
		while (nd > 1 && cmp(node[nd >> 1], node[nd])) {
			swap(node[nd >> 1], node[nd]);
			nd >>= 1;
		}
	}
	void sink(int nd) {
		int chose;
		while ((chose = nd << 1) <= n) {
			chose = chose | ((chose | 1) <= n && cmp(node[chose], node[chose | 1]));
			if (cmp(node[nd], node[chose])) {
				swap(node[nd], node[chose]);
				nd = chose;
			} else {
				break;
			}
		}
	}
	
	inline char empty() { //神tm empty写WA了 
		return n == 0;
	}
	
	inline void push(const Type &a) {
		node[++n] = a;
		swim(n);
	}
	inline void pop() {
		swap(node[1], node[n--]);
		sink(1);
	}
};

Heap<E, C2>h1;
Heap<int, greater<int> >h2;
Heap<E, C3>h3;

struct _Main {
	int we[MXN];
	char use[MXN];
	E en[MXN];
	_Main() {
		lld ans = 0;
		int n, m, idx;
		read(n); read(m);
		for (int i = 1; i <= n; i++) {
			read(we[i]);
		}
		for (int i = 1; i <= m; i++) {
			read(en[i].am); read(en[i].sc);
		}
		sort(we + 1, we + n + 1);
		sort(en + 1, en + m + 1, C1());
		for (int i = 1, idx = 0; i <= n; i++) {
			while (idx + 1 <= m && en[idx + 1].am < we[i]) {
				h1.push(en[++idx]);
			}
			if (!h1.empty()) {
				ans += we[i] + h1.top().sc - h1.top().am;
				use[i] = 1;
				h3.push(h1.top());
				h1.pop();
				h2.push(we[i]);
			}
		}
		for (int i = n; i >= 1; i--) {
			if (!use[i]) {
				if (h2.empty() || h2.top() >= we[i]) {
					break;
				}
				ans -= h2.top();
				h2.pop();
				h2.push(we[i]);
				ans += we[i];
			}
		}
		while (!h3.empty()) { // 这种情况没考虑 
			if (h3.top().sc - h3.top().am < - h2.top()) {
				ans -= h3.top().sc - h3.top().am + h2.top();
				h3.pop(); h2.pop();
			} else {
				break;
			}
		}
		printf("%lld", ans);
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
}bzoj4977;
}
