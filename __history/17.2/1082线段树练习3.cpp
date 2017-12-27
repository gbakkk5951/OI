using namespace std;
const int nu=262144;
#include<cstdio>
#include<algorithm>
long long tree[602150];
long long lazy[602150];
int po[20];
void build(){
	int it=18;
int i,j,k,l;
	for(it=18;it>=0;it--)
	{
		for(i=po[it];i<po[it+1];i+=2)
		{
			tree[i>>1]=tree[i]+tree[i+1];
		}

	}
}


void add(int l,int r,int val,int root=1,int tl=1,int tr=nu)
{
	if(l<=tl&&r>=tr){
		lazy[root]+=val;
		tree[root]+=(tr-tl+1)*val;
	}else{
		if(r<tl||l>tr)
		return;
		int mid=(tl+tr)>>1;
		tree[root]+=val*(min(r,tr)-max(l,tl)+1);
		
		add(l,r,val,root<<1,tl,mid);
		add(l,r,val,(root<<1)+1,mid+1,tr);

	
	}
	
	
}
long long sum(int l,int r,int root=1,int tl=1,int tr=nu)
{
	if(l<=tl&&r>=tr){
		return tree[root];
	}else{
		if(tl>r||tr<l)
		return 0;
		int mid=(tl+tr)>>1;
		if(lazy[root]){
		lazy[root<<1]+=lazy[root];
		tree[root<<1]+=lazy[root]*(mid-tl+1);
		lazy[(root<<1)+1]+=lazy[root];
		tree[(root<<1)+1]+=lazy[root]*(tr-mid);
		lazy[root]=0;}
		return (sum(l,r,root<<1,tl,mid)+sum(l,r,(root<<1)+1,mid+1,tr));
	}
	
	
}


int main()
{
	po[0]=1;
	int n,i,t,j,k,l;
	for(i=1;i<20;i++)
	po[i]=po[i-1]*2;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tree[nu+i]);
	}
	build();
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d%d",&j,&k,&l);
			add(j,k,l);
		}
		else{
			scanf("%d%d",&j,&k);
			printf("%lld\n",sum(j,k));
		}
		
	}
	
}

