using namespace std;
int main(){}
#include<cstdio>
#include<algorithm>
#include<cstring>
const long long mod =1e9;
struct big{
	long long num[10];
	int high;
	
	bool friend operator < (big a,big b){
		if(a.high == b.high ){
			int i;
			for(i=a.high ;i>=0;i--){
				if(a[i]!=b[i]){
					return a[i]<b[i];
				}
			}return false;
		}else{
			return a.high <b.high ;
		}
	}
	
	big friend operator + (big a,big b){
		int i;
		for(i=0;i<=max(a.high ,b.high );i++){
			a[i]+=b[i];
			if(a[i]>=mod){
				a[i+1]+=a[i]/mod;
				a[i]%=mod;
			}
		}
		a.high =0;
		for(i=max(a.high ,b.high )+1;i>=0;i--){
			if(a[i]){
				a.high =i;
				break;
			}
		}
		return a;
	}
	void zero(){
		memset(this,0,sizeof(big));
	}
	big friend operator * (big a,big b){
		int i,j;big ret;ret.zero();
		for(i=0;i<=a.high ;i++){
			for(j=0;j<=b.high;j++){
				if(ret[i+j]>=mod){
					ret[i+j+1]+=ret[i+j]/mod;
					ret[i+j]%=mod;
				}
				ret[i+j]+=a[i]*b[j];
				if(ret[i+j]>=mod){
					ret[i+j+1]+=ret[i+j]/mod;
					ret[i+j]%=mod;
				}
			}
		}
		ret.high =0;
		for(i=a.high +b.high +1;i>=0;i--){
			if(ret[i]){
				ret.high =i;
				break;
			}
		}return ret;
	}
	big friend inline operator * (big a,int b){
		big temp;temp.zero();temp[0]=b;
		return a*temp;
	}	
	big friend inline operator * (int a,big b){
		return b*a;
	}
	long long &  operator [] (int a){
		return num[a];
	}
	void print(){
		int i=high;
		printf("%lld",num[i--]);
		for(;i>=0;i--){
			printf("%09lld",num[i]);
		}
	}
};

struct _Main{
char str[50];
big dp[7][41][41];
big pow[41];big t1,t2,t3;
int n,k;
int cheng;
_Main(){
	int i,j,k,l,m;
	scanf("%d%d%s",&n,&cheng,str);
	pow[0][0]=1;
	for(i=1;i<=n;i++){
		pow[i]=pow[i-1]*10;
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			for(k=1;j-k+1>=i;k++){
				dp[0][i][j]=dp[0][i][j]+(str[j-k+1]-'0')*pow[k-1];
			}
		}
	}		
	for(i=1;i<=cheng;i++){
		for(j=0;j<n-i;j++){
			for(k=j+i;k<n;k++){
				for(l=j;l<k;l++){
					for(m=0;m<i;m++){
						t1=dp[m][j][l]*dp[i-m-1][l+1][k];
						if(dp[i][j][k]<t1){
							dp[i][j][k]=t1;
						}
					}
				}
			}
		}
	}
	dp[cheng][0][n-1].print();
}
	
}cdvs1017;
