#include<cstdio>
#include<cstdlib>
#include<bitset>
#include<ctime>
using namespace std;
bitset<5000000>vis;
int main(){
	vis[0]=1;
	srand((int)time(NULL));

	freopen("data.in","w",stdout);
	int n=1+((rand()<<15)+rand())%1000000,m=1+((rand()<<15)+rand())%100000;
	printf("%d\n",n);
	int i,j;
	for(i=0;i<n;i++){
		while(vis[j])
		j=1+((rand()<<15)+rand())%5000000;
		vis[j]=1;
		printf("%d\n",j);
	}
		printf("%d\n",m);
	for(i=0;i<m;i++){
		if(rand()%2){
			printf("M %d %d\n",1+rand()%n,1+rand()%n);
		}else{
			printf("K %d\n",1+rand()%n);
		}
		
		
	}
	
	fclose(stdout);
}
