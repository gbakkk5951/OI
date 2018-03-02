using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {







char buf[100050];
int match(int l1, int r1, int l2, int r2) {
	int i;
	for (i = 0; l1 + i <= r1 && l2 + i <= r2; i++) {
		if (buf[l1 + i] != buf[l2 + i]) {
			break;
		}
	}
	return i;
}

struct _Main {
_Main() {

	int n, m;
	scanf("%d%d%s", &n, &m, buf);
	int i, j, k;
	int Q, Qn = m;
	int a, b, c, d;
	for (Q = 1; Q <= Qn; Q++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a--; b--; c--; d--;
		int ans = 0;
		int i;
		for (i = a; i <= b; i++) {
			ans = max(ans, match(i, b, c, d));
		}
		printf("%d\n", ans);
	}
}
}brute;

}

