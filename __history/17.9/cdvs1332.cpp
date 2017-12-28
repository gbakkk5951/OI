using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<bitset>
#include<stack>
stack<int>stk;
namespace rev{
	int ans;
	stack<int>block;
	bitset<5010>v;
	int nxt[50010];
	int t[50010];
	int low[5010];
	int head[5010];
	int cnt[5010];
	int idx;
	int mn;
	void inline add(int a,int b){
		idx++;
		nxt[idx]=head[a];
		head[a]=idx;
		t[idx]=b;
	}	
	void inline ini(){
		mn=100000000;
	}
	void dfs(int nd,bool first=true){
		int i;
		if(first){
			ini();	
			v[nd]=1;mn=min(nd,mn);
			block.push(nd);
			for(i=head[nd];i;i=nxt[i])if(!v[t[i]]){
			
				dfs(t[i],false);
			}
			while(!block.empty() ){
				cnt[mn]++;
				low[block.top()]=mn;
				block.pop();
			}if(cnt[mn]>cnt[ans]||(cnt[mn]==cnt[ans] && mn<ans)){
				ans=mn;
			}
		}else{
			v[nd]=1;mn=min(nd,mn);
			block.push(nd);
			for(i=head[nd];i;i=nxt[i])if(!v[t[i]]){
				dfs(t[i],false);
			}
		}
	}
	
	
}
namespace org{
	bitset<5010>v;
	int nxt[50010];
	int t[50010];	
	int head[5010];
	int idx;
	void inline add(int a,int b){
		idx++;
		nxt[idx]=head[a];
		head[a]=idx;
		t[idx]=b;
	}
	void dfs(int nd){
		v[nd]=1;int i;
		for(i=head[nd];i;i=nxt[i])if(!v[t[i]]){
			dfs(t[i]);
		}stk.push(nd); 
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
_Main(){
	int a,b,c;int n,m;int i,j,k;
	read(n);read(m);
	for(i=0;i<m;i++){
		read(a);read(b);read(c);
		rev::add(b,a);
		org::add(a,b);
		if(c==2){
			rev::add(a,b);
			org::add(b,a);			
		}
	}
	for(i=1;i<=n;i++)if(!org::v[i]){
		org::dfs(i);
	}
	while(!stk.empty()){
		if(!rev::v[stk.top()]){
			rev::dfs(stk.top());
		}
		stk.pop();
	}
	printf("%d\n",rev::cnt[rev::ans]);
	for(i=1;i<=n;i++)if(rev::low[i]==rev::ans){
		printf("%d ",i);
	}
	
}	
	
}cdvs1332;
