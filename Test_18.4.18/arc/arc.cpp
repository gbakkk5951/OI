using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 1010;
const lld mod = 1e9 + 7;
int n;
struct ArrayTree {
	lld node[MXN];
	void add(int nd, int v) {
		for (; nd <= n; nd += nd & (-nd)) {
			node[nd] += v;
		}
	}
	lld query(int nd) {
		lld ret = 0;
		for (; nd; nd -= nd & (-nd)) {
			ret += node[nd];
		}
		return ret % mod;
	}
}tree;

struct _Main {
	
	int srt[MXN];
	int arr[MXN];
	lld ans;
	_Main() {
		freopen("arc.in", "r", stdin);
		freopen("arc.out", "w", stdout);
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		memcpy(srt + 1, arr + 1, n * sizeof(int));
		sort(srt + 1, srt + n + 1);
		for (int i = 1; i <= n; i++) {
			arr[i] = lower_bound(srt + 1, srt + n + 1, arr[i]) - srt;
		}
		for (int i = 1; i <= n; i++) {
			int lst = i;
			lld sum = 0;
			for (int j = i + 1; j <= n; j++) {
				if (arr[j] == arr[i]) {
					if (j != lst + 1) {
						sum += tree.query(j - 1) - tree.query(lst);
						sum %= mod;
					}
					ans += sum;
					ans %= mod;
					tree.add(j, 1);
					lst = j;
				}
			}
		}
		ans += ans < 0 ? mod : 0;
		printf("%lld", ans);
		fclose(stdout);
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
}arc;

}


