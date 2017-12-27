using namespace std;
int main(){}
#include<cstdio>

struct _Main{
char x[4],y[4],z[4],w[4];int num;
bool check(){
	int i,j,k;
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			for(k=0;k<4;k++){
				if(x[k]==j || y[k]==i || z[k]==i+j || w[k]==j-i) break;
			}
			if(k==4)return false;
		}
	}return true;
}
bool map[7][7];
int cnt;
void dfs(int yy){
	int i,j,k;
	if(num==4 ){
		if(check()){
		
			printf("[%d]\n",++cnt);
			for(i=0;i<7;i++){
				for(j=0;j<7;j++){
					printf("%d",map[j][i]);
					
				}
				printf("\n");
			}
		}
	}else{
		for(i=yy+1;i<7-(3-num);i++){
			for(j=0;j<7;j++){
				for(k=0;k<num;k++){
					if(x[k]==j || y[k]==i || z[k]==i+j || w[k]==j-i) break;
				}
				if(k==num){
					map[j][i]=1;
					x[num]=j;y[num]=i;z[num]=i+j;w[num]=j-i;
					num++;
					dfs(i);
					num--;
					map[j][i]=0;
				}
			}
		}
		
		
		
	}
	
}
	
_Main(){
	dfs(-1);
}
	
}stick;
