using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<queue>
#include<cstring>
#include<algorithm>
#include<functional>
#include<vector>
namespace Protector{

struct Edge{
	int dst,val;
	bool operator > (const Edge &b) const{
		return val>b.val;
	}
};

struct _Main{
template<typename Type>
	void  read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
	
int head[2000099],edge[6000905][3];//0 dst 1 val 2 nxt
int dis[2000099];
int eidx;
void inline add(int a,int b,int c){
	eidx++;
	edge[eidx][0]=b;
	edge[eidx][1]=c;
	edge[eidx][2]=head[a];
	head[a]=eidx;	
	swap(a,b);
	eidx++;
	edge[eidx][0]=b;
	edge[eidx][1]=c;
	edge[eidx][2]=head[a];
	head[a]=eidx;		
//	printf("dis %d %d = %d\n",a,b,c);
}

int heng[1005][1005],zong[1005][1005],xie[1005][1005];
int n,m,dst,src;
_Main(){
	int i,j,k,a,b,c;
	read(n);read(m);
	dst=((n-1)*m+m-1<<1)+5;
	src=0;
	memset(dis,63,sizeof(int)*(dst+3));
	for(i=1;i<=n;i++){
		for(j=1;j<=m-1;j++){
			read(heng[i][j]);
		}
	}
	for(i=1;i<=n-1;i++){
		for(j=1;j<=m;j++){
			read(zong[i][j]);
		}
	}
	for(i=1;i<=n-1;i++){
		for(j=1;j<=m-1;j++){
			read(xie[i][j]);
		}
	}
	if(n==1){
		int ans=0x3f3f3f3f << 1;
		for(i=1;i<=m-1;i++){
			ans=min(ans,heng[1][i]);
		}
		printf("%d",ans);
		return ;
	}else if(m==1){
		int ans=0x3f3f3f3f << 1;
		for(i=1;i<=n-1;i++){
			ans=min(ans,zong[i][1]);
		}
		printf("%d",ans);		
		return ;
	}
	
	
	for(i=1;i<=n-1;i++){
		for(j=1;j<=m-1;j++){
			add((i-1)*(m-1)+j-1 +1 << 1, (i-1)*(m-1)+j-1 +1 << 1 |1,xie[i][j]);
			if(i!=n-1) add((i-1)*(m-1)+j-1 +1 << 1,(i-1+1)*(m-1)+j-1 +1 << 1|1,heng[i+1][j]);
			if(j!=m-1) add( (i-1)*(m-1)+j-1 +1  << 1 |1,(i-1)*(m-1)+j-1 +1 +1 << 1,zong[i][j+1]);
		}
	}
	for(i=1;i<=n-1;i++){
		add(0,(i-1)*(m-1)+1-1 +1 << 1,zong[i][1]);
	}
	for(i=1;i<=m-1;i++){
		add(0,(n-1-1)*(m-1)+i-1 +1 << 1 ,heng[n][i]);
	}
	for(i=1;i<=m-1;i++){
		add(dst,(1-1)*(m-1)+i-1 +1 << 1 |1 ,heng[1][i]);
	}
	for(i=1;i<=n-1;i++){
		add(dst,(i-1)*(m-1)+m-1-1 +1 << 1 |1 , zong[i][m]);
	}
	dijkstra();
//	printf("dst =%d\n)",dst);
	printf("%d",dis[dst]);
//	printf("\n");
//	for(i=10;i<=((n-1)*m+m-1<<1|1)+10;i++){
//		printf("dis %d =%d\n",i,dis[i]);
//	}
}
priority_queue<Edge,vector<Edge>,greater<Edge> > heap;
void dijkstra(){
	Edge nd;
	dis[0]=0;
	heap.push((Edge){0,0});
	int i,j,k;
	while(!heap.empty() ){
		nd=heap.top();
		heap.pop();
		if(nd.val==dis[nd.dst]){
			for(i=head[nd.dst];i;i=edge[i][2]){
				if(nd.val+edge[i][1] < dis[edge[i][0]]){
					dis[edge[i][0]] = nd.val+edge[i][1];
					heap.push((Edge){edge[i][0],dis[edge[i][0]]});
				}
			}
		}
	}
	
	
	
}


}bzoj1001;








}
