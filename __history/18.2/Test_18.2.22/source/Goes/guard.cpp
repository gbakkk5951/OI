#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
inline int read(){
	char ch='*';int sum=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
		sum*=10,sum+=ch-'0',ch=getchar();
	return sum;
}
#if 0
Writers: G.S.M. && Goes;
锐意进取;
#endif
const int N=50005;
const int M=N<<1;
const int INF=0x3f3f3f3f;
struct ss{
	int to,nex,cap;
}edge[M<<1];int head[N<<1],ecnt=1;
void add(int x,int y){
	edge[++ecnt]=(ss){y,head[x],1};
	edge[++ecnt]=(ss){x,head[y],0};
	head[x]=ecnt-1;head[y]=ecnt;
}
//网络流 
int level[N<<1],S,T,n,m,k[N];
bool bfs(){
	memset(level,0,sizeof(level));
	queue<int>Q;Q.push(S);level[S]=1;
	while(!Q.empty()){
		int pos=Q.front();Q.pop();
		for(int i=head[pos];i;i=edge[i].nex)
		if(edge[i].cap&&!level[edge[i].to]){
			level[edge[i].to]=level[pos]+1;
			Q.push(edge[i].to);
			if(edge[i].to==T)return true;
		}
	}return false;
}
int dfs(int pos,int flow){
	if(pos==T||!flow)return flow;int ret=0;
	for(int i=head[pos];i;i=edge[i].nex)
	if(level[edge[i].to]==level[pos]+1){
		int temp=dfs(edge[i].to,min(flow,edge[i].cap));
		edge[i].cap-=temp;edge[i^1].cap+=temp;
		flow-=temp;ret+=temp;if(!flow)return ret;
	}return ret;
}
int Dinic(){
	int res=0;while(bfs()) 
	res+=dfs(S,INF);return res;
}
//辅助输入 
struct node{
	int a,b,c,d;
}gsin[N];int sum[N],bbb;
int num(int build,int floor){
	return sum[build]+floor;
}int nex(int x){if(x==m)return 1;else return x+1;}

int main()
{
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	m=read();int A,B,C,D;
	while(scanf("%d%d%d",&A,&B,&C)!=EOF)
	{
		D=nex(C);
		k[C]=max(k[C],A);k[D]=max(k[D],B);
		gsin[++bbb]=(node){A,B,C,D};
	}for(int i=1;i<=m;i++)n+=k[i],sum[i]=sum[i-1]+k[i-1];
	//√ 
	S=0;T=2*n+1;
	for(int i=1;i<=bbb;i++){
		add(num(gsin[i].c,gsin[i].a),n+num(gsin[i].d,gsin[i].b));
		add(num(gsin[i].d,gsin[i].b),n+num(gsin[i].c,gsin[i].a));
	}for(int i=1;i<=n;i++)add(S,i),add(i+n,T);
	//建边√ 
	int ans=Dinic();ans/=2;printf("%d",n-ans);return 0;	
}
/*
3
1 1 1
1 2 1
1 1 2
*/
