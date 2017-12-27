using namespace std;
int main(){}
#include<cmath>
#include<vector>
#include<cctype>
#include<cstdio>
struct _Main{
vector<vector<long long> >way;
int n;	
_Main(){
	int i,j;
	scanf("%d",&n);
	int g=sqrt(n);
	way.resize(n+2);
	way[0].resize(g+2);
	for(i=0;i<=g;i++){
		way[0][i]=1;
	}
	for(i=1;i<=n;i++){
		way[i].resize(g+2);
		for(j=1;j*j<=i;j++){
			way[i][j]=way[i][j-1]+way[i-j*j][j];
		}
		for( ;j<=g;j++){
			way[i][j]=way[i][j-1];
		}
	}
	printf("%lld",way[n][g]);
}	
	
}cdvs1721;


