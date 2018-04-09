using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
namespace OI {
typedef long long lld;
const int MXN = 20005;
struct Info {
	int lsum, rsum, sum;
};
struct Node {
	Node *s[2];
	int id;
	Info dp;
}pool[MXN * 15 + MXN * 2];
int pidx;
Node *new_(int id) {
	Node *nd = &pool[pidx++];
	nd->id = id;
	return nd;
}
void merge(Info &dst, const Info &l, const Info &r) {
	dst.lsum = max(l.lsum, l.sum + r.lsum);
	dst.rsum = max(r.rsum, r.sum + l.rsum);
	dst.sum = l.sum + r.sum;
}
Node *build(int nl, int nr) {
	Node *nd =new_(0);
	nd->dp.lsum = nd->dp.rsum = nd->dp.sum = nr - nl + 1;
	nd->id = 0;
	if (nl == nr) {
		return nd;
	}
	int mid = nl + nr >> 1;
	nd->s[0] = build(nl, mid);
	nd->s[1] = build(mid + 1, nr);
	return nd;
}
Node* change(Node *b, int nl, int nr, int id, int pos) {
	Node *nd;
	nd = (id == b->id) ? b : new_(id);
	if (nl == nr) {
		nd->dp.lsum = nd->dp.rsum = nd->dp.sum = -1;
		return nd;
	}
	int mid = nl + nr >> 1;
	int cmp;
	if (cmp = pos > mid) {
		nd->s[1] = change(b->s[1], mid + 1, nr, id, pos);
	} else {
		nd->s[0] = change(b->s[0], nl, mid, id, pos);
	}
	nd->s[cmp ^ 1] = b->s[cmp ^ 1];
	merge(nd->dp, nd->s[0]->dp, nd->s[1]->dp);
	return nd;
}
Info query(Node *nd, int nl, int nr, int l, int r) {
	if (l <= nl && nr <= r) {
		return nd->dp;
	}
	int mid = nl + nr >> 1;
	Info a, b;
	if (l <= mid) {
		a = query(nd->s[0], nl, mid, l, r);
	} 
	if (r > mid) {
		b = query(nd->s[1], mid + 1, nr, l, r);
		if (l <= mid) {
			merge(a, a, b);
		}
	}
	return l <= mid ? a : b;
}
	

Node *root[MXN];


struct _Main {
	lld arr[MXN], uniq[MXN];
	int n, mx;
	vector<int> pos[MXN];
	lld lstans;
	int in[4];
	_Main() {
		int Qn;
		int a, b, c, d;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		memcpy(uniq + 1, arr + 1, n * sizeof(lld));
		sort(uniq + 1, uniq + n + 1);
		mx = unique(uniq + 1, uniq + n + 1) - uniq - 1;
		for (int i = 1; i <= n; i++) {
			arr[i] = lower_bound(uniq + 1, uniq + mx + 1, arr[i]) - uniq;
			pos[arr[i]].push_back(i);
		}
		root[0] = build(1, n);
		for (int i = 1; i <= mx; i++) {
			root[i] = change(root[i - 1], 1, mx, i, pos[i][0]);
			for (int j = 1; j < pos[i].size(); j++) {
				change(root[i], 1, n, i, pos[i][j]);
			}
		}
		read(Qn);
		for (int Q = 1; Q <= Qn; Q++) {
			for (int i = 0; i < 4; i++) {
				dread(in[i]);
			}
			sort(in, in + 4);
			lstans = getans(in[0], in[1], in[2], in[3]);
			printf("%lld\n", lstans);
		}
		
	}
	lld getans(int a, int b, int c, int d) {
		int l = 1, r = mx, mid, sum;
		while (l < r) {
			sum = 0;
			mid = (l + r >> 1) + 1;
			if ( b + 1 < c) {
				sum += query(root[mid - 1], 1, mx, b + 1, c - 1).sum;
			}
			sum += query(root[mid - 1], 1, mx, a, b).rsum;
			sum += query(root[mid - 1], 1, mx, c, d).lsum;
			if (sum < 0) {
				r = mid - 1;
			}  else {
				l = mid;
			}
		}
		return uniq[l];
	}
	
template <typename Type>
	void dread(Type &a) {
		read(a);
		a = (a + lstans) % n + 1;
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
}bzoj2653;
}
