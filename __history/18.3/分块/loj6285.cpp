using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <cstdlib>

namespace OI {
const int MXN = 100005, SQ = 325, SQN = 325;
int n;
int arr[MXN], sorted[MXN], sum[SQN][MXN], ans[SQN][SQN];
int id[MXN], st[SQN], ed[SQN];
int now_ans, ans_cnt, cnt[MXN];
int getsq(int n) {
	return ceil(sqrt(n));
}
int getcnt(int a, int lid, int rid) {
	return cnt[a] + sum[rid][a] - sum[lid - 1][a];
}
void count(int l, int r, int lid, int rid) {
	int a;
	for (int i = l; i <= r; i++) {
		++cnt[arr[i]];
		a = getcnt(arr[i], lid, rid);
		if (a > ans_cnt || a == ans_cnt && arr[i] < now_ans) {
			now_ans = arr[i];
			ans_cnt = a;
		}
	}
}
void decount(int l, int r) {
	for (int i = l; i <= r; i++) {
		cnt[arr[i]]--;
	}
}
void init() {
	int sq = getsq(n);
	int idx = 1;
	for (int i = 1; i <= n; i++) {
		id[i] = idx;
		if (i % sq == 0) {
			ed[idx] = i;
			st[++idx] = i + 1;
		}
	}
	st[id[1]] = 1;
	ed[id[n]] = n;
	for (int i = 1; i <= id[n]; i++) {
		now_ans = n + 1;
		ans_cnt = 0;
		for (int j = i; j <= id[n]; j++) {
			count(st[j], ed[j], 1, 0);
			ans[i][j] = now_ans;
			if (i == 1) {
				memcpy(sum[j], cnt, (n + 1) * sizeof(int));
			}
		}
		decount(st[i], ed[id[n]]);
	}
	ans[1][0] = n + 1;
}
int query(int l, int r) {
	int lid = id[l] + 1, rid = id[r] - 1;
	int le = st[lid] - 1, rb = ed[rid] + 1;
	if (lid > rid) {
		lid = 1;
		rid = 0;
		le = r; rb = r + 1;
	}
	now_ans = ans[lid][rid];
	ans_cnt = getcnt(now_ans, lid, rid);
	count(l, le, lid, rid);
	count(rb, r, lid, rid);
	decount(l, le);
	decount(rb, r);
	return sorted[now_ans];
}


struct _Main {
	_Main() {
		int l, r;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		memcpy(sorted + 1, arr + 1, n * sizeof(int));
		sort(sorted + 1, sorted + n + 1);
		for (int i = 1; i <= n; i++) {
			arr[i] = lower_bound(sorted + 1, sorted + n + 1, arr[i]) - sorted;
		}
		init();
		for (int Q = 1; Q <= n; Q++) {
			read(l); read(r);
			printf("%d\n", query(l, r));
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			if (t == '-') f = -1;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
		a *= f;
	}
}loj6285;

}
//检查有没有拼写错误，
//考虑包含的块数 == 0 的情况 
