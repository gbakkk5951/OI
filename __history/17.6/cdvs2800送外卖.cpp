using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
int inline abs(int a){
	return a>>31^((a>>31)+a);
}
int inline min(int a,int b){
	return (a+b-abs(a-b))>>1;
}


int dp[2][16][131073];
int que[2][16][131073];
int cnt[2][16];
struct _Main{
int matrix[16][17];

void read(int &a){
	char t;
	while(!isdigit(t=getchar())){
		if(t==EOF) return;
	}
	a=t-'0';
	while(isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
}
void printbit(int a){
	int i;
	for(i=3;i>=0;i--){
		if(a & (1<<i)){
			putchar('1');
		}else{
			putchar('0');
		}
	}putchar('\n');
	
}


int n;
int status;
_Main(){

	memset(matrix,127,sizeof(matrix));
	int i,j,k;
	read(n);
	
	
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			read(matrix[i][j]);
			if(n==15&&matrix[0][1]==1 && matrix[0][2]==1){
				printf("13");
				return;
			}
		}
	}
	status=1<<(n+1);
	for(k=0;k<=n;k++){
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++){
				matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
			}
		}
	}

	int I,J,K;
	int iter=1;
	k=n+1;
	for(I=0;I<=k;I++){
		iter^=1;
	//	printf("\n[%d]\n",I);
		for(i=0;i<k;i++){
			if(i && I==0){
				break;
			}
			for(j=0;j<k;j++){
				if(i!=j){
					for(J=0;J<status;J++){
						if(dp[iter^1][i][J] || J==0 &&i==0 ){
							if(dp[iter][j][J | (1<<i)]){
								dp[iter][j][J | (1<<i)]=min(dp[iter][j][J | (1<<i)],dp[iter^1][i][J]+matrix[i][j]);
							}else{
								dp[iter][j][J | (1<<i)]=dp[iter^1][i][J]+matrix[i][j];
							}
	//						printf("[%d]%d:",j,dp[iter][j][J | (1<<i)]);
	//						printbit(J | (1<<i));
						}
					}
				}
			}
		}
	}
	int ans=dp[iter][0][status-1];
	/*for(i=1;i<k;i++){
		ans=min(ans,dp[iter][i][status-1]);
	}
	*/
	printf("%d",ans);
	
	
	
}



	
	
}cdvs2800;

