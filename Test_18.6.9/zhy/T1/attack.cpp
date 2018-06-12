using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cctype>
namespace OI {
const int NXT = 1, FLOW = 2, DST = 0;
struct _Main {
int tot;
int n, m;
void dfs(int nd) {
	if (nd == n) {
		printf("%d\n", n);
		return;
	}
	int t;
	for (int e = head[nd]; e; e = edge[e][NXT]) {
		if (edge[e][FLOW]) {
			printf("%d ", nd);
			t = edge[e][DST];
			dfs(t);
			edge[e][FLOW]--;
			return;
		} else {
			head[nd] = edge[e][NXT];
		}
	}
}

	_Main() {
		freopen("attack.in", "r", stdin);
		freopen("attack.out", "w", stdout);
		int a, b, c;
		read(n); read(m);	
		for (int i = 1; i <= m; i++) {
			read(a); read(b); read(c);
			if (a == 1) tot += c;
			add(a, b, c);
		}
		for (int i = 1; i <= tot; i++) {
			dfs(1);
		}
		fclose(stdout);
	}
int eidx;
int head[(int)8e3 + 10];
int edge[(int)5e4 + 10][3];
void add(int a, int b, int c){
	eidx++;
	edge[eidx][DST] = b;
	edge[eidx][NXT] = head[a];
	edge[eidx][FLOW] = c;
	head[a] = eidx;
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
}attack;
}
