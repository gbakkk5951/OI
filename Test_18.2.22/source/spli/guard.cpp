#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>
#define LL long long
using namespace std;

const int N=55;
int n;
struct node{
	int d,p;
	bool operator < (const node &b)const{
		return d<b.d;
	}
}a[105];int p[105];
int id[N][105],tot;
bool vis[105];
int nx(int c) {
	if(c<n) return c+1;
	else return 1;
}
struct edge{
	int to,nxt;
}e[105*105];int head[105],cnt;
void add(int f,int t){
	e[++cnt]=(edge){t,head[f]};
	head[f]=cnt;
}
int ans;

void h(){
	int x,y;
	for(int i=1;i<n;++i){
		x=rand();
		y=rand();
		swap(p[(i+x)%tot+1],p[(i+y)%tot+1]);
	}
}

void bfs(){
	int u,v;
	int num=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=tot;++i){
		u=p[i];
		if(vis[u]) continue;
		num++;
		vis[u]=1;
		for(int j=head[u];~j;j=e[j].nxt){
			v=e[j].to;
			vis[v]=1;
		}
	}
	ans=max(ans,num);
}

int main(){
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);

	srand(time(0));
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	int x,b,c;
	while(scanf("%d%d%d",&x,&b,&c)!=EOF) {
		if(!id[c][x]) id[c][x]=++tot;
		if(!id[nx(c)][b]) id[nx(c)][b]=++tot;
		a[id[c][x]].d++;
		a[id[nx(c)][b]].d++;
		add(id[c][x],id[nx(c)][b]);
		add(id[nx(c)][b],id[c][x]);
		//cout<<id[c][x]<<" "<<id[nx(c)][b]<<endl;
	}
	//cout<<tot<<endl;
	//cout<<cnt<<endl;
	for(int i=1;i<=tot;++i) a[i].p=i;
	//for(int i=1;i<=tot;++i) p[i]=a[i].p;
	sort(a+1,a+1+tot);
	int num=0;
	for(int i=1;i<=tot;++i){
		int u=a[i].p;
		if(vis[u]) continue;
		num++;
		vis[u]=1;
		for(int j=head[u];~j;j=e[j].nxt){
			int v=e[j].to;
			vis[v]=1;
		}
	}
	ans=max(ans,num);
	//cout<<ans<<endl;
	for(int i=1;i<=tot;++i) p[i]=a[i].p;
	//for(int i=1;i<=tot;++i) cout<<p[i]<<" ";cout<<endl;
	for(int T=1;T<=100000;++T){
		h();
		memset(vis,0,sizeof(vis));
		bfs();
	}
	cout<<ans;
	return 0;
}

/*
3
1 1 1
1 2 1
1 1 2
*/

/*
13
1 2 6 7 2 7 2 6 13 1 1 9 2 6 1 4 4 10 7 6 8 2 2 13 5 2 11 7 5 12 1 5 9 1 1 1 3 4 7 5 6 12 7 2 5 6 7 3 3 7 12 2 5 8 4 3 6 7 4 12 3 5 3 4 7 9 4 1 10 4 1 11 8 1 5 4 7 1 3 7 2 1 4 8 7 7 8 2 4 2 2 1 13 2 8 4 6 5 13 4 5 9 6 4 1 5 7 3 1 2 1 1 2 2 4 5 1 4 2 9 3 6 8 4 8 4 3 4 12 8 6 5 3 4 3 2 3 7 2 5 2 8 2 13 3 6 9 2 7 8 3 4 9 4 2 6 6 1 5 2 4 13 5 5 10 4 7 10 1 7 7 1 4 12 3 5 5 5 6 9 6 2 11 1 3 4 3 4 8 3 2 6 2 1 3 7 3 1 1 5 4 3 2 7 1 4 7 7 5 13 4 7 2 6 6 9 6 1 9 7 4 3 1 6 7 4 6 4 5 1 8 4 1 6 3 6 7 2 4 6 8 1 13 7 5 4 5 1 9 3 7 8 3 7 1 3 1 2 7 4 8 6 5 5 7 5 6 1 2 8 3 6 6 3 3 11 6 2 2 7 6 4 1 4 5 5 3 1 6 7 10 8 6 13 3 3 2 5 3 6 7 2 6 3 5 1 7 7 4 2 7 5 2 7 6 7 4 6 3 3 4 5 2 9 8 5 13 7 6 2 3 3 1 5 8 12 6 4 9 2 4 8 5 2 2 6 6 7 4 4 12 5 4 12 5 4 2 3 3 6 1 5 8 5 2 3 4 3 3 6 2 12 1 7 3 1 3 7 7 4 1 7 5 10 5 6 10 4 2 13 2 3 3 2 4 1 7 2 9 3 2 1 6 8 4 3 1 11 3 6 4 7 4 2 4 4 7 4 2 12 4 1 1 5 7 11 5 7 8 6 7 11 6 5 7 7 4 10 6 6 5 2 1 11 6 6 12 6 3 9 2 3 1 3 6 1 6 2 3 6 2 8 7 1 9 7 3 10 2 4 12 7 6 12 7 7 10 2 5 4 1 4 3 4 6 6 6 5 4 3 4 4 5 6 5 6 2 6 3 5 9 5 7 7 8 3 13 4 7 12 6 6 3 4 2 10 6 4 3 5 4 7 8 3 12 1 2 10 5 7 12 2 5 3 7 6 1 6 1 1 1 7 13 4 5 2 2 7 11 6 7 6 5 5 7 3 2 3 6 6 2 5 2 7 7 5 2 6 6 6 5 8 4 5 2 8 6 3 6 3 7 5 7 2 4 7 6 5 4 6 8 1 5 10 2 2 2 2 2 11 4 1 13 2 7 10 6 6 11 8 2 12 1 2 3 7 6 10 7 7 7 3 7 10 5 7 6 3 3 13 6 1 6 1 7 6 6 5 2 5 2 5 1 1 2 2 3 8 1 1 5 2 4 9 1 2 5 1 6 5 4 7 13 7 1 2 1 4 1 5 1 2 3 7 9 6 3 11 5 3 9 3 2 9 6 1 10 4 8 12 5 3 3 5 7 2 1 1 11 2 1 8 8 3 5 7 2 2 1 1 10 2 8 11 3 1 4 2 2 6 5 4 5 3 5 13 2 6 10 1 6 2 3 6 3 4 2 4 7 7 3 4 3 7 4 3 9 8 7 5 6 4 2 2 4 7 8 4 13 
*/