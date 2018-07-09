using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <iostream>
namespace OI {
typedef long long lld;
const int MXN = 2e5 + 10;
struct _Main {
	lld srt[MXN << 1];
	lld l[MXN], r[MXN];
	int tag[MXN << 1];
	lld ans[MXN];
	_Main() {
		int idx = 0;
		int n;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(l[i]); read(r[i]);
			++r[i];
			srt[++idx] = l[i];
			srt[++idx] = r[i];
		}
		sort(srt + 1, srt + idx + 1);
		idx = unique(srt + 1, srt + idx + 1) - srt - 1;
		for (int i = 1; i <= n; i++) {
			l[i] = lower_bound(srt + 1, srt + idx + 1, l[i]) - srt;
			r[i] = lower_bound(srt + 1, srt + idx + 1, r[i]) - srt;
			++tag[l[i]]; --tag[r[i]];
		}
		lld now = 0;
		for (int i = 1; i <= idx - 1; i++) {
			now += tag[i];
			ans[now] += srt[i + 1] - srt[i];
		}
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
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
}std;
}
