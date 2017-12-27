using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<queue>
#include<vector>
#include<functional>
#include<cstring>
struct Node{
	int idx;
	int dis;
	bool friend operator > (const Node &a,const Node &b){
		return a.dis>b.dis;
	}
};
priority_queue<Node,vector<Node>,greater<Node> >heap;
int empty;
struct _Main{
int head[11000];
int nxt[1005];
int to[1005];
int val[1005];
int idx[15];
int dis[11000];
void dijkstra(int beg){
	Node tmp;
	memset(dis,63,sizeof(dis));
	dis[beg]=0;
	int i;
	heap.push((Node){beg,0});
	
	while(!heap.empty()){
		tmp=heap.top();
		heap.pop();
		if(dis[tmp.idx]==tmp.dis){
			for(i=head[tmp.idx];i;i=nxt[i]){
				if(dis[tmp.idx]+val[i]<dis[to[i]]){
					dis[to[i]]=dis[tmp.idx]+val[i];
					heap.push((Node){to[i],dis[to[i]]});
				}
			}
		}
	}
	
	
}

int sn[15];//station num
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
int eidx;
void inline add(int a,int b,int c){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
	val[eidx]=c;
}	
int n,m;
_Main(){
	int i,j;int a,b,c,d;
	read(n);read(m);
	for(i=1;i<=n;i++){
		read(idx[i]);
		read(sn[i]);
		read(empty);
		for(j=1;j<=sn[i]-1;j++){
			read(a);
			add(idx[i]*100+j,idx[i]*100+j+1,a+1);
			add(idx[i]*100+j+1,idx[i]*100+j,a+1);
		}
	}
	for(i=1;i<=m;i++){
		read(a);read(b);read(c);read(d);
		add(a*100+b,c*100+d,0);
		add(c*100+d,a*100+b,0);
	}
	for(i=1;i<=5;i++){
		read(empty);read(empty);
		read(a);read(b);read(c);read(d);
		dijkstra(a*100+b);
		printf("%d\n",dis[c*100+d]);
	}
}	
	
	
}ezoj1118;
