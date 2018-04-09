#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define MN 200000
#define INF 1000000000LL
#define eps 1e-4
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
double d[MN + 5], w[MN + 5];
double mid;
vector<int> v[MN + 5];
int maxh, h[MN + 5], size[MN + 5], q[MN + 5], top = 0, f[MN + 5];
int n, low, up, minn, rt, tot, bigrt, cnt=0, head[MN + 5], mx[MN + 5], rtnum = 0;
int root[MN + 5];
struct edge {
	int to, next;
	double w;
}e[MN * 2 + 5];
bool yes, mark[MN + 5];
struct Queue{
    int hd, tl, n, qx[MN + 5];
    void init(int size) {
		hd = -1;
		tl = 0;
		n = size;
	}
    void ins(int x) {
        if(hd >= tl && qx[hd] <= x)return;
        if(hd < tl && x > n)return;
        while(d[x] >= d[qx[hd]] && hd >= tl) hd--;
        qx[++hd] = x;
    }
    double query(int x)
    {
        while(qx[tl] > x && hd >= tl) ++tl;
        if(hd < tl) return -INF;
        return d[qx[tl]];    
    }
}Q;

void ins(int f, int t, int w)
{
    e[++cnt] = (edge){t, head[f], w}; head[f] = cnt;
    e[++cnt] = (edge){f, head[t], w}; head[t] = cnt;
}

void getrt(int x, int fa)
{
    for (int i = head[x]; i; i = e[i].next)
        if(e[i].to != fa && !mark[e[i].to]) 
            getrt(e[i].to, x);
    if (max(tot - size[x], size[mx[x]]) < minn) {
		minn = max(tot - size[x], size[mx[x]]);
		rt=x;
	}
}

void bfs(int x, int from)
{
    int i, j;
	f[x] = from;
    for (q[i = top = 1] = x; i <= top; i++) {
        for (j = head[q[i]]; j; j = e[j].next) {
			if (!mark[e[j].to] && f[e[j].to] != from) {
				f[q[++top] = e[j].to] = from;     
			}
        }
    }
}

void dfs(int x, int fa)
{
    maxh = max(maxh,h[x]); 
    for(int i = head[x]; i; i = e[i].next) {
        if (e[i].to != fa && !mark[e[i].to]) {
            h[e[i].to] = h[x] + 1;
			w[e[i].to] = w[x] + (double)e[i].w - mid;
            dfs(e[i].to, x);
        }
	}
}

void pre_dfs(int x, int fa)
{
    size[x] = 1;
	mx[x] = 0;
    for(int i = head[x]; i; i = e[i].next) {
        if (e[i].to != fa && !mark[e[i].to]) {
            pre_dfs(e[i].to, x);
            size[x] += size[e[i].to];
            if(size[e[i].to] > size[mx[x]]) mx[x] = e[i].to;
        }
    }
}

void pre_work(int x)
{
    mark[x] = 1;
    if (yes) return;
    for(int i = head[x]; i; i = e[i].next) if(!mark[e[i].to]) {
        pre_dfs(e[i].to,x);    	
    }
    for(int i = head[x]; i; i = e[i].next) {
        if(!mark[e[i].to]) {
            tot = size[e[i].to];
			minn = INF;
            getrt(e[i].to, x);
            root[++rtnum] = rt;
			pre_work(rt);
        }
	}
}

void solve(int x)
{
    mark[x] = 1;
	maxh = 0;
    if (yes) return;
	int mxdp = 0; 
    for (int i = head[x]; i; i = e[i].next) if (!mark[e[i].to]) {
        maxh = 0;
		h[e[i].to] = 1;
		w[e[i].to] = (double)e[i].w - mid;
        dfs(e[i].to, x);
        mxdp = max(mxdp, maxh);
        v[maxh].push_back(e[i].to);
    }
    for (int i = 1;i <= mxdp; i++) {
        for(int j = 0; j < v[i].size(); j++)
        {
            top = 0;
			bfs(v[i][j], x);
			Q.init(mxdp);
            int k;
			for (k = i; k > low - 1; k--) {
				Q.ins(k);
			}
            for(k = 1; k <= top; k++) {
                if (w[q[k]] >= 0 && h[q[k]] >= low && h[q[k]] <= up) {
					yes = true;
					for (int i = 1; i <= mxdp; i++) {
						d[i] = -INF;
						v[i].clear();
					}
					return;
				}
                if (h[q[k]] > up) {
                	break;
                }
                if (h[q[k]] < low) {
                	Q.ins(low - h[q[k]]);
                }
                if (Q.query(up - h[q[k]]) + w[q[k]] >= 0) {
					yes = true;
					for(int i = 1; i <= mxdp; i++) {
						d[i] = -INF;
						v[i].clear();
					}
					return;
				}
            }
            for(k = 1; k <= top; k++) {
            	d[h[q[k]]] = max(d[h[q[k]]], w[q[k]]);
			}
        }
    }
	for(int i = 1; i <= mxdp; i++) {
		d[i] = -INF;
		v[i].clear();
	}
}

int main() {    
//	freopen("data0.in", "r", stdin);
    tot = n = read(); low = read(); up = read();
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read(), w = read();
        ins(u, v, w);    
    } 
    for(int i = 1; i <= n; i++) d[i] = -INF;
    double l = 0, r = 1000000;
	minn = INF;
	pre_dfs(1, 0);
	getrt(1, 0);
	double ans = 0;
    root[++rtnum] = rt;
	pre_work(rt);
    while (l + eps <= r) {
        mid = (l + r) / 2.0;
		yes = false;
        memset(f, 0, sizeof(f));
        memset(mark, 0, sizeof(mark));
        for(int i = 1; i <= n && !yes; i++) solve(root[i]);
        if (yes) ans = mid, l = mid;
        else r = mid; 
    } 
    
    printf("%0.3lf",ans);
    return 0;
}
