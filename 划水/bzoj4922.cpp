using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
namespace OI {
const int MXN = 305;
struct A {
	int l, r, len; //l 表示左边的右括号数量， r表示右边的左括号数量
	bool operator < (const A &dst) const {
		int pos;
		if ((pos = r - l >= 0) != (dst.r - dst. l >= 0)) {
			return pos;
		}
		if (pos) {
			return l < dst.l;
		}
		return r > dst.r;
	}
	
}arr[MXN];
struct _Main {
	char str[MXN];
	int dp[2][MXN * MXN];
	int stk[MXN], top;
	void count(int id) {
		int len = strlen(str);
		top = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] == ')' && top && stk[top] == '(') {
				top--;
			} else {
				stk[++top] = str[i];
			}
		}
		int l, r;
		for (l = 0; l + 1 <= top && stk[l + 1] == ')'; l++);
		r = top - l;	
		arr[id].len = len;
		arr[id].l = l;
		arr[id].r = r;
	}

	int n;
	_Main() {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			count(i);
		}
		sort(arr + 1, arr + n + 1);
		getdp();
		printf("%d", dp[n & 1][0]);
	}
	void getdp() {
		memset(dp, 192, sizeof(dp));
		int now, lst, mx = 0;
		dp[0][0] = dp[1][0] = 0;
		for (int i = 1; i <= n; i++) {
			now = i & 1; lst = now ^ 1;
			memcpy(dp[now], dp[lst], (mx + 1) * sizeof(int));
			for (int j = arr[i].l, t = arr[i].r; j <= mx; j++, t++) {
				dp[now][t] = max(dp[lst][j] + arr[i].len, dp[now][t]);
			}
			if (mx >= arr[i].l) {
				mx = max(mx, mx - arr[i].l + arr[i].r);
			}
		}
	}
}bzoj4922;
}
