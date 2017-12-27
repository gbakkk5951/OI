#include<cstdio>
struct node
{
	int p,l,r;
}tree[17] ;
int n;
int w[18];
int mh,mw;
void dfs(int root,int iter)
{
	w[iter]++;
	if(tree[root].l)
	{dfs(tree[root].l,iter+1);
	}
	if(tree[root].r)
	{dfs(tree[root].r,iter+1);
	}
	
}
int main()
{
	scanf("%d",&n);
	int i=1;
	int t1,t2;
	for(;i<=n;i++)
	{
		scanf("%d%d",&t1,&t2);
		tree[i].l=t1;
		tree[t1].p=i;
		tree[i].r=t2;
		tree[t2].p=i;
    }
	for(i=1;i<=n;i++)
	{
		if(tree[i].p ==0)
		{
			dfs(i,1);
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(w[i]>0)
		mh=i;
		if(w[i]>mw)
		mw=w[i];
		
	}
	printf("%d %d",mw,mh);
}


