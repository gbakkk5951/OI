using namespace std;
int main() {}
#include <cstdio>
namespace OI {

struct _Main {
	int val[25];
	_Main() {
		int n; int zero = 0;
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &val[i]);
			if (val[i] == 0) {
				zero = 1;
			}
		}
		if ((n & 1) && zero == false) {
			printf("YES");
			return;
		}
		
		int l, r, i;
		for (i = 1; i <= n; i++) {
			if (val[i] == 1) {
				l = i;
				break;
			}
		}
		for (i = n; i >= 1; i--) {
			if (val[i] == 1) {
				r = i;
				break;
			}
		}
		if (i == 0 || ((l - 1) & 1) && ((n + 1 - r) & 1)) {
			printf("NO");
		} else {
			printf("YES");
		}
	}
}cdvs1037;
}
