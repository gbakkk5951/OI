using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
const int INF = 0x3f3f3f3f;
struct _Main {
	char map[25][25];
	int n, m;
	int mxlen;
	queue<int>q[2];
	char cnt[512];
	int dp[25][25][512];
	int com(int x, int y, int s) {
		return x << 14 | y << 9 | s;
	}
	int decom(int hash, int &x, int &y, int &s) {
		s = hash & 511;
		y = hash >> 9 & 31;
		x = hash >> 14;
	}
	void calc() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != -1) {
					q[0].push(com(i, j, 1 << map[i][j]));
				}
			}
		}
		int x, y, s;
		for (it = 1; i <= cnt; i++) {
			while (!q[~it & 1].empty()) {
				if (it != cnt) {
					
				}
			}
			
		}
	}
	_Main() {
		while (1) {
			
		}
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
}chocolate;
}
