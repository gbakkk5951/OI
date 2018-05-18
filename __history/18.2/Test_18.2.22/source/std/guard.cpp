#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype>
#include <string>
#include <cstring> 
#include <ctime> 
#include <cassert> 

using namespace std;

int Graph[110][110];
int ID[110][110];
bitset <110> vist;
vector <pair<int, int> > from, to;
int match[110];
int forbid[110];
int Num[110];
int n;

int dfs(int x) {
    for(int y = 0; y < n; y ++) if(!forbid[y] && Graph[x][y] && !vist.test(y)) {
        vist.set(y);

        if(match[y] == -1 || dfs(match[y])) {
            match[y] = x;
            return 1;
        }
    }

    return 0;
}
int solve(int N) {
    int res = 0;

    memset(Graph, 0, sizeof(Graph));
    n = 0;
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < Num[i]; j ++)
        ID[i][j] = n ++;
    }    
    assert(n <= 100);
    for(int i = 0; i < from.size(); i ++) {
        Graph[ID[from[i].first][from[i].second]][ID[to[i].first][to[i].second]] = 1;
        Graph[ID[to[i].first][to[i].second]][ID[from[i].first][from[i].second]] = 1;
    }
    // N is even -> bipartite graph
    memset(forbid, 0, sizeof(forbid));
    if((N & 1) == 0) {
        res = n;
        memset(match, -1, sizeof(match));
        for(int i = 0; i < N; i ++) if(i & 1)
            for(int j = 0; j < Num[i]; j ++) {
                vist.reset();
                if(dfs(ID[i][j])) res --;
            }
    } else {
        int centre, cnt;

        for(int i = 0; i < N; i ++) if(Num[i] <= 10) {
            centre = i;
            break;
        }
        for(int i = 0; i < 1 << Num[centre]; i ++) {
            int ok = 1;
            for(int j = 0; j < Num[centre]; j ++) if(i & (1 << j))
                for(int k = j + 1; k < Num[centre]; k ++) if(i & (1 << k))
                    if(Graph[ID[centre][j]][ID[centre][k]]) {
                        ok = 0;
                        goto fini;
                    }
fini:;
            if(ok) {
                cnt = 0;
                for(int j = 0; j < Num[centre]; j ++) if(i & (1 << j)) cnt ++;
                memset(forbid, 0, sizeof(forbid));
                for(int j = 0; j < Num[centre]; j ++) {
                    forbid[ID[centre][j]] = 1;
                    if(i & (1 << j)) {
                        for(int k = 0; k < n; k ++) if(Graph[ID[centre][j]][k]) forbid[k] = 1;
                    }
                }
                int v = 0, m = 0;
                for(int j = 0; j < n; j ++) if(!forbid[j]) v ++;
                memset(match, -1, sizeof(match));
                for(int j = 0; j < n; j ++) if(!forbid[j]) {
                    vist.reset();
                    if(dfs(j)) m ++;
                }
                res = max(res, cnt + v - m / 2);
            }
        }
    }
    return res;
}
int main() {
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    int N, A, B, C; 

    cin >> N;
    memset(Num, 0, sizeof(Num));
    while(cin >> A >> B >> C) {
        from.push_back(make_pair(C - 1, A - 1));
        to.push_back(make_pair(C % N, B - 1));
        Num[C - 1] = max(Num[C - 1], A);
        Num[C % N] = max(Num[C % N], B);
    }
    cout << solve(N) << endl;
    return 0;
}

