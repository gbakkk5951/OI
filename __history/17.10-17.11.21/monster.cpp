using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
long long dp[100010];
int head[100010];
int nxt[1000010];
int to[1000010];
bool vis[100010];
int noratk[100010];
int magatk[100010];


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
void getdp(int nd){
	vis[nd]=true;
	int i;long long sum=noratk[nd];
	dp[nd]=magatk[nd];
	for(i=head[nd];i;i=nxt[i]){
		if(!vis[to[i]])getdp(to[i]);
		sum+=dp[to[i]];
		if(sum>=magatk[nd]){
			sum=magatk[nd];
			break;
		}
	}
	dp[nd]=sum;
}
int n;
int eidx;
void inline add(int a,int b){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
}
_Main(){
	freopen("monster6.in","r",stdin);
//	freopen("monster.out","w",stdout);
	read(n);int i,j;int a,b;
	memset(dp,63,sizeof(long long)*(n+3));
	for(i=1;i<=n;i++){
		read(noratk[i]);
		read(magatk[i]);
		read(a);
		for(j=0;j<a;j++){
			read(b);
			add(i,b);
		}
	}
	getdp(1);
	printf("%lld",dp[1]);
	fclose(stdout);
}	

	
	
	
	
	
	
}monster;


