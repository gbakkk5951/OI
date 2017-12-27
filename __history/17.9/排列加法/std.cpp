using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>

int n;
struct Tree1{
int inline lb(int a){
	return a&-a;
}
int node[50005];
void add(int pos){
	for(pos++;pos<=n;pos+=lb(pos)){
		node[pos]++;
	}
}	
int query(int pos){
	int ret=0;
	for(pos++;pos;pos-=lb(pos)){
		ret+=node[pos];
	}return ret;
}
}tree[3];


struct _Main{
int a[3][50005];	
int s[3][50005];
template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while( isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
_Main(){
	int i,j,k,l,r,mid;
	read(n);
	for(j=0;j<2;j++)
		for(i=n-1;i>=0;i--)
			read(a[j][i]);
	for(j=0;j<2;j++)
		for(i=0;i<n;i++){
			s[j][i]=tree[j].query(a[j][i]);
			tree[j].add(a[j][i]);
		}
	for(i=0;i<n;i++){
		s[2][i]+=s[0][i]+s[1][i];
		if(s[2][i]>i){
			s[2][i+1]++;
			s[2][i]-=i+1;	
		}
	}
	for(i=n-1;i>=0;i--){
		l=0;r=n-1;
		while(l<r){
			mid=(l+r)>>1;
			if(tree[2].query(mid)+s[2][i]<=mid){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		tree[2].add(l);
		a[2][i]=l;
	}
	for(i=n-1;i>0;i--){
		printf("%d ",a[2][i]);
	}printf("%d",a[2][i]);
}	
	
	
	
}jsk;
