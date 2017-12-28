using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
int h[100010];
int ans;
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;a+=t-'0';
		}
	}

struct Tree{
public:
	int const & size(){
		return n;
	}
	void inline resize(int a){
		n=a;
	}
	void change(int nd,int val){
		for( ;node[nd]<val && nd<=n;nd+=lowbit(nd)){
			node[nd]=val;
		}
	}
	int query(int nd){
		int ans=0;
		for( ;nd;nd-=lowbit(nd)){
			ans=max(ans,node[nd]);
		}
		return ans;
	}
private:
	int n;
	int inline lowbit(const int &a){
		return a&(-a);
	}
	int node[100010];	
}tree[2];//0表示上次下降，1表示上次上升

struct _Main{
	int org[100010];
	int sorted[100010];
	int rk[100010];
_Main(){
	int i,j,k;
	int n;int tmp;int m;
	read(n);
	for(i=1;i<=n;i++){
		read(org[i]);
	}
	memcpy(sorted,org,(n+1)*sizeof(int));
	sort(sorted+1,sorted+1+n);
	m=unique(sorted+1,sorted+1+n)-sorted-1;
	tree[0].resize(m);tree[1].resize(m);
	for(i=1;i<=n;i++){
		rk[i]=lower_bound(sorted+1,sorted+1+m,org[i])-sorted;
	}
	
	for(i=1;i<=n;i++){
		tmp=tree[0].query(rk[i]-1);
		tree[1].change(m+1-rk[i],tmp+1);
		ans=max(ans,tmp+1);	
		tmp=tree[1].query(m-rk[i]);
		tree[0].change(rk[i],tmp+1);		
		ans=max(ans,tmp+1);	
	}
	printf("%d\n",ans);
	
}	
	
	
	
}ezoj1110;
 


