using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
const long long mod=(long long)1e9+7;
long long fastpower(long long base,long long pow){
	long long ans=1;
	while(pow){
		if(pow&1){
			ans=ans*base%mod;
		}
		pow>>=1;
		base=base*base%mod;
	}
	return ans;
}
long long inline getdiv(long long a){
	return fastpower(a,mod-2);
}
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
int eidx;
void inline add(int a,int b){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
	son[b]=1;
}
int height[3005];
long long inline getsum(int nd,int idx){
	if(idx<0)return 0;
	return dp[nd][min(idx,height[nd])];
}
long long getdp(int nd,int idx){
	return getsum(nd,idx)-getsum(nd,idx-1);
}
long long dp[3005][3005];//i号点，最坏<=j的概率 
void getans(int nd){
	int i,j,k,cnt,mx=0;
	long long div;
	long long sum[4];
	for(i=head[nd],cnt=0;i;i=nxt[i],cnt++){
		getans(to[i]);
		mx=max(mx,height[to[i]]);
	}
	div=getdiv(cnt);
	if(cnt==0)dp[nd][0]=1;
	else if(cnt==1)dp[nd][0]=dp[to[head[nd]]][0];
	for(j=1;j<=mx+1;j++){
		sum[0]=0;sum[2]=0;
		sum[1]=0;sum[3]=1;
		for(i=head[nd];i;i=nxt[i]){
			
			sum[0]=sum[0]*getsum(to[i],j-1)+sum[1]*getdp(to[i],j-1)-sum[0]*getdp(to[i],j-1)
				  +sum[2]*getsum(to[i],j)  +sum[3]*getdp(to[i],j)  -sum[2]*getdp(to[i],j)
				  ;
			sum[1]=sum[1]*getsum(to[i],j-1)+sum[3]*getsum(to[i],j);
			sum[2]=sum[2]*getsum(to[i],j-1)+sum[3]*getdp(to[i],j-1)-sum[2]*getdp(to[i],j-1);
			sum[3]=sum[3]*getsum(to[i],j-1);
			for(k=0;k<4;k++)sum[k]%=mod;
		}
		dp[nd][j]=sum[0]*div%mod;
	}
	for(i=mx+1;i>=0;i--)if(dp[nd][i]){
		mx=i;break;
	}
	for(i=1;i<=mx;i++){
		dp[nd][i]+=dp[nd][i-1];
		dp[nd][i]%=mod;
	}
	
	height[nd]=mx;
}

bool son[3005];

int nxt[3005];int to[3005];int head[3005];
int ans;
_Main(){
	int n;int i,j,k;int a,b,c;int root;
	read(n);
	for(i=1;i<=n;i++){
		read(a);
		for(j=1;j<=a;j++){
			read(b);
			add(i,b);
		}
	}
	for(i=1;i<=n;i++)if(!son[i]){
		root=i;break;
	}
	getans(root);
	for(i=1;i<=height[root];i++){
		ans+=getdp(root,i)*i%mod;
		ans%=mod;
	}
	printf("%lld",(ans%mod+mod)%mod);
	
	
}
	
	
	
}ezoj1123;
