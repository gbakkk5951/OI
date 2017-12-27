using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>

struct _Main{
int n,time;
int v[105];
int dp[105][205];	
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
int nxt[205],to[205],head[105];	
int idx;		
void inline add(int a,int b){
	idx++;
	nxt[idx]=head[a];
	head[a]=idx;
	to[idx]=b;
}
int ans;
int inline abs(int a){
	return a>>31^((a>>31)+a);
}
int inline max(int a,int b){
	return ((a+b)+abs(a-b))>>1;
}
_Main(){
	int i,a,b;
	read(n);read(time);
	for(i=1;i<=n;i++){
		read(v[i]);
	}
	for(i=0;i<n-1;i++){
		read(a);read(b);
		add(a,b);add(b,a);
	}
	dfs(1,0);
	noback(1,0);
	for(i=0;i<=time;i++){
		ans=max(ans,nbk[1][i]);
	}
	printf("%d",ans);
}
int without[105][205];
int nbk[105][205];
void noback(int nd,int from){
	int i,j,k;
	nbk[nd][0]=v[nd];
	for(i=head[nd];i;i=nxt[i]){
		if(to[i]!=from){
			noback(to[i],nd);
			for(j=time;j>=1;j--){
				for(k=0;k<j;k++){
					nbk[nd][j]=max(nbk[nd][j],without[to[i]][k]+nbk[to[i]][j-k-1]);
				}
			}
		}
	}
}
void dfs(int nd,int from){
	int i,j,k,l;
	dp[nd][0]=v[nd];
	for(i=head[nd];i;i=nxt[i]){
		if(to[i]!=from){
			without[to[i]][0]=v[nd];
		}
	}
	
	
	for(i=head[nd];i;i=nxt[i]){
		if(to[i]!=from){
			dfs(to[i],nd);
			for(j=time;j>=2;j--){
				for(k=0;k<=j-2;k++){
					dp[nd][j]=max(dp[nd][j],dp[nd][j-k-2]+dp[to[i]][k]);
					for(l=head[nd];l;l=nxt[l]){
						if(l!=i && to[l]!=from){
							without[to[l]][j]=max(without[to[l]][j],without[to[l]][j-k-2]+dp[to[i]][k]);
						}
					}
				}
			}
		}
	}

}
	
}jsk_diamond;
