using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
const int base = 1900;
const int MAXN = 40000;
int id[103][12][31];
int lim[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int idx;
void initday(int &y, int &m, int &d) {
	d = 30, m = 11, y = -1;
}
void nxtday(int &y, int &m, int &d) {
	d++;
	if (d == lim[m]) {
		d = 0;
		m++;
		if (m == 12) {
			m = 0;
			y++;
			if ((y + base) % 4 == 0 && ((y + base) % 100 || (y + base) % 400 == 0)) {
				lim[1] = 29;
			} else {
				lim[1] = 28;
			}
		}
	}
}
bool isend(int &y, int &m, int &d) {
	if (y == 101 && m == 10 && d == 3) {
		return 1;
	}
	return 0;
}
void getid() {
	int y, m, d;
	initday(y, m, d);
	while (1) {
		nxtday(y, m, d);
		id[y][m][d] = ++idx;
		if (isend(y, m, d)) {
			break;
		}
	}
}
int eidx;
const int NXT = 1, DST = 0;
int edge[MAXN << 1][2];
int head[MAXN];
void add(int a, int b) {
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
}
void build_graph() {
	int y, m, d;
	initday(y, m, d);
	int lst = 0, now, t, cnt;
	while (1) {
		nxtday(y, m, d);
		now = id[y][m][d];
		if (lst) {
			add(lst, now);
			cnt++;
		}
		if (t = id[y + ((m == 11) ? 1 : 0)][(m + 1) % 12][d]) {
			add(now, t);
			cnt++;
		}
		if (isend(y, m, d)) {
			break;
		}
		lst = now;
	}
}
int vis[MAXN];
int val[MAXN];
void run(int nd = 1) {
	int i, t;
	vis[nd] = 1;
	val[nd] = 1;
	for (i = head[nd]; i; i = edge[i][NXT]) {
		if (!vis[t = edge[i][DST]]) {
			run(t);
		}
		val[nd] &= val[t];
	}
	val[nd] = !val[nd];
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
struct _Main {
	_Main() {
		int Qn, Q, d, m, y;
		getid();
		build_graph();
		run();
		read(Qn);
		for (Q = 1; Q <= Qn; Q++) {
			read(y); read(m); read(d);
			y -= base; m--; d--;
			if (val[id[y][m][d]]) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
}poj1082;

}

