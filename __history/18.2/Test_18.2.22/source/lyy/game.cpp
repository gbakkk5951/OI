#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define SIZ(x) ((int)x.size())
#define SET(x,k) memset(x,k,sizeof(x))
#define ALL(x) x.begin(),x.end()

typedef long long LL;
typedef long double DB;
typedef vector<int> VI;
typedef pair<int,int> PII;

inline LL read() {
	LL f=1,x=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f*x;
}

const int N = 200 + 5;

int n;
int g[N][N];
int nxt[N];
int vis[N],col[N];
bool rod;

inline void join(int x) {
	for (int i=0;i<n;++i) {
		if (g[i][x]) {
			col[i]=1;
		}
	}
	vis[x]=1;
	return;
}

void work() {
	//find rode
	int head=0;
	int tail=0;
	for (int i=1,x;i<n;++i) {
		x=i;
		if (g[x][head]) {
			nxt[x]=head;
			head=x;
		} else {
			int y=head;
			int prey=0;
			while (prey!=tail&&g[y][x]) {
				prey=y;
				y=nxt[y];
			}
			if (prey!=tail) {
				nxt[prey]=x;
				nxt[x]=y;
			} else {
				nxt[tail]=x;
				tail=x;
			}
		}
	}
	if (rod) {
		puts("1");
		int nw=head;
		for (int i=0;i<n;++i)
			printf("%d ",nw+1),nw=nxt[nw];
		puts("");
		return;
	}
	//get circle

	int mid=head;
	join(head);
	while (mid!=tail) {
		int x=nxt[mid];
		if (g[x][head]) {
			join(x);
			mid=x;
			continue;
		} 

		int y=head;
		int prey=0;
		while (y!=mid&&g[y][x]) {//
			prey=y;
			y=nxt[y];
		}
		if (y!=mid) {
			nxt[mid]=head;
			nxt[prey]=x;
			head=y;
			mid=x;
			join(x);
			continue;
		}
    
		int p, r, prer;
		for (p=0;p<n;++p) {
			if (!vis[p]&&col[p]) {
				break;
			}
		}
		for (r=head;r!=mid;r=nxt[r]) { //
			if (g[p][r]) {
				break;
			}
		}
		nxt[mid]=head;
		for (prer=head;nxt[prer]!=r;prer=nxt[prer]);
		nxt[prer]=x;
		for (int j=x;j!=p;j=nxt[j])
			join(j);
		join(p),mid=p,head=r;
	}
	nxt[mid]=head;
	puts("0");
	int nw=head;
	for (int i=0;i<n;++i)
		printf("%d ",nw+1),nw=nxt[nw];
	puts("");
	return;
}

int dfn[N],dfs_cnt,low[N],scc_cnt,stk[N],top,instk[N];

void dfs(int u) {
	low[u]=dfn[u]=++dfs_cnt;
	stk[top++]=u,instk[u]=1;
	for (int i=0;i<n;++i) {
		if (g[u][i]) {
			if (instk[i]) {
				low[u]=min(low[u],dfn[i]);
			} else {
				dfs(i);
				low[u]=min(low[u],low[i]);
			}
		}
	}
	if (low[u]==dfn[u]) {
		int y;
		++scc_cnt;
		do {
			y=stk[--top];
			instk[y]=0;
		} while (y!=u);
	}
}

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n = read();
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			g[i][j]=read();
	dfs(0);
	if (scc_cnt!=1)
		rod=1;
	for (int i=0;i<n;++i) {
		if (!dfn[i]) {
			rod=1;
			break;
		}
	}
	work();
	return 0;
}

