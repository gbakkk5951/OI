using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
struct _Main{
int n,m,v,e;
int dis[305][305];
int org[2005],change[2005];
double rate[2005];
double ans;
double dp[2005][2005][2];
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			
			a*=10;a+=t-'0';
		}
	}
_Main(){
	int a,b,c;
	int i,j,k;
	memset(dis,63,sizeof(dis));
	read(n);read(m);read(v);read(e);
	for(i=1;i<=n;i++){
		read(org[i]);
	}
	for(i=1;i<=n;i++){
		read(change[i]);
	}	
	for(i=1;i<=n;i++){
		scanf("%lf",&rate[i]);
	}
	for(i=0;i<e;i++){
		read(a);read(b);read(c);
		if(dis[a][b]>c){
			dis[a][b]=dis[b][a]=c;
		}
	}
	for(int i=1;i<=v;i++)dis[i][i]=0;
	for(k=1;k<=v;k++){
		for(j=1;j<=v;j++){
			for(i=1;i<=v;i++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	for(i=0;i<=n+1;i++){
		for(j=0;j<=m+1;j++){
			dp[i][j][0]=dp[i][j][1]=1000000000.0;
		}
	}
	
	/*
	dp[1][0][0]=0;
	dp[1][0][1]=0;
	int o,oo,cc;
	for(i=2;i<=n;i++){
		o=org[i];c=change[i];
		oo=org[i-1];cc=change[i-1];
		dp[i][0][0]=dp[i-1][0][0]+dis[oo][o];
		dp[i][0][1]=dp[i-1][0][0]+dis[oo][c];	
		for(j=1;j<=i-1 && j<=m;j++){
			dp[i][j][0]=min(
				(dp[i-1][j-1][0]+dis[oo][o])*(1.0-rate[i-1])+
				(dp[i-1][j-1][1]+dis[cc][o])*rate[i-1]
				,
				(dp[i-1][j][0]+dis[oo][o])
			);
			dp[i][j][1] =min(
				(dp[i-1][j-1][0]+dis[oo][c])*(1.0-rate[i-1])+
				(dp[i-1][j-1][1]+dis[cc][c])*rate[i-1]
				,
				(dp[i-1][j][0]+dis[oo][c])
			);
		}
	}
	ans=dp[n][0][0];
	for(j=1;j<=m;j++){
		ans=min(ans,dp[n][j][0]);
		ans=min(ans,dp[n][j-1][0]*(1.0-rate[n])+dp[n][j-1][1]*rate[n]);
	}
	*/
	dp[1][0][0]=0;
	dp[1][1][1]=0;
	for(i=2;i<=n;i++){
//		dp[i][0][0]=dp[i-1][0][0]+dis[org[i-1]][org[i]];
		for(j=0;j<=i&&j<=m;j++){
			
			dp[i][j][0]=min(
				dp[i-1][j][0]+dis[org[i-1]][org[i]]
				,
				(dp[i-1][j][1]+dis[org[i-1]][org[i]])*(1.0-rate[i-1])
			   +(dp[i-1][j][1]+dis[change[i-1]][org[i]])*rate[i-1]
			);
			if(j)dp[i][j][1]=min(
				(dp[i-1][j-1][0]+dis[org[i-1]][org[i]])*(1.0-rate[i])
			   +(dp[i-1][j-1][0]+dis[org[i-1]][change[i]])*rate[i]
			    ,
			    (dp[i-1][j-1][1]+dis[org[i-1]][org[i]])*(1.0-rate[i-1])*(1.0-rate[i])
			   +(dp[i-1][j-1][1]+dis[change[i-1]][org[i]])*rate[i-1]*(1.0-rate[i])
			   +(dp[i-1][j-1][1]+dis[org[i-1]][change[i]])*(1.0-rate[i-1])*rate[i]
			   +(dp[i-1][j-1][1]+dis[change[i-1]][change[i]])*rate[i-1]*rate[i]
			);
		}
	}
	/*
	printf("%d %d %f %f\n",dis[org[4-1]][org[4]],dis[change[4-1]][org[4]],rate[4-1],rate[4]);
	
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++){
			printf("%d %d %lf %lf; ",i,j,dp[i][j][0],dp[i][j][1]);
		}
		printf("\n");
	}
	*/
	ans=dp[n][0][0];
	for(i=0;i<=m;i++){
		ans=min(ans,dp[n][i][0]);
		ans=min(ans,dp[n][i][1]);
	}
	printf("%.2lf\n",ans);
}

	
	
	
}ezoj1094;
