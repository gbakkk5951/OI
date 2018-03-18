using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
namespace OI {
const int MXN = 100010;
struct M {
	int d, a, id;	
	bool operator < (const M &b) const {
		return a - d < b.a - b.d;
	}
}arr[MXN];
struct CMP {
	bool operator () (const M &a, const M &b) {
		if (a.d != b.d) return a.d < b.d;
		return a.a < b.a;
	}
}cmp;

int idx;
priority_queue<M> h_add;
priority_queue<M, vector<M>, CMP> h_dec;
struct _Main {
	int hp, n;
	void refresh() {
		while (idx <= n && arr[idx].d < hp) {
			h_add.push(arr[idx]);
			h_dec.push(arr[idx]);
			idx++;
		}
		while (!h_add.empty() && vis[h_add.top().id]) {
			h_add.pop();
		}
		while (!h_dec.empty() && vis[h_dec.top().id]) {
			h_dec.pop();
		}
	}
	int vis[MXN];
	int ans[MXN];
	int ans_idx;
template <typename Type>
	void pop(Type &heap) {
		M nd = heap.top();
		heap.pop();
		vis[nd.id] = 1;
		hp += nd.a - nd.d;
		ans[++ans_idx] = nd.id;
	}
	_Main() {
		read(n); read(hp);
		for (int i = 1; i <= n; i++) {
			read(arr[i].d); read(arr[i].a); arr[i].id = i;
		}
		sort(arr + 1, arr + n + 1, cmp);
		idx = 1;
		refresh();
		while (!h_add.empty() && h_add.top().a - h_add.top().d >= 0) {
			pop(h_add);
			refresh();
		}
		while (!h_add.empty()) {
			M a = h_add.top(), b = h_dec.top();
			if (a.id != b.id && hp + a.a - a.d > b.d) {
				pop(h_add);
			} else {
				pop(h_dec);
			}
			refresh();
		}

		if (idx > n && hp > 0) {
			printf("TAK\n"); 
			for (int i = 1; i <= ans_idx; i++) {
				printf("%d ", ans[i]);
			}
		} else {
			printf("NIE");
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
}bzoj3709;
}

