#include<cstdio>
#include<cctype>
#include<bitset>
#include<cstring>
using namespace std;
bitset<101>lk[101];
bitset<101>v;
bitset<101>use;
int tot;
int f[101],t[101];
int fa[101];
struct _Main{
	
int read(){
	char t;int ans;
	while(!isdigit(t=getchar()));
	ans=t-'0';
	while(isdigit(t=getchar())){
		ans=ans*10-'0'+t;
	}
	return ans;
}
int n;
_Main(){
	int i,j,t1,t2;
	for(i=0;i<=100;i++){
		lk[i].set();
	}
	n=read();
	t1=read();
	t2=read();
	while(t1||t2){
		lk[t1][t2]=0;
		t1=read();
		t2=read();
	}
	magyarorszag();
	int k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(lk[i][j]&&fa[j]==i){
				lk[i][j]=0;
				fa[j]=0;
				v.reset();
				if(!dfs(i)){
					f[tot]=i;
					t[tot++]=j;	
					fa[j]=i;					
				}
				lk[i][j]=1;
				
			}
		}
	}
	for(i=0;i<tot;i++){
		printf("%d %d\n",f[i],t[i]);
	}
	if(!i){
		printf("none");
	}
}	
void magyarorszag(){
	memset(fa,0,sizeof(fa));
	int i,j;
	for(i=1;i<=n;i++){
		v.reset();
		dfs(i);
	}
}
bool dfs(int po){
	int i,j,k;
	for(i=1;i<=n;i++){
		if(lk[po][i] && !v[i]){
			v[i]=1;
			if( !fa[i] || dfs(fa[i])){
				fa[i]=po;
				return true;
			}
		}
	}
	return false;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}cdvs1222;int main(){} 
