using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
const int mod=10007;
struct _Main{
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}
int head[200010];
int nxt[400010];
int to[400010];	
int val[200010];
int ndsum[200010];
int ndmx[200010];
int mx;
int sum;
void dfs(int nd=1,int from=0){
	int i;
	for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
		dfs(to[i],nd);
		mx=max(mx,val[nd]*ndmx[to[i]]);
		mx=max(mx,ndmx[nd]*val[to[i]]);
		sum=(sum+2*val[nd]*(ndsum[to[i]])+2*ndsum[nd]*val[to[i]])%mod;
		ndsum[nd]+=val[to[i]];
		ndsum[nd]%=mod;
		ndmx[nd]=max(ndmx[nd],val[to[i]]);
	}
	
}
int eidx;
void inline add(int a,int b){
	eidx++;
	nxt[eidx]=head[a];
	head[a]=eidx;
	to[eidx]=b;
}
int n;
_Main(){
	
	int i,j,k;int a,b;
	read(n);
	for(i=0;i<n-1;i++){
		read(a);read(b);
		add(a,b);add(b,a);
	}
	for(i=1;i<=n;i++){
		read(val[i]);
	}
	dfs();
	printf("%d %d",mx,sum);
}	
	
	
	
}ezoj1103;
