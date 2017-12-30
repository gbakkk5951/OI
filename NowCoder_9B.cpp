using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
namespace Protector{

const int MAXN = 100005;
int root;
struct _Main {
    
    template<typename Type>
        void read(Type &a) {
            char t;
            while (! isdigit(t = getchar()));
            a = t - '0';
            while (  isdigit(t = getchar())) {
                a *= 10;
                a += t - '0';
            }
        }
    
    int n;
    int in[MAXN];
    int head[MAXN];
    int edge[MAXN][2];
    int size[MAXN];
    int minIdx[MAXN];
    int maxIdx[MAXN];
    int ans;
    void dfs(int nd = root) {
        int i;
        for (i = head[nd]; i; i = edge[i][1]) {
            dfs(edge[i][0]);
            size[nd] += size[edge[i][0]];
            minIdx[nd] = min(minIdx[edge[i][0]], minIdx[nd]);
            maxIdx[nd] = max(maxIdx[edge[i][0]], maxIdx[nd]);
        }
        size[nd]++;
        minIdx[nd] = min(minIdx[nd], nd);
        maxIdx[nd] = max(maxIdx[nd], nd);
        if(maxIdx[nd] - minIdx[nd] + 1 == size[nd]){
            ans++;
        }
    }
    int eidx;
    void inline add (int a, int b) {
        eidx++;
        edge[eidx][1] = head[a];
        head[a] = eidx;
        edge[eidx][0] = b;
        in[b]++;
    }
    _Main() {
        memset(minIdx,63,sizeof(minIdx));
        int i, j, k;
        int a, b, c;
        read(n);
        for (i = 1; i <= n - 1; i++) {
            read(a);
            read(b);
            add(a, b);
        }
        for (i = 1; i <= n; i++) {
            if (! in[i]) {
               root = i;
               break; 
            }
        }
        dfs();
        printf("%d", ans);
        
    }
    
    
    
}nowCoder9B;


}
