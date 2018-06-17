using namespace std;
int main() {}
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <vector>
namespace OI {
typedef long long lld;
typedef pair<int, int> p;
typedef vector<int>::iterator it;
const int MXN = 3e5 + 10;

lld ans;
struct _Main {
	char up;
	int mx;
	int n;
	int arr[MXN];
	void judge_task() {
		up = 1;
		for (int i = 1; i <= n; i++) {
			if (arr[i] < arr[i - 1]) {
				up = 0;
			}
			mx = max(mx, arr[i]);
		}
	}
	void sb4(int arr[], int n) {
		int pre = 0, pn = 0;
		ans += (n / 2LL + 1) * (n / 2LL) >> 1;
		for (int i = 1; i < n; i += 2) {
			if (arr[i] == arr[i + 1]) {
				if (arr[i] != pre) {
					pre = arr[i];
					pn = 0;
				}
				++pn;
				ans -= pn;
			} else {
				pn = 0;
			}
		}
	}
	void sb3(int arr[], int n) {
		for (int i = 1; i < n; i += 2) {
			ans += (arr[i + 1] - arr[i]) * (i + 1LL >> 1) * (n - i + 1LL >> 1);
		}
	}
	void sb12(int arr[], int n) {
		vector<p> srt;
		srt.push_back((p) {-1, -1});
		for (int i = 1; i <= n; i++) {
			srt.push_back((p) {arr[i], i});
		}
		sort(srt.begin(), srt.end());
		vector<int> v;
		v.push_back(0);
		v.push_back(n / 2 + 1);
		lld r_oddsum, r_evensum, l_oddsum, l_evensum, now;
		int pos;
		for (int i = 1; i <= n; i++) {
			r_oddsum = 0, r_evensum = 0, l_oddsum = 0, l_evensum = 0;
			
			pos = srt[i].second + 1 >> 1;
			now = lower_bound(v.begin(), v.end(), pos) - v.begin();
			
			if (v[now] != pos) {
				v.insert(v.begin() + now, pos);
				ans -= (lld)srt[i].first * (v[now] - v[now - 1]) * (v[now + 1] - v[now]);
				for (int j = now + 1; v[j] <= n >> 1; j++) {
					if ((j - now) & 1) {
						r_oddsum += v[j + 1] - v[j];
					} else {
						r_evensum += v[j + 1] - v[j];
					}
				}
				ans += (lld)srt[i].first * (v[now] - v[now - 1]) * r_oddsum;
				ans -= (lld)srt[i].first * (v[now] - v[now - 1]) * r_evensum;
				r_evensum += v[now + 1] - v[now];
				for (int j = now - 1; v[j] >= 1; j--) {
					if ((now - j) & 1) {
						l_oddsum += v[j] - v[j - 1];
					} else {
						l_evensum += v[j] - v[j - 1];
					}
				}
				ans += (lld)srt[i].first * l_oddsum * r_evensum;
				ans += (lld)srt[i].first * r_oddsum * l_evensum;
				ans -= (lld)srt[i].first * l_oddsum * r_oddsum;
				ans -= (lld)srt[i].first * l_evensum * r_evensum;
			} else {
				ans += (lld)srt[i].first * (v[now] - v[now - 1]) * (v[now + 1] - v[now]);
				for (int j = now + 1; v[j] <= n >> 1; j++) {
					if ((j - now) & 1) {
						r_evensum += v[j + 1] - v[j];
					} else {
						r_oddsum += v[j + 1] - v[j];
					}
				}
				ans += (lld)srt[i].first * (v[now] - v[now - 1]) * r_oddsum;
				ans -= (lld)srt[i].first * (v[now] - v[now - 1]) * r_evensum;
				r_oddsum += v[now + 1] - v[now];
				for (int j = now - 1; v[j] >= 1; j--) {
					if ((now - j) & 1) {
						l_oddsum += v[j] - v[j - 1];
					} else {
						l_evensum += v[j] - v[j - 1];
					}
				}
				ans += (lld)srt[i].first * l_oddsum * r_evensum;
				ans += (lld)srt[i].first * r_oddsum * l_evensum;
				ans -= (lld)srt[i].first * l_oddsum * r_oddsum;
				ans -= (lld)srt[i].first * l_evensum * r_evensum;
				v.erase(v.begin() + now);
			}
			
		}
	}
	_Main() {
		freopen("chanson.in", "r", stdin);
		freopen("chanson.out", "w", stdout);
		read(n);
		if (n == 1) {
			printf("0");
			fclose(stdout);
			return;
		}
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		judge_task();
		if (mx <= 1) {
			sb4(arr, n & -2);
			if (n > 2) sb4(arr + 1, (n - 1) & -2);
		} else
		if (up) {
			sb3(arr, n & -2);
			if (n > 2) sb3(arr + 1, (n - 1) & -2);
		} else {
			sb12(arr, n & -2);
			if (n > 2) sb12(arr + 1, (n - 1) & -2);
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
}chanson;
}
