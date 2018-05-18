using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <algorithm>
namespace OI {
const int MXN = 50005;
struct _Main {
int sum[MXN];
int dp[MXN][2];
	_Main() {
		
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
}poj1738;
}
