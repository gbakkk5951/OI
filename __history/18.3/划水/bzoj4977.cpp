using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
namespace OI {
typedef long long lld;

const int MXN = 100010;
struct E {
	int am, sc;
};
struct C1 {//比敌弹
	bool operator () (const E &a, const E &b) {
		return a.am < b.am;
	}
};

struct C2 {//比分数
	bool operator () (const E &a, const E &b) {
		return a.sc - a.am < b.sc - b.am;
	}
};
priority_queue <E, vector<E>, C2> h1;
priority_queue <int, vector<int>, greater<int> > h2;
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
				ans += we[i];
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
