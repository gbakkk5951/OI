using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {

struct _Main {
	int dp[105][105];
	int psum[105];
	int sum(int l, int r) {
		return psum[r] - psum[l - 1];
	}
	_Main() {
		int n;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(psum[i]);
			psum[i] += psum[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			for (int l = 1, r = l + i - 1; l + i - 1 <= n; l++, r++) {
				dp[l][r] = sum(l, r) - min(dp[l + 1][r], dp[l][r - 1]);
			}
		}
		printf("%d %d", dp[1][n], sum(1, n) - dp[1][n]);
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
}jsk;
}
