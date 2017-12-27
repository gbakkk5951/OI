int main(){}
using namespace std;
#include<cstdio>
const 	int mark[5][5]={
	0,0,1,1,0,
	1,0,0,1,0,
	0,1,0,0,1,
	0,0,1,0,1,
	1,1,0,0,0
};
struct _Main{

	void getmark(int a,int b){
		sc[0]+=mark[a][b];
		sc[1]+=mark[b][a];
	}
	
	int n,na,nb;
	int sc[2];
	int list[2][210];
	
	_Main(){
		int i,j,k;
		scanf("%d%d%d",&n,&na,&nb);
		for(i=0;i<na;i++){
			scanf("%d",&list[0][i]);
		}
		for(i=0;i<nb;i++){
			scanf("%d",&list[1][i]);
		}
		j=0;
		k=0;
		for(i=0;i<n;i++){
			getmark(list[0][j],list[1][k]);
			j++;
			k++;
			j%=na;
			k%=nb;
		}
		
		printf("%d %d",sc[0],sc[1]);
		
		
		
	}
	
	
}cdvs3716;
