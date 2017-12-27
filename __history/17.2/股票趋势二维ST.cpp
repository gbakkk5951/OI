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
int po[11];
int st[1024][1024][11];

void insert(int x,int y,short val)
{

	int mn=min(x,y);
	int i,j,k,l;
	
	
	for(i=10;mn<po[i];i--);
	int maxn=i;
	st[x][y][0]=val;
	for(i=1;i<=maxn;i++)
	{
		st[x][y][i]=max(st[x-po[i-1]][y][i-1],st[x-po[i-1]][y-po[i-1]][i-1]);
		st[x][y][i]=max(st[x][y][i],st[x][y][i-1]);
		st[x][y][i]=max(st[x][y][i],st[x][y-po[i-1]][i-1]);
	}
}



short query(int xl,int xr,int yl,int yr)
{if(!xl||!xr||!yl||!yr)
return 0;

	int mn=min(xr-xl+1,yr-yl+1);
	int i,j,k,l;
	int ans=0;
	for(i=10;po[i]>mn;i--);
	
	int nj=(xr-xl+1)/po[i],nk=(yr-yl+1)/po[i];
	for(j=0;j<nj;j++)
	{
		for(k=0;k<nk;k++)
		{

			ans=max(ans,st[xr-j*po[i]][yr-k*po[i]][i]);
		}

	}
	for(j=0;j<nj;j++)
	{
		ans=max(ans,st[xr-j*po[i]][yl+po[i]-1][i]);
	}
	for(k=0;k<nk;k++)
	{
		ans=max(ans,st[xl+po[i]-1][yr-k*po[i]][i]);
	}	
	
	ans=max(ans,st[xl+po[i]-1][yl+po[i]-1][i]);
	

	
	return ans;
}


int main()
{
	
int n;
scanf("%s",a);
scanf("%s",b);
scanf("%d",&n);
int i=0,j=0;
po[0]=1;
for(i=1;i<11;i++)
po[i]=po[i-1]*2;

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
else insert(i,j,0); 
}

}


}
