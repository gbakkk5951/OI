using namespace std;
int main() {}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
namespace OI {
const int MXN = 20005;
const int DST = 0, NXT = 1;
const int VAL = 0, POS = 1;
struct _Main {
	int n, k;
	int f[MXN];
	int head[MXN << 1], edge[MXN << 1][2];
	int v[MXN << 1], num[MXN << 1];
	int size[MXN << 1];
	int data[2][50580010];
	int id[2][MXN << 1];
	int *dp[2][MXN << 1];
	int ans;
	int q[500050][2];//q应该开50W个 
	int eidx;
	void clear_edge() {
		memset(head + 1, 0, n * sizeof(int));
		eidx = 0;
	}
	void add(int a, int b) {
		eidx++;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	_Main() {
		int Tn, idx;
		read(Tn);
//		Tn = 8;
		for (int T = 1; T <= Tn; T++) {
			clear_edge();
			
			read(n); read(k);
//			n = 5;
//			k = 500000;
			for (int I = 0; I < 2; I++) {
				dp[I][0] = data[I];
				memset(dp[I][0], 0, (k + 1) * sizeof(int));
				for (int i = 1; i <= n << 1; i++) {
					dp[I][i] = dp[I][i - 1] + (k + 1);
				}
			}
			
			int *v1 = v, *v2 = v + n, *n1 = num, *n2 = num + n; 
			fill(n1 + 1, n1 + n + 1, 1);
			for (int i = 1; i <= n; i++) {
				read(f[i]);
//				if (T == 1)
//				f[i] = i - 1;
//				if (T == 2)
//				f[i] = i >> 1;
//				if (T == 3)
//				f[i] = min(i - 1, 1);
				add(f[i], i);
				read(n2[i]);
				read(v1[i]);
//				n2[i] = 1e8;
//				v1[i] = 100;
				
				n2[i]--;
				if (n2[i] > 0) {
					add(i, n + i);
				}
			}
			memmove(v2 + 1, v1 + 1, n * sizeof(int));
			dfs(1, dp[0], id[0], idx = 0);
			
			clear_edge();
			for (int i = n; i >= 1; i--) {
				add(f[i], i);
				if (n2[i] > 0) {
					add(i, n + i);
				}
			}
			dfs(1, dp[1], id[1], idx = 0);
//			printf("dfs finsih");
			ans = 0;
			getans(1, 0);
			printf("%d\n", ans);
		}
	}
	void dfs(int nd, int *dp[], int id[], int &idx) {
		size[nd] = 1;
		int t;
		for (int e = head[nd]; e; e = edge[e][NXT]) {
			dfs(t = edge[e][DST], dp, id, idx);
			size[nd] += size[t];
		}
		
		int now = id[nd] = ++idx;

		int *dpnow = dp[now], *dpfrom = dp[now - 1];
		int add = 0, v = this->v[nd], tmp, num = this->num[nd];
		int h;
		h = 0, t = -1;
		dpnow[0] = 0;//清空初值
		for (int i = 1; i <= k; i++) {
			//加入i - 1
			tmp = dpfrom[i - 1] - add;
			add += v;
			while (t >= h && q[t][VAL] <= tmp) {
				--t;
			}
			++t;
			q[t][POS] = i - 1;
			q[t][VAL] = tmp;
			//弹出队头
			h += (i - q[h][POS] > num);
			//更新dp
			dpnow[i] = q[h][VAL] + add;
		}
		
		
		if (now > size[nd]) {
			dpfrom = dp[now - size[nd]];	
			for (int i = 1; i <= k; i++) {
				dpnow[i] = max(dpnow[i], dpfrom[i]);
			}
		}
		/*
		printf("[%d] id = %d\nsize = %d\n", nd, id[nd], size[nd]);
		for (int i = 1; i <= k; i++) {
			printf("dp[%d] = %d\n", i, dpnow[i]);
		}
		*/
	}
	void getans(int nd, int pre) {
		pre += nd <= n ? v[nd] : 0;
		if (head[nd]) { // 非叶子
			int t;
			for (int e = head[nd]; e; e = edge[e][NXT]) {
				t = edge[e][DST];
				getans(t, pre);
			}
			return;
		}
		int *dp0 = nd <= n ? dp[0][id[0][nd] - 1] : dp[0][id[0][nd]], *dp1 = dp[1][id[1][nd] - 1];
		int now = 0;
		for (int i = 0; i <= k; i++) {
//			printf("dp[0][%d][%d] = %d\n", id[0][nd] - 1, i, dp0[i]);
//			printf("dp[1][%d][%d] = %d\n", id[1][nd] - 1, k - i, dp1[k - i]);
			now = max(now, dp0[i] + dp1[k - i]);
		}
//		printf("now %d = %d\n", nd, now + pre);
		ans = max(ans, now + pre);
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
}bzoj4910;
}
