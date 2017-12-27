#include<cstdio>
#define mod 1000000000
struct _Main{

_Main(){
	ini();
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	scanf("%d",&n);
	printf("%d",newdfs(0,n));
	fclose(stdout);
}

inline int lb(int x){
	return x&(-x);
}
int mem[27][37];
int dp[21][21][21];
int ini(){
	int i,j,k,l,m;
	
	long long r=0;
	for(j=0;j<=20;j++){
		for(i=0;i<=j;i++){
			dp[i][i][i]=1;
			for(k=i;k<=20&&k<=j;k++){
				r=dp[i][j][k];
				for(l=i;l<=k;l++){
					for(m=l;m<=k;m++){				
						r+=(long long)dp[i][j-1][l]*dp[m][j-1][k];
						r%=mod;	
					}
				}
				dp[i][j][k]=r;
			}
		}
	}
}
int newdfs(int last,int rem){
	
	
	if(rem==0)return 1;
	int i,j,k;
	long long ans=0;
	for(i=last;(1<<i)<lb(rem);i++);
	rem-=lb(rem);
	long long sum1=0,sum=0;
	int i2;
	if(rem){
		for(i2=i;!((1<<i2)&rem);i2++);
	}
	for(k=last;k<=i;k++){
		if(rem){
			if(!mem[k][i2]){
				ans=newdfs(k,rem);
				mem[k][i2]=ans;
			}else ans=mem[k][i2];				
		}else ans=1;

		
		for(j=last;j<=k;j++){
			sum+=dp[j][i][k];
			sum%=mod;
		}
		sum1=(sum1+ans*sum)%mod;
		sum=0;
	}

	return sum1;
	
}
int n;
}time;int main(){}
