using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
namespace OI {
const int MXN = 256;
struct _Main {
	char c[5][MXN];
	char str[MXN];
	_Main() {
		int n;
		scanf("%d", &n);
		int len;
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			len = strlen(str);
			++c[len][str[len - 1]];
		}
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			len = strlen(str);
			--c[len][str[len - 1]];
		}
		int ans = 0;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < MXN; j++) {
				ans += c[i][j] > 0 ? c[i][j] : 0;
			}
		}
		printf("%d", ans);
		
	}
}std;
}
