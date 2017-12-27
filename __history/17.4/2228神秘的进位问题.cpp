#include<cstdio>
using namespace std;
struct  _Main{
int m,n;
int ans;int cn[20][4];
void ini(){
	int i,j;
	cn[1][0]=cn[1][1]=1;
	for(i=2;i<20;i++){
		cn[i][0]=1;
		for(j=1;j<4;j++){
			cn[i][j]=cn[i-1][j]+cn[i-1][j-1];
		}
	}
}
void dfs(){
	int i,j,k;
	for(i=2;i<20;i++){
		for(j=1;j<i;j++){
			for(k=0;k<j;k++){
				if(cn[i][3]+cn[j][2]+cn[k][1]==n){
					printf("%d%d%d\n",i,j,k);
					return;
				}
			}
		}
	}
}
_Main(){
	int i;ini();
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&n);
		dfs();
	}
}

}instance;int main(){}
