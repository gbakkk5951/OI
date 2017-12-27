#include<cstdio>
#include<bitset>
using namespace std;
int prime[5000000];
int tot;
bitset<1000000>vis;
int main(){
	int i=0;
	int j=0;
	freopen("ÖÊÊı±í.txt","w",stdout);
	for(i=2;i<1000000;i++){
		if(!vis[i]){

			prime[tot++]=i;
			printf("%d ",i);
		}
		
			for(j=0;j<tot&&((i*prime[j])<1000000);j++){
				
				
				vis[i*prime[j]]=1;
			
				if(!(i%prime[j]))
				break;
				
			}
		
		
		
	}

	fclose(stdout);
}
