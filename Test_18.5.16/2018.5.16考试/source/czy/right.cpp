#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, q, p;

namespace force_p_odd {

	int sum[N * 10], tag[N * 10];
	#define lc (id << 1)
	#define rc (id << 1 | 1)
	void build(int id, int l, int r) {
		int mid = (l + r) >> 1;
		if(l == r) {
			scanf("%d", &sum[id]), sum[id] %= 2;
		} else {
			build(lc, l, mid), build(rc, mid + 1, r), sum[id] = sum[lc] + sum[rc];
		}
	}
	void push(int id, int l, int r) {
		if(tag[id]) {
			sum[id] = r - l + 1 - sum[id];
			tag[lc] ^= 1, tag[rc] ^= 1, tag[id] = 0;
		}
	}
	void modify(int id, int l, int r, int ql, int qr) {
		push(id, l, r);
		int mid = (l + r) >> 1;
		if(ql > r || qr < l) return ;
		else if(ql <= l && r <= qr) tag[id] ^= 1;
		else {
			modify(lc, l, mid, ql, qr), modify(rc, mid + 1, r, ql, qr);
			push(lc, l, mid), push(rc, mid + 1, r), sum[id] = sum[lc] + sum[rc];
		}
	}
	int query(int id, int l, int r, int ql, int qr) {
		push(id, l, r);
		int mid = (l + r) >> 1;
		if(ql > r || qr < l) return 0;
		else if(ql <= l && r <= qr) return sum[id];
		else return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
	}
	void sol() {
		build(1, 1, n);

		for(int i = 1, t, l, r, x ; i <= q ; ++ i) {
			scanf("%d%d%d", &t, &l, &r); if(!t) scanf("%d", &x);
			if(t) {
				// query
				int x = query(1, 1, n, l, r);
				printf("%d\n", x % 2);
			} else {
				// modify
				if(x % 2) modify(1, 1, n, l, r);
			}
		}
	}

}

namespace pianfen {
	int a[N];
	void sol() {
		for(int i = 1, t, l, r, x ; i <= q ; ++ i) {
			scanf("%d%d%d", &t, &l, &r); if(!t) scanf("%d", &x);
			if(t) {
				int xsum = 0;
				for(int j = l ; j <= r ; ++ j) xsum ^= a[j];
				printf("%d\n", xsum & 1);
			} else {
				for(int j = l ; j <= r ; ++ j) a[j] += x;
			}
		}
	}
}

namespace force_n_50000 {
	int a[N];
	int sg(int n) {
		return n % (p + 1) == p ? 2 : n % (p + 1) % 2;
	}
	void sol() {
		for(int i = 1 ; i <= n ; ++ i) scanf("%d", &a[i]);
		for(int i = 1, t, l, r, x ; i <= q ; ++ i) {
			scanf("%d%d%d", &t, &l, &r); if(!t) scanf("%d", &x);
			if(t) {
				int xsum = 0;
				for(int j = l ; j <= r ; ++ j) xsum ^= sg(a[j]);
				printf("%d\n", !!xsum);
			} else {
				for(int j = l ; j <= r ; ++ j) a[j] += x;
			}
		}
	}
}

int main() {
    freopen("right.in", "r", stdin);
    freopen("right.out", "w", stdout);
	scanf("%d%d%d", &n, &q, &p);

	if(p & 1) {
		force_p_odd :: sol();
	} else if(n <= 50000) {
		force_n_50000 :: sol();
	} else {
		pianfen :: sol();
	}
}
