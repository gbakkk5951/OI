#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<vector>
using namespace std;

struct _main{
int d[15000];
int nxt[15000];
int to[15000];
int head[15000];
int tail[15000];
int dis[15000];
int q_min;
int matrix[62][62];
int beg[61],bt;
int end[61],et;
int n,m;
int tot;
bool in[15000];
bool cmpz(int a,int b){
	return d[a]<d[a];
}
struct vetex{
	int num;
	int d;
	bool	friend operator  < (vetex a,vetex b){
		return a.d>b.d;
	}
};
priority_queue<vetex>q;

void clear(){
	memset(d,127,sizeof(d));
	memset(in,0,sizeof(in));
}
void printmatrix(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",matrix[i][j]);
			
			
		}
		printf("\n");
		
	}
	
}
void printlist(){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			k=head[i*100+j];	
			printf("%d:(",i*100+j);
			
			printf("%d[%d],",to[k],dis[k]);
			while(k=nxt[k]){
				printf("%d[%d],",to[k],dis[k]);
			}
			printf(")\n");
		}
	}
}
void printbeg(){
	int i;
	printf("beg:");
	for(i=0;i<bt;i++){
		printf("%d,",beg[i]);
	}printf("\n");
}
void printend(){
	int i;
	printf("end:");
	for(i=0;i<et;i++){
		printf("%d,",end[i]);
	}printf("\n");
}
int min(int in,int b){
	return in<b?in:b;
}
inline int abs(int val){
	return (val>>31)^((val>>31)+val);
}
_main(){
	int i,j;
	q_min=2147483647;
	readin();
//	printmatrix();
	deal();
//	printlist();
//	printbeg();
//	printend();
	for(i=0;i<bt;i++){
		clear();
		dijkstra(beg[i]);
		getans();
		
	}
	
	printf("%d\n",q_min<2047483647?q_min:-1);
}
void readin(){
	int i,j;
	n=read();m=read();
	if(n==1){
		for(j=0;j<m;j++){
			if(read()){
				q_min=min(q_min,read());
			}else read();
		}
		printf("%d\n",q_min<2047483647?q_min:-1);
		exit(0);		
	}
	for(j=0;j<m;j++){
		if(read()){
			matrix[0][j]=-1;
			beg[bt++]=j;
		}
		else matrix[0][j]=1;
		matrix[0][j]*=read();
	}	
	for(i=1;i<n-1;i++){
		for(j=0;j<m;j++){
			if(read())matrix[i][j]=-1;
			else matrix[i][j]=1;
			matrix[i][j]*=read();
		}
	}
	for(j=0;j<m;j++){
		if(read()){
			matrix[n-1][j]=-1;
			end[et++]=100*(n-1)+j;
		}
		else matrix[n-1][j]=1;
		matrix[n-1][j]*=read();
	}		
	
}
void deal(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
				head[i*100+j]=tot;
				to[tot]=(i*100)+(j?j-1:m-1);
				dis[tot]=abs(matrix[i][j?j-1:m-1]);
				tail[i*100+j]=tot;
				tot++;
				nxt[tail[i*100+j]]=tot;
				to[tot]=i*100+((j^(m-1))?j+1:0);
				dis[tot]=abs(matrix[i][(j^(m-1))?j+1:0]);
				tail[i*100+j]=tot;
				tot++;
				if(i<n-1)
				{
					if(matrix[i][j]>>31){
						nxt[tail[i*100+j]]=tot;
						to[tot]=(i+1)*100+j;
						dis[tot]=abs(matrix[i+1][j]);
						tail[i*100+j]=tot;
						tot++;
					}
				}
		}
	}	
}

int read(){
	int ans=0;char t,f=1;
	while((t=getchar())<'0'||t>'9'){
		if(t=='-')f=-1;
	}
	ans=t-'0';
	while((t=getchar())>='0'&&t<='9'){
		ans*=10;
		ans+=t-'0';
	}return ans*f;
}



void getans(){
	int i;
	for(i=0;i<et;i++){
		
		q_min=min(q_min,d[end[i]]);
	//	if(!q_min)printf("min=d[%d]=0 ",end[i]);
	}
}
	
void dijkstra(int s){
	vetex v;

	d[s]=abs(matrix[0][s]);
	v.num=s;
	v.d=d[s];
	q.push(v);
	int now;
	while(!q.empty() ){
		
		now=head[q.top().num]; 
		if(!in[q.top().num])
		{
	//	printf("[%d]=%d ",q.top().num,in[q.top().num]);
		in[q.top().num]=true;
		while(now){
			d[to[now]]=min(d[to[now]],q.top().d+dis[now]);
			v.num=to[now];
			v.d=d[to[now]];
			if(!in[v.num])
			q.push(v);
			now=nxt[now];
		}
		}
		
		
		q.pop();
		
		
	}
	
	
	
}
	
	
	
	
	
	
	
	
	
}instance;int main(){}
