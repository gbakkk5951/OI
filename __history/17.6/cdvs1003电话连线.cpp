using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
int fa[101];
struct _Main{
int read(){
	char t;
	int ans;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while( isdigit(t=getchar())){
		ans*=10;
		ans+=t-'0';
	}
	return ans;
}
int n,m,cst;
int arr[110];
int map[101][101];

_Main(){
	int i,j,k;
	n=read();
	for(i=0;i<n;i++){
		fa[i]=i;
		for(j=0;j<n;j++){
			map[i][j]=read();
		}
	}
	
}
	
	
}cdvs1003;


