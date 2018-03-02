using namespace std;
int main () {}
#include <cstdio>
#include <cctype>
#include <algorithm>
namespace Protector {
const int DST = 0;
const int IDX = 1;
const int NXT = 2;
const int MAXN = 1000010;
struct _Main {

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
char vis[MAXN];
char in_stk[MAXN];
int fa_even[MAXN];
int fa_odd[MAXN];
int head[MAXN];    
int edge[MAXN << 1][3];
int ans_arr[MAXN];
int depth[MAXN];
int fa_edge[MAXN];
int odd_untree_edge;
int odd_loop_cnt;
int e_idx;
int ans_idx;

void inline add(int src, int dst, int idx) {
    e_idx++;
    edge[e_idx][DST] = dst;
    edge[e_idx][IDX] = idx;
    edge[e_idx][NXT] = head[src];
    head[src] = e_idx;
}
void dfs(int nd) {
	int i, dst;
	vis[nd] = 1;
	in_stk[nd] = 1;
	for (i = head[nd]; i; i = edge[i][NXT]) {
		if (edge[i][IDX] == fa_edge[nd]) continue;
		dst = edge[i][DST];
		if (!vis[dst]) {
			depth[dst] = depth[nd] + 1;
			fa_edge[dst] = edge[i][IDX];
			dfs(dst);
			fa_even[nd] += fa_even[dst];
			fa_odd[nd] += fa_odd[dst];
		} else if (in_stk[dst]) {
			if ((depth[nd] - depth[dst] + 1) & 1) {
				odd_loop_cnt++;
				fa_odd[nd]++;
				fa_odd[dst]--;
				odd_untree_edge = edge[i][IDX];
			} else {
				fa_even[nd]++;
				fa_even[dst]--;
			}
		}
		
	}
	
	
	
	in_stk[nd] = 0;
}

 
_Main() {
    int i, j, k;
    int a, b, c;
    int n, m;
    read(n); read(m);
    for (i = 1; i <= m; i++) {
    	read(a); read(b);
    	add(a, b, i); 
		if (a != b) {
			add(b, a, i);	
		}
    }
    for (i = 1; i <= n; i++) {
    	if (!vis[i]) {
    		dfs(i);
    	}
    }
    for (i = 1; i <= n; i++) {
    	if (fa_edge[i] && fa_even[i] == 0 && fa_odd[i] == odd_loop_cnt) {
    		ans_arr[ans_idx++] = fa_edge[i];
    	}
    }
    if (odd_loop_cnt == 1) {
    	ans_arr[ans_idx++] = odd_untree_edge;
    }
    
    if (odd_loop_cnt == 0) {
    	for (i = 0, ans_idx = 0; i < m; i++) {
    		ans_arr[ans_idx++] = i + 1;
    	}
    } else {
    	sort(ans_arr, ans_arr + ans_idx);
    }
	if (ans_idx) {
    	printf("%d\n", ans_idx);
    	for (i = 0; i < ans_idx - 1; i++) {
			printf("%d ", ans_arr[i]);
    	}
    	printf("%d", ans_arr[i]);
    } else {
    	printf("0");
    }
	
    
}
    
    
    
    
    
    
}C;


}
//检查有没有把nd写成i的 
//不要把分类讨论中简单的一类忽视了 
//双向边空间双倍
//特殊情况答案重置
//有重边是默认情境
 
