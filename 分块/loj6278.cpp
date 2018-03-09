using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
namespace OI {
typedef long long lld;
const int MXN = 50005, SQ = 85, SQN = 630;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 31 | INF;
class Block {
public:	
	int sq;
	lld id[MXN + SQ], st[MXN + SQ], ed[MXN + SQ];
	lld sorted[MXN + SQ], org[MXN + SQ], bl[SQN];
	void resort(int id) {
		memcpy(sorted + st[id], org + st[id], sq * sizeof(lld));
		sort(sorted + st[id], sorted + ed[id] + 1);
	}
	void init(int n) {
		sq = ceil(sqrt(n) / sqrt(log(sqrt(n)) / log(2)));
		int idx = 0;
		st[0] = 1;
		for (int i = 1; i <= n + sq; i++) {
			id[i] = idx;
			if (i % sq == 0) {
				ed[idx] = i;
				idx++;
				st[idx] = i + 1;
			}
		}
		for (int i = n + 1; i <= ed[id[n]]; i++) {
			org[i] = LINF;
		}
		for (int i = 1; i <= n; i += sq) {
			resort(id[i]);
		}
	}
	void add(lld arr[], int idl, int idr, int c) {
		for (int i = idl; i <= idr; i++) {
			arr[i] += c;
		}
	}
	void change(int l, int r, int c) {
		int t;
		if (ed[id[l]] <= r) {
			add(org, l, t = ed[id[l]], c);
			resort(id[l]);
			l = t + 1;
		}
		if (ed[id[l]] <= r ) {
			add(bl, id[l], t = id[r] - (r != ed[id[r]]), c);
			l = ed[t] + 1;
		}
		if (l <= r) {
			add(org, l, r, c);
			resort(id[l]);
		}
	}
	int count(int l, int r, lld mx) {
		int ret = 0;
		for (int i = l; i <= r; i++) {
			if (org[i] + bl[id[i]] < mx) {
				ret++;
			}
		}
		return ret;
	}
	int blcount(int l, int r, lld c) {
		int ret = 0;
		for (int i = l; i <= r; i++) {
			ret += lower_bound(sorted + st[i], sorted + ed[i] + 1, c - bl[i])
				- (sorted + st[i]);
		}
		return ret;
	}
	int query(int l, int r, lld c) {
		c = min(c, LINF);
		int t, ret = 0;
		if (ed[id[l]] <= r) {
			ret += count(l, t = ed[id[l]], c);
			l = t + 1;
		}
		if (ed[id[l]] <= r) {
			ret += blcount(id[l], t = id[r] - (r != ed[id[r]]), c);
			l = ed[t] + 1;
		}
		if (l <= r) {
			ret += count(l, r, c);
		}
		return ret;
	}
}data;

struct _Main {
	_Main() {
		/*
		int sq = 0, sqn = 0;
		for (int i = 1; i <= 50000; i++) {
			sq = max(sq, (int)ceil(sqrt(i) / sqrt(log(sqrt(i)) / log(2))));
			sqn = max(sqn, (int)(i / (ceil(sqrt(i) / sqrt(log(sqrt(i)) / log(2))))));
		}
		printf("sqmx = %d\nsqnmx = %d\n", sq, sqn);
		*/
		int n, l, r, c, op;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(data.org[i]);
		}
		data.init(n);
		for (int Q = 1; Q <= n; Q++) {
			read(op); read(l); read(r); read(c);
			if (op == 0) {
				data.change(l, r, c);
			} else {
				printf("%d\n", data.query(l, r, (lld)c * c));
			}
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
	
}loj6278;
}
//改变类型后检查memcpy 
