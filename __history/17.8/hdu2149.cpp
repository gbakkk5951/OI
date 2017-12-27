using namespace std;
int main(){}
#include<cstdio>

struct _Main{
	
_Main(){
	int n,m;int i;
	while(~scanf("%d%d",&m,&n)){
		if(n<m){
			if(m%(n+1)){
				printf("%d\n",m%(n+1));
			}else{
				printf("none\n");
			}			
		}else{
			for(i=m;i<n;i++){
				printf("%d ",i);
			}
			printf("%d\n",n);			
		}

		
	}
	
	
}	
}hdu2149;
