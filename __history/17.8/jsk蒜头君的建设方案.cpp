using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
struct _Main{
template <typename Type>
void read(Type &a){
	char t;
	while(!isdigit(t=getchar()));
	a=t-'0';
	while(isdigit(t=getchar())){
		a*=10;
		a+=t-'0';
	}
}
int inline abs(int a){
	return a>>31^((a>>31)+a);
}
int nxt[2000010];
int to[2000010];
long long l[2000010];
int head[2000010];
long long ans;
void inline add(){
	int a;int b;int c;
	read(a);read(b);read(c);
	idx++;
	nxt[idx]=head[a];
	head[a]=idx;
	to[idx]=b;
	l[idx]=c;
	idx++;
	nxt[idx]=head[b];
	head[b]=idx;
	to[idx]=a;
	l[idx]=c;	
}
int idx;
long long n;

_Main(){
	int i,a,b,c;
	read(n);
	for(i=0;i<n-1;i++){
		add();
	}
	dfs(1,0);
	printf("%lld",ans);
}
long long dfs(int nd,int from){
	int i;int size=0;long long t;
	for(i=head[nd];i;i=nxt[i]){
		if(to[i]!=from){
			t=dfs(to[i],nd);
			size+=t;
			ans=ans+(long long)abs(n-(t<<1))*l[i];
		}
	}size++;
	return size;
}


	
	
	
	
}road;
