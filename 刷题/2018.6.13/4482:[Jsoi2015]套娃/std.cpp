using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
namespace OI {
typedef long long lld;
typedef pair<int, int> p;
const int MXN = 2e5 + 10;
struct _Main {
	int out[MXN], in[MXN], val[MXN];
	lld ans;
	int n;
	priority_queue<p> heap;
	p oa[MXN], ia[MXN];
	_Main() {
		read(n);
		for (int i = 1; i <= n; i++) {
			read(out[i]); read(in[i]); read(val[i]);
			ans += (lld)in[i] * val[i];
			oa[i] = (p) {out[i], i};
			ia[i] = (p) {in[i], i};
		}
		sort(oa + 1, oa + n + 1, greater<p>());
		sort(ia + 1, ia + n + 1, greater<p>());
		for (int i = 1, j = 1; i <= n; i++) {
			while (j <= n && ia[j].first > oa[i].first) {
				heap.push((p) {val[ia[j].second], ia[j].second});
				++j;
			}
			if (!heap.empty()) {
				ans -= (lld)heap.top().first * oa[i].first;
				heap.pop();
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
			a *= 10; a += t - '0';
		}
	}
}std;
}
