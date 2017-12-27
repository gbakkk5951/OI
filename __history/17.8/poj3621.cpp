int main(){}
using namespace std;
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<list>
const double eps=1e-6;

struct Edge{
	int to;int time;
};
int n,m;
list<Edge> head[1005];
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
	
void inline insert(int nd){
	if(!in[nd]){
		in[nd]=true;
		q[idx++]=nd;
	}
}	
double happy[1005];
double dis[1005];
int q[1000010];int idx;
int cnt[1005];bool in[1005];
bool legal;
void islegal(int nd){
	in[nd]=true;
	list<Edge>::iterator it;
	for(it=head[nd].begin();it!=head[nd].end();it++){
		if(in[it->to]){
			if(it->to==0){
				legal=true;
				return;
			}
		}else{
			islegal(it->to);
			if(legal)return;
		}
	}
}


bool spfa(double lmd){//return if it's too small;
//	printf("spfa(%f)",lmd);
	memset(dis,0,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	memset(in,0,sizeof(in));
	idx=0;
	int front=0;int i;
	q[idx++]=0;dis[0]=0;in[0]=true;
	for(i=1;i<n;i++){
		dis[i]=10000000;
	}
	
	
	list<Edge>::iterator it;
	while(front<idx){
		
		for(it=head[q[front]].begin() ;it!=head[q[front]].end();it++){
			if(dis[q[front]]+ it->time*lmd-happy[it->to]<dis[it->to]){
				dis[it->to]=dis[q[front]]+ it->time*lmd-happy[it->to];
				cnt[it->to]++;
				if(cnt[it->to]>n){
					return true;
				}
				insert(it->to);
			}
		}
		in[q[front]]=false;
		front++;
	}
	return false;
	
}	

void inline add(int a,int b,int c){
	head[a].push_back((Edge){b,c});	
}
_Main(){
	read(n);read(m);
	int i;int a,b,c;
	for(i=0;i<n;i++){
		read(happy[i]);
	}for(i=0;i<m;i++){
		read(a);read(b);read(c);
		add(a-1,b-1,c);
	}
	islegal(0);
	if(!legal){
		printf("0");
		return;
	}
	
	double left=0,right=1000,mid;
	while(fabs(right-left)>eps){
		mid=(left+right)/2.0;
		if(!spfa(mid)){
			right=mid;
		}else{
			left=mid;
		}
	}
	printf("%.2f",left);
}	
	
	
	
	
	
}poj3621;

