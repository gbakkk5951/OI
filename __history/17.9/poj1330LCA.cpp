using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<bitset>
bitset<10005>v;
int ans;
namespace query{
	int fa[10005];
	int getfa(int a){
		return fa[a]==a?a:getfa(fa[a]);
	}
}

namespace graph{
int head[10005];
int t[10005];
int nxt[10005];
bool in[2];
int idx;
int la,lb;
void ini(){
	memset(head,0,(idx+2)*sizeof(int));
	idx=0;in[1]=in[0]=0;ans=0;
}
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
		dfs(t[i]);query::fa[t[i]]=nd;
		if(ans)return;
	}
	if(nd==la){
		if(in[1]){
			ans=query::getfa(lb);
			return;
		}
		in[0]=1;
	}else if(nd==lb){
		if(in[0]){
			ans=query::getfa(la);
			return;
		}
		in[1]=1;
	}
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
	int a,b,c;int i,j,k;int root;int T;
	read(T);
	while(T--){
		v.reset();
		graph::ini();
		read(n);
		for(i=1;i<=n-1;i++){
			read(a);read(b);
			graph::add(a,b);
			v[b]=1;
		}
		for(i=1;i<=n;i++)if(!v[i]){
			root=i;break;
		}
		read(graph::la);read(graph::lb);
		if(graph::la!=graph::lb)
		graph::dfs(root);
		else ans=graph::la;
		printf("%d\n",ans);
	}


}	
	
	
	
	
	
}poj1330;
