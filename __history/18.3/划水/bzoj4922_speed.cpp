#pragma GCC optimize(3)
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
}arr[MXN];
struct CMP {
	inline bool operator () (const A &a, const A &b) {
		int pos;
		if ((pos = a.r - a.l >= 0) != (b.r - b. l >= 0)) {
			return pos;
		}
		return pos ? a.l < b.l : a.r > b.r;		
	}
};

struct _Main {
	char str[MXN];
	int dp[MXN * MXN];
	int stk[MXN], top;
	int tot_len;
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
		tot_len += len;
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
		sort(arr + 1, arr + n + 1, CMP());
		getdp();
		printf("%d", dp[0]);
	}
	void getdp() {
		memset(dp + 1, 192, tot_len * sizeof(int));
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i].l <= arr[i].r) {
				for (int j = mx, t = mx - arr[i].l + arr[i].r; j >= arr[i].l; j--, t--) {
					dp[t] = max(dp[j] + arr[i].len, dp[t]);
				}				
				if (mx >= arr[i].l) {
					mx = max(mx, mx - arr[i].l + arr[i].r);
				}
			} else {
				for (int j = arr[i].l, t = arr[i].r; j <= mx; j++, t++) {
					dp[t] = max(dp[j] + arr[i].len, dp[t]);
				}
			}
		}
	}
}bzoj4922;
}
