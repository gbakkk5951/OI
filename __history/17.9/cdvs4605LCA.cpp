using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<bitset>


int ans[100005];
namespace query{
	int head[100005];
	int nxt[200005];
	int dst[200005];
	int fa[100005];
	int idx[200005];
	int cnt;
	int getfa(int a){
		return fa[a]==a?a:getfa(fa[a]);
	}
	int merge(int a,int b){
		if(getfa(a)!=getfa(b)){
			fa[fa[a]]=fa[b];
		}
	}
	add(int q,int to,int num){
		cnt++;
		nxt[cnt]=head[q];
		head[q]=cnt;
		idx[cnt]=num;
		dst[cnt]=to;
	}
}

namespace graph{
int head[100005];
int t[100005];
int nxt[100005];
bitset<100005>in;
int idx;
void inline add(int fa,int son){
	idx++;
	nxt[idx]=head[fa];
	head[fa]=idx;
	t[idx]=son;
}
int root;	
void dfs(int nd){
	int i;query::fa[nd]=nd;
	for(i=head[nd];i;i=nxt[i]){
		dfs(t[i]);query::merge(nd,t[i]);
	}
	for(i=query::head[nd];i;i=query::nxt[i]){
		if(in[query::dst[i]]){
			ans[idx]=query::getfa(query::dst[i]);
		}
	}in[nd]=1;
}	
	
}

struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
int n;int m;
_Main(){
	int a,b,c;int i,j,k;int root;
	read(n);
	for(i=1;i<=n;i++){
		read(a);
		if(a==0)root=i;
		else graph::add(a,i);
	}read(m);
	for(i=0;i<m;i++){
		read(a);read(b);
		query::add(a,b,i);
		query::add(b,a,i);
	}
	graph::dfs(root);
	for(i=0;i<m;i++){
		printf("%d\n",ans[i]);
	}
}	
	
	
	
	
	
}cdvs4605LCA;
