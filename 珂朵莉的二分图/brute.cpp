using namespace std;
int main () {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>

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
char color[MAXN];
int del;
int head[MAXN];    
int edge[MAXN << 1][3];
int ans_arr[MAXN];
int e_idx;
int ans_idx;
int n, m;

void inline add(int src, int dst, int idx) {
    e_idx++;
    edge[e_idx][DST] = dst;
    edge[e_idx][IDX] = idx;
    edge[e_idx][NXT] = head[src];
    head[src] = e_idx;
}
bool dfs(int nd) {
	int i, dst;
	for (i = head[nd]; i; i = edge[i][NXT]) {
		if (del == edge[i][IDX]) continue;
		dst = edge[i][DST];
		if (!color[dst]) {
			color[dst] = color[nd] ^ 1;
			if (!dfs(dst)) {
				return false;
			}
		} else{
			if (color[dst] != (color[nd] ^ 1)) {
				return false;
			}
		}
	}
	return true;
}

bool is_bipartite() {
	memset(color, 0, (n + 1) * sizeof(char));
	int i;
	for (i = 1; i <= n; i++) {
		if (!color[i]) {
			color[i] = 2;
			if (!dfs(i)) {
				return false;
			}
		}
	}
	return true;
}

 
_Main() {
    int i, j, k;
    int a, b, c;
    
    read(n); read(m);
    for (i = 1; i <= m; i++) {
    	read(a); read(b);
    	add(a, b, i); add(b, a, i);
    }
    for (i = 1; i <= m; i++) {
		del = i;
		if (is_bipartite()) {
			ans_arr[ans_idx++] = i;
		}		
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
//邻接表的i仅作为edge数组下标 
//不要把分类讨论中简单的一类忽视了 
//双向边空间双倍
//特殊情况答案重置
 
