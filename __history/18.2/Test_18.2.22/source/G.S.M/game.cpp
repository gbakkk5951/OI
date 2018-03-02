#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdlib>
using namespace std;
inline int read(){
	char ch='*';
	while(!isdigit(ch=getchar()));
	int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num;
}
//stack<int> q;
const int maxn= 205;
struct edge{
	int to,next,val;
}e[50005];
int mp[505][505];
int n,h[maxn],dfn[maxn],low[maxn],belong[maxn];
int vis[maxn],tot,cnt,pcnt;	
int r[maxn],q[maxn];

bool f=0;		
inline void add(int from,int to,int val){
	e[++cnt]=(edge){to,h[from],val};h[from]=cnt;
	//e[++cnt]=(edge){from,h[to],val};h[to]=cnt;
}
/*
void tarjan(int x){
	dfn[x]=low[x]=++tot;
	q.push(x);vis[x]=1;
	for(int i=h[x];i;i=e[i].next){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]){
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(low[x]=dfn[x]){
		pcnt++;
		int  j;
		do{
			j=q.top();
			q.pop();
			belong[j]=pcnt;
			tot[pcnt]++;
		}while(j!=x);
	}
}
*/
void judge(){
//	for(int i=1;i<=n;i++) printf("%d ",dfn[i]);
//	cout<<endl;
	for(int i=1;i<n;i++){
		if(!mp[dfn[i]][dfn[i+1]]) return ;
	}
	if(!mp[dfn[n]][dfn[1]]) if(n<=10)	return ;
	else{
		f=1;
		puts("1");
		for(int i=1;i<=n;i++) printf("%d ",dfn[i]);
		return ;
	}
	f=1;
	puts("0");
	for(int i=1;i<=n;i++){ printf("%d ",dfn[i]);}
	return ;
}
				
void dfs(int step){
	if(f||tot*step>8e7) return ;
	if(step==n) {
		tot++;
		judge();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[r[i]]){
			dfn[step+1]=r[i];
			vis[r[i]]=1;
			dfs(step+1);
			vis[r[i]]=0;
		}
	}
}
bool cmp(int a,int b){
	return q[a]<q[b];
}
int main(){
	//freopen("dd.out","r",stdin);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	srand(233);
	for(int i=1;i<=n;i++) r[i]=i,q[i]=rand();
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
			{
				mp[i][j]=read();
				//if(mp[i][j]) add(i,j,1);
			}
//	for(int i=1;i<=n;i++) cout<<r[i]<<endl;
	if(n>10) {cout<<-1<<endl;return 0;}
	dfs(0);
	if(!f) puts("-1");
}
		
		
