using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
const int MXN = 100010;
int cnt[MXN];
int uniq[MXN];
int arr[MXN];
int out[MXN];
struct Num {
	int rk, cnt;
	bool operator < (const Num &b) const {
		return cnt < b.cnt;
	}
};
priority_queue <Num> heap;
struct _Main {
	_Main() {
		int n, mx;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		sort(arr + 1, arr + n + 1);
		memcpy(uniq + 1, arr + 1, n * sizeof(int));
		mx = unique(uniq + 1, uniq + n + 1) - uniq - 1;
		for (int i = 1; i <= n; i++) {
			arr[i] = lower_bound(uniq + 1, uniq + mx + 1, arr[i]) - uniq;
			cnt[arr[i]]++;
		}
		for (int i = 1; i <= mx; i++) {
			heap.push((Num){i, cnt[i]});
			if (cnt[i] > n + 1 >> 1) {
				printf("-1");
				return;
			}
		}
		Num nd; int idx = 1;
		for (int i = 1; i <= n; i++) {
			nd = heap.top();
			while (nd.cnt > n - i + 1 >> 1) {
				heap.pop();
				if (cnt[nd.rk] == nd.cnt) {
					out[i] = nd.rk;
					cnt[nd.rk]--;
				}
				nd.cnt = cnt[nd.rk];
				if (nd.cnt) heap.push(nd);
				if (!heap.empty()) nd = heap.top();
			}
			if (out[i] == 0) {
				while (cnt[idx] == 0) idx++;
				for (int j = idx; 1; j++) {
					if (cnt[j] && out[i - 1] != j) {
						out[i] = j;
						cnt[j]--;
						break;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", uniq[out[i]]);
		}
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
}hiho1356;

}

