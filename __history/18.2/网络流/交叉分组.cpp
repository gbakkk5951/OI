using namespace std;
int main() {}
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <cstring>

namespace Protector {

const int MAXE = 83000;
const int MAXN = 450;
const int DST = 0;
const int NXT = 1;
const int FLOW = 2;
const int INF = 0x3f3f3f3f;
const int GROUP = 2;

struct _Main {
    
  
    
    
    
//Dinic    


queue<int> q;
int head[MAXN];
int now[MAXN];
int edge[MAXE][3];
int layer[MAXN];
int size;
int node_idx;
int src, dst;
int eidx;
int ans;
void push(int nd, int layer) {
    q.push(nd);
    this->layer[nd] = layer;
}
int getLayer() {
    memset(layer, 0, size * sizeof(int));
    push(src, 1);
    int i, nd, t;
    while (!q.empty()) {
        nd = q.front();
        q.pop();
        for (i = head[nd]; i; i = edge[i][NXT]) {
            if (edge[i][FLOW] && !layer[t = edge[i][DST]]) {
                push(t, layer[nd] + 1);
            }
        }
    }
    return layer[dst];   
}

int getFlow(int nd, int mx_flow) {
    if (nd == dst) {
        ans += mx_flow;
        return mx_flow;
    }
    int i, t, use = 0;
    for (i = now[nd]; i; i = edge[i][NXT]) {
        if (edge[i][FLOW] && layer[t = edge[i][DST]] > layer[nd]) {
            t = getFlow(t, min(edge[i][FLOW], mx_flow - use));
            if (t) {
                use += t;
                edge[i][FLOW] -= t;
                edge[i ^ 1][FLOW] += t;
                if (use == mx_flow) {
                    break;
                }
            }
        }
    }
    now[nd] = i;
    return use;
}
void run() {
    while (getLayer()) {
        memcpy(now, head, size * sizeof (int));
        while (getFlow(src, INF));
    }
}
    
void inline add(int src, int dst, int flow) {
    eidx++;
    edge[eidx][DST] = dst;
    edge[eidx][FLOW] = flow;
    edge[eidx][NXT] = head[src];
    head[src] = eidx;
}
    
    
    
//Dinic:End    
    
    
    
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
    int class_id[160], group_id[280];
    int id[MAXN];
    int type[MAXN];
    _Main() {
        int fail_flag = 0;
        int class_sum = 0, group_sum = 0;
        int classes, groups;
        int i, j;
        int students;
        int nd;
        int t;
        eidx = 1;  
        read(classes); read(groups);
        src = node_idx++;
        dst = node_idx++;
        for (i = 1; i <= classes && fail_flag == 0; i++) {
            class_id[i] = nd = node_idx++;
            id[nd] = i;
            read(students);
            class_sum += students;
            if (students > groups) {
                fail_flag = 1;
            }
            add(src, nd, students);
            add(nd, src, 0);
        }
        for (i = 1; i <= groups; i++) {
            nd = group_id[i] = node_idx++;
            id[nd] = i;
            type[nd] = GROUP;
            read(students);
            group_sum += students;
            add(nd, dst, students);
            add(dst, nd, 0);
        }
        for (i = 1; i <= classes; i++) {
            for (j = 1; j <= groups; j++) {
                add(class_id[i], group_id[j], 1);
                add(group_id[j], class_id[i], 0);
            }
        }
        size = node_idx;
        if (group_sum < class_sum) {
            fail_flag = 1;
        }
        if (fail_flag == 0) {
            run();
            if (ans < class_sum) {
                fail_flag = 1;
            }
        }
        if (fail_flag == 1) {
            printf("0");
            return;
        }
        printf("1\n");
        for (i = 1; i <= classes; i++) {
            for (j = head[class_id[i]]; j; j = edge[j][NXT]) {
                if (edge[j][FLOW] == 0 && type[t = edge[j][DST]] == GROUP) {
                    printf("%d ", id[t]);
                }
            }
            printf("\n");
        }
    }
    
    
    
}jsk;


}

