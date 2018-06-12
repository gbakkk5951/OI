using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MOD = 1e9 + 7;
struct Node {
	Node *s[2], *fail, *lst;
	int id;
}pool[2050];
int pidx;
inline Node *new_(int id) {
	Node *nd = &pool[pidx++];//忘了++
	nd->id = id;
	return nd;
}
int que[1015];
struct AC {
	Node *node[1015], *end, *root;
	int idx;
	AC() {
		end = new_(-1);
		node[0] = root = new_(0);
		root->lst = root;
	}
	void insert(char str[]) {
		int i;
		Node *nd = root;
		int c;
		for (i = 0; str[i + 1]; i++) {
			c = str[i] - '0';
			//不能-= 因为这里的str是引用
			if (!nd->s[c]) {
				++idx;
				nd->s[c] = node[idx] = new_(idx);
			} else
			if (nd->s[c] == end) {
				return;
			}
			nd->s[c]->lst = nd;
			nd = nd->s[c];
		}
		nd->s[str[i] - '0'] = end;
	}
	void build() {
		int h = 0, t = -1;
		Node *nd = root;
		for (int i = 0; i < 2; i++) {
			if (nd->s[i] == 0) {
				nd->s[i] = nd;
			} else
			if (nd->s[i] != end) {
				nd->s[i]->fail = nd;
				que[++t] = nd->s[i]->id;
			}
		}
		while (h <= t) {
			nd = node[que[h++]];
			for (int i = 0; i < 2; i++) {
				if (nd->fail->s[i] == end) {
					nd->s[i] = end;
					continue;
				}
				if (nd->s[i] == 0) {
					nd->s[i] = nd->fail->s[i];
				} else
				if (nd->s[i] != end) {
					nd->s[i]->fail = nd->fail->s[i];
					que[++t] = nd->s[i]->id;
				}
			}
		}
	}
	inline int lst (int id) {
		return node[id]->lst->id;
	}
	inline int operator () (int id, int ch) {
		return node[id]->s[ch]->id;
	}
}org, rev;
int q[2][100000], t[2];
int dp[2][1005][1005][2];//dp值为-1表示未入队
inline void decom(int hash, int &x, int &y, int &cnt) {
	x = hash >> 11;
	y = hash >> 1 & 1023;
	cnt = hash & 1;
}
inline int com(int x, int y, int cnt) {
	return x << 11 | y << 1 | cnt; 
}
int it;
void getdp(int n, char odd) {
	int *dst, ox, oy, on, ov, nx, ny, nn;
	memset(dp, -1, sizeof(dp));
	dp[it][0][0][0] = 1;
	q[it][++t[it]] = 0;
	for (int I = 1; I <= n; I++) {
		it ^= 1;
		t[it] = 0;
		for (int i = 1; i <= t[it ^ 1]; i++) {
			decom(q[it ^ 1][i], ox, oy, on);
			dst = dp[it ^ 1][ox][oy] + on;
			ov = *dst;
			*dst = -1;
			
			for (int j = 0; j < 2; j++) {
				if (!odd || I != n) nx = org(ox, j);
				else nx = ox;//忘了else
				ny = rev(oy, j);//写成org了
				nn = on + (nx == -1) + (ny == -1); 
				if (nn >= 2) continue;
				nx += nx == -1;
				ny += ny == -1;
				dst = dp[it][nx][ny] + nn;
				if (*dst == -1) {
					*dst = ov;
					q[it][++t[it]] = com(nx, ny, nn);
				} else {
					*dst += ov;
					*dst -= (*dst >= MOD) * MOD;
				}
			}
		}
	}
}
int getans() {
	lld ans = 0;
	int x, y, n;
	int *dst;
	for (int i = 1; i <= t[it]; i++) {
		decom(q[it][i], x, y, n);
		dst = dp[it][x][y] + n;
		if (n == 0) {
			ans += *dst;
			continue;
		}
		while (x != 0) {
			y = rev(y, x == org(org.lst(x), 1));
			if (y == -1) break;
			x = org.lst(x);
		}
		if (y != -1) ans += *dst;
	}
	return ans % MOD;
}
struct _Main {
	char str[35];
	int n, S;
	_Main() {
		freopen("string.in", "r", stdin);
		freopen("string.out", "w", stdout);
		int len;
		scanf("%d%d", &n, &S);
		for (int i = 1; i <= S; i++) {
			scanf("%s", str);
			len = strlen(str);
			org.insert(str);
			for (int j = 0; j < len >> 1; j++) {
				swap(str[j], str[len - j - 1]);//神Tm写成i了
			}
			rev.insert(str);
		}
		org.build();
		rev.build();
		getdp(n + 1 >> 1, n & 1);
		printf("%d", getans());
		fclose(stdout);
	}
}He_hala_string;
}
