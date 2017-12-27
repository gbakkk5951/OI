#include<cstdio>
#include<cctype>
#include<bitset>
using namespace std;
bitset<800>v;
int head[410];
int nxt[80010];
int to[80010];
int tail[410];
char buf[80010];
int fa[405];
int tot;
int ans;
struct _Main{
void add(int a,int b){
	if(head[a]){
		nxt[tail[a]]=tot;
	}else{
		head[a]=tot;
	}
	tail[a]=tot;
	to[tot]=b;
	tot++;
}
int pos;
int read(){
	int ans=0;
	while(!isdigit(buf[pos])){
		pos++;
	}
	while(isdigit(buf[pos])){
		ans*=10;
		ans+=buf[pos]-'0';
		pos++;
	}
	return ans;
}
int m,n;

int readline(){
	v.reset();
	int i,t,l;
	fgets(buf,80008,stdin);
	n=read();
	m=read();
	pos=0;
	for(i=1;i<=n;i++){
		
		fgets(buf,80008,stdin);
		while(t=read()){
			add(i,t+200);
			add(t+200,i);
		}
		pos=0;
	}
}
	
_Main(){
	tot=1;
	readline();
	magyarorszag();
	printf("%d",ans);
}
bool dfs(int now){
	int i,y;
	for(i=head[now];i;i=nxt[i]){
		if(!v[y=to[i]]){
			v[y]=1;
			if(!fa[y] || dfs(fa[y])){
				fa[y]=now;
				return true;
			}
		}
	}
	return false;
	
}
void magyarorszag(){
	int i;
	for(i=1;i<=n;i++){
		v.reset();
		if(dfs (i)){
			ans++;
		}
	}
}	
	
	
	
	
	
	
	
	
	
	
}cdvs2776;int main(){}
