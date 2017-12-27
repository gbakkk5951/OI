using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<vector>
int nxt[600010];
int to[600010];
int eidx;
bool in[300010];int fa[300010];
int getfa(int nd){
	if(fa[nd]){
		return fa[nd]=getfa(fa[nd]);
	}return nd;
}
struct Path{
	int s,t,lca;
	int len;
}rela[300011];
int begdep[600010];
int enddep[600050];
const int base=300010;
struct Point{
	int dep;
	int head;
	int time;
	int ans;
	vector<int>rel;
	vector<int>son;
}point[300011];
void tarjan(int nd,int from){
	in[nd]=true;point[nd].dep=point[from].dep+1;
	int i;
	#define re rela[point[nd].rel[i]]	
	for(i=0;i<point[nd].rel .size();i++)if(in[re.s] && in[re.t]){
		if(nd==re.s ){
			re.lca=getfa(re.t);
			point[re.lca].son .push_back(point[nd].rel[i]);
			re.len=point[re.s].dep-point[re.lca].dep+point[re.t].dep-point[re.lca].dep;
		}else {
			re.lca=getfa(re.s);
			point[re.lca].son .push_back(point[nd].rel[i]);
			re.len=point[re.s].dep-point[re.lca].dep+point[re.t].dep-point[re.lca].dep;
		}
	}
	for(i=point[nd].head;i;i=nxt[i])if(to[i]!=from){
		tarjan(to[i],nd);
		fa[to[i]]=nd;
	}
}
void dfs(int nd,int from){
	int i;
	int t1=begdep[point[nd].time+point[nd].dep];
	int t2=enddep[base+point[nd].time-point[nd].dep];
	
	#define re rela[point[nd].rel[i]]	
	#define so rela[point[nd].son[i]]
	
	//处理子树
	for(i=point[nd].head;i;i=nxt[i])if(to[i]!=from){
		dfs(to[i],nd);
	}
	//施加影响
	for(i=0;i<point[nd].rel.size();i++){
		if(re.s==nd){
			begdep[point[nd].dep]++;
		}else{
			enddep[base+re.len-point[nd].dep]++;
		}
	}
	//计算答案
	point[nd].ans+=begdep[point[nd].time+point[nd].dep]-t1;
	point[nd].ans+=enddep[base+point[nd].time-point[nd].dep]-t2;	 
	//清空nd为lca的影响 + 去除多余 
	for(i=0;i<point[nd].son.size();i++){
		if(point[nd].time+point[nd].dep==point[so.s].dep){
			point[nd].ans--;
		}
		begdep[point[so.s].dep]--;
		enddep[base+so.len-point[so.t].dep]--;
	}
}



struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
	
int n,m;
void inline add(int a,int b){
	eidx++;
	nxt[eidx]=point[a].head;
	point[a].head=eidx;
	to[eidx]=b;
}	
	
_Main(){
	int i,j,k;int a,b,c;
	read(n);read(m);
	for(i=1;i<=n-1;i++){
		read(a);read(b);
		add(a,b);add(b,a);
	}
	for(i=1;i<=n;i++){
		read(point[i].time);
	}
	for(i=1;i<=m;i++){
		
		read(a);read(b);
		if(a==b){
			if(point[a].time==0){
				point[a].ans++;
			}
			continue;
		}
		rela[i].s=a;rela[i].t=b;
		point[a].rel.push_back(i); 
		point[b].rel.push_back(i);
	}tarjan(1,0);
	dfs(1,0);
	for(i=1;i<=n;i++){
		printf("%d ",point[i].ans);
	}
}	
	
	
	
	
}running;
