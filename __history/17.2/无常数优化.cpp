
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool read();
int la,lb;
int maxn=0;
void search();
char a[802],b[802];
int dis[256];
int re[6];
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
	for(;i;i/=2)
	{
		tree[j].subnode[i].val=max(tree[j*2].subnode[i].val ,tree[j*2+1].subnode[i].val );
 	
	}
}



void insert(int x,int y,short val)
{
	int i,j,k,l;
	j=y+1024;
	k=x+1024;
	tree[k].subnode[j].val =val;

	for(j/=2;j;j/=2)
	
	{
		tree[k].subnode[j].val =max(tree[k].subnode[j*2].val,tree[k].subnode[j*2+1].val );

	}
		for(j=(x+1024)/2;j;j/=2)
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
	for(;l-r==1;l/=2,r/=2)
	{
		
		if(!l%1)
		{smax=max(smax,tree[x].subnode[l+1].val);

			}	
		if(r%1)
		{
		
		smax=max(smax,tree[x].subnode[r-1].val);
 
		}
	}
	return smax;
}


short query(int xl,int xr,int yl,int yr)
{
	short qmax=0;
	int l=1024+xl-1,r=1024+xr+1;
	for(;r-l==1;l/=2,r/=2)
	{
		if(!l%1)
		qmax=max(qmax,subquery(yl,yr,l+1));
		if(r%1)
		qmax=max(qmax,subquery(yl,yr,r-1));
	}
	return qmax;
}

int main()
{
	
int n;
scanf("%s",a);
scanf("%s",b);
scanf("%d",&n);
int i=0,j=0;

for(i=0;i<n;i++)
{
for(j=0;j<256;j++)
dis[j]=802;
while(read());

search();
re[i]=maxn;
maxn=0;

	
}
for(i=0;i<n;i++)
{
printf("%d ",re[i]);
}

 } 
 
 bool read()
{char ct;
ct=getchar();

if(ct=='$')
return false;
else if(ct=='\n'||ct=='\r'||ct==' ')
return true;
else if(ct==EOF)
return false;

scanf("%d",&dis[(int)ct]);
return true;
}

void search()
{
int m,n;
la=strlen(a);
lb=strlen(b);
int i,j,l;

for(i=1;i<=la;i++)
{
for(j=1;j<=lb;j++)
{
if(a[i-1]==b[j-1])
{
int xl=1>i-dis[a[i-1]]-1?1:i-dis[a[i-1]]-1;
int xr=i-1;
int yl=1>j-dis[b[j-1]]-1?1:j-dis[b[j-1]]-1;
int yr=j-1;


int zmax=query(xl,xr,yl,yr)+1;
if(maxn<zmax)
maxn=zmax;

insert(i,j,zmax);

}
}

}


}
