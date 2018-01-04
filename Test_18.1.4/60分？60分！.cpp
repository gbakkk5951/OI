using namespace std;
int main() {}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<queue>
namespace Protector {

struct Node {
    int son[27];
    int dep;
}node[1000500];
int head[1000500];
int dp[1000500];
int edge[1000500][2];
int k_arr[1000500];
char vis[1000500];
char instk[1000500];
int e_idx;
int node_idx = 1;
int root = 1;
int k_idx;

int n, len;

void inline add(int a ,int b) {
    e_idx++;
    edge[e_idx][1] = head[a];
    edge[e_idx][0] = b;
    head[a] = e_idx;
}    
class Ac {
queue<int>q;
public:
    void insert(char *str) {
        int nd = root;
        for ( ; *str; str++) {
            if (!node[nd].son[*str - 'a']) {
                node[nd].son[*str - 'a'] = ++node_idx;
                node[node_idx].dep = node[nd].dep + 1;
            }
            nd = node[nd].son[*str - 'a'];
        }
    }
    void build() {
        int nd = root, i, j, k, s;
        for (i = 0; i < 26; i++) {
            if (s = node[nd].son[i]) {
                node[s].son[26] = root;
                q.push(s);
            } else {
                node[nd].son[i] = root;
            }
        }
        while (!q.empty()) {
            nd = q.front();
            q.pop();
            if (node[nd].dep == len) {
                k_arr[k_idx++] = nd;
            }
            for (i = 0; i < 26; i++) {
                if (s = node[nd].son[i]) {
                    node[s].son[26] = node[node[nd].son[26]].son[i];
                    q.push(s);
                } else {
                    s = node[nd].son[i] = node[node[nd].son[26]].son[i];
                }
                if (node[nd].dep >= len && node[s].dep >= len) {
                    add(nd, s);
                }
            }
        }
    }
    
    
    
}tree;
int dfs(int nd) {
    if (vis[nd]) {
        return dp[nd];
    } 
    vis[nd] = 1;
    instk[nd] = 1;
    int i, t;
    for (i = head[nd]; i ; i = edge[i][1]) {
        if (instk[edge[i][0]] || ((t = dfs(edge[i][0])) == -1)) {
            instk[nd] = 0;
            return -1;
        } else {
            dp[nd] = max(dp[nd], t + 1);
        }
    }
    instk[nd] = 0;
    return dp[nd];
}

struct _Main {
    char buf[100010];
    
    void init() {
        memset(node, 0 ,(node_idx + 1) * sizeof(Node));
        memset(head, 0 ,(node_idx + 1) * sizeof(int));
        memset(vis, 0 ,(node_idx + 1) * sizeof(char));
        memset(edge, 0 ,(node_idx + 1) * 2 * sizeof(int));
        memset(dp, 0 ,(node_idx + 1) * sizeof(int));
        node_idx = 1;
        e_idx = 0;
        k_idx = 0;
    }
    _Main() {
        int i, j, len_now, ans, t;
        while (~scanf("%d%d", &n, &len)) {
            init();   
            ans = len - 1;
            for (i = 1 ; i <= n ; i++) {
                scanf("%s", buf);
                len_now = strlen(buf);
                if (len_now < len) {
                    continue;
                } else {
                    for (j = 0; j <= len_now - len; j++) {
                        tree.insert(buf + j);
                    }
                }
            }
            tree.build();
            for (i = 0 ; i < k_idx; i++) {
                if (!vis[k_arr[i]]) {
                    t = dfs(k_arr[i]);
                    if (t == -1) {
                        ans = t;
                        break;
                    } else {
                        ans = max(ans, t + len);
                    }
                }
            }
            
            if (ans == -1) {
                printf("INF\n");
            } else {
                printf("%d\n",ans);
            }
           
        }
       
       
    } 
    
    
    
}T2;





}
//对于多组数据的题return 一定要小心， 可能一些情况会导致该次询问结束，此时没有被初始化的元素一定要回溯。 
//最好还是 nd = root 这样能减少错误 
