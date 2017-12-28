using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<queue>
struct _Main{
int head[10005];
int nxt[200010];	
int to[200010];
int rhead[10005];
int rnxt[200010];
int rto[200010];
int eidx,reidx;
bool legal[10005];
bool vis[10005];
bool inq[10005];
queue<int>q;
void inline add(int a,int b){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
}	
void inline radd(int a,int b){
	reidx++;
	rnxt[reidx]=rhead[a];
	rhead[a]=reidx;
	rto[reidx]=b;
}
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
int n,m,beg,end;
_Main(){
	int a,b;int i,j,k;int step,g;
	read(n);read(m);
	for(i=0;i<m;i++){
		read(a);read(b);
		add(a,b);radd(b,a);
	}
	read(beg);read(end);
	getvis(end);
	for(i=1;i<=n;i++){
		for(j=head[i];j;j=nxt[j])if(!vis[to[j]]){
			break;
		}
		if(j)legal[i]=false;
		else legal[i]=true;
	}
	
	
	if(!legal[beg]){
		printf("-1");
	}else{
		q.push(beg);inq[beg]=1;
		step=0;
		while(!q.empty()){
			g=q.size();
			for(i=0;i<g;i++){
				if(q.front()==end){
					break;
				}
				for(j=head[q.front()];j;j=nxt[j])if(legal[to[j]] && !inq[to[j]]){
					inq[to[j]]=true;
					q.push(to[j]);
				}
				q.pop();
			}
			if(i<g)break;
			step++;
		}
		printf("%d",step);
	}
}	
void getvis(int nd){
	vis[nd]=true;
	int i;
	for(i=rhead[nd];i;i=rnxt[i])if(!vis[rto[i]]){
		getvis(rto[i]);
	}
}


}ezoj1105;
