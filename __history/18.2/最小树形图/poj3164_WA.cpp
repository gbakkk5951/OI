using namespace std;
int main () {}
#include<cstdio>
#include<cctype>
#include<cmath>
namespace Protector {
	
const int MAX_N = 105;
const int MAX_M = 10010;
const int FROM = 0;
const int TO = 1; 
const double EPS = 1e-6;
int fa[MAX_N << 1];
int loop_idx;
int getFa(int nd) {
	if (fa[nd]) {
		return fa[nd] = getfa(fa[nd]);
	} else {
		return nd;
	}
}
struct Edge{
	int nxt, dst;
	double dis;
	int getDst() {
		return dst = getFa(dst);
	}
}rev_edge[MAX_M], edge[MAX_M];

int head[MAX_N];
double x[MAX_N], y[MAX_N];
int tmp_edge[MAX_M][2];
char vis[MAX_N];
int reveidx, eidx;
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
void merge_loop(int nd, int new_idx) {
	int i;
	fa[getFa(nd)] = new_idx;
	for (i = pre[nd]; i != nd; i = pre[nd]) {
		fa[getFa(i)] = new_idx;
	}
	
}
int countNodes(int nd) {
	int size = 0;
	int i;
	for (i = head[nd];)
	
	return size + 1;
}

double getMinTreeGraph() {
	
	
	
	
}
double ans;
void clear() {
	memset(fa, 0, (loop_idx + 1) * sizeof(int));
	memset(head, 0, (lstn + 1) * sizeof(int));
	memset(vis, 0, (lstn + 1) * sizeof(char));
}

_Main() {
	int i, j, k;
	int a, b, c;
	double ans;
	while(~scanf("%d%d", &n, &m)){
		clear();
		loop_idx = n + 1;
		
		for (i = 1; i <= m; i++) {
			read(tmp_edge[FROM]); read(tmp_edge[TO]);
		}
		for (i = 1; i <= n; i++) {
			scanf("%lf%lf", &x[i], &y[i]);
		}
		for (i = 1; i <= m; i++) {
			edge[i].nxt = head[tmp_edge[TO]];
			head[tmp_edge[TO]] = i;
			rev_edge[i].dst = tmp_edge[FROM];
			rev_edge[i].dis = sqrt(pf(x[tmp_edge[FROM]] - x[tmp_edge[TO]]) + pf(y[tmp_edge[FROM]] - y[tmp_edge[TO]]));
			edge_e
		}
		ans = getMinTreeGraph();
		if (ans < -EPS) {
			printf("poor snoopy\n");
		} else {
			printf("%.2lf\n", round(ans * 100.0 + EPS) / 100.0);
		}
		lstn = n;
	}
}
	
	
	
	
}poj3164;


}
