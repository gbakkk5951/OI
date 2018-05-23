using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <algorithm>
namespace OI {
const int MXN = 2e5 + 10;
struct _Main {
int sa[MXN];
int sum[MXN];
int str[MXN];
int ans[MXN];
	_Main() {
		int n, m, cho;
		read(n); read(m);
		for (int i = 1; i <= n + 1; i++) {
			read(str[i]); 
			cho = str[i] == 0 ? i : cho;
		}
		for (int i = 1; i <= n + 1; i++) {// n + 1
			sum[str[i]]++;
		}
		for (int i = 1; i <= m; i++) {
			sum[i] += sum[i - 1];
		}
		for (int i = n + 1; i >= 1; i--) {//循环顺序WA了; n + 1
			sa[sum[str[i]]--] = i;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", str[sa[cho]]);
			cho = sa[cho];
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
}bzoj4104;
}
