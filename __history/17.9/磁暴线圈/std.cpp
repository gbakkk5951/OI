using namespace std;
int main(){}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<functional>
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

double dp[20];


void getdp(int nd,int from,int s){
	int i;
	double sum=0;double dptmp[20];
	for(i=head[nd],cnt[nd]=0;i;i=nxt[i])if(to[i]!=from && (s&(1<<to[i]))){
		getdp(to[i],nd,s);
		dptmp[cnt[nd]]=dp[to[i]];
		cnt[nd]++;
	}
	sort(dptmp,dptmp+cnt[nd],greater<double>());
	for(i=0;i<cnt[nd];i++){
		sum+=dptmp[i];
		dp[nd]=max(dp[nd],sum*(p[nd]+(1-p[nd])/(double)(i+1)));
	}
	if(m==0 && cnt[nd])dp[nd]=sum*(p[nd]+(1-p[nd])/(double)cnt[nd]);
	dp[nd]+=fix[nd];
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
	sdp[0]/=4.0;
	if(fabs(sdp[0]-round(sdp[0]))>0.295){
		printf("fail");
	}
	printf("%.0lf",sdp[0]);
	fclose(stdout);
}	
	
	
	
}teslatower;
