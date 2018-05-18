using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cmath>
namespace OI {
typedef double lf;
const int MXN = 10010, MXM = 200010;
const int WS = 0, ES = 1, XISHU = 2, DP = 3;
const int DST = 0, NXT = 1, VAL = 2;
int eidx;
int head[MXN], edge[MXM][3];
int out[MXN], in[MXN];
lf data[MXN][4];
lf delta;
int cnt[MXN];
int n, m;


void add(int a, int b, int c) {
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][VAL] = c;
	edge[eidx][NXT] = head[a];
	head[a] = eidx;
	if (c) {
		out[a]++;
		in[b]++;
	}
}
void topo1(int nd) {
	out[nd] = -1;
	int t;
	lf w;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if (edge[e][VAL]) {
			w = edge[e][VAL];
			t = edge[e][DST];
			data[nd][WS] += w;
			data[nd][ES] += w * data[t][DP];
			cnt[nd]++;
		}
	}
	if (cnt[nd]) {
		data[nd][DP] = 1.0 + data[nd][ES] / data[nd][WS];	
	} 
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if (edge[e][VAL] == 0) {
			t = edge[e][DST];
			if (--out[t] == 0) {
				topo1(t);
			}
		}
	}
	
}

void topo2(int nd) {
	int t;
	lf w;
	in[nd] = -1;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if (edge[e][VAL]) {
			w = edge[e][VAL];
			t = edge[e][DST];
			if (cnt[nd] > 1)  {
				delta = max(delta, data[nd][XISHU] * ((data[nd][ES] - w * data[t][DP]) /
													 (data[nd][WS] - w) 
													 + 1.0 - data[nd][DP]));
			}
			data[t][XISHU] += data[nd][XISHU] * w / data[nd][WS]; //Õ¸¡Àcheng xishu[nd] 
			if (--in[t] == 0) {
				topo2(t);
			}
		}
	}
}
struct _Main {
	_Main() {
		read(n); read(m);
		int a, b, c;
		for (int i = 1; i <= m; i++) {
			read(a); read(b); read(c);
			if (b == 0) continue;
			add(a, b, c); add(b, a, 0);
		}
		for (int i = 0; i < n; i++) {
			if (out[i] == 0 && head[i]) {
				topo1(i);
			}
		}
		data[0][XISHU] = 1.0;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0 && head[i]) {
				topo2(i);
			}
		}
		printf("%.6lf", round((data[0][DP] + delta) * 1e6) / 1e6);
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
}T2;
}
