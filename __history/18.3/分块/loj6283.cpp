using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
namespace OI {
typedef long long lld;
const int INF = 0x3f3f3f3f, SQ = 320, SQN = 320, MXN = 100005;
const lld LINF = (lld)INF << 30 | INF;
int getsq(int n) {
//	return n + 1;
//	return 1;
	return ceil(sqrt(n));
}

class Block {
public:	
	int org[MXN], sorted[MXN];
	int id[MXN], st[SQN], ed[SQN];
	lld tag[SQN];
	void resort(int id) {
		memcpy(sorted + st[id], org + st[id], (ed[id] - st[id] + 1) * sizeof(int));
		sort(sorted + st[id], sorted + ed[id] + 1);
	}
	void init(int n) {
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
		ed[0] = n + 1;
		for (int i = 1; i <= id[n]; i++) {
			resort(i);
		}
		memset(tag + 1, 63, id[n] * sizeof(lld)); //看好开头  n不是tag的size
	}
template <typename Type>
	void assign(Type arr[], int l, int r, int val) {
		for (int i = l; i <= r; i++) {
			arr[i] = val;
		}
	}
	void change(int l, int r, int val) {
		int t;
		if (ed[t = id[l]] <= r) {
			if (tag[t] < LINF) {
				assign(org, st[t], l - 1, tag[t]);
				tag[t] = LINF;
			}
			assign(org, l, ed[t], val);
			resort(t);
			l = ed[t] + 1;
		}
		if (ed[id[l]] <= r) {
			assign(tag, id[l], t = id[r] - (r != ed[id[r]]), val);
			l = ed[t] + 1;
		}
		if (l <= r) { // 若l和r1都位于一个块的中间，需要全部下放 
			if (tag[t = id[l]] < LINF) {//标记下放。 
				assign(org, st[t], ed[t], tag[t]);
				tag[t] = LINF;
			}
			assign(org, l, r, val);
			resort(t);
		}
	}
	int count(int l, int r, int val) {
		if (tag[id[l]] < LINF) return (r - l + 1) * (val == tag[id[l]]);
		int ret = 0;
		for (int i = l; i <= r; i++) {
			ret += (org[i] == val);
		}
		return ret;
	}
	int getrank(int id, int val) {
		return lower_bound(sorted + st[id], sorted + ed[id] + 1, val) - sorted;
	}
	int blcount(int lid, int rid, int val) {
		int ret = 0;
		for (int i = lid; i <= rid; i++) {
			if (tag[i] >= LINF) {
				ret += getrank(i, val + 1) - getrank(i, val);
			} else {
				ret += (ed[i] - st[i] + 1) * (tag[i] == val);
			}
		}
		return ret;
	}
	int query(int l, int r, int val) {
		int t, ret = 0;
		if (ed[t = id[l]] <= r) {
			ret += count(l, ed[t], val);
			l = ed[t] + 1;
		}
		if (ed[id[l]] <= r) {
			ret += blcount(id[l], t = id[r] - (r != ed[id[r]]), val);
			l = ed[t] + 1;
		}
		if (l <= r) {
			ret += count(l, r, val);
		}
		return ret;
	}
}data;
class Brute {
	public:
	int arr[MXN];
	void change(int l, int r, int val) {
		for (int i = l; i <= r; i++) {
			arr[i] = val;
		}
	}
	int query(int l, int r, int val) {
		int ret = 0;
		for (int i = l; i <= r; i++) {
			if (arr[i] == val) ret++;
		}
		return ret;
	}
}brute;

struct _Main {
	_Main() {
		int n, l, r, c;
		read(n);
		for (int i = 1; i <= n; i++) {
			read(data.org[i]);
		}
		data.init(n);
		for (int Q = 1; Q <= n; Q++) {
			read(l); read(r); read(c);
			printf("%d\n", data.query(l, r, c));
			data.change(l, r, c);
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
}loj6283;

}
//貌似块 = n 的时候会重复计数， 块编号从1开始用并将ed[0] = n + 1 
