using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<bitset>



struct _Main{
bitset<64>link;	
int color;
int n;
int cnt;
void dfs(int pos){
	if(pos==n){
		cnt++;
		return;
	}
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<pos;j++)if(link[(pos*n)+j]){
			if( (( color>>(j<<1) ) &3) ==i){
				goto EndFor;
			}
		}
		color|=(i<<(pos<<1)) ;
		dfs(pos+1);
		color^=(i<<(pos<<1));
		EndFor:;
	}
}
_Main(){
	char t;int g;
	while(!isdigit(t=getchar()));
	n=t-'0';g=n*n;
	int i;
	for(i=0;i<g;i++){
		while(!isdigit(t=getchar()));
		link[i]=t-'0';
	}
	dfs(0);
	printf("%d",cnt);
}
	
	
	
	
	
	
}cdvs1116;

