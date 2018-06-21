using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <bitset>
#include <cmath>
namespace OI {
typedef long long lld;
struct _Main {
	bitset<2000000010> vis;
	_Main() {
		freopen("rinascimento.in", "r", stdin);
		freopen("rinascimento.out", "w", stdout);
		lld l, r;
		read(l); read(r);
		if (r - l > 2000000000) return;
		int sq = ceil(sqrt(r));
		for (lld i = 2; i <= sq; i++) {
			for (lld j = i * i; j <= r; j *= i) {
				for (lld k = (l + j - 1) / j, t = k * j - l; t + l <= r && k < i; k++, t += j) {
					vis[t] = 1;
				}
				if (r / j < i) break;
			}
		}
		printf("%u", vis.count());
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
}rinascimento;
}
