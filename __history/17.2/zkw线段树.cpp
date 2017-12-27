#include<cstdio>
int n;
int m;
int q;
int tree[300000];
void build()
{for(m=1;m<n;m<<=1);
int i=0;
for(i=m+1;i<=m+n;i++)
{
scanf("%d",&tree[i]);
}
for(i=m-1;i;i--)
{tree[i]=tree[i<<1]+tree[i<<1|1];
}
}
int sum(int l,int r)
{
	int ans=0;
	for(l=l+m-1,r=m+r+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)ans+=tree[l^1];
		if(r&1)ans+=tree[r^1];
	}printf("%d\n",ans);
}
void add(int x,int v)
{
	tree[m+x]+=v;
	int i=0;
	for(i=m+x>>1;i;i>>=1)
	{
		tree[i]=tree[(i<<1)]+tree[(i<<1)^1];
	}
	
}

int main()
{
	scanf("%d",&n);
	build();
	scanf("%d",&q);
	int t1,t2,t3;
	int i,j,k;
	for(i=0;i<q;i++)
	{scanf("%d%d%d",&t1,&t2,&t3);
		if(t1==1)
		add(t2,t3);
		else sum(t2,t3);
		
	}
	
	
	
	
	
	
	
}
