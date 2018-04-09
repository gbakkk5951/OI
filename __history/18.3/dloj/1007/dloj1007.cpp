using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
namespace OI {
const int MXN = 500005, SQN = 710, MXBIT = 15;
struct Node {
	int s[2], cnt;
}node[MXN * (MXBIT) + SQN * 3];
int pidx;

int n;

int arr[MXN], tag[SQN], id[MXN], st[SQN], ed[SQN], root[SQN];
queue<int> q;
int new_() {
	if (!q.empty()) {
		int nd = q.front();
		q.pop();
		node[nd].s[0] = node[nd].s[1] = node[nd].cnt = 0;
		return nd;
	}
	return ++pidx;
}
void del(int id, int num) {
	int nd = root[id], s, spo;
	for (int I = 0; I <= MXBIT; I++) {
		s = node[nd].s[spo = num >> (MXBIT - I) & 1];	
		if (--node[s].cnt == 0) {
			node[nd].s[spo] = 0;
			q.push(s);
		}
		nd = s;
	}
}
void add(int id, int num) {
	int nd = root[id], spo;
	for (int I = 0; I <= MXBIT; I++) {
		if (node[nd].s[spo = num >> (MXBIT - I) & 1] == 0) {
			node[nd].s[spo] = new_();
		}
		nd = node[nd].s[spo];
		node[nd].cnt++;
	}
}
void init() {
	int idx = 1;
	int sq = ceil(sqrt(n));
	for (int i = 1; i <= n; i++) {
		id[i] = idx;
		if (i % sq == 0) {
			ed[idx] = i;
			st[++idx] = i + 1;
		}
	}
	st[id[1]] = 1;
	ed[id[n]] = n;
	st[0] = ed[0] = n + 1; //¿¨Õâ¸ö
	for (int i = 1; i <= id[n]; i++) {
		root[i] = new_();
	}
	for (int i = 1; i <= n; i++) {
		add(id[i], arr[i]);
	}
}
int brquery(int l, int r) {
	int ans = 0;
	for (int i = l; i <= r; i++) {
		ans = max(ans, arr[i] ^ tag[id[i]]);
	}
	return ans;
}
int blquery(int id) {
	int nd = root[id];
	int ret = 0, spo;
	for (int I = 0; I <= MXBIT; I++) {
		spo = (tag[id] >> (MXBIT - I) & 1) ^ 1;
		if (node[nd].s[spo]) {
			nd = node[nd].s[spo];
			ret |= 1 << (MXBIT - I);
		} else {
			nd = node[nd].s[spo ^ 1];
		}
	}
	return ret;
}
void inline blchange(int id, int val) {
	tag[id] ^= val;
}
void brchange(int l, int r, int val) {
	for (int i = l; i <= r; i++) {
		del(id[i], arr[i]);
		add(id[i], arr[i] ^= val);
	}
}
void change(int l, int r, int val) {
	if (l != st[id[l]] && ed[id[l]] <= r) {
		brchange(l, ed[id[l]], val);
		l = ed[id[l]] + 1;
	}
	while (ed[id[l]] <= r) {
		blchange(id[l], val);
		l = ed[id[l]] + 1;
	}
	if (l <= r) {
		brchange(l, r, val);
	}
}
int query(int l, int r) {
	int ans = 0;
	if (l != st[id[l]] && ed[id[l]] <= r) {
		ans = max(ans, brquery(l, ed[id[l]]));
		l = ed[id[l]] + 1;
	}
	while (ed[id[l]] <= r) {
		ans = max(ans, blquery(id[l]));
		l = ed[id[l]] + 1;
	}
	if (l <= r) {
		ans = max(ans, brquery(l, r));
	}
	return ans;
}
struct _Main {
	_Main() {
		int l, r, op, x;
		int Qn;
		read(n); read(Qn);
		for (int i = 1; i <= n; i++) {
			read(arr[i]);
		}
		init();
		int mx = 0;
		for (int Q = 1; Q <= Qn; Q++) {
			read(op);
			
			if (op == 1) {
				int t = q.size();
				read(x); read(l); read(r);
				change(l, r, x);
			} else {
				read(l); read(r);
				printf("%d\n", query(l, r));
			}
			mx = max(mx, (int)q.size());
		}
	}
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10;
			a += t - '0';
		}
	}
}dloj1007;

}
