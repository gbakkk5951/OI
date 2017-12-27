using namespace std;
int main(){}
#include<cstdio>
#include<cctype>

struct _Main{
	int n;
	double sum;
	double charge[500010];
	double tong[1000010];
	int head[500010];
	int nxt[1000010];
	int to[1000010];
	double rate[500010];//不算父亲不充的概率 
	void dfs0(int nd=1,int from=0){
		int i;
		rate[nd]=1.0-charge[nd];
		for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
			dfs0(to[i],nd);
			rate[nd]*=(1.0-tong[i]*rate[to[i]]);
		}
	}
	void dfs1(int nd=1,int from=0,int edge=0){
		int i;
		sum+=rate[nd]*(1.0-(tong[edge]*(1.0-rate[from]/rate[nd])) );
		for(i=head[nd];i;i=nxt[i])if(to[i]!=from){
			dfs1(to[i],nd,i);
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
	int eidx;
	void inline add(int a,int b,double c){
		eidx++;
		nxt[eidx]=head[a];
		head[a]=eidx;
		to[eidx]=b;
		tong[eidx]=c;
	}
	_Main(){
		int i,a,b,c;
		read(n);
		for(i=1;i<=n-1;i++){
			read(a);read(b);read(c);
			add(a,b,c/100.0);add(b,a,c/100.0);
		}
		for(i=1;i<=n;i++){
			read(charge[i]);
			charge[i]/=100.0;
		}
		dfs0();
		dfs1();
		printf("%.6lf",n-sum);
	}
}ezoj1177;
