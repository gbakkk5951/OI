
using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <functional>
int ans;
const int MXN = 205;
struct _Main {
	int arr[MXN];
	int n;
	int calc(int beg = 1, int now = 0) {
		for (int i = beg; i <= n; i++) {
			now = abs(now - arr[i]);
		}
		ans = max(ans, now);
		return now;
	}
	_Main() {
		int Tn, tmp, t1;
		
		read(Tn);
//		Tn = 5;
		srand(179915 ^ (unsigned long long) new char);
		for (int T = 1; T <= Tn; T++) {
			ans = 0;
//			n = 200;
			read(n);
			for (int i = 1; i <= n; i++) {
				read(arr[i]);
//				arr[i] = rand() % 1001 - 500;
			}		
			calc();	
			sort(arr + 1, arr + n + 1);
			calc();
			sort(arr + 1, arr + n + 1, greater<int>());
			calc();			
			int g;
			if (n <= 50) {
				g = 500 - n * 3;
			} else {
				g = 60 / Tn;
			}
			for (int i = 1; i <= g; i++) {
				for (int j = 2; j <= n; j++) {
					swap(arr[j], arr[rand() % j + 1]);
				}
				tmp = calc();
				int flag = 1;
				while (flag) {
					flag = 0;
					int now = 0;
					for (int j = 1; j <= n; j++) {
						for (int k = j + 1; k <= n; k++) {
							if (arr[j] != arr[k]) {
								swap(arr[j], arr[k]);
								t1 = calc(j, now);
								if (t1 > tmp) {
									tmp = t1;
									flag = 1;
								} else {
									swap(arr[j], arr[k]);
								}
							}
						}
						now = abs(now - arr[j]);
					}
				}
			}
			printf("Case #%d: %d\n", T, ans);
		}
	}
	
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f;
	}
}T2;
