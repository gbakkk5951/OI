#include<cstdio>
#include<cctype>
#include<ctime>
#include<cstring>

#define mod 1000000000
struct _Main{
long long read(){
	char t ; long long ans;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}



void test(){
	int i;
//	for(i=0;i<64;i++){
//		printf("%lld\n",1LL<<i);
//	}
	

}
long long tot;
_Main(){
	char f1[500],f2[500];
	
	test();
	int i;
	ini();
	for(i=1;i<=20;i++){
		sprintf(f1,"bit%d.in",i);
		freopen(f1,"r",stdin);
		scanf("%lld",&n);
		sprintf(f2,"bit%d.out",i);
		freopen(f2,"w",stdout);
		
		printf("%d",newdfs(0,n));
		fclose(stdout);
		memset(mem,0,sizeof(mem));
	}
}

inline long long lb(long long x){
	return x&(-x);
}
long long mem[67][64];
long long dp[67][66][65];
int ini(){
	int i,j,k,l,m,r;
	for(j=0;j<=63;j++){
		dp[j][j][j]=1;
		for(i=0;i<=j;i++){
			for(k=i;k<=63&&k<=j;k++){
				for(l=i;l<=k;l++){
					for(m=l;m<=k;m++){
						tot++;				
						dp[i][j][k]+=dp[i][j-1][l]*dp[m][j-1][k];
						dp[i][j][k]%=mod;	
					}
				}
			}
		}
	}
}
int newdfs(long long last,long long rem,int iter=0){
	
	
	if(rem==0)return 1;
	long long i,j=0,k=0;
	long long ans=0;
	for(i=last;(1LL<<i)<lb(rem);i++);
	rem=rem-lb(rem);
	long long sum1=0,sum=0;
	long long i2=0;
	if(rem){
		for(i2=i+1;(long long)(1LL<<i2)<lb(rem);i2++);
	}
	
	for(k=last;k<=i;k++){
		if(!mem[k][i2]){
			ans=newdfs(k,rem,iter+1);
			mem[k][i2]=ans;
		}else ans=mem[k][i2];
		
		for(j=last;j<=k;j++){
			sum+=dp[j][i][k];
			sum%=mod;
		}
		sum1=(sum1+ans*sum)%mod;
		sum=0;
	}

	return sum1;
	
}
/*
int dfs(int last,int rem){
	if(last>lb(rem)){
		return 0;
	}
	long long ans=0;
	int i;
	for(i=last;i<=lb(rem);i<<=1){
		if(rem==i){
			ans++;
			if(ans>1000000000)
				ans-=1000000000;
			break;
		}
		ans+=dfs(i,rem-i);
		if(ans>1000000000){
			ans-=1000000000;
		}
	}

	return ans;
	
}
*/
long long n;
}ztime;int main(){}
