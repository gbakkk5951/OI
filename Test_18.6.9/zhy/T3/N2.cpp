using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 1e6 + 10;
struct _Main {
	int n, tot;
	int oil[MXN], dis[MXN];
	lld mnv[MXN];
	lld sum[MXN];
	_Main() {
		read(n); read(tot);
		for (int i = 1; i <= n - 1; i++) {
			read(dis[i]);
		}
		for (int i = 1; i <= n; i++) {
			read(oil[i]);
		}
		for (int i = n - 1; i >= 1; i--) {
			sum[i] = sum[i + 1] + dis[i];
		}
		for (int i = n - 1; i >= 1; i--) {
			mnv[i] = min((lld)dis[i] - oil[i + 1], mnv[i + 1] + dis[i] - oil[i + 1]);
		}
		for (int i = 1; i <= n; i++) {
			int ans = i;
			lld rem = tot;
			lld storge = 0, mxdis = 0;
			if (sum[i] * 2 - min((lld)oil[i], sum[i]) - min((lld)oil[n], sum[i]) <= tot) {
				printf("%d ", n);
				continue;
			}
			for (int j = i + 1; j <= n; j++) {
				storge += oil[j - 1];
				if (dis[j - 1] > storge) {//在j-1处放油
					rem -= dis[j - 1] - storge;
					mxdis -= dis[j - 1] - storge;
					storge = 0;
				} else {//不放油
					storge -= dis[j - 1];
				}
				mxdis = max(0LL, mxdis) + dis[j - 1] - oil[j];
				if (rem < 0) break;
				if (mxdis <= rem) ans = j;
				if (mxdis + mnv[j] > rem) break;
			}
			printf("%d ", ans);
		}
		
		
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
}N2;
}
