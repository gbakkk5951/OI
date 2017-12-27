using namespace std;
int main(){}
#include<cstdio> 
#include<cstring>
#include<deque> 
const int p=100003;
int dp[2][68];
unsigned long long in;
deque<int>que[2];
struct _Main{
int n,m;
_Main(){
	scanf("%d%d",&n,&m);
	int i,j,k,iter,g;
	g=1<<n;
	unsigned long long temp;
	dp[0][0]=1;
	que[0].push_back(0); 
	iter=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			iter^=1;
			in=0;
		//	memset(dp[iter],0,68*4);
		//	printf("j=%d\n",j);
			while(!que[iter^1].empty() ){
				k=que[iter^1].front();
				dp[iter^1][k]%=p;
				que[iter^1].pop_front();
				
				temp=(long long unsigned)1LLU<<(k^(1<<j));
				if(! (in & temp) ){
					in |= temp ;
					que[iter].push_back(k^(1<<j)); 
					dp[iter][k^(1<<j)] =dp[iter^1][k];
				}else{
					dp[iter][k^(1<<j)]+=dp[iter^1][k];
				}
				
				if(j && k & 1 << ( j-1 ) && ! ( k & (1<<j) ) ){
					
					temp=(long long unsigned) 1LLU<<(k^(1<<j-1));
						if(!( in & (temp) )){
		//					printf(" !in [%llu]",temp);
							in |=temp;
							que[iter].push_back(k^(1<<(j-1))) ;
							dp[iter][k ^ (1<<j-1)] =dp[iter^1][k];
						}else{
							dp[iter][k ^ (1<<j-1)]+=dp[iter^1][k];
						}
				}
				
			}
			/*
			for(k=0;k<g;k++){
				dp[iter][k]%=p;
				if(dp[iter^1][k]){
					dp[iter][k^(1<<j)]+=dp[iter^1][k];
					
					
					if(j && k & 1 << ( j-1 ) && ! ( k & (1<<j) ) ){
						dp[iter][k ^ (1<<j-1)]+=dp[iter^1][k];
					}
				}
			}*/
		}
	}
	printf("%d",dp[iter][0]%p);	
}	
}codevs1184;
