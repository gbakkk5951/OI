using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
namespace OI {
typedef long long lld;
struct _Main {
	_Main() {
		lld sum = 0, ans = 0;
		int n = 50000; 
		for (int i = 1; i <= n; i++) {
			ans += (n / i) * sum;
			sum += (n / i);
		}
		printf("sum = %lld, ans = %lld", sum, ans);
	}
}couter;
}

