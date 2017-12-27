using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define so SearchObject
#include<queue>

struct SearchObject{
	long long s;char astar;char cost;char b;
	bool friend operator < (const so &a,const so &b){
		return a.astar<b.astar;
	}
	bool friend operator > (const so &a,const so &b){
		return a.astar>b.astar;
	}
}temp;
priority_queue<so,vector<so>,greater<so> >Heap;
struct alpha5{
	int	N;
};
struct alpha4{
	alpha5	A;
};
struct alpha3{
	alpha4	M;
};
struct alpha2{
	alpha3	D;
};
struct alpha1{
	alpha2	A;
}M;
struct _Main{
bool  issquare(long long s,int x,int y,int size){
	int i;
	for(i=0;i<size;i++){
		if(!(  (s&(1LL<<( y*(2*n+1)+x+i) ) ) 
			&& (s&(1LL<<( (y+i)*(2*n+1) +n + x   ) ) ) 
			&& (s&(1LL<<( y*(2*n+1)+x+i + size*(2*n+1) )))
			&& (s&(1LL<<( (y+i)*(2*n+1)	+n + x + size )))
			) ){
			return false;
		}
	}return true;
}	
void printbit(long long s){
	int i;
	for(i=0;i<tot;i++){
		printf("%d",(int)((s>>i & 1LL )));
	}
}
int  count(long long s,int size){
	int i,j;int ret=0;
	for(i=0;i<=n-size;i++){
		for(j=0;j<=n-size;j++){
			if(issquare(s,i,j,size)){
				ret++;
			}
		}
	}
	return ret;
}
int  TotCount(long long s){
	int i;int ret=0;
	for(i=1;i<=n;i++){
		ret+=count(s,i);
	}return ret;
}
int inline AStar(long long s){
	return (count(s,1)+1)>>1;
}
void inline insert(long long s,int c=0,int b=0){
	temp.s=s;temp.b=b;
	temp.cost =c;
	temp.astar =c+AStar(s);
	Heap.push(temp); 
}
template<typename type>
	void inline read(type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
	
	
int n;	
_Main(){
	int T;long long beg;
	read(T);int j,i;
	int k;
	while(T--){
		read(n);
		tot=(n+1)*n*2;
		M.A.D.M.A.N;
		
		beg=0;
		for(i=0;i<tot;i++){
			beg|=(1LL<<i);
		}
		read(k);
		for(i=0;i<k;i++){
			read(j);
			beg^=(1LL<<(j-1));
		}
		insert(beg);
		bfs();
	}
}
int tot;
void bfs(){
	int i;so s;
	while(!Heap.empty()){
		s=Heap.top();
		Heap.pop();	
		if(TotCount(s.s)==0){
			printf("%d\n",(int)s.cost);
			while(!Heap.empty() ){
				Heap.pop();
			}
			return;
		}
		for(i=s.b;i<tot;i++)if(s.s&(1LL<<i)){
			insert(s.s^(1LL<<i),s.cost+1,i+1);
		}
	}
	
	
}	
	
}SquareDestroyer;
