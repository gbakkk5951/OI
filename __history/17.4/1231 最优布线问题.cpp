#include<cstdio>
#include<queue>
using namespace std;
struct edge;
priority_queue<edge>heap;

struct edge{
	int r,c;
	bool friend operator < (edge a,edge b){
		return a.c > b.c;
	}
};
bool in[100010];
int head[100010],to[200020],val[200020],nxt[200020];
int tail[100010];
int tot;
long long ans;
struct _Main{
int n,m;
void add(int v,int r,int l){
	if(!head[l]){
		head[l]=tot;
	}else{
		nxt[tail[l]]=tot;
	}
	tail[l]=tot;
	to[tot]=r;
	val[tot]=v;
	tot++;
	if(!head[r]){
		head[r]=tot;
	}else{
		nxt[tail[r]]=tot;
	}
	tail[r]=tot;
	to[tot]=l;
	val[tot]=v;
	tot++;	
}
_Main(){
	tot=1;
	n=read();m=read();
	int i,j;
	for(i=0;i<m;i++){
		add(read(),read(),read());
	}
	prim();
	printf("%lld",ans);
}
int read(){
	char f=1,t;int ans=0;
	while((t=getchar())<'0'||t>'9'){if(t=='-')f=-1;}
	do{ans*=10;ans+=t-'0';}while((t=getchar())<='9'&&t>='0');
	return f*ans;
}
void prim(){
	int now=head[1];
	int left=n-1;
	edge t,t2;
	
	while(now){
		t.r=to[now];t.c=val[now];
		heap.push(t);
		now=nxt[now];
	}
	in[1]=true;
	while(left){
		t=heap.top();
		heap.pop();
		if(!in[t.r]){
			left--;
			ans+=t.c;
			in[t.r]=true;
			now=head[t.r];
			while(now){
				if(!in[to[now]]){
				t2.r=to[now];t2.c=val[now];
				heap.push(t2);
				}
				now=nxt[now];
			}
		}
	}
}	
}instance;int main(){}
