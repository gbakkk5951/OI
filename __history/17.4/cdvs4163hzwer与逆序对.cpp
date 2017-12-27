#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#define base 1048576
//using namespace std;
long long ans;
/*struct zkw{
	
int node[2100007];
int zn;
void insert(int t){
	for(t=base+t;t;t>>=1){
		node[t]+=1;
	}
}
int query(int s){
	int t=base+zn+1;
	int ans=0;
	for(s=s+base-1;t^s^1;t>>=1,s>>=1){
		if(~s&1)ans+=node[s^1];
		if( t&1)ans+=node[t^1];
	}
	return ans;
}
	
	
}tree;*/	
#define lb(i) i&(-i)
int node[1100007];
int n;
struct index_tree{
int zn;
void insert(int t){
	while(t<=zn){
		node[t]++;
		t+=lb(t);
	}
}
int query(int l){
	int ans=0;
	int r=zn;
	l--;
	while(l){
		ans-=node[l];
		l-=lb(l);
	}
	while(r){
		ans+=node[r];
		r-=lb(r);
	}
	return ans;
	
}
	
	
	
}tree;
struct _Main {


	
int n;
int a[1000017];
int b[1000009];
int read(){
	char t;int ans=0;
	while(!isdigit(t=getchar()));
	do{
		ans*=10;
		ans+=t-'0';
	}while(isdigit(t=getchar()));
	return ans;
}
int nn;
_Main(){
	using std::sort;
	using std::unique;
	n=read();
	tree.zn =n;
	int i,j;
	for(i=1;i<=n;i++){
		a[i]=read();
	}
	memcpy(b,a,4*n+8);
	sort(b+1,b+n+1);
	nn=unique(b+1,b+n+1)-b;
	for(i=1;i<=n;i++){
		j=binary(a[i]);
		ans+=tree.query(j+1);
		tree.insert(j);
	}
	printf("%lld",ans);
}
int binary(int in){
	int l=1,r=nn;
	while(l^r){
		if(b[(l+r)>>1]<in){
			l=((l+r)>>1)+1;
		}else{
			r=(l+r)>>1;
		}
	}
	return l;
	
}

	
	
	
}cdvs4163;
int main(){}
