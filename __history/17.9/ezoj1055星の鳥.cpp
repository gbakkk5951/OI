using namespace std;
int main(){}
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>

struct _Main{
long long cstsum[50005];
int h[50005];
bool goal[50005];
void predfs(int nd,int from){
	h[nd]=h[from]+1;
	int i;
	for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
		predfs(to[i],nd);
		if(cstsum[to[i]]||goal[to[i]]){
			cstsum[nd]+=cstsum[to[i]]+2*cst[i];
		}
	}
}
long long ans;
void ansdfs(int nd,long long totcst){
	int i;
	if(cstsum[nd]==0){
		ans=min(ans,totcst);
		return;
	}
	for(i=head[nd];i;i=nxt[i])if(h[to[i]]>h[nd] && (cstsum[to[i]]||goal[to[i]])){
		ansdfs(to[i],totcst+cstsum[nd]-cstsum[to[i]]-cst[i]);
	}
}

template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		} 
	}
int nxt[100015];int to[100015];long long cst[100015];
int head[50015];
int eidx;
void inline	add(int a,int b,long long c){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
	cst[eidx]=c;
}
int m,n,root;
_Main(){
	ans=(1LL<<62);
	int a,b;long long c;
	int i;
	read(n);read(root);
	for(i=0;i<n-1;i++){
		read(a);read(b);read(c);
		add(a,b,c);add(b,a,c);
	}
	read(m);
	for(i=0;i<m;i++){
		read(a);goal[a]=1;
	}
	predfs(root,0);
	ansdfs(root,0);
	printf("%lld",ans);
}
	
	
}ezoj1055;
