using namespace std;
int main() {}
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
namespace OI {
const int MXN = 100010;
struct _Main {
	int cnt[MXN];
	_Main() {
		int n, k, a, mx = 0, brk = 0;
		read(n); read(k);
		for (int i = 1; i <= n; i++) {
			read(a); cnt[a]++;
			mx = max(mx, a);
		}
		for (int i = 1; i <= mx; i++) {
			if (brk) {
				cnt[max(0, i - k)] += cnt[i];
			} else 
			if (cnt[i] == 0) {
				if (i + k <= mx && cnt[i + k]) {
					cnt[i]++; cnt[i + k]--;
				} else {
					brk = 1;
				}
			}
		}
		int tms = 1, amt = cnt[0];
		for (int i = 1; i <= mx; i++) {
			if (cnt[i]) {
				tms++;
				amt += cnt[i];
			} else {
				break;
			}
		}
		printf("%d %d", amt, tms);
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
}A;
}
