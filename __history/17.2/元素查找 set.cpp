#include<cstdio>
#include<bitset>
using namespace std;
bool ls[100000010];
int n,m;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&j);
		ls[j]=1;
	}
	for(i=0;i<m;i++){
		scanf("%d",&j);
		if(ls[j]==1){
			printf("YES\n");
		}else
		{
			printf("NO\n");
		}
		
	} 
	
}
