using namespace std;
int main () {}
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstring>
namespace Protector {
	
const int MAX_N = 105;
const int MAX_M = 10110;
const int FROM = 0;
const int TO = 1; 
const double EPS = 1e-6;
int fa[MAX_N << 1];
int loop_idx;
int getFa(int nd) {
	if (fa[nd]) {
		return fa[nd] = getFa(fa[nd]);
	} else {
		return nd;
	}
}
template <typename Type>
	Type inline pf(Type a) {
		return a * a;
	}

struct Edge{
	int nxt, dst;
	double dis;
	int getDst() {
		return dst = getFa(dst);
	}
}edge[MAX_M];

int head[MAX_N];
double x[MAX_N], y[MAX_N];
double pre_val[MAX_N << 1];
int reveidx, eidx;
int pre[MAX_N << 1];
char vis[MAX_N << 1];
char out_stk[MAX_N << 1];


struct _Main {
template <typename Type>
	void read(Type &a) {
		int t;
		while (!isdigit(t = getchar()));
		a = t - '0';
		while ( isdigit(t = getchar())){
			a *= 10 ;
			a += t - '0';
		}
	}
int n, m;
int lstn;
double sum;

void merge_loop(int nd) {
	int i;
	fa[getFa(nd)] = loop_idx;
	for (i = pre[nd]; i != nd; i = pre[nd]) {
		fa[getFa(i)] = loop_idx;
	}
	pre_val[loop_idx] = sum * 2;
	loop_idx++;
}


double getMinTreeGraph() {
	double ans = 0;
	char finish = 0;
	int i, nd;
	for (i = 1; i <= n; i++) {
		pre_val[i] = sum * 2;
	}
	while (finish == 0) {
		finish = 1;
		for (nd = 0; nd <= n; nd++) {
			for (i = head[nd]; i; i = edge[i].nxt) {
				if (getFa(nd) == edge[i].getDst() ) {
					continue;
				}
				if (edge[i].dis + EPS < pre_val[edge[i].getDst()] - EPS) {
					pre_val[edge[i].getDst()] = edge[i].dis;
					pre[edge[i].getDst()] = getFa(nd);
				}
			}
		}
		for (i = 1; i <= loop_idx; i++) {
			if (!vis[i]) {
				printf("beg from %d\n", i);
				for (nd = i; nd; nd = pre[nd]) {
					if (vis[nd]) {
						if (out_stk[nd]) {
							break;
						} else {
							merge_loop(nd);
							finish = 0;
							break;									
						}
					}
					vis[nd] = 1;
					ans += pre_val[nd];
					printf("pre_val[%d] = %lf\n", nd, pre_val[nd]);
				}
				for (nd = i; nd; nd = pre[nd]) {
					if (out_stk[nd]) {
						break;
					} else {
						out_stk[nd] = 1;
					}
				}
			}
		}
		printf("ans = %lf\n", ans);
		if (!(ans + EPS < sum * 2 - EPS)) {
			return -1;
		}
	}
	return ans;
}

void clear() {
	memset(fa, 0, (loop_idx) * sizeof(int));
	memset(head, 0, (lstn + 1) * sizeof(int));
	memset(vis, 0, (loop_idx) * sizeof(char));
}
void inline add(int src, int dst, double dis) {
	eidx++;
	edge[eidx].nxt = head[src];
	head[src] = eidx;
	edge[eidx].dst = dst;
	edge[eidx].dis = dis;	
}
_Main() {
	int i, j, k;
	int a, b, c;
	int src, dst;
	double ans;
	double dis;
	while(~scanf("%d%d", &n, &m)){
		clear();
		loop_idx = n + 1;
		sum = 0;
		for (i = 1; i <= n; i++) {
			scanf("%lf%lf", &x[i], &y[i]);
		}



		for (i = 1; i <= m; i++) {
			read(src); read(dst);
			dis = sqrt(pf(x[src] - x[dst]) + pf(y[src] - y[dst]));
			sum += dis;
			add(src, dst, dis);
		}
		sum += 1000;
		for (i = 1; i <= n; i++) {
			add(0, i, sum);
		}		
		ans = getMinTreeGraph();
		if (ans < -EPS) {
			printf("poor snoopy\n");
		} else {
			printf("%lf >= %lf", ans, -EPS);
			printf("%.2lf\n", round((ans - sum) * 100.0 + EPS) / 100.0);
		}
		lstn = n;
	}
}
	
	
	
	
}poj3164;


}
