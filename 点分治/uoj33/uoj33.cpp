using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
namespace OI {
typedef long long lld;
const int MXN = 2e5 + 10;
const int DST = 0, NXT = 1;
const int INF = 0x3f3f3f3f;
struct _Main {
	lld cnt[MXN];
	lld ans[MXN];
	int mark[MXN];
	int n;
	int f[MXN];
	int val, cho;
	int getsize(int nd, int fa, int tot) {
		int sum = 1, mx = 0, t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t] && t != fa) {
				t = getsize(t, nd, tot);
				sum += t;
				mx = max(mx, t);
			}
		}
		mx = max(mx, tot - sum);
		if (mx < val) {
			val = mx;
			cho = nd;
		}
		return sum;
	}
	int utree[MXN << 1], ntree[MXN];
	int mem[480][480];
	lld scnt[MXN];
	int geth(int nd, int fa, int h) {
		int mxh = h, t;
		ntree[h]++;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST]; //这回把DST 写成了NXT 23333
			if (!mark[t] && t != fa) {
				mxh = max(mxh, geth(t, nd, h + 1));
			}
		}
		return mxh;
	}
	void solve(int nd, int tot) {
		int mxh = 0, nowh = 0, t;
		val = INF;
		getsize(nd, 0, tot);
		nd = cho;
		mark[nd] = 1;
		//u以下, 减去u的每个子树,
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (mark[t] || t == f[nd]) continue;
			nowh = geth(t, nd, 1);
			//子树cnt
			for (int i = 1; i <= nowh; i++) {
				int sum = 0;
				for (int j = i; j <= nowh; j += i) {
					sum += ntree[j];
				}
				cnt[i] -= (lld)sum * sum;
			}
			for (int i = 1; i <= nowh; i++) {
				utree[i] += ntree[i];
			}
			mxh = max(mxh, nowh);
			memset(ntree + 1, 0, nowh * sizeof(int));
		}
		//总cnt
		utree[0] = 1;
		for (int i = 1; i <= mxh; i++) {
			int sum = 0;
			for (int j = 0; j <= mxh; j += i) {
				sum += utree[j];
			}
			cnt[i] += (lld)sum * sum - 1;//-1是为了防止两个0
		}
		//上边
		int dis = 0;
		for (int fa = f[nd], lst = nd; !mark[fa]; lst = fa, fa = f[fa]) {
			++dis;
			nowh = 0;
			for (int e = head[fa]; e; e = edge[e][NXT]) {//fa 不是 nd
				t = edge[e][DST];
				if (t != lst && !mark[t] && t != f[fa]) {//差点忘了mark[t]
					nowh = max(geth(t, fa, 1), nowh);
				}
			}
			for (int i = 1; i <= nowh; i++) {//不含fa本身
				int sum1 = 0, sum2 = 0, r = -dis % i;
				r += r < 0 ? i : 0;
				for (int j = 0; j <= nowh; j += i) {
					sum1 += ntree[j];
				}
				if (i <= 475 && i * i <= mxh && mem[i][r]) {//i * i 爆int了
					sum2 = mem[i][r];
				} else {
					for (int j = r; j <= mxh; j += i) {
						sum2 += utree[j];
					}
				}
				if (i <= 475 && i * i <= mxh) {
					mem[i][r] = sum2;
				}
				//因为这个不会重复计数, 所以要乘2
				cnt[i] += (lld)sum1 * sum2 << 1;//不会有2个零,因为dis >= 1
			}
			memset(ntree, 0, (nowh + 1) * sizeof(int));
		}
		//清空记忆化
		for (int i = 1; i * i <= mxh; i++) {
			memset(mem[i], 0, i * sizeof(int));
		}
		//计算fa到nd
		if (dis) {
			for (int i = 1; i <= (mxh + dis) * 2; i++) {
				utree[i] += utree[i - 1];
			}
			for (int i = 1; i <= mxh + dis; i++) {//枚举值
				lld sum = 0;
				for (int j = i - 1; j <= (mxh + dis) * 2; j += i) {//枚举位置
					sum += utree[j] - (j >= dis ? utree[j - dis] : 0);
				}
				//没有重复要*2
				cnt[i] += sum << 1;
			}
			memset(utree, 0, (mxh + dis + 1) * 2 * sizeof(int));//这里忘了乘2
		} else {
			memset(utree, 0, (mxh + 1) * sizeof(int));
		}
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			t = edge[e][DST];
			if (!mark[t]) {
				tot = getsize(t, nd, 0);
				if (tot > 1) solve(t, tot);
			}
		}
	}
	_Main() {
		mark[0] = 1;
		lld ans;
		read(n);
		getprime(n);
		for (int i = 2; i <= n; i++) {
			read(f[i]);
			add(f[i], i); add(i, f[i]);
		}
		solve(1, n);
		for (int i = 1; i <= n - 1; i++) {
			cnt[i] >>= 1;
		}
		for (int i = 1; i <= n - 1; i++) {
			ans = 0;
			for (int j = 1, t = i; t <= n - 1; t += i, j++) {
				ans += mu[j] * cnt[t];
			}
			printf("%lld\n", ans);
		}
	}
	int vis[MXN], mu[MXN], p[18000], pn;
	void getprime(int mx) {
		int t;
		mu[1] = 1;
		for (int i = 2; i <= mx; i++) {
			if (!vis[i]) {
				p[pn++] = i;
				mu[i] = -1;
			}
			for (int j = 0; j < pn && (t = i * p[j]) <= mx; j++) {
				vis[t] = 1;
				if (i % p[j]) {
					mu[t] = -mu[i];
				} else {
					mu[t] = 0;
					break;
				}
			}
		}
	}
	int eidx;
	int head[MXN];
	int edge[MXN << 1][2];
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
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
}uoj33;
}
