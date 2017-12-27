using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#define stats beg

const char goal[3][3]={1,2,3,8,0,4,7,6,5};
char inline abs(char a){
	return a>>7^((a>>7)+a);
}
void swap(char &a,char &b){
	char t=a;
	a=b;
	b=t;
}

struct _Main{

char GuJia(){
	char i,j;
	#define num stats[i][j]
	char ret=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			ret+=abs(x[num]-j)+abs(y[num]-i);
		}
	}return ret;
}
bool dfs(short iter){
	char i,j;
	if(iter==depth){
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(stats[i][j]!=goal[i][j]){
					return false;
				}
			}
		}
		return true;
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(stats[i][j] == 0){
				if(i>0){
					
					swap(stats[i][j],stats[i-1][j]);
					if(dfs(iter+1)){
						return true;
					}
					swap(stats[i][j],stats[i-1][j]);
				}
				if(i<2){
					swap(stats[i][j],stats[i+1][j]);
					if(dfs(iter+1)){
						return true;
					}
					swap(stats[i][j],stats[i+1][j]);						
				}				
				if(j>0){
					swap(stats[i][j],stats[i][j-1]);
					if(dfs(iter+1)){
						return true;
					}
					swap(stats[i][j],stats[i][j-1]);		
				}
				if(j<2){
					swap(stats[i][j],stats[i][j+1]);
					if(dfs(iter+1)){
						return true;
					}
					swap(stats[i][j],stats[i][j+1]);					
				}
				return false;	
			}
		}
	}
	
}

char x[9],y[9];
char beg[3][3];
short depth;
_Main(){
	char i,j;char t;
	char *a=beg[0];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			x[goal[i][j]]=j;
			y[goal[i][j]]=i;
		}
	}
	
	while((t=getchar())!=EOF){
		if(isdigit(t)){
			*a=t-'0';
			a++;
		}
	}
	depth=0;
	while(dfs(0)==false){
		depth++;
	}
	printf("%d",(int)depth);
}	
	
	
	
}cdvs1225;
