#include<cstdio>
#include<algorithm>
#include<cmath>
int map[1024][1024];
int po[11];
int st[1024][1024][11];
using namespace std;
int query(int xl,int xr,int yl,int yr)
{
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

int deal(int x,int y)
{
	int mn=min(x,y);
	int i,j,k,l;
	for(i=10;mn-po[i]<0;i--);
	int maxn=i;
	st[x][y][0]=map[x][y];
	for(i=1;i<maxn;i++)
	{
		st[x][y][i]=max(st[x-po[i-1]][y][i-1],st[x-po[i-1]][y-po[i-1]][i-1]);
		st[x][y][i]=max(st[x][y][i],st[x][y][i-1]);
		st[x][y][i]=max(st[x][y][i],st[x][y-po[i-1]][i-1]);
	}
	
	
	
}






















int main()
{
	int i,j,k,l;
	po[0]=1;
	for(i=1;i<11;i++)
	po[i]=po[i-1]*2;
	
	map[1][1]=10;
	deal(1,1);
	map[1][2]=15;
	deal(1,2);
	map[15][1]=1;
	deal(15,1);
	for(i=0;i<1024;i++)
	{
		for(j=0;j<1024;j++)
		{
			deal(i,j);
		}
		
	}
	
	printf("%d ",query(1,1,1,1));
	printf("%d ",query(1,2,1,1));
	printf("%d ",query(15,15,1,100));
	printf("%d ",query(1,1,1,2));
	printf("%d ",query(0,1023,0,1023));	
}
