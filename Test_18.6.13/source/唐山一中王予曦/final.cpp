#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#define For(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long LL;
const int MAXN=7;

int n,h[MAXN][MAXN];

int gcd(int a,int b){return b?gcd(b,a%b):a;}

void print(){
	For(i,1,n){
		For(j,1,n) printf("%d ",h[i][j]);
		puts("");
	}
	exit(0);
}

void dfs(int x,int y){
	if(x>n){
		if((LL)h[1][1]*(h[2][2]*h[3][3]-h[2][3]*h[3][2])+
			(LL)h[1][2]*(-h[2][1]*h[3][3]-h[2][3]*h[3][1])+
			(LL)h[1][3]*(h[2][2]*h[3][1]-h[2][1]*h[3][2])==1) print();
		return;
	}
	For(i,-15,15){
		h[x][y]=i;
		if(clock()>950) puts("no solution");
		if(y==n) dfs(x+1,1); else dfs(x,y+1);
	}
}

int main(){
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
	
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&h[1][i]);
	if(n==2){
		For(i,-2000,2000){
			For(j,-2000,2000){
				if(h[1][1]*j-h[1][2]*i==1){
					h[2][1]=i; h[2][2]=j;
					print();
				}
			}
		}
	}else{
		dfs(2,1);
	}
	puts("no solution");
	return 0;
}

