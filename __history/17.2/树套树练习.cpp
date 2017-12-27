#include<cstdio>
#include<algorithm>
using namespace std;
struct sbn
{
	short val;
};

struct node
{
	sbn subnode[2048];
}tree[2048];


void subinsert(int y,int j)
{
	int i=1024+y;
	for(;i;i>>=1)
	{
		tree[j].subnode[i].val=max(tree[j<<1].subnode[i].val ,tree[(j<<1)|1].subnode[i].val );
 		printf("stree[%d][%d]=%d;\n",j,i,tree[j].subnode[i].val);
	}
}



void insert(int x,int y,short val)
{
	int i,j,k,l;
	j=y+1024;
	k=x+1024;
	tree[k].subnode[j].val =val;
 	printf("tree[%d][%d]=%d;\n",k,j,tree[k].subnode[j].val);
	for(j>>=1;j;j>>=1)
	
	{
		tree[k].subnode[j].val =max(tree[k].subnode[j<<1].val,tree[k].subnode[(j<<1)|1].val );
		printf("tree[%d][%d]=%d;\n",k,j,tree[k].subnode[j].val);
	}
		for(j=(x+1024)>>1;j;j>>=1)
	{
		subinsert(y,j);
	}
}

short subquery(int yl,int yr,short x)
{
	int l, r;
	short smax=0;
	l=1024+yl-1;
	r=1024+yr+1;
	for(;l^r^1;l>>=1,r>>=1)
	{
		
		if(~l&1)
		{smax=max(smax,tree[x].subnode[l^1].val);
 	 	printf("qstree[%d][%d]=%d\n",x,l^1,tree[x].subnode[l^1].val );
			}	
		if(r&1)
		{
		
		smax=max(smax,tree[x].subnode[r^1].val);
 		printf("qstree[%d][%d]=%d\n",x,r^1,tree[x].subnode[r^1].val );
		}
	}
	return smax;
}


short query(int xl,int xr,int yl,int yr)
{
	short qmax=0;
	int l=1024+xl-1,r=1024+xr+1;
	for(;l^r^1;l>>=1,r>>=1)
	{
		if((~l)&1)
		qmax=max(qmax,subquery(yl,yr,l^1));
		if(r&1)
		qmax=max(qmax,subquery(yl,yr,r^1));
	}
	return qmax;
}

int main()
{
	insert(1,1,5);
	insert(2,2,4);
	printf("%d\n%d",(int)query(2,2,2,2),(int)query(1,20,1,20));
	
	
 } 
