using namespace std;
int main(){}
#include<cstdio>
#include<algorithm>
#include<cstring>
double sdp[270100];
const double eps=1e-6;
int head[20];
int to[40];
int nxt[40];
double p[20];
double fix[20];
double cst[20];
int cnt[20];
int n,m;
struct _Main{
double dptmp[20];
double dp[20];
void getdp(int nd,int from,int s){
	int i,j;
	
	for(i=head[nd],cnt[nd]=0;i;i=nxt[i])if(to[i]!=from&& (1&(s>>to[i]))){
		getdp(to[i],nd,s);
		cnt[nd]++;
	}
	memset(dptmp,0,sizeof(dptmp));
	
	for(i=head[nd];i;i=nxt[i])if(to[i]!=from&& (1&(s>>to[i]))){
		dptmp[0]=(dptmp[0]+dp[to[i]])*p[nd]+(-dptmp[0]+dp[to[i]])*(1-p[nd])*(1.0/cnt[nd]);
		for(j=min(m,cnt[nd]-1);j>0;j--){
			dptmp[j]=max(dptmp[j-1],(dptmp[j]+dp[to[i]])*p[nd]+(-dptmp[j]+dp[to[i]])*(1-p[nd])*(1.0/(cnt[nd]-j)));
		}
	}
	for(i=min(m,cnt[nd]-1);i>=0;i--){
		dp[nd]=max(dp[nd],dptmp[i]);
	}dp[nd]+=fix[nd];
}
int eidx;
void add(int a,int b){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
}
_Main(){
	int i;int I;int a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	for(i=1;i<=n;i++){
		scanf("%lf",&cst[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%lf",&fix[i]);
	}	
	for(i=1;i<=n;i++){
		scanf("%lf",&p[i]);
	}		
	for(I=(1<<n)-1;I;I--){
		
		for(i=0;i<n;i++)if((I>>i)&1){
			memset(dp,0,sizeof(dp));
			getdp(i+1,0,I<<1);
			sdp[I^(1<<i)]=max(sdp[I^(1<<i)],sdp[I]+dp[i+1]-fix[i+1]);
		}
	}
	for(i=1;i<=n;i++){
		sdp[0]+=cst[i];
	}
	printf("%.0lf",sdp[0]);
}	
	
	
	
}teslatower;
