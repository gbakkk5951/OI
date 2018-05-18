using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>

namespace OI {
typedef long long lld;
const lld mod = 1e9 + 7;
multiset<int> st;
struct _Main {
	inline lld getnxt(lld lst, lld lstans) {
		return (1714636915 * lst + 1681692777) % mod * ((846930886 * lstans + 1804289383) % mod) % mod;
	}
	_Main() {
		lld lst, ans, n;
		lld ret = 0;
		multiset<int>::iterator it;
		read(n); read(lst);
		for (int i = 1; i <= n; i++) {
			if (st.count(lst)) {
				printf("got same\n");
			}
			st.insert(lst);
	//		printf("ins %lld\n", lst);
			it = st.begin();
			for (int j = 0; j < (i + 1 >> 1) - 1; j++) {
				it++;
			}
			ans = *it;
	//		printf("%lld\n", ans);
			ret ^= ans;
			lst = getnxt(lst, ans);
		}
		printf("%lld", ret);
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : 1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}mid;
}
