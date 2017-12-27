using namespace std;
int main(){}
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<vector>
#include<stack>
struct _Main{
stack<int>stk;
vector< vector<int> >edge;
vector<int>low,dfn,num;
vector<bool>vis,in;
int idx;int cnt;
void dfs(int nd){
	
	int i;in[nd]=true;
	low[nd]=dfn[nd]=idx++;vis[nd]=true;
	stk.push(nd);in[nd]=true;
	for(i=0;i<edge[nd].size();i++){
		if(!vis[edge[nd][i]]){
			dfs(edge[nd][i]);
			low[nd]=min(low[nd],low[edge[nd][i]]);
		}else if(in[edge[nd][i]]){
			low[nd]=min(low[nd],low[edge[nd][i]]);
		}
	}
	if(low[nd]==dfn[nd]){
		int lst;
		do{
			num[dfn[nd]]++;
			lst=stk.top();
			low[lst]=dfn[nd];
			in[lst]=false;
			stk.pop();
		}while(lst!=nd);
		if(num[dfn[nd]]>=2)
		cnt++;
	}
}	
	
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
int n,m;int ans;
_Main(){//beg from 1
	int i,j;int a,b;
	read(n);read(m);
	edge.resize(n+2);low.resize(n+2);dfn.resize(n+2);
	vis.resize(n+2);in.resize(n+2);num.resize(n+2);
	for(i=0;i<m;i++){
		read(a);read(b);
		edge[a].push_back(b);
	}
	for(i=1;i<=n;i++)if(!vis[i]){
		dfs(i);
	}printf("%d\n",cnt);
	ans=-1;
	vis.clear();vis.resize(n+2);
	for(i=1;i<=n;i++)if(!vis[i]){
		if(mark(i) && num[low[i]]>=2){
			if(ans!=-1){
				ans=-1;
				break;
			}else{
				ans=low[i];
			}
		}
	}
	if(ans!=-1){
		for(i=1;i<=n;i++)if(low[i]==ans){
			printf("%d ",i);
		}
	}else{
		printf("-1");
	}
}	
bool mark(int nd){
	int i;int ret=true;
	vis[nd]=true;
	for(i=0;i<edge[nd].size();i++){
		if(low[edge[nd][i]]!=low[nd]){
			ret=false;
		}else if(!vis[edge[nd][i]]){
			ret=mark(edge[nd][i])&&ret;
		}
	}
	return ret;
}	
	
}cdvs2822;
