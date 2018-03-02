int source;         // Դ��
int sink;           // ���
int p[max_nodes];   // ������·�ϵ���һ�����ı��
int num[max_nodes]; // �� t ����̾������ i �Ľڵ�����
int cur[max_nodes]; // ��ǰ���±�
int d[max_nodes];   // ���������нڵ� i ����� t ����̾���
bool visited[max_nodes];

// Ԥ����, ���� BFS ���� d ����
bool bfs()
{
    memset(visited, 0, sizeof(visited));
    queue<int> Q;
    Q.push(sink);
    visited[sink] = 1;
    d[sink] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (iterator_t ix = G[u].begin(); ix != G[u].end(); ++ix) {
            Edge &e = edges[(*ix)^1];
            if (!visited[e.from] && e.capacity > e.flow) {
                visited[e.from] = true;
                d[e.from] = d[u] + 1;
                Q.push(e.from);
            }
        }
    }
    return visited[source];
}

// ����
int augment()
{
    int u = sink, df = __inf;
    // �ӻ�㵽Դ��ͨ�� p ׷������·��, df Ϊһ·����С�Ĳ���
    while (u != source) {
        Edge &e = edges[p[u]];
        df = min(df, e.capacity - e.flow);
        u = edges[p[u]].from;
    }
    u = sink;
    // �ӻ�㵽Դ���������
    while (u != source) {
        edges[p[u]].flow += df;
        edges[p[u]^1].flow -= df;
        u = edges[p[u]].from;
    }
    return df;
}

int max_flow()
{
    int flow = 0;
    bfs();
    memset(num, 0, sizeof(num));
    for (int i = 0; i < num_nodes; i++) num[d[i]]++;
    int u = source;
    memset(cur, 0, sizeof(cur));
    while (d[source] < num_nodes) {
        if (u == sink) {
            flow += augment();
            u = source;
        }
        bool advanced = false;
        for (int i = cur[u]; i < G[u].size(); i++) { 
            Edge& e = edges[G[u][i]];
            if (e.capacity > e.flow && d[u] == d[e.to] + 1) {
                advanced = true;
                p[e.to] = G[u][i];
                cur[u] = i;
                u = e.to;
                break;
            }
        }
        if (!advanced) { // retreat
            int m = num_nodes - 1;
            for (iterator_t ix = G[u].begin(); ix != G[u].end(); ++ix)
                if (edges[*ix].capacity > edges[*ix].flow)
                    m = min(m, d[edges[*ix].to]);
            if (--num[d[u]] == 0) break; // gap �Ż�
            num[d[u] = m+1]++;
            cur[u] = 0;
            if (u != source)
                u = edges[p[u]].from;
        }
    }
    return flow;
}
