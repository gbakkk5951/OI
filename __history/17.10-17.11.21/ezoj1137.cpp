using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<algorithm>
namespace Protector{
int base;

struct RangeMinRangeChangeTree{
	int node[2100000];
	int query(int s,int t){
		long long lans=2e9+7,rans=2e9+7;
		for(s=s+base-1,t=t+base+1;s^t^1;s>>=1,t>>=1){
			lans+=node[s];rans+=node[t];
			if(~s&1)lans=min(lans,(long long)node[s^1]);
			if( t&1)rans=min(rans,(long long)node[t^1]);
		}
		lans=min(lans+node[s],rans+node[t]);
		while(s>>=1){
			lans+=node[s];
		}
		return lans;
	}
	void change(int s,int t,int val){
		int a;
		for(s=s+base-1,t=t+base+1;s^t^1;s>>=1,t>>=1){
			if(~s&1)node[s^1]+=val;
			if( t&1)node[t^1]+=val;
			a=min(node[s],node[s^1]);node[s>>1]+=a;node[s]-=a;node[s^1]-=a;
			a=min(node[t],node[t^1]);node[t>>1]+=a;node[t]-=a;node[t^1]-=a;			
		}
		while(s>>=1){
			a=min(node[s<<1],node[s<<1|1]);node[s]+=a;node[s<<1]-=a;node[s<<1|1]-=a;
		}
	}
}tree;

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
	_Main(){
		int i,j,k;
		int n,m;
		int a,b,c;
		read(n);read(m);
		for(base=4;base<(n+2);base<<=1);
		for(i=1;i<=n;i++){
			read(tree.node[i+base]);
		}
		for(i=base-1;i;i--){
			a=min(tree.node[i<<1],tree.node[i<<1|1]);
			tree.node[i]=a;tree.node[i<<1]-=a;tree.node[i<<1|1]-=a;	
		}
		for(i=1;i<=m;i++){
			read(a);read(b);read(c);
			if(tree.query(b,c)>=a){
				tree.change(b,c,-a);
			}else{
				printf("-1\n%d",i);
				goto EndMain;
			}
		}
		printf("0");
		EndMain:
			fclose(stdout);
	}
	
}ezoj1137;


}
