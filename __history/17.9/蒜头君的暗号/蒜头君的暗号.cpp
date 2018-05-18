using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
struct _Main{
int to[210];
int vis[210];
char str[210];
int len[210];
int head[210];
int circnt;
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
_Main(){
	int n;int i,j,k;int g;char tmp;int t1,t2;
	read(n);read(g);
	for(i=1;i<=n;i++){
		read(to[i]);
	}fgets(str+1,205,stdin);
	
	t1=strlen(str+1);if(str[t1]!='\n')t1++;
	for(i=t1;i<=n;i++){
		str[i]=' ';
	}str[n+1]='\0';
	for(i=1;i<=n;i++)if(!vis[i]){
		head[circnt]=i;
		for(j=i;!vis[j];j=to[j]){
			vis[j]=true;
			len[circnt]++;
		}
		circnt++;
	}
	
	for(i=0;i<circnt;i++){
		for(j=1;j<=g%len[i];j++){
			tmp=str[head[i]];
			for(k=head[i];1;k=to[k]){
				swap(tmp,str[to[k]]);
				if(to[k]==head[i])break;
			}
		}
	}
	for(i=1;i<=n;i++){
		putchar(str[i]);
	}fclose(stdout);
}
	
	
}jsk;
