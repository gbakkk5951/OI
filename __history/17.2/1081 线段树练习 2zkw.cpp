using namespace std;
#include<cstdio>
#include<algorithm>
const int nu=131072;
int tree[262200];
int n;
int q;
int query(int x)
{
	int re=0;
	int i,j,k,l;
	re+=tree[nu+x];
	for(i=(nu+x)>>1;i;i>>=1)
	{
		re+=tree[i];
	}
	return re;
}

void insert(int x,int val)
{
	int root=nu+x;
	int t;
	tree[root]=val;
	root>>=1;
	for(;root;root>>=1){
		t=min(tree[root<<1],tree[(root<<1)^1]);
		tree[root<<1]-=t;
		tree[(root<<1)^1]-=t;
		tree[root]+=t;
	}
	
	
	
}

void add(int ql,int qr,int v)
{
	int s,t,i,j,k;
	s=nu+ql-1;
	t=nu+qr+1;
	for(;s^t^1;s>>=1,t>>=1){
		if(~s&1)tree[s^1]+=v;
		if(t&1)tree[t^1]+=v;
		i=min(tree[s],tree[s^1]);
		tree[s]-=i;tree[s^1]-=i;
		tree[s>>1]+=i;
		i=min(tree[t],tree[t^1]);
		tree[t]-=i;tree[t^1]-=i;
		tree[t>>1]+=i;
		
	}
	
	
	
}

int main()
{
	int i,j,k,l;
	int t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		insert(i,t);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d%d",&j,&k,&l);
	 		add(j,k,l);
			
		}
		else{
			scanf("%d",&j);
			printf("%d\n",query(j));
			
			
		}
		
	}
	
	
	
}
