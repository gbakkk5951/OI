#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct _main{
int val[110][110];
int n;
_main(){
	int sum[110];
	int i,j,k;
	sum[0]=0;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	for(i=2;i<=n;i++){
		for(j=i-1;j;j--){
			for(k=i;k>j;k--){
				if(val[j][i])
				val[j][i]=min(val[j][i],sum[i]-sum[j-1]+val[j][k-1]+val[k][i]);
				else val[j][i]=sum[i]-sum[j-1]+val[j][k-1]+val[k][i];
			}
		}
	}
	printf("%d",val[1][n]);
	
}
	
}instance;
int main(){}
