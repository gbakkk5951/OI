using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <queue>
namespace OI {
typedef long long lld;
const int MXN = 1e5 + 10;
const int DST = 0, NXT = 1, VAL = 2;
struct _Main {
	int n;
	int dis[MXN];
	int head[MXN];
	int edge[MXN * 2][3];//every pair of relation for 2 edge /*and every none zero for 1 edge*/
	int eidx;
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	char inq[MXN];
	int cnt[MXN];
	lld spfa() {
		queue<int> q;
		fill(dis + 1, dis + n + 1, 1);
		int nd, t;
		for (int i = 1; i <= n; i++) {
			if (cnt[i]) continue; 
			q.push(i);
			while (!q.empty()) {
				nd = q.front();
				inq[nd] = 0;
				q.pop();
				for (int e = head[nd]; e; e = edge[e][NXT]) {
					t = edge[e][DST];
					if (dis[t] < dis[nd] + edge[e][VAL]) {
						dis[t] = dis[nd] + edge[e][VAL];
						if (++cnt[t] == n) return -1;
						if (!inq[t]) {
							q.push(t);
							inq[t] = 1;
						}
					}
				}
			}
		
		}
		lld ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += dis[i];
		}
		return ans;
	}
	
	_Main() {
		int m;
		int op, a, b;
		read(n); read(m);
		for (int i = 1; i <= m; i++) {
			read(op); read(a); read(b);
			if (op == 1) { //equal
				add(a, b, 0); add(b, a, 0);
			} else
			if (op == 2) {//less
				add(a, b, 1);
			} else
			if (op == 3) {//greater equal
				add(b, a, 0);
			} else
			if (op == 4) {//greater
				add(b, a, 1);
			} else
			if (op == 5) {//less equal
				add(a, b, 0);
			}
		}
		//there's no need to do this; just assign the dis to 1
		/*for (int i = 1; i <= n; i++) {
			add(0, i, 1);
		}*/
		printf("%lld", spfa());
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
}bzoj2330;
}
