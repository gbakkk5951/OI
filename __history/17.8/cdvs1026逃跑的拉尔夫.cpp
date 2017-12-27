using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<bitset>
bitset<2551010>v;
int h,l;
char map[51][51];
struct _Main{
char dir[1010];
int dx[256],dy[256];
int n; 
_Main(){
	dx['W']=-1;dx['A']=+1;
	dy['N']=-1;dy['U']=+1;
	int bx,by;
	int i,j;
	char t;
	scanf("%d%d",&h,&l);
	for(i=0;i<h;i++){
		for(j=0;j<l;j++){
			while(isspace(t=getchar()));
			map[j][i]=t;
			if(t=='*'){
				bx=j;by=i;	
				map[j][i]='.';
			}
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		while(isspace(t=getchar()) || (t!='N' && t!='U' && t!='A' && t!='W'));
		dir[i]=t;
	}
	
	dfs(bx+dx[dir[0]],by+dy[dir[0]],0);
	for(i=0;i<h;i++){
		for(j=0;j<l;j++){
			putchar(map[j][i]);
		}putchar('\n');
	}
}
int inline com(int x,int y,int pos){
	return pos+x*1000+y*50000;
}
bool inline islegal(int x,int y,int pos){
	return x>=0 && y>=0 &&x<l &&y<h &&map[x][y]!='X' && !v[com(x,y,pos)];
}
void dfs(int x,int y,int pos){
	if(!islegal(x,y,pos))return;
	v[com(x,y,pos)]=1;
	if(pos==n-1){
		map[x][y]='*';
	}else{
		dfs(x+dx[dir[pos+1]],y+dy[dir[pos+1]],pos+1);
	}
	dfs(x+dx[dir[pos]],y+dy[dir[pos]],pos);
	
	
	
}


}cdvs1026;
