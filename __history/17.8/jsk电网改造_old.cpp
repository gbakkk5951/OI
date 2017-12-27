using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
struct _Main{
template <typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
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

int head[307];
int to[307];
int v[307];
int nxt[307];
int dp[307][307][2];
int n;int setsize;int m;int idx;

void inline add(int a,int b,int c){
	idx++;
	nxt[idx]=head[a];
	head[a]=idx;
	to[idx]=b;
	v[idx]=c;
}
_Main(){
	int i,a,b,c;
	memset(dp,62,sizeof(dp));
	read(n);read(m);read(setsize);
	if(n-setsize <m-1){
		printf("-1");
		return;
	}
	for(i=0;i<n-1;i++){
		read(a);read(b);read(c);
		add(a,b,c);
		add(b,a,c);
	}
	dfs(1,0);
	printf("%d",min(dp[1][setsize][1],dp[1][setsize][0]));
}	
void dfs(int nd,int from){
	bool leaf=true;
	int i,j,k;
	printf("vis[%d]\n",nd);
	for(i=head[nd];i;i=nxt[i]){
		if(to[i]!=from){
			leaf=false;
			dfs(to[i],nd);

			for(j=setsize;j>=0;j--){
				for(k=0;k+j<=setsize;k++){
					dp[nd][j+k][1]=min(dp[nd][j+k][1],dp[nd][j][1]+dp[to[i]][k][0]);
					dp[nd][j+k][1]=min(dp[nd][j+k][1],dp[nd][j][1]+dp[to[i]][k][1]+v[i]);
					dp[nd][j+k][0]=min(dp[nd][j+k][0],dp[nd][j][0]+dp[to[i]][k][1]);
					dp[nd][j+k][0]=min(dp[nd][j+k][0],dp[nd][j][0]+dp[to[i]][k][0]+(m>2?0:v[i]));
					if(dp[nd][j+k][1]<1000){
						printf("dp(%d)(%d)(1)=%d\n",nd,j+k,dp[nd][j+k][1]);
					}
					if(dp[nd][j+k][0]<1000){
						printf("dp(%d)(%d)(0)=%d\n",nd,j+k,dp[nd][j+k][0]);
					}				
				}
			}
			dp[nd][0][0]=min(dp[nd][0][0],dp[to[i]][0][0]+(m>2?0:v[i]));
			dp[nd][1][1]=min(dp[nd][1][1],dp[to[i]][0][0]);
			if(dp[nd][1][1]<1000){
				printf("dp(%d)(1)(1)=%d\n",nd,dp[nd][1][1]);
			}			
			if(dp[nd][0][0]<1000){
				printf("dp(%d)(0)(0)=%d\n",nd,dp[nd][0][0]);
			}								
		}
	}
	if(leaf){
		printf("leaf");
		dp[nd][1][1]=0;
		dp[nd][0][0]=0;
		if(dp[nd][1][1]<1000){
			printf("dp(%d)(1)(1)=%d\n",nd,dp[nd][1][1]);
		}			
		if(dp[nd][0][0]<1000){
			printf("dp(%d)(0)(0)=%d\n",nd,dp[nd][0][0]);
		}			
	}
}	
	
	
	
}jsk;
