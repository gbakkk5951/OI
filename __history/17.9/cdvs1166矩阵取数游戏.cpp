using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
const long long mod=1e9;

struct big{
	void zero(){
		memset(this,0,sizeof(big));
	}
	
	long long num[10];
	int high;
	big friend operator + ( big a, big b){
		big ret;int i;ret.zero();
		for(i=0;i<=a.high || i<=b.high ;i++){
			ret[i]+=a[i]+b[i];
			if(ret[i]>=mod){
				ret[i+1]+=ret[i]/mod;
				ret[i]%=mod;
			}
		}
		ret.high  =0;
		for(i=max(a.high ,b.high )+1;i>=0;i--){
			if(ret[i]){
				ret.high=i;
				break;
			}
		}
		return ret;
	}
	bool friend operator <(big a,big b){
		if(a.high==b.high ){
			int i;
			for(i=a.high ;i>=0;i--){
				if(a[i]!=b[i])return a[i]<b[i];
			}
			return false;
		}else{
			return a.high <b.high ;
		}
	}
	
	big friend operator * (big a,big b){
		int i,j;
		big ret;ret.zero();
		for(i=0;i<=a.high ;i++){
			for(j=0;j<=b.high ;j++){
				ret[i+j+1]+=ret[i+j]/mod;
				ret[i+j]%=mod;
				ret[i+j]+=a[i]*b[j];
				ret[i+j+1]+=ret[i+j]/mod;
				ret[i+j]%=mod;				
			}
		}
		ret.high =0;
		for(i=a.high +b.high +1;i>=0;i--){
			if(ret[i]){
				ret.high =i;
				break;
			}
		}
		return ret;
	}
	
	
	long long & operator [] (int idx){
		return num[idx];
	}
	void print(){
		int i=high;
		printf("%lld",num[i]);
		for(i--;i>=0;i--){
			printf("%09lld",num[i]);
		}
	}
};
struct _Main{
int matrix[100][100];
int n,m;
big pow[85];
big dp[85][85];
big t1,t2,t3;
big ans;
_Main(){
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	pow[1][0]=2;
	for(i=2;i<=m;i++){
		pow[i]=pow[1]*pow[i-1];
	}
	t1.zero();
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			t1[0]=matrix[i][j];
			dp[j][j]=pow[m]*t1;
		}
		for(j=2;j<=m;j++){
			for(k=1;k+j-1<=m;k++){
				t2.zero();t3.zero();
				t1[0]=matrix[i][j+k-1];
				t2=dp[k][j+k-2]+pow[m-j+1]*t1 ;
				t1[0]=matrix[i][k];
				t3=dp[k+1][j+k-1]+pow[m-j+1]*t1;
				if(t2<t3){
					dp[k][j+k-1]=t3;
				}else{
					dp[k][j+k-1]=t2;
				}
			}
		}
		ans=ans+dp[1][m];
	}
	ans.print();
	
	
}	
	
	
	
}cdvs1166;
