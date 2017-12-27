#include<cstdio>
#include<cctype>
#include<bitset>
#include<cstring>
#include<deque>
using namespace std;
int map[240][240][4];
bool del[234][235];
int cengci[234][237];
int px[4]={0,1,0,-1},py[4]={1,0,-1,0};
bool vis[240][240];
int cnt;
int ans;
int way[500];

int m,n;
int tot;
struct _Main{

inline bool islegal(int x,int y){
	return x>=0 && x<n && y>=0 && y<m && !vis[x][y];
}
inline int min(int a,int b){
	return a<b?a:b;
}
int dfs(int x,int y){
//	printf("test (%d , %d)",x,y);
	vis[x][y]=true;
	int i,j,k;
	if(x==n-1&&y==m-1){
		return 2147483647;
	}
	for(i=0;i<4;i++){
		
		if(islegal(x+px[i],y+py[i]) && map[x][y][i]>0){
			way[cnt++]=x*10000+y*10+i;
			if(j=dfs(x+px[i],y+py[i])){
				return min(map[x][y][i],j);
			}
			cnt--;
		}/*else{
			printf("\nfrom (%d,%d)-->fail(%d,%d) reason:",x,y,x+px[i],y+py[i]);
			bool flag=false;
			if(!islegal(x+px[i],y+py[i])){
				flag=true;
				printf("illegal,");
			}
			if(!map[x][y][i]){
				flag=true;
				printf("no way,");
			}
			if(!flag){
				printf("next fail,");
			}
			puts("");
		}*/
	}
	vis[x][y]=false;
	return 0;
}

void netflow(){
	int i,j,k,x,y;
	while(k=dfs(0,0)){
		ans+=k;
//		printf("once");
		for(i=0;i<cnt;i++){
			x=way[i]/10000;
			y=(way[i]-x*10000)/10;
			j=way[i]%10;
//			printf("(%d,%d)-%d->",x,y,j);
			map[x][y][j]-=k;
			map[x+px[j]][y+py[j]][(j+2)%4]+=k;
		}
		cnt=0;
		memset(vis,0,sizeof(vis));
	}

	
}


void dinic(){
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

int read(){
	char t;
	int ans;
	while(!isdigit( t = getchar() ));
	ans=t-'0';
	while(isdigit( t = getchar () )){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}
	
	
	
int ans;
_Main(){
	n=read();
	m=read();
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<m-1;j++){
			map[i][j][0]=read();
			map[i][j+1][2]=map[i][j][0];
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n-1;j++){
			map[j][i][1]=read();
			map[j+1][i][3]=map[j][i][1];
		}
	}
	netflow();
	printf("%d",ans/2);
}

}instance;int main(){}
