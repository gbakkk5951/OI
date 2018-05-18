using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = (1 << 13) + 11;
struct _Main {
	int dst[MXN], lst[MXN], now[MXN];
	int ans[14][MXN];
	_Main() {
		int pow, n, a, flag;
		while (1) {
			flag = 0;
			read(pow);
			if (pow == 0) break;
			n = 1 << pow;
			for (int i = 0; i < n; i++) {
				read(a);
				lst[a] = i;
			}
			for (int i = 0; !flag && i < pow >> 1; i++) {//分奇偶
				for (int j = 0; j < n; j += 2) {
					if ((lst[j] >> i & 1) && !(lst[j + 1] >> i & 1)) {//换
						ans[i][j >> 1] = 1;
					} else if (!(lst[j] >> i & 1) && (lst[j + 1] >> i & 1)) {//不换
						
					} else {
						flag = 1;
						break;
					}
				}
				if (flag) break;
				for (int )
			}
			if (!flag) for (int j = pow >> 1; j < pow; j++) {//比大小:
				
			}
			
			if (flag) {
				printf("-1\n");
			} else {
				for (int i = 1; i <= pow; i++) {
					for (int j = 0; j < n; j++) {
						printf("%d ", ans[i][j]);
					}
					printf("\n");
				}
			}
			
			printf("\n");
		}
		fclose(stdout);
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
}left;
}
