using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <queue>
namespace OI {
const int MXN = 1e5 + 10;

int l[MXN], r[MXN], val[MXN], mark[MXN], idx;
struct Cmp {
	bool operator () (int a, int b) {
		return val[a] > val[b];
	}
};

void cut(int a) {
	if (a != 0) {
		l[r[a]] = l[a];
		r[l[a]] = r[a];
		mark[a] = 1;
	}
}
void link(int a) {
	l[a] = a - 1;
	r[a - 1] = a;
}
priority_queue<int, vector<int>, Cmp> hp;
struct _Main {
	int n, m;
	_Main() {
		int a, sum = 0, used = 0, ans = 0;
		read(n); read(m);
		if (m == 0) {
			printf("0");
			return;
		}
		for (int i = 1; i <= n; i++) {
			read(a);
			if (a == 0) continue;
			if (a < 0 && sum <= 0 || a > 0 && sum >= 0) {
				sum += a;
			} else {
				if (sum > 0) {
					val[++idx] = sum;
					hp.push(idx);
					++used;
					ans += sum;
					link(idx);
				} else {
					if (idx != 0) {
						val[++idx] = -sum;
						hp.push(idx);
						link(idx);
					}
				}
				sum = a;
			}
		}
		if (sum > 0) {
			val[++idx] = sum;
			hp.push(idx);
			++used;
			ans += sum;
			link(idx);
		}
		if (idx == 0) {//没有正数
			printf("0");
			return;
		} 
		int nd;
		while (used-- > m) {
			do {
				nd = hp.top();
				hp.pop();
			} while (mark[nd]);
			ans -= val[nd];
			val[nd] = val[l[nd]] + val[r[nd]] - val[nd];
			if (l[nd] && r[nd]) {
				hp.push(nd);	
				cut(l[nd]);
				cut(r[nd]);
			} else {
				mark[nd] = 1;
				cut(l[nd]);
				cut(r[nd]);
				cut(nd);
			}
		}
		printf("%d", ans);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
