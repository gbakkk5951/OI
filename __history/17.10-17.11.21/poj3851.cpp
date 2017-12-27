using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cmath>
const int INF=0x3f3f3f;
template<typename Type>
	void read(Type &a){
		char t,f=1;
		while(!isdigit(t=getchar())){
			if(t=='-')f=-1;
		}
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
		a*=f;
	}
struct Node{
	int x[3][2];
	int tme;int add;
	void fakepoint(){
		int i;
		for(i=0;i<3;i++){
			x[i][1]=x[i][0];
		}
		tme=-INF;add=0;
	}
	void inline readpair(int a){
		int i;
		for(i=0;i<3;i++){
			read(x[i][a]);
		}
	}
}node[55];


struct _Main{

	int distance(const Node &a,const Node &b ){
		double sum=0;int i;
		for(i=0;i<3;i++){
			sum+=pf(a.x[i][1]-b.x[i][0]);
		}
		return a.add+(int)ceil(sqrt(sum));
	}
	
	double pf(int a){
		return (double)a*a;
	}
	int n;
	int dis[55];
	int map[55][55];
	int pre[55];
	void solve(){
		bool flag;
		int i,j,k,t;
		memset(pre,255,sizeof(pre));
		memset(dis,63,sizeof(dis));		
		dis[0]=0;
		while(1){
			
			flag=false;
			for(i=0;i<=n;i++){
				if(dis[i]<=node[i].tme)pre[i]=-1;
				for(j=0;j<=n;j++){
					t=max(node[i].tme,dis[i])+map[i][j];
					if(t<dis[j]){
						dis[j]=t;
						flag=true;
						pre[j]=i;
					}
				}
			}
			if(!flag)return;
			for(i=0;i<=n;i++){
				k=i;
				for(j=0;k!=-1 && j<=n;j++)k=pre[k];
				if(k==-1)continue;
				int mn=max(dis[pre[k]],node[pre[k]].tme)+map[pre[k]][k]-node[k].tme;
				for(j=pre[k];j!=k;j=pre[j]){
					mn=min(mn,max(dis[pre[j]],node[pre[j]].tme)+map[pre[j]][j]-node[j].tme);
				}
				if(mn<=0)continue;
				dis[k]-=mn;
				for(j=pre[k];j!=k;j=pre[j]){
					dis[j]-=mn;
				}
			}
			
			
		}
	}
	
	_Main(){
		int T;
		int i,j,k;
		read(T);
		while(T--){

			node[0].readpair(0);
			node[0].fakepoint();
			node[51].readpair(0);
			node[51].fakepoint();
			read(n);
			n++;
			node[n]=node[51];
			for(i=1;i<n;i++){
				node[i].readpair(0);
				node[i].readpair(1);
				read(node[i].tme);
				read(node[i].add);
			}
			for(i=0;i<=n;i++){
				for(j=0;j<=n;j++){
					map[i][j]=distance(node[i],node[j]);
				}
			}
			solve();
			printf("%d\n",dis[n]);
		}
	}
	
}poj3851;
