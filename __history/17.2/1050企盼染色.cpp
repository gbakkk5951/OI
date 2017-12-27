#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int map[101];
int way[2][101];
int beg=99;
int end=0;
int main(){int i,j,k;
	char inc;
	scanf("%d",&n);
	for(j=0;j<n;j++)
	for(i=5;i;i--){
		inc=getchar();
		if(inc-'0'){
			map[j]+=1<<(i-1);
			beg=min(beg,j);
			end=max(end,j);
		}
	}
	way[beg%2][beg]=map[beg];
	for(i=beg+1;i<=)
	
}
