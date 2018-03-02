using namespace std;
int main() {}
#include <cstdio>
#include <algorithm>
#include <cstring>
namespace OI {
const int 
	DST = 0,
	NXT = 1
;
typedef long long lld;
typedef double lf;
struct Node {
	lf time, x;
	int a, b;
	bool operator < (const Node &b) const {
		if (time != b.time) {
			return time < b.time;
		}
		return x < b.x;
	}
}arr[1000];
		
struct _Main {
	lld x[20], v[20];
	int set[2000];
	int head[2000], edge[2000][2];
	int id[1000];
	int eidx;
	int top[20], bot[20];
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	void getSet(int nd) {
		for (int i = head[nd]; i; i = edge[i][NXT]) {
			int t;
			if (!set[t = edge[i][DST]]) {
				getSet(t);
			}
			set[nd] |= set[t];
		} 
	}
	int node() {
		static int idx = 1;
		return idx++;
	}
	int n;
	_Main() {
		freopen("infection.in", "r", stdin);
		freopen("infection.out", "w", stdout);
		int i, j, k;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%lld%lld", x + i, v + i);
			top[i] = node(); bot[i] = node();
		}
		
		int aidx =  0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (x[i] < x[j] && v[i] > v[j]) {
					lld time = (lf)(x[j] - x[i]) / (v[i] - v[j]);
					lld pos = x[i] + time * v[i];
					arr[aidx++] = (Node) {time, pos, i, j};
				}
			}
		}
		sort(arr, arr + aidx);
		for (i = 0; i < aidx; i++) {
			id[i] = node();
		}
		for (i = 0; i < n; i++) {
			int lst = top[i];
			for (j = 0; j < aidx; j++) {
				if (i == arr[j].a || i == arr[j].b) {
					add(lst, id[j]);
					lst = id[j];
				}
			}
			add(lst, bot[i]);
		}
		for (i = 0; i < n; i++) {
			set[bot[i]] = 1 << i;
		}
		for (i = 0; i < n; i++) {
			getSet(top[i]);
		}
		int ans = 0;
		for (int I = 0; I < 1 << n; I++) {
			int set = 0;
			for (i = 0; i < n; i++) {
				if (I & (1 << i)) {
					set |= this->set[top[i]];
				}
			}
			if (set == (1 << n) - 1) {
				ans++;
			}
		}
		
		printf("%d", ans);
		fclose(stdout);
	}
}infection;

}
