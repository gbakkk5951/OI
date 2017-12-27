#include<cstdio>

using namespace std;
void updata(int root,int nl,int nr,int index,int val);

int tree[200010];
int m,n,n2;
int find(int root,int nl,int nr,int ql,int qr);

int main()
{
int i=0;
for(i=0;i<200010;i++)
{
tree[i]=0;

}
scanf("%d",&n);
n2=n*n;
int temp;
for(i=1;i<=n;i++)
{
	scanf("%d",&temp);
	insert(temp);
}
build();
int t1,t2,t3;
scanf("%d",&m);

for(i=1;i<=m;i++)
{
scanf("%d%d%d",&t1,&t2,&t3);
if(t1==2)
{temp=find(1,1,n,t2,t3);
printf("%d\n",temp);
}
else updata(1,1,n,t2,t3);
}
return 0;
}
int find(int root,int nl,int nr,int ql,int qr)
{
if(nl>qr||nr<ql)
return 0;
if(nl>=ql&&nr<=qr)
return tree[root];
int mid=(nl+nr)>>1;
return(find((root<<1),nl,mid,ql,qr)+find((root<<1)+1,mid+1,nr,ql,qr));

}


void updata(int root,int nl,int nr,int index,int val)
{
	if(nl==nr)
	{
	if(index==nl)
	tree[root]+=val;
	return;
	}
	int mid=(nl+nr)>>1;
	if (index<=mid)
	{
	updata(root<<1,nl,mid,index,val);
	}else updata((root<<1)+1,mid+1,nr,index,val);
	tree[root]+=val;
	

}

