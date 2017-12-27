#include<cstring>
#include<cstdio>
#include<vector> 
#include<algorithm>
#include<ctime>
using namespace std;
char a[802],b[802];
int re[5];
int dis[256];
bool read();
void search();

int la,lb;
int maxn=0;

/*struct dp
{int v;
int a;
int b;
};*/
struct sftree
{
int val;
sftree *zx,*zs,*ys,*yx;
};

void clear(sftree *&a,int times=0);

int pmax(int a,int b,int c,int d)
{int temp=a;
if(b>temp)
temp=b;
if(c>temp)
temp=c;
if(d>temp)
temp=d;
return temp;
}


sftree *roo;

void insert(sftree *root,int xl,int xr,int yl,int yr,int x,int y,int val);
int findmax(sftree *root,int xl,int xr,int yl,int yr,int nxl,int nxr,int nyl,int nyr); 
//vector<dp>data;

void initialize(sftree *&a,int times=0)
{
	a=(sftree *)malloc(sizeof(sftree)); 
	a->val=0;
	if(times<10)
	{
	initialize(a->zx,times+1);
	initialize(a->zs,times+1);
	initialize(a->yx,times+1);
	initialize(a->ys,times+1);
    }
} 
int main()
{
initialize(roo);
int n;
//printf("%f",(float)clock()/CLOCKS_PER_SEC);
scanf("%s",a);
scanf("%s",b);
scanf("%d",&n);
int i=0,j=0;

for(i=0;i<n;i++)
{
for(j=0;j<256;j++)
dis[j]=802;
while(read());
clear(roo);
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
//printf("fmax ");

int max=findmax(roo,1,1024,1,1024,xl,xr,yl,yr)+1;
if(maxn<max)
maxn=max;
//printf("insert");
insert(roo,1,1024,1,1024,i,j,max);

}}

}


}

void insert(sftree *root,int xl,int xr,int yl,int yr,int x,int y,int val)
{
//printf("insert(xl=%d,xr%d)",yl,yr);
if(xr==xl&&yl==yr)
{
	root->val=val;
	return;
}
int xmid=(xl+xr)/2;
int ymid=(yl+yr)/2;

if(val>root->val)
root->val=val;

if(x<=xmid)
{
	if(y<=ymid)
	{
		insert(root->zx,xl,xmid,yl,ymid,x,y,val);
	}else insert(root->zs,xl,xmid,ymid+1,yr,x,y,val);
}
else
{if(y<=ymid)
insert(root->yx,xmid+1,xr,yl,ymid,x,y,val);
else insert(root->ys,xmid+1,xr,ymid+1,yr,x,y,val);
}
	

}

int findmax(sftree *root,int xl,int xr,int yl,int yr,int nxl,int nxr,int nyl,int nyr)
{
	if(nxl>xr||nxr<xl||nyl>yr||nyr<yl)
	return 0;
	if(nxl<=xl&&nxr>=xr&&nyl<=yl&&nyr>=yr)
	return root->val;
	//进一步四分 
	int xmid=(xl+xr)/2;
	int ymid=(yl+yr)/2;
	return(pmax(findmax(root->zx,xl,xmid,yl,ymid,nxl,nxr,nyl,nyr),findmax(root->yx,xmid+1,xr,yl,ymid,nxl,nxr,nyl,nyr),findmax(root->zs,xl,xmid,ymid+1,yr,nxl,nxr,nyl,nyr),findmax(root->ys,xmid+1,xr,ymid+1,yr,nxl,nxr,nyl,nyr)));
}


void clear(sftree *&a,int times)
{
a->val=0;
if(times<10)
{clear(a->zx,times+1);
clear(a->zs,times+1);
clear(a->yx,times+1);
clear(a->ys,times+1);
}

}
