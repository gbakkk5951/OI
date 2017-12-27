int main(){}
using namespace std;
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<cmath>
struct _Main{
int nxt[200010];
int t[200010];
int head[100010];
int dfn[100010];
int l[100010];
int r[100010];
int h[100010];
int arr[100010];
int sig[330];// [ sq*i,sq*(i+1) )
int sq;
int dfsidx;
int sorted[100010];
int dfs(int nd,int from){
	int i;
	dfn[nd]=++dfsidx;
	l[nd]=dfsidx+1;
	r[nd]=dfsidx;
	for(i=head[nd];i;i=nxt[i]) if(t[i]!=from){
		r[nd]=dfs(t[i],nd);
	}
	return r[nd];
}

void BFchange(int l,int r,int val){
	int i;int g=(int)(l/sq)*sq;
	for(i=l;i<=r;i++){
		arr[i]-=val;
	}
	memcpy(sorted+g,arr+g,sq*sizeof(int));
	sort(sorted+g,sorted+g+sq);
}

void change(int l,int r,int val){
	if(l>r)return ;
	int i;
	if(l%sq!=0&& (i=(l/sq)*sq+sq)-1<=r){
		BFchange(l,i-1,val);
	}else{
		i=l;
	}
	for( ;i+sq-1<=r;i+=sq){
		sig[i/sq]+=val;
	}
	if(i<=r){
		BFchange(i,r,val);
	}

}
int BFquery(int l,int r){
	int i;int ans=0;int g=l/sq;
	for(i=l;i<=r;i++){
		if(arr[i]>sig[g]){
			ans++;
		}
	}return ans;
}
int query(int l,int r){
	if(l>r)return 0;
	int i;int ans=0;
	if(l%sq!=0 && (i=(l/sq)*sq+sq)-1<=r){
		ans+=BFquery(l,i-1);
	}else{
		i=l;
	}
	for( ;i+sq-1<=r;i+=sq){
		ans+=sorted+sq+i-upper_bound(sorted+i,sorted+i+sq,sig[i/sq]);
	}
	if(i<=r){
		ans+=BFquery(i,r);
	}return ans;
}

template<typename Type>
	void read(Type &a){
		char t;
		while(!isdigit(t=getchar()));
		a=t-'0';
		while(isdigit(t=getchar())){
			a*=10;
			a+=t-'0';
		}
	}
int idx;
void inline add(int a,int b){
	idx++;
	nxt[idx]=head[a];
	head[a]=idx;
	t[idx]=b;
}
int n;
_Main(){
	int q;
	int i;int a,b,c;
	read(n);sq=sqrt(n);
	for(i=1;i<=n;i++){
		read(h[i]);read(a);
		add(a,i);add(i,a);
	}
	dfs(0,-1);
	for(i=1;i<=n;i++){
		sorted[dfn[i]]=arr[dfn[i]]=h[i];
	}
	for(i=0;i<=n+1;i+=sq){
		sort(sorted+i,sorted+i+sq);
	}
	read(q);
	for(i=0;i<q;i++){
		read(a);
		switch (a){
			case 1:{
				read(b);read(c);
				change(l[b],r[b],c);
				break;
			}
			case 2:{
				read(b);
				printf("%d\n",query(l[b],r[b]));
				break;
			}
		}
	}
}	
	
	
	
}alone;
