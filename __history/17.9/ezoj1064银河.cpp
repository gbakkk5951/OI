using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>


struct _Main{

int nxt[400005];int to[400005];
int head[100005];int in[100005];
bool vis[100005]; 
int val[100005];int rel[400005];
int eidx;
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
void add(int a,int b,int c){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
	rel[eidx]=c;//1表示小于 0表示小于等于 
}
int cnt[100005];
long long sum;
void dfs(int nd){
	in[nd]=-1;
	sum+=(long long)val[nd]*cnt[nd];
	int i;
	for(i=head[low[nd]];i;i=nxt[i])if(low[nd]!=low[to[i]]){
		in[low[to[i]]]--;
		val[low[to[i]]]=max(val[low[to[i]]],val[low[nd]]+rel[i]);
		if(in[low[to[i]]]==0){
			dfs(low[to[i]]);
		}
	}
}
bool instk[100005];
void tarjan(int nd){
	vis[nd]=true;
	dfn[nd]=low[nd]=++dfncnt;
	int i;
	stk[stkcnt++]=nd;instk[nd]=true;
	for(i=head[nd];i;i=nxt[i]){
		if(vis[to[i]] && instk[to[i]]){
			low[nd]=min(low[nd],low[to[i]]);
		}else if(!vis[to[i]]){
			tarjan(to[i]);
			if(instk[to[i]])low[nd]=min(low[nd],low[to[i]]);
		}
	}
	if(dfn[nd]==low[nd]){
		while(1){
			instk[stk[stkcnt-1]]=false;
			low[stk[stkcnt-1]]=nd;
			stkcnt--;
			cnt[nd]++;
			if(stk[stkcnt]==nd)break;
		}
	}
}

int stk[100005];
int stkcnt;
int n,m;
int dfncnt;
int dfn[100005];
int low[100005];
int in1,in2,in3;
_Main(){
	int i,j;
	read(n);read(m);
	for(i=0;i<m;i++){
		read(in1);read(in2);read(in3);
		if(in2==in3)continue;
		switch(in1){
		case 1:{
			add(in3,in2,0);
			add(in2,in3,0);
			break;
		}
		case 2:{
			add(in2,(in3 ),1);
			break;
		}
		case 3:{
			add((in3 ),(in2 ),0);
			break;
		}				
		case 4:{
			add((in3 ),(in2 ),1);
			break;
		}
		case 5:{
			add((in2 ),(in3 ),0);
			break;
		}
		}
	}
	for(i=1;i<=n;i++)if(!vis[i]){
		tarjan(i);
	}

	for(i=1;i<=n;i++){
		for(j=head[i];j;j=nxt[j])if(low[to[j]]!=low[i]){
			in[low[to[j]]]++;
		}
	}
	for(i=1;i<=n;i++){
		if(i!=low[i]){
			for(j=head[i];j;j=nxt[j])if(low[to[j]]!=low[i]){
				add(low[i],low[to[j]],rel[j]);
			}
		}
	}
	int temp=0;
	for(i=1;i<=n;i++)if(in[low[i]]==0){
		val[low[i]]=1;
		dfs(low[i]);
	}
	printf("%lld",sum);
}

	
}ezoj1064;
