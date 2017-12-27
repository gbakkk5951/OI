using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
const long long pow[11]={
	1,10,100,1000,10000,100000,
	1000000,10000000,100000000,
	1000000000LL,10000000000LL
};

struct _Main{
int dp[11][91][91][91];

void getdp(){
	int i,j,k,l,m,n;
	for(i=0;i<=9;i++){
		for(j=1;j<90;j++){
			dp[0][i][j][i%j]++;
		}
	}
	for(i=1;i<=9;i++){
		for(j=0;j<=9;j++){//放什么 
			for(k=1;k<90;k++){//模几 
				for(l=0;l<=i*9;l++){//数位和
					for(m=0;m<k;m++){//数值和 
						dp[i][j+l][k][((j*pow[i])+m)%k]+=dp[i-1][l][k][m];
					}
				}
			}
		}
	}
}
int getans(int num){
	if(num<=0)return 0;
	int sum=0,s=0;int ans=0;
	int i,j,k;int nd;
	for(i=10;i>0;i--)if(num>=pow[i]){
		nd=num/pow[i]%10;
		for(j=0;j<nd;j++){
			for(k=((j+s)?0:1);k<=9*i;k++){
				ans+=dp[i-1][k][k+s+j][(k+s+j-(sum+j*pow[i]%(k+s+j))%(k+s+j))%(k+s+j)];
			}
		}
		sum+=nd*pow[i];s+=nd;
	}
	nd=num%10;
	for(i=0;i<=nd;i++){
		if(sum+i!=0 && (sum+i)%(s+i)==0)ans++;
	}return ans;
	
}

_Main(){
	int l,r;
	getdp();
	while(~scanf("%d%d",&l,&r)){
		r=getans(r);
		l=getans(l-1);
		printf("%d\n",r-l);
	}
}	
	
	
	
}ezoj1014;
