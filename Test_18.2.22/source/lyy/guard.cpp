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

const int N=100+5;
const int E=N*N;

int n;

int nxt[E],to[E],head[N],tot,exi[E];
int from[E],used[N];
void add(int u,int v) {
	from[tot]=u,to[tot]=v,nxt[tot]=head[u],head[u]=tot++;
}

int fa[N],vis[N],cnt;

bool dfs(int u) {
	for (int o=head[u];~o;o=nxt[o]) {
		int v=to[o];
		if (used[v])
			continue;
		if (!vis[v]) {
			vis[v]=1;
			if (fa[v]==0||dfs(fa[v])) {
				fa[v]=u;
				return true;
			}
		}
	}
	return false;
}


bool lef[N];

int solve() {
	int ans=0;
	SET(fa,0);
	for (int i=1;i<=cnt;++i) {
		if (lef[i]&&!used[i]) {
			SET(vis,0);
			if (dfs(i))
				++ans;
		}
	}
	return ans;
}

map<PII,int> id;
VI ve[N];
vector<PII> del;

int check(int s,vector<PII>&v,int f) {
	SET(used,0);
	int cnt=0;
	for (int i=0;i<f;++i) {
		if (s&(1<<i)) {
			if (used[del[i].FI])
				return -1;
			if (used[del[i].SE])
				return -1;
			used[del[i].FI]=1;
			used[del[i].SE]=1;
			++cnt;
		}
	}
	return cnt;
	
}

void rebuild() {
	vector<PII> v;
	for (int i=0;i<tot;++i) {
		if (!exi[i]) {
			v.PB(MP(from[i],to[i]));;
		} else
			del.PB(MP(from[i],to[i]));
	}
	tot=0;
	SET(head,-1);
	for (int i=0;i<SIZ(v);++i) {
		int a=v[i].FI;
		int b=v[i].SE;
		if (lef[a])
			add(a,b);
		else
			add(b,a);
	}
}

int main() {
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	n=read();
	cnt=0;
	int a,b,c;
	SET(head,-1);
	while (~scanf("%d%d%d",&a,&b,&c)) {
		--c;
		int nxtc=(c+1)%n;;
		if (!id[MP(c,a)]) 
			id[MP(c,a)]=++cnt;
		if (!id[MP(nxtc,b)])
			id[MP(nxtc,b)]=++cnt;
		int u=id[MP(c,a)],v=id[MP(nxtc,b)];
		if (c&1)
			swap(u,v);
		add(u,v),lef[u]=1,ve[c].PB(tot-1);
	}
	if (n&1) {
		
		SET(lef,0);
		int cur=0,mn=1e9;
		for (int i=0;i<n;++i) {
			if (mn>SIZ(ve[i]))
				mn=SIZ(ve[i]),cur=i;
		}
		int nw=(cur+1)%n,isl=1;
		
		for (int i=0;i<n;++i) {

			if (isl) {
				map<PII,int>::iterator it=id.begin();
				while (it!=id.end()) {
					if ((*it).FI.FI==nw)
						lef[(*it).SE]=1;
					++it;
				}
			}
			nw=(nw+1)%n,isl^=1;
		}
		
		for (int i=0;i<SIZ(ve[cur]);++i)
			exi[ve[cur][i]]=1;

		rebuild();
		int lim=1<<SIZ(del);

		int ans=0;
		for (int s=0;s<lim;++s) {
			int c=check(s,del,SIZ(del));
			if (c==-1)
				continue;
			ans=max(ans,c+solve());
		}
		printf("%d\n",ans);

	} else
		printf("%d\n",solve());
	return 0;
}
