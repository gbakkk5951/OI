using namespace std;
int main(){}
#include<cstdio>
#include<cctype>

int n,m;

struct TreeArray{
	int node[30005];
private:
	int inline lowbit(int a){
		return a&(-a);
	}
public:
	int query(int nd){
		int sum=0;
		for(;nd;nd-=lowbit(nd)){
			sum+=node[nd];
		}
		return sum;
	}
	void minus(int nd){
		for(;nd<=n;nd+=lowbit(nd)){
			node[nd]--;
		}
	}
	void add(int nd){
		for(;nd<=n;nd+=lowbit(nd)){
			node[nd]++;
		}
	}
	
}tree[2];//0Ë³Ðò£¬1ÄæÐò 
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

int arr[30005];

int nowl,nowr;
long long ans;

void lr(){
	tree[1].minus(n-arr[nowl]+1);
	tree[0].minus(arr[nowl]);
	ans-=tree[0].query(arr[nowl]);
	nowl++;
}
void ll(){
	nowl--;
	ans+=tree[0].query(arr[nowl]);
	tree[1].add(n-arr[nowl]+1);
	tree[0].add(arr[nowl]);
}
void rr(){
	nowr++;
	ans+=tree[1].query(n-arr[nowr]+1);
	tree[1].add(n-arr[nowr]+1);
	tree[0].add(arr[nowr]);	
}
void rl(){
	tree[1].minus(n-arr[nowr]+1);
	tree[0].minus(arr[nowr]);
	ans-=tree[1].query(n-arr[nowr]+1);
	nowr--;	
}
_Main(){
	
	int i,j,k;
	int l,r;
	read(n);
	for(i=1;i<=n;i++){
		read(arr[i]);
	}
	nowl=nowr=1;
	tree[0].add(arr[1]);
	tree[1].add(n-arr[1]+1);
	read(m);
	for(i=1;i<=m;i++){
		read(l);read(r);
		while(nowl>l){
			ll();
		}
		while(nowr<r){
			rr();
		}
		while(nowl<l){
			lr();
		}
		while(nowr>r){
			rl();
		}
		printf("%lld\n",ans);
	}
	
}

}jsk;

