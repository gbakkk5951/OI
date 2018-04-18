using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 200010;


struct _Main {
	
	int arr[MXN << 1];
	int n;
	lld ans;
	_Main() {
		freopen("counter.in", "r", stdin);
		freopen("brute.out", "w", stdout);
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		memmove(arr + n + 1, arr + 1, n * sizeof(int));
		for (int i = n; i <= n * 2 - 1; i++) {
			for (int j = i - 1; j >= i - n + 2; j--) {
				if (arr[j] < arr[i]) {
					for (int k = j - 1; k >= i - n + 1; k--) {
						ans += arr[k] < arr[j];
					}
				}
 			}
		}
		printf("%lld", ans);
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
}counter;

}


