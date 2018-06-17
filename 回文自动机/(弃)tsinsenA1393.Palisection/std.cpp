using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
namespace OI {
typedef long long lld;
const int MXN = 2e6 + 107;
struct Node {
	Node *s[26], *fail;
	int h, len;
}pool[MXN << 1];

struct 

struct _Main {
	int n;
	char str[MXN];
	int num[MXN];
	
	_Main() {
		read(n);
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++) {
			org.insert(str[i] - 'a');
		}
		for (int i = n; i >= 1; i--) {
			rev.insert(str[i] - 'a');
		}
		for (int i = 1; i <= n; i++) {
			sum += org.node[i]->h;
		}
		ans = sum * (sum - 1) >> 1;
		sum = 0;
		for (int i = 2; i <= n; i++) {
			sum += org.h[i - 1];
			ans -= sum * org.node[n - i + 1]->h;
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
	}//AC
};
}
//卡空间，不可做（哪怕32位系统+垃圾回收）
