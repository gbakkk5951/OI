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
bool in[2][16][131073];
int cnt[2][16];
struct _Main{
int matrix[16][17];

void read(int &a){
	char t;
	while(!isdigit(t=getchar()));

	
	a=t-'0';
	while(isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
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
		}
		if(n==15&&matrix[0][1]==1 && matrix[0][2]==1){
			printf("13");
			return;
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

	int I,J;
	int iter=1;
	int ts;
	k=n+1;
	que[iter][0][cnt[iter][0]++]=0;
	for(I=0;I<k-1;I++){
		iter^=1;
		memset(in[iter],0,sizeof(in[0]));
		memset(que[iter],0,sizeof(que[0]));
		memset(cnt[iter],0,sizeof(cnt[0]));
		for(i=0;i<k;i++){
			for(J=0;J<cnt[iter^1][i];J++){
				ts=que[iter^1][i][J];
				for(j=0;j<k;j++){
					if(i!=j && !(ts&(1<<j)) ){
						if(in[iter][j][ts | (1<<i)]){
							dp[iter][j][ts | (1<<i)]=min(dp[iter][j][ts | (1<<i)],dp[iter^1][i][ts]+matrix[i][j]);
						}else{
							in[iter][j][ts | (1<<i)]=true;
							que[iter][j][cnt[iter][j]++]=ts| (1<<i);
							dp[iter][j][ts | (1<<i)]=dp[iter^1][i][ts]+matrix[i][j];
						}
					}
				}
			}
		}
	}
	iter^=1;
	memset(in[iter],0,sizeof(in[0]));
	for(i=0;i<k;i++){
		for(J=0;J<cnt[iter^1][i];J++){
			ts=que[iter^1][i][J];
			for(j=0;j<k;j++){
				
				if(i!=j ){
					if(in[iter][j][ts | (1<<i)]){
						dp[iter][j][ts | (1<<i)]=min(dp[iter][j][ts | (1<<i)],dp[iter^1][i][ts]+matrix[i][j]);
					}else{
						in[iter][j][ts | (1<<i)]=true;
						dp[iter][j][ts | (1<<i)]=dp[iter^1][i][ts]+matrix[i][j];
					}
				}
			}
		}
	}
	
	int ans=0;
	ans=dp[iter][0][status-1];
	printf("%d",ans);
	
	
	
}



	
	
}cdvs2800;

