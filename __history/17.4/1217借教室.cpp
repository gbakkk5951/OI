#include<cstdio>
#include<cctype>
using namespace std;
#define base 1048576
struct _Main{

int read(){
	char t;int ans=0;
	while(!isdigit(t=getchar()));
	do{
		ans*=10;
		ans+=t-'0';
	}while(isdigit(t=getchar()));
	return ans;
}


struct segment_tree{

inline int _min(int a,int b){
	return a>b?b:a;
}
int tree[2100003];	
void change(int s,int t,int add){
	int a;
	for(s=s+base-1,t=t+base+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)
			tree[s^1]+=add;
		if(t&1)
			tree[t^1]+=add;
			
		a=_min(tree[s],tree[s^1]);
		tree[s   ]-=a;
		tree[s^1 ]-=a;
		tree[s>>1]+=a;	
		
		a=_min(tree[t],tree[t^1]);
		tree[t   ]-=a;
		tree[t^1 ]-=a;
		tree[t>>1]+=a;		
	}
	while(t^1){
		int c=1;
		a=_min(tree[t],tree[t^1]);
		
		tree[t   ]-=a;
		tree[t^1 ]-=a;
		tree[t>>=1]+=a;
	}
}	

int min(int s,int t){
	int lans=0,rans=0;
	for(s=s+base-1,t=t+base+1;s^t^1;s>>=1,t>>=1){
		lans+=tree[s];
		rans+=tree[t];
		if(~s&1)lans=_min(lans,tree[s^1]);
		if( t&1)rans=_min(rans,tree[t^1]);
	}
	lans=_min(lans,rans);
	while(s){
		lans+=tree[s>>=1];
	}
	return lans;
}

}zkw;


int n,m;
_Main(){

	
	
	int i,j,t1,t2,t3;
	n=read();
	m=read();
	for(i=1;i<=n;i++){
		j=read();
		zkw.change(i,i,j);
	}
	for(i=1;i<=m;i++){
		t3=read();
		t1=read();
		t2=read();
		
		zkw.change(t1,t2,-t3);
		if(zkw.min(t1,t2)<0){
			printf("-1\n%d",i);
			return;
		}
	}printf("0");	
}	
	
}instance;int main(){}
