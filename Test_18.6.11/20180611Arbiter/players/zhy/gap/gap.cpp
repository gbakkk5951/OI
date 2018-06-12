using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
namespace OI {
const int MXN = 1e5 + 10;
const int SQ = 20;
struct _Main {
set<int>tree;
int getnear(int mndis, int val) {
	set<int>::iterator it = tree.lower_bound(val);
	if (it != tree.end()) {
		if (*it - val < mndis) {
			return *it;
		}
	}
	if (it != tree.begin()) {
		if (val - *(--it) < mndis) {
			return *it;
		}
	}
	return 0;
}
int getnearest(int val) {
	set<int>::iterator it = tree.lower_bound(val);
	int ret = 1e5 + 10;
	if (it != tree.end()) {
		ret = min(ret, *it - val);
	}
	if (ret && it != tree.begin()) {
		ret = min(ret, val - *(--it));
	}
	return ret;
}
int arr[MXN];
int n;
int h;
	_Main() {
		freopen("gap.in", "r", stdin);
		freopen("gap.out", "w", stdout);
		int Tn;
		int mn, ans, tmp, mxv, mnv, now;
		read(Tn);
		for (int T = 1; T <= Tn; T++) {
			ans = 0;
			read(n); read(mn);
			mxv = 0; mnv = 1e5;
			for (int i = 1; i <= n; i++) {
				read(arr[i]);
				mxv = max(mxv, arr[i]);
				mnv = min(mnv, arr[i]);
			}
			for (int i = 1; i <= SQ; i++) {//DDDL
				if ((mxv - mnv) / i + 1 < mn) break;
				tree.clear();
				h = 1;
				for (int j = 1; j <= n; j++) {
					do {
						tmp = getnear(i, arr[j]);//arr[j]不是j
						if (tmp) {
							do {
								tree.erase(arr[h]);
							} while (arr[h++] != tmp);
						}
					} while (tmp);
					tree.insert(arr[j]);
					if (tree.size() >= mn) {
						ans = max(ans, i * ((int)tree.size() - 1));
					}
				}
			}
			if ((mxv - mnv) / (SQ + 1) + 1 >= mn) for (int i = 1; i <= n; i++) {//分块
				now = 1e5 + 10;
				tree.clear();
				for (int j = i; j <= n; j++) {
					tmp = getnearest(arr[j]);
					if (tmp <= SQ) break;
					tree.insert(arr[j]);
					now = min(now, tmp);
					if (j - i + 1 >= mn) {
						ans = max(ans, (j - i) * now);
					}
				}
			}
			printf("%d\n", ans);
		}
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
}gap; 
}
