#include<cstdio>
#include<algorithm>
using namespace std;const int N=1e5+10;
int n;int m;int mod;int a[18][N];
struct linetree
{
	int v[4*N];int add[4*N];
	inline void pushdown(int p)
	{
		if(add[p]==0)return;
		v[p<<1]^=add[p];v[p<<1|1]^=add[p];
		add[p<<1]^=add[p];add[p<<1|1]^=add[p];
		add[p]=0;
	}
	inline void rv(int p,int l,int r,int dl,int dr)
	{
		if(dl==l&&dr==r){v[p]^=1;add[p]^=1;return;}
		int mid=(l+r)/2;pushdown(p);
		if(dl<mid)rv(p<<1,l,mid,dl,min(dr,mid));
		if(mid<dr)rv(p<<1|1,mid,r,max(dl,mid),dr);
		v[p]=v[p<<1]^v[p<<1|1];
	}
	inline int sum(int p,int l,int r,int dl,int dr)
	{
		if(dl==l&&dr==r){return v[p];}
		int mid=(l+r)/2;int ret=0;pushdown(p);
		if(dl<mid)ret^=sum(p<<1,l,mid,dl,min(dr,mid));
		if(mid<dr)ret^=sum(p<<1|1,mid,r,max(dl,mid),dr);
		return ret;
	}
	inline void build(int* a,int p,int l,int r)
	{
		if(r-l==1){v[p]=a[r];return;}int mid=(l+r)/2;
		build(a,p<<1,l,mid);build(a,p<<1|1,mid,r);v[p]=v[p<<1]^v[p<<1|1];
	}
}lt[18];
int main()
{
	freopen("right.in","r",stdin);
	freopen("right.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1,t;i<=n;i++){scanf("%d",&t);for(int j=0;t;j++,t/=mod)a[j][i]=t%mod,a[j][i]%=2;}
	for(int i=0;i<=16;i++)lt[i].build(a[i],1,0,n);
	for(int i=1,t,l,r;i<=m;i++)
	{
		scanf("%d%d%d",&t,&l,&r);
		if(t==0)
		{
			int v;scanf("%d",&v);
			for(int k=0;v;k++,v/=mod)
				if((v%mod)%2){lt[k].rv(1,0,n,l-1,r);}
		}
		else
		{
			int ret=0;for(int j=0;j<=16;j++)ret^=lt[j].sum(1,0,n,l-1,r);
			printf("%d\n",ret);
		}
	}fclose(stdin);fclose(stdout);return 0;
}

