using namespace std;
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <queue>
#include <functional>
struct chose {
	int astar;
	int nd;
	bool operator > (const chose &b) const {
		return astar > b.astar;
	}
};

int arr[31];
int n;
int legal(int end) {
	if (end <= 2) {
		return 1;
	}
	return (arr[end - 1] < arr[end]) == ((arr[1] < arr[2]) ^ (end & 1));
}
int ans;
priority_queue<chose, vector<chose>, greater<chose> >heap[31];
int astar(int nd) {
	nd = max(nd, 3);
	int cmp = arr[1] < arr[2];
	int cnt = 0;
	for (int i = nd; i <= n; i++) {
		if ((arr[i - 1] < arr[i]) != (cmp ^ (i & 1))) {
			cnt++;
		}
	}
	return cnt + 1 >> 1;
}
int tot;
void dfs(int nd, int rem) {
	if (ans <= tot) {
		return;
	}
	if (rem == 0 || nd == n) {
		for (int i = 3; i <= n; i++) {
			if (!legal(i)) {
				return;
			}
		}
		ans = tot;
		return;
	}
	
	if (legal(nd)) {
		dfs(nd + 1, rem);
	}
	for (int i = nd + 1; i <= n; i++) {
		swap(arr[nd], arr[i]);
		if (legal(nd)) {
			heap[nd].push((chose){astar(nd + 1), i});
		}
		swap(arr[nd], arr[i]);
	}
	while (!heap[nd].empty()) {
		int val = heap[nd].top().astar;
		int nd_ = heap[nd].top().nd;
		heap[nd].pop();
		if (val <= rem - 1) {
			swap(arr[nd], arr[nd_]);
			dfs(nd + 1, rem - 1);
			swap(arr[nd], arr[nd_]);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1 ; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	ans = 7;
	for (int i = 0; i <= n; i++) if(ans > i) {
		tot = i;
		dfs(1, i);
	}
	printf("%d\n", ans);
}
