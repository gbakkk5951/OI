using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

namespace OI {
typedef long long lld;
const int MXN = 50005, SQ = 230, SQN = 230;
int getsq(int n) {
	return ceil(sqrt(n));
}
class Block {
public:
	lld arr[MXN], tag[SQN], sum[SQN];
	int st[SQN], ed[SQN], id[MXN];
	void calcsum(int id) {
		sum[id] = 0;
		for (int i = st[id]; i <= ed[id]; i++) {
			sum[id] += arr[i];
		}
	}
	lld calc(int l, int r) {
		lld ret = 0;
		for (int i = l; i <= r; i++) {
			ret += arr[i];
		}
		return ret + tag[id[l]] * (r - l + 1);
	}
	lld blcalc(int lid, int rid, lld mod) {
		lld ret = 0;
		for (int i = lid; i <= rid; i++) {
			ret += (ed[i] - st[i] + 1) * tag[i] + sum[i];
			ret %= mod;
		}
		return ret;
	}
	void add(lld arr[], int l, int r, int c) {
		for (int i = l; i <= r; i++) {
			arr[i] += c;
		}
	}
	void init(int n) {
		int sq = getsq(n);
		int idx = 0;
		for (int i = 1; i <= n; i++) {
			id[i] = idx;
			if (i % sq == 0) {
				ed[idx] = i;
				st[++idx] = i + 1;
			}
		}
		st[id[1]] = 1;
		ed[id[n]] = n;
		for (int i = 0; i <= id[n]; i++) {
			calcsum(i);
		}
	}
	void change(int l, int r, int c) {
		int t;
		if (ed[t = id[l]] <= r) {
			add(arr, l, ed[t], c);
			sum[t] += (ed[t] - l + 1LL) * c;
			l = ed[t] + 1;
		}
		if (ed[id[l]] <= r) {
			add(tag, id[l], t = id[r] - (ed[id[r]] != r), c);
			l = ed[t] + 1;
		}
		if (l <= r) {
			add(arr, l, r, c);
			sum[id[l]] += (r - l + 1LL) * c; 
		}
	}
	lld query(int l, int r, lld mod) {
		lld ret = 0;
		int t;
		if (ed[t = id[l]] <= r) {
			ret += calc(l, ed[t]);
			l = ed[t] + 1;
		}
		if (ed[id[l]] <= r) {
			ret += blcalc(id[l], t = id[r] - (ed[id[r]] != r), mod);
			l = ed[t] + 1;
		}
		if (l <= r) {
			ret += calc(l, r);
		}
		return ret % mod;
	}
}data;

struct _Main {
	_Main() {
		int n;
		int op, l, r, c;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(data.arr[i]);
		}
		data.init(n);
		for (int Q = 1; Q <= n; Q++) {
			read(op); read(l); read(r); read(c);
			if (op == 0) {
				data.change(l, r, c);
			} else {
				printf("%lld\n", data.query(l, r, c + 1));
			}
		}
		/*
		int sq = 0, sqn = 0;
		for (int i = 1; i <= 5e4; i++) {
			int t = getsq(i);
			sq = max(sq, t);
			sqn = max(sqn, (int)ceil((double)i / t));
		}
		printf("sq = %d, sqn = %d\n", sq, sqn);
		*/
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
}loj6280;
}
