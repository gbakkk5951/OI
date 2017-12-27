#include<cstdio>
#define ll long long
#define ini long long i,j,k;
struct begin{
	
ll max(ll a,ll b)
{
	return a>b?a:b;
	}	
ll max(ll a,ll b,ll c ){
	return max(max(a,b),c);
}
ll max (ll a,ll b,ll c, ll d){
	return max(max(a,b,c),d);
}
	
struct st_tree{
	ll sum;
	ll max;
	ll lm;
	ll rm;	
	int l,r;
	
}tree[524300];
ll arr[200010];

begin(){
	readin();
}
int n,q;

void build(int now=1,int l=1,int r=262144){
	tree[now].l =l;
	tree[now].r=r;

	
	if(l==r){
		if(l>200000)
		return;
		tree[now].lm =arr[l];
		tree[now].rm=arr[l];
		tree[now].sum =arr[l];
		tree[now].max =arr[l];
	}else{
	
		int mid=(l+r)>>1;
		build(now<<1,l,mid);
		build(now<<1|1,mid+1,r);
		tree[now].lm =max(tree[now<<1].lm ,tree[now<<1].sum +tree[now<<1|1].lm);
		tree[now].rm =max(tree[now<<1|1].rm ,tree[now<<1|1].sum +tree[now<<1].rm);
		tree[now].sum=tree[now<<1].sum +tree[now<<1|1].sum ;
		tree[now].max =max(tree[now<<1].rm +tree[now<<1|1].lm  ,tree[now<<1|1].max ,tree[now<<1].max);
	}

}

void readin(){
	ini
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	scanf("%lld",&arr[i]);
	}

	build();

	scanf("%d",&q);
	
	
	for(i=0;i<q;i++){
		scanf("%lld%lld",&j,&k);
		printf("%lld\n",query(j,k).max);
	}
}

st_tree query(int l,int r,int now=1){
	//printf("%d ",now);
	//printf(" l=%d r=%d;",l,r);
	if(tree[now].r==r&&tree[now].l==l){
		return  tree[now];
	}
	int mid=(tree[now].l+tree[now].r)>>1;
	if(mid>=r){
		return query(l,r,now<<1);
	}
	if(mid<l){
		return query(l,r,now<<1|1);
	}
	else{ st_tree ans;
		st_tree lc,rc;
		lc=query(l,mid,now<<1);
		rc=query(mid+1,r,now<<1|1);
		ans.sum=lc.sum+rc.sum;
		ans.lm=max(lc.lm,lc.sum+rc.lm);
		ans.rm=max(rc.rm,rc.sum+lc.rm);
		ans.max=max(rc.max,lc.max,rc.lm+lc.rm);return ans;
	}
	
	
}
	
	
	
	
	
	
	
	
	
	
	
}instance;int main(){}
