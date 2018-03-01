using namespace std;
int main() {}
#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<cstring>

namespace Protector {
const int MAXV = 105;
const int MAXE = 10010;
const double INF = 1e100;
struct Edge {
    int src, dst;
    double val;
};
char file_he_complete;

class DirectedMST {
private:
    Edge edge[MAXE];
    int dfn[MAXV], low[MAXV];
    int new_id[MAXV];
    int pre[MAXV];
    int stk[MAXV];
    double pre_val[MAXV];
    int stk_idx;
    int dfn_idx;
    int e_idx;
    double val_sum;
    int root; 
    int V, E;
    double ans;
    char in_stk[MAXV];
    char finish;
    
    void makeVirtualRoot() {}
    
    void initTarjan() {
        memset(dfn, 0, (V + 1) * sizeof(int));
        dfn_idx = 0;   
    }
    
    void tarjan(int nd) {
        dfn[nd] = low[nd] = ++dfn_idx;
        stk[stk_idx++] = nd;
        in_stk[nd] = 1;
        if (nd != root) {
            if (!dfn[pre[nd]]) {
                tarjan(pre[nd]);
                low[nd] = min(low[nd], low[pre[nd]]);
            } else if(in_stk[pre[nd]]) {
                low[nd] = min(low[nd], dfn[pre[nd]]);
            }
        }
        if (low[nd] == dfn[nd]) {
            while(stk[stk_idx - 1] != nd) {
                stk_idx--;
                in_stk[stk[stk_idx]] = 0;
                low[stk[stk_idx]] = low[nd];
                finish = 0;
            }
            in_stk[nd] = 0;
            stk_idx--;
        }
    }
    void getLoop() {
        initTarjan();
        int i;
        for (i = 1; i <= V; i++) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }
    }
    
    void refreshVertex() {
        int i; int new_V;
        for (i = 1, new_V = 0; i <= V; i++) {
            if (dfn[i] == low[i]) {
                new_id[low[i]] = ++new_V;
            }
        }
        for (i = 1; i <= V; i++) {
            low[i] = new_id[low[i]];
        }
        V = new_V;
        root = new_id[low[root]];
    }
    
    bool inSameLoop(int a, int b) {
        return low[a] == low[b];
    }
    
    void getNewID(int &idx) {
        idx = low[idx];
    }
    
    void refreshEdge() {
        int i;
        int new_E;
        for (i = 1, new_E = 0; i <= E; i++) {
            if (!inSameLoop(edge[i].src, edge[i].dst)) {
                ++new_E;
                edge[new_E] = edge[i];  
                edge[new_E].val -= pre_val[edge[new_E].dst]; 
                getNewID(edge[new_E].src); 
                getNewID(edge[new_E].dst); 
            }
        }
        E = new_E;
    }
    
    void getPreVal() {
        int i, dst, src;
        double val;
        for (i = 1; i <= V; i++) {
            pre_val[i] = INF;
        }
        for (i = 1; i <= E; i++) {
            dst = edge[i].dst;
            if (dst == root) {
                continue;
            } 
            src = edge[i].src;
            val = edge[i].val;
            if (pre_val[dst] > val) {
                pre_val[dst] = val;
                pre[dst] = src;
            }
        }
    }
    
    bool checkLegal() {
        int i;
        if (root == 0) {
            if (!(ans < val_sum * 2)) {
                return false;
            }
        } else {
            for (i = 1; i <= V; i++) {
                if (i != root && !(pre_val[i] < INF)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    void getTotVal() {
        int i;
        for (i = 1; i <= V; i++) {
            if (i != root) {
                ans += pre_val[i];       
            }
        }
    }
    
public:
    void setRoot(int new_root) {
        root = new_root;
    }
    void addEdge(int src, int dst, double val) {
        if (src == dst || dst == root) {
            return ;
        }
        ++e_idx;
        edge[e_idx].src = src;
        edge[e_idx].dst = dst;
        edge[e_idx].val = val;
    }
    void init(int new_V, int new_E) {
        root = 0;
        e_idx = 0;
        V = new_V;
        ans = 0;
        finish = 0;
    }
    double getMinCost() {
        E = e_idx;
        int i, j;
        if (root == 0 && finish == 0) {
            makeVirtualRoot();
        }
        while (finish == 0) {
            finish = 1;
            getPreVal();
            getTotVal();
            if (!checkLegal()) {
                return INF;
            }
            getLoop();
            refreshVertex();
            refreshEdge();
        }
        return ans;
        
    }
    
}solver;


struct _Main {
    double x[MAXV][2];
	double inline pf (double a) {
	    return a * a;
	}
	
    double getDis(int idx_a, int idx_b) {
	    return sqrt(pf(x[idx_a][0] - x[idx_b][0]) + pf(x[idx_a][1] - x[idx_b][1]));
	}
    
    template<typename Type>
		void read(Type &a) {
			char t;
			while (!isdigit(t = getchar())) {
			    if (t == EOF) {
			        file_he_complete = 1;
			        return;
			    }
			    
			}	
			a = t - '0';
			while ( isdigit(t = getchar())) {
			    a *= 10; 
                a += t - '0';
			}
		}
		
	_Main() {
	    int n, m;
	    int a, b;
	    int i, j, k;
	    double ans;
        while (~scanf("%d%d", &n, &m)) {
	        solver.init(n, m);
	        solver.setRoot(1);
	        for (i = 1; i <= n; i++) {
	            scanf("%lf%lf", &x[i][0], &x[i][1]) == EOF;
	        }
	        for (i = 1; i <= m; i++) {
	            scanf("%d%d", &a, &b);
                solver.addEdge(a, b, getDis(a, b));
	        }
	        ans = solver.getMinCost();
	        if (!(ans < INF) ) {
	            printf("poor snoopy\n");
	        } else {
	            printf("%.2f\n", ans );
	        }
	    }
	    
	    
	    
	}
	
	
	
}poj3164;


}
