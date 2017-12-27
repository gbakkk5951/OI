using namespace std;
int main(){}
#include<cstdio>
#include<queue>
#include<cstring>
int from[41000];
char way[41000]; 
bool vis[41000];
int fact[10];
int dst;
char strdst[10],strbeg[10];
struct Oper{
void A(char *matrix){
	char i;char t;
	for(i=0;i<4;i++){
		t=matrix[i];matrix[i]=matrix[8-i-1];
		matrix[8-i-1]=t;
	}
}
void B(char *matrix){
	char i;char t;
	t=matrix[3];
	for(i=3;i>0;i--){
		matrix[i]=matrix[i-1];
	}matrix[0]=t;
	t=matrix[4];
	for(i=4;i<7;i++){
		matrix[i]=matrix[i+1];
	}matrix[7]=t;
}
void C(char *matrix){
	char t[4];
	t[0]=matrix[1];t[1]=matrix[2];t[2]=matrix[5];t[3]=matrix[6];
	matrix[2]=t[0];matrix[5]=t[1];matrix[6]=t[2];matrix[1]=t[3];
}

}oper;

struct _Main{

void revcantor(int val,char *matrix){
	char i,j,d,n;unsigned char vis=0;
	for(i=0;i<8;i++){
		n=val%fact[8-i]/fact[8-i-1];
		for(j=0,d=0;j<8;j++)if(!(vis&(1<<j))){
			if(d==n){
				break;
			}
			d++;
		}
		vis|=(1<<j);
		matrix[i]=j;
	}
}	

int cantor(char *matrix){
	char i,j,d;int ans=0;
	for(i=0;i<8;i++){
		for(j=i+1,d=0;j<8;j++){
			if(matrix[j]<matrix[i]){
				d++;
			}
		}
		ans+=d*fact[8-i-1];
	}return ans;
}
int goal;
queue<int>q;
_Main(){
	int i,j,k;int nd;int tmp;
	int step=0;
	fact[0]=1;
	for(i=1;i<=8;i++){
		fact[i]=fact[i-1]*i;
	}
	scanf("%s%s",strbeg,strdst);
	goal=cantor(strdst);
	q.push(i=cantor(strbeg));
	vis[i]=1;
	while(!q.empty() ){
		k=q.size();
		for(i=0;i<k;i++){
			nd=q.front();
			if(nd==goal){
				goto EndFlag;
			}q.pop();
			revcantor(nd,strbeg);
			memcpy(strdst,strbeg,sizeof(strbeg));
			oper.A(strdst);
			tmp=cantor(strdst);
			if(!vis[tmp]){
				vis[tmp]=1;q.push(tmp);
				way[tmp]='A';from[tmp]=nd;
			}
			memcpy(strdst,strbeg,sizeof(strbeg));
			oper.B(strdst);
			tmp=cantor(strdst);
			if(!vis[tmp]){
				vis[tmp]=1;q.push(tmp);
				way[tmp]='B';from[tmp]=nd;
			}			
			oper.C(strbeg);
			tmp=cantor(strbeg);
			if(!vis[tmp]){
				vis[tmp]=1;q.push(tmp);
				way[tmp]='C';from[tmp]=nd;
			}
		}
		step++;
	}
	EndFlag:;
	if(!q.empty() ){
		dfs(goal);
	}else{
		printf("-1");
	}
	fclose(stdout);
}
void dfs(int idx){
	if(from[idx]){
		dfs(from[idx]);
	}if(way[idx]){
		putchar(way[idx]);
	}
}

}jsk;
