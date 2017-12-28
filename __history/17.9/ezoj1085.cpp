using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<queue>
#include<algorithm>
struct Map{
	char num[3][3];
	char way;int from;
}q[363000],tmp;
bool vis[363000];
int head;int tail;
int fac[10];
struct _Main{
int cantor(char map[3][3]){
	char *nd=&map[0][0];
	int i,j;int ret=0,cnt;
	for(i=0;i<8;i++){
		for(j=i+1,cnt=0;j<9;j++)if(nd[j]<nd[i]){
			cnt++;
		}
		ret+=cnt*fac[8-i];
	}
	return ret;
}	
void getfac(){
	fac[0]=1;
	int i;
	for(i=1;i<=9;i++){
		fac[i]=fac[i-1]*i;
	}
}
int bfs(){
	int i;int x,y,hash;
	i=tail=0;
	tail++;
	
	for(i=0;i<tail;i++){
		for(y=0;y<3;y++){
			for(x=0;x<3;x++)if(q[i].num[y][x]==8){
				break;
			}
			if(x<3)break;
		}
		if(y){
			tmp=q[i];tmp.from =i;tmp.way ='u';
			swap(tmp.num[y-1][x],tmp.num[y][x]);
			hash=cantor(tmp.num);
			if(!vis[hash]){
				vis[hash]=1;
				q[tail++]=tmp;
				if(hash==0){
					return tail-1;
				}
			}
		}
		if(y<2){
			tmp=q[i];tmp.from =i;tmp.way ='d';
			swap(tmp.num[y+1][x],tmp.num[y][x]);
			hash=cantor(tmp.num);
			if(!vis[hash]){
				vis[hash]=1;
				q[tail++]=tmp;
				if(hash==0){
					return tail-1;
				}
			}
		}
		if(x){
			tmp=q[i];tmp.from =i;tmp.way ='l';
			swap(tmp.num[y][x-1],tmp.num[y][x]);
			hash=cantor(tmp.num);
			if(!vis[hash]){
				vis[hash]=1;
				q[tail++]=tmp;
				if(hash==0){
					return tail-1;
				}
			}
		}
		if(x<2){
			tmp=q[i];tmp.from =i;tmp.way ='r';
			swap(tmp.num[y][x+1],tmp.num[y][x]);
			hash=cantor(tmp.num);
			if(!vis[hash]){
				vis[hash]=1;
				q[tail++]=tmp;
				if(hash==0){
					return tail-1;
				}
			}
		}
	}
	return -1;
	
}

_Main(){
	getfac();
	char *nd=&q[0].num[0][0];
	char t;int i;
	for(i=0;i<9;i++){
		while(!isdigit(t=getchar()) && t!='x');
		if(t=='x')*nd=8;
		else *nd=t-'1';
		nd++;
	}
	dfs(bfs());
}	
void dfs(int nd){
	if(nd>0){
		dfs(q[nd].from);
		putchar(q[nd].way);
	}else if(nd==-1){
		printf("unsolvable");
	}
}
	
	
}ezoj1085;
