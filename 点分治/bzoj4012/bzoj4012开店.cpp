using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
namespace OI {
typedef long long lld;
typedef pair<int, lld> p;
typedef vector<p> pa;
const int DST = 0, NXT = 1, VAL = 2;
const int MXN = 150005;
const int INF = 0x3f3f3f3f;

struct _Main {
	
	pa root[MXN];
	map<int, pa> son[MXN];
	int dfn[MXN], id[MXN << 1], idx;
	int h[MXN], f[MXN][18];
	int st[18][MXN << 1];
	int log[MXN << 1];//log的大小要与下标范围相同, 改了大小之后还有st也要同步
	lld sum[MXN];
	int mark[MXN];
	int cho, val;
	int lst[MXN];
	void gettree(int nd, int fa, int tot) {
		val = INF;
		int t = getsize(nd, 0, tot);
		nd = cho;
		lst[nd] = fa;
		mark[nd] = 1;
		root[nd].push_back((p) {-1, 0});
		if (tot == 1) return;
		//printf("nowroot = %d\n", nd);
		getsize(nd, 0, tot);
		pa* a; 
		for (int e = head[nd]; e; e = edge[e][NXT]) {//NXT 写成 DST
			t = edge[e][DST];
			if (!mark[t]) {
				a = &son[nd][t];
				getdis(t, nd, edge[e][VAL], *a);
				root[nd].insert(root[nd].end(), a->begin(), a->end());
				a->push_back((p) {-1, 0});
				sort(a->begin(), a->end());
				calcsum(*a);
			}
		}
		sort(root[nd].begin(), root[nd].end());
		calcsum(root[nd]);
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t]) {
				gettree(t, nd, size[t]);
			}
		}
	}
	void calcsum(pa &a) {
		for (int i = 1; i < a.size(); i++) {
			a[i].second += a[i - 1].second;
		}
	}
	void getdis(int nd, int fa, lld sum, pa &a) {
	//	printf("dis %d = %d\n", nd, sum);
		a.push_back((p) {age[nd], sum});
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t] && t != fa) {
				getdis(t, nd, sum + edge[e][VAL], a);
			}
		}
	}
	int size[MXN];
	int getsize(int nd, int fa, int sum) {
		int t, mx = 0;
		size[nd] = 1;
		for (int e = head[nd]; e; e = edge[e][NXT]) {//NXT 写成 DST
			t = edge[e][DST];
			if (t != fa && !mark[t]) {
				t = getsize(t, nd, sum);
				size[nd] += t;
				mx = max(mx, t);
			}
		}
		mx = max(mx, sum - size[nd]);
		if (mx < val) {
			val = mx;
			cho = nd;
		}
		return size[nd];
	}
	inline pa::iterator ub(pa &a, int r) {
		return upper_bound(a.begin(), a.end(), (p) {r, INF}) - 1;
	}
	inline int min(int a, int b){
		return h[a] < h[b] ? a : b;
	}
	inline int getlca(int a, int b) {
		a = dfn[a]; b = dfn[b];
		if (a > b) swap(a, b);
		int lg = log[b - a + 1];
//		printf("st [%d, %d] = %d\n", a, b, min(st[lg][a], st[lg][b - (1 << lg) + 1]));
//		printf("lca %d %d = %d\n", id[a], id[b], min(st[lg][a], st[lg][b - (1 << lg) + 1]));
		return min(st[lg][a], st[lg][b - (1 << lg) + 1]);
	}
	void getst(int st[][MXN << 1], int arr[], int len) {
		for (int i = 1; i <= len; i++) {
			log[i] = log[i - 1] + (i == 1 << log[i - 1] + 1);
		}
		int mxp = log[len], mx;
		memcpy(st[0], arr, (len + 1) * sizeof(int));
		for (int I = 1; I <= mxp; I++) {
			mx = len - (1 << I) + 1;
			for (int i = 1; i <= mx; i++) {
				st[I][i] = min(st[I - 1][i], st[I - 1][i + (1 << I - 1)]);
			}
		}
	}
	int getclose(int a, int b) {
		int lca = getlca(a, b), dis;
		if (lca != b) return f[b][0];
		while (int dis = h[a] - h[b] - 1) { //应该-1, 因为本来f就是距离不是长度
			a = f[a][log[dis]];
		}
		return a;
	}
	void dfs(int nd, int fa, lld sum = 0) {
		this->sum[nd] = sum;
		f[nd][0] = fa;
		h[nd] = h[fa] + 1;
		id[dfn[nd] = ++idx] = nd;
//		printf("id %d = %d\n", idx, nd);
		for (int I = 1; 1 << I < h[nd]; I++) {
			f[nd][I] = f[f[nd][I - 1]][I - 1];
		}
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (t != fa) {
				dfs(t, nd, sum + edge[e][VAL]);
				id[dfn[nd] = ++idx] = nd;
//				printf("id %d = %d\n", idx, nd);
			}
		}
	}
	void init() {
		dfs(1, 0);
		getst(st, id, (n << 1) - 1);
		gettree(1, 0, n);
	}
	inline lld getdis(int a, int b) {
		return sum[a] + sum[b] - sum[getlca(a, b)] * 2;
	}
	lld query(int nd, int l, int r) {
		lld ret, cnt, dis;
		int rt = nd;
		pa::iterator a, b;
		pa *s;
		l = l - 1;
		b = ub(root[rt], r); a = ub(root[rt], l);
		ret = b->second - a->second;
//		printf("org = %lld\n", ret);
		while (rt = lst[rt]) {
			int tp = getclose(nd, rt);
//			if (son[rt].count(tp) == 0) {
//				printf("nd = %d, rt = %d, tp = %d\n", nd, rt, tp);
//			}
			s = &son[rt][tp];//rt的son不是nd的son
			dis = getdis(nd, rt);
			a = ub(root[rt], l), b = ub(root[rt], r);
//			printf("root %d = %lld cnt = %d\n", rt, b->second - a->second, b - a);
			cnt = b - a;
			ret += b->second - a->second;
			a = ub(*s, l), b = ub(*s, r);
//			printf("tp %d = %lld cnt = %d\n", tp, b->second - a->second, b - a);
			ret -= b->second - a->second;
			cnt -= b - a;
			ret += dis * (cnt + (age[rt] > l && age[rt] <= r));
		}
		return ret;
	}
	int n;
	_Main() {
		int Qn, A, a, b, c, u;
		lld ans = 0;
		read(n); read(Qn); read(A);//神TM赋值语句没关,以后要把这些东西写在读入上面
		for (int i = 1; i <= n; i++) {
			read(age[i]);
		}
		for (int i = 1; i <= n - 1; i++) {
			read(a); read(b); read(c);
			add(a, b, c); add(b, a, c);
		}
		init();
		for (int Q = 1; Q <= Qn; Q++) {
			read(u); read(a); read(b);
			a = (a + ans) % A; b = (b + ans) % A;
			if (a > b) swap(a, b);
			ans = query(u, a, b);
			printf("%lld\n", ans);
		}
	}
	
	int head[MXN];
	int edge[MXN << 1][3];
	int age[MXN];
	int eidx;
	
	void add(int a, int b, int c) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][VAL] = c;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	
template <typename Type>
	void read(Type &a) {
		char t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
	}
}bzoj4012;
}
