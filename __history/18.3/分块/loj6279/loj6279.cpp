using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>
namespace OI {
typedef long long lld;
const int MXN = 100005, SQ = 320, SQN = 320;
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 30 | INF;
int getsq(int n) {
//	return n + 1;
//	return 1;
//	return 2;
	return (int)ceil(sqrt(n));
}
class Block {
public:
	lld bl[SQN], org[MXN], sorted[MXN],
		id[MXN], ed[SQN], st[SQN];
	
	
	void resort(int id) {
		memcpy(sorted + st[id], org + st[id], (ed[id] - st[id] + 1) * sizeof(lld));
		sort(sorted + st[id], sorted + ed[id] + 1);
	}
	void init(int n) {
		int sq = getsq(n);
		cerr << "sq = "<< sq << endl;
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
			resort(i);
		}
	}
	void add(lld arr[], int l, int r, int c) {
		for (int i = l; i <= r; i++) {
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
		if (ed[id[l]] <= r) {
			add(bl, id[l], t = id[r] - (r != ed[id[r]]), c);
			l = ed[t] + 1;
		}
		if (l <= r) {
			add(org, l, r, c);
			resort(id[l]);
		}
	}
	lld find (int l, int r, int c) {
		lld ret = -LINF;
		for (int i = l; i <= r; i++) {
			if (org[i] + bl[id[i]] < c) {
				ret = max(ret, org[i] + bl[id[i]]);
			}
		}
		return ret;
	} 
	lld blfind(int lid, int rid, int c) {
		lld ret = -LINF, t;
		for (int i = lid; i <= rid; i++) {
			t = lower_bound(sorted + st[i], sorted + ed[i] + 1, c - bl[i]) - sorted;
			if (t > st[i]) ret = max(ret, sorted[t - 1] + bl[i]);
		}
		return ret;
	}
	lld query(int l, int r, int c) {
		lld ret = -LINF;
		int t;
		if (ed[id[l]] <= r) {
			ret = max(ret, find(l, t = ed[id[l]], c));
			l = t + 1;
		}
		if (ed[id[l]] <= r) {
			ret = max(ret, blfind(id[l], t = id[r] - (r != ed[id[r]]), c));
			l = ed[t] + 1;
		}
		if (l <= r) {
			ret = max(ret, find(l, r, c));
		}
		return ret > -LINF ? ret : -1;
	}
	
}data;

struct _Main {
	_Main() {
		int n, op, l, r, c;
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
				printf("%lld\n", data.query(l, r, c));
			}
		}
		/*
		int mxsq = 0, mxsqn = 0, t;
		for (int i = 1; i <= (int)1e5; i++) {
			t = getsq(i);
			mxsq = max(mxsq, t);
			mxsqn = max(mxsqn, (int)ceil((double)i / t));
		}
		printf("sq = %d, sqn = %d\n", mxsq, mxsqn);
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
}bzoj6279;

}

//均值不等式一定要列对， 所有操作都考虑 
//更改边界后memcpy不能直接sq * sizeof（lld） 
//上交前查看sq是否去调试 
//忘了调用init函数（笑哭） 
