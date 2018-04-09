using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
const int MXN = 20010;
const int DST = 0, NXT = 1, VAL = 2;
struct NDC {
	int head[MXN], edge[MXN << 1][3];//[3]写成[2]了 
	int eidx;
	void add(int src, int dst, int val) {
		eidx++;
		edge[eidx][DST] = dst;
		edge[eidx][VAL] = val;
		edge[eidx][NXT] = head[src];
		head[src] = eidx;
	}
	int size[MXN];
	int tot;
	int mark[MXN];
	int chose, val;
	void getsize(int nd, int fa) {
		int mx = 0, t;
		size[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				getsize(t, nd);
				mx = max(mx, size[t]);
				size[nd] += size[t]; 
			}
		}
		mx = max(mx, tot - size[nd]);
		if (mx < val) {
			val = mx;
			chose = nd;
		}
	}
	int nowcnt[3];
	void getdeep(int nd, int fa, int dis) { //顺便求size
		nowcnt[dis]++;
		int t;
		size[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				getdeep(t, nd, (dis + edge[e][VAL]) % 3);
				size[nd] += size[t];
			}
		}
	}
	int ans;
	int cnt[3];
	void calc(int nd, int _tot) {
	
		ans++;//自己
		if (_tot == 1) return;
		tot = _tot;
		val = 1e9;//没赋初值 
		getsize(nd, 0);
		nd = chose;
		mark[nd] = 1;
		memset(cnt, 0, sizeof(cnt));
		cnt[0]++;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t]) {
				memset(nowcnt, 0, sizeof(nowcnt));
				getdeep(t, nd, edge[e][VAL] % 3); //顺便求size
				for (int i = 0; i < 3; i++) {
					ans += cnt[i] * nowcnt[i ? 3 - i : i] * 2;//有顺序 
					cnt[i] += nowcnt[i];
				}
			}
		}
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t]) {
				calc(t, size[t]);
			}
		}
	}
	
}ndc;
struct _Main {
	int n;
	int gcd (int a, int b) {
		return b ? gcd(b, a % b) : a;
	}
	void prepro() {
		int a, b, c;
		read(n);
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			ndc.add(a, b, c);
			ndc.add(b, a, c);
		}
	}
	void solve() {
		ndc.calc(1, n);
		int cnt, tot, g;
		cnt = ndc.ans;
		tot = n * n;
		g = gcd(tot, cnt);
		printf("%d/%d", cnt / g, tot / g);
	}
	_Main() {
		prepro();
		solve();
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while(!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
}bzoj2152; 
}
