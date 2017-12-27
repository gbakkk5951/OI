using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>

struct _Main{
	
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
int inline abs(int a){
	return a>>31^((a>>31)+a);
}	
int inline min(int a,int b){
	return ((a+b)-abs(a-b))>>1;
}
int to[605];
int head[305];
int v[605];
int nxt[605];	
int idx;		
void inline add(int a,int b,int c){
	idx++;
	nxt[idx]=head[a];
	head[a]=idx;
	v[idx]=c;
	to[idx]=b;
}
int n,m,size;
_Main(){
	int i,a,b,c;
	read(n);read(m);read(size);
	if(n-size < m-1 ){
		printf("-1");return;
	}
	
	for(i=0;i<n-1;i++){
		read(a);read(b);read(c);
		add(a,b,c);add(b,a,c);
	}
	memset(dp,63,sizeof(dp));
	dfs(1,0);
	printf("%d",dp[1][size][1]);
}	
int dp[303][303][2];
void dfs(int nd,int from){
	int i,j,k;
	bool leaf=true;
	
	for(i=head[nd];i;i=nxt[i]){
		if(to[i]!=from){
			leaf=false;
			dfs(to[i],nd);
			for(k=size;k>=0;k--){
			
				for(j=0;j<=k;j++){
					dp[nd][k][1]=min(dp[nd][k][1],dp[nd][k-j][1]+dp[to[i]][j][1]+v[i]);
					dp[nd][k][1]=min(dp[nd][k][1],dp[nd][k-j][1]+dp[to[i]][j][0]);
					dp[nd][k][0]=min(dp[nd][k][0],dp[nd][k-j][0]+dp[to[i]][j][1]);
					dp[nd][k][0]=min(dp[nd][k][0],dp[nd][k-j][0]+dp[to[i]][j][0]+(m>2?0:v[i]));
				}
				dp[nd][k][1]=min(dp[nd][k][1],dp[to[i]][k][1]+v[i]);
				dp[nd][k][1]=min(dp[nd][k][1],dp[to[i]][k][0]);
				dp[nd][k][0]=min(dp[nd][k][0],dp[to[i]][k][0]+v[i]);
				dp[nd][k][0]=min(dp[nd][k][0],dp[to[i]][k][1]);					
			}
		}
	}
	if(leaf){
		dp[nd][1][1]=0;
		dp[nd][0][0]=0;
	}else{
		for(k=size;k>=1;k--){
			dp[nd][k][1]=dp[nd][k-1][1];
		}		
	}

	
}	
	
	
}jsk;
