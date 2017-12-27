#include<cstdio>
#include<algorithm>
using namespace std;
long long mx=0;
long long tree[100010];
long long n,m;
long long ans(long long  l,long long r);

int main(){
	long long i,j,k,l;
	
	scanf("%lld%lld",&n,&m);
	
	for(i=0;i<n;i++){
		scanf("%lld",&tree[i]);
		mx=max(mx,tree[i]);
	}
	printf("%lld",ans(mx,100000000000000));
	
}
long long ans(long long l,long long r){
	if(l==r)
	return l;
	long long mid=(l+r)>>1;
	long long now=mid;
	long long use=1;
	long long i,j,k;
	
	for(i=0;i<n;i++){
		if(tree[i]>now){
			now=mid-tree[i];
			use++;
			if(use>m)
			return ans(mid+1,r);
		}else{
			now-=tree[i];
		}
	}
	if(use>m)
	return ans(mid+1,r);
	else
	return ans(l,mid);
	
}
