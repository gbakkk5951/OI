using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cmath>
const long long mod=1e9+7;
const double eps=1e-6;
const double pi=acos(-1.0);
double ox[55],oy[55];int nd[55];
bool vis[55];
bool link[55][55];
double angle[55];
double dis[55];
int cnt;
int change[55];
double mx,my;
long long ans;

bool equal(double a,double b){
	return a+eps>b &&a-eps<b;
}
struct _Main{
long long fastpower(long long base,long long pow){
	long long ans=1;
	while(pow){
		if(pow&1)ans=ans*base%mod;
		if(pow>>=1)base=base*base%mod;
	}return ans;
	
}	
int n,m;double delta;
_Main(){
	int i,j,k;int a,b;int c;
	scanf("%d%d%d",&n,&m,&c);
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&ox[i],&oy[i]);
		mx+=ox[i];my+=oy[i];
	}mx/=n;my/=n;	
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		link[a][b]=link[b][a]=1;
	}
	for(i=1;i<=n;i++){
		ox[i]-=mx;oy[i]-=my;
		dis[i]=ox[i]*ox[i]+oy[i]*oy[i];
		
		if(equal(ox[i],0) && equal(oy[i],0)){
			angle[i]=0;
		}else if(ox[i]<eps){
			angle[i]=acos(oy[i]/sqrt(dis[i]) );
		}else{
			angle[i]=pi+acos(-oy[i]/sqrt(dis[i]));
		}
	}
	for(a=1;a<=n;a++)if(!equal(dis[a],0))break;
	for(i=1;i<=n;i++)if(equal(dis[i],dis[a])){
		delta=angle[i]-angle[a];nd[a]=i;
		for(j=1;j<=n;j++){
			if(j==a)continue;
			for(k=1;k<=n;k++)if(equal(dis[j],dis[k]) &&
					 (equal(angle[k],angle[j]+delta) || 
					 equal(fabs(angle[j]+delta-angle[k]),2.0*pi)
					  || equal(dis[j],0))){
				nd[j]=k;break;
			}
			if(k>n)break;
		}if(j<=n)continue;
		
		
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++)if(link[j][k] && !link[nd[j]][nd[k]]){
				break;
			}
			if(k<=n)break;
		}if(j<=n)continue;
		memset(vis,0,sizeof(vis));	
		for(j=1;j<=n;j++)if(!vis[j]){
			change[cnt]++;
			for(k=j;!vis[k];k=nd[k]){
				vis[k]=1;
			}
		}cnt++;
	}	
		
	
	

	for(i=0;i<cnt;i++){
		ans+=fastpower(c,change[i]);
	}
	ans*=fastpower(cnt,mod-2);
	ans%=mod;
	printf("%lld",ans);
}	
	
	
	
	
}jsk; 
