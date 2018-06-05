using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
const int MXN = 1e5 + 10;
typedef pair<int, int> p;
priority_queue<p> hp[2];
int val[MXN];
int mark[MXN];
struct _Main {
	_Main() {
		int n, sum = 0, a, m, ans = 0, idx = 1;
		read(n); read(m);
		if (m == 0) {
			printf("0");
			return;
		}
		for (int i = 1; i <= n; i++) {
			read(a);
			if (a == 0) continue;
			if (a > 0 && sum >= 0 || a < 0 && sum <= 0) {
				sum += a;
			} else {
				++idx;
				if (sum > 0) {
					hp[1].push((p) {sum, idx});
				} else {
					val[idx] = sum;
				}
				sum = a;
			}
		}
		++idx;
		if (sum > 0) {
			hp[1].push((p) {sum, idx});
		} else {
			val[idx] = sum;
		}
		p nd;
		while (!hp[1].empty() && m--) {
			nd = hp[1].top();
			ans += nd.first;
			hp[1].pop();
			mark[nd.second] = 1;
			if (mark[nd.second - 2]) {
				hp[0].push((p) {val[nd.second - 1], nd.second - 1});
			}
			if (mark[nd.second + 2]) {
				hp[0].push((p) {val[nd.second + 1], nd.second + 1});
			}
		}
		int now = ans;
		while (!hp[1].empty() && !hp[0].empty()) {
			nd = hp[1].top();
			now += hp[1].top().first + hp[0].top().first;
			ans = max(ans, now);
			hp[1].pop(); hp[0].pop();
			mark[nd.second] = 1;
			if (mark[nd.second - 2]) {
				hp[0].push((p) {val[nd.second - 1], nd.second - 1});
			}
			if (mark[nd.second + 2]) {
				hp[0].push((p) {val[nd.second + 1], nd.second + 1});
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
