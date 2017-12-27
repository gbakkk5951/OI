using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
struct Edge{
	int dst;int dis;
	bool friend operator > (Edge a,Edge b){
		return a.dis>b.dis;
	}
};
struct Point{
	int idx;int dis;
	bool friend operator < (Point a,Point b){
		return a.dis<b.dis;
	}
}arr[1005];
priority_queue<Edge,vector<Edge>,greater<Edge> >heap1;
struct Mod{
unsigned int friend operator % (unsigned int a,Mod b){
	a=(a>>31u )+ (a&2147483647u);
	return (a==2147483647u)?0:a;
}	
unsigned int friend operator %= (unsigned int &a,Mod b){
	a=(a>>31u)+ (a&2147483647u);
	return a=(a==2147483647u)?0:a;
}	

}mod;

int head[1005];int nxt[1000010];int to[1000010];int val[1000010];
int eidx;
void inline add(int a,int b,int c){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
	val[eidx]=c;
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
int dis[1005];
void dijkstra(){
	memset(dis,63,sizeof(dis));
	int i;int nd;
	dis[1]=0;
	heap1.push((Edge){1,0});
	
	while(!heap1.empty() ){
		nd=heap1.top().dst;heap1.pop();
		for(i=head[nd];i;i=nxt[i]){
			if(dis[nd]+val[i]<dis[to[i]]){
				dis[to[i]]=dis[nd]+val[i];
				heap1.push((Edge){to[i],dis[to[i]]});
			}
		}
	}
	
	
}

_Main(){
	unsigned int ans[2]={0u,0u};
	
	read(n);read(m);
	int i,j;int a,b,c;int iter=0;
	for(i=0;i<m;i++){
		read(a);read(b);read(c);
		add(a,b,c);add(b,a,c);
	}dijkstra();
	for(i=2;i<=n;i++){
		arr[i].dis=dis[i];
		arr[i].idx=i;
	}sort(arr+2,arr+n+1);
	ans[iter]=1;
	for(i=2;i<=n;i++){
		iter^=1;ans[iter]=0;
		for(j=head[arr[i].idx];j;j=nxt[j])if(dis[to[j]]+val[j]==dis[arr[i].idx] ){
			ans[iter]+=ans[iter^1];
			ans[iter]%=mod;
		}
	}
	printf("%u",ans[iter]);
	
}	
	
	
	
}ezoj1018;


