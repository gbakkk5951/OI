#include<cstring>
#include<cstdio>
#include<vector> 
#include<algorithm>
using namespace std;
char a[802],b[802];
int re[5];
int dis[256];
bool read();
void search();

int la,lb;
int maxn=0;
int mx[1400000];

void clear();

int pmax(int a,int b,int c,int d)
{int temp=a;
if(b>temp)
temp=b;
if(c>temp)
temp=c;
if(d>temp)
return d;
return temp;
}


void insert(int x,int y,int val);
int findmax(int root,int xl,int xr,int yl,int yr,int nxl,int nxr,int nyl,int nyr,int iter);
//vector<dp>data;
int iter[11];
int beg[11];
void initialize()
{
	iter[0]=1;
	beg[0]=1;
	int i=0;
	for(i=1;i<12;i++)
	{iter[i]=iter[i-1]*4;
	beg[i]=beg[i-1]+iter[i-1];
	}

} 
/*int finditer(int x)
{
	int i;
	for(i=0;i<11;i++)
	if(beg[i]<=x&&x<beg[i+1])
	return i;
	
}*/



int main()
{
initialize();
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
clear();
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

int max=findmax(1,1,1024,1,1024,xl,xr,yl,yr,0)+1;
if(maxn<max)
maxn=max;
//printf("insert");
insert(i,j,max);

}}

}


}

void insert(int x,int y,int val)
{
//printf("insert(xl=%d,xr%d)",yl,yr);
int iter=0;
int now=1;
int xl=1,xr=1024,yl=1,yr=1024;
int xmid=512,ymid=512;
while(iter<10)
{
	if(val>mx[now])
	mx[now]=val;
	if(x<=xmid)
	{if(y<=ymid)
	    {
		 now=beg[iter+1]+4*(now-beg[iter])+2;//3象限 
	     xr=xmid;
	     yr=ymid;
	     }
	else {now=beg[iter+1]+4* (now-beg[iter])+1;//2象限 
	     xr=xmid;
	     yl=ymid+1;
	     }
	}
	else{
		if(y<=ymid)
		{now=beg[iter+1]+4*(now-beg[iter])+3;//4象限 
		xl=xmid+1;
		yr=ymid;
	    }
		else{ now=beg[iter+1]+4*(now-beg[iter]);//1象限 
		xl=xmid+1;
		yl=ymid+1;
	        }
	}
	
	iter++;
	xmid=(xl+xr)>>1;
	ymid=(yl+yr)>>1;
}


mx[now]=val; 
	

}

int findmax(int root,int xl,int xr,int yl,int yr,int nxl,int nxr,int nyl,int nyr,int iter)
{
	if(nxl>xr||nxr<xl||nyl>yr||nyr<yl)
	return 0;
	if(nxl<=xl&&nxr>=xr&&nyl<=yl&&nyr>=yr)
	return mx[root];
	//进一步四分 
	int xmid=(xl+xr)/2;
	int ymid=(yl+yr)/2;
	
		int kid1,kid2,kid3,kid4,ans1,ans2,ans3,ans4;
		kid1=beg[iter+1]+4*(root-beg[iter]);
		kid2=beg[iter+1]+4*(root-beg[iter])+1;
		kid3=beg[iter+1]+4*(root-beg[iter])+2;
		kid4=beg[iter+1]+4*(root-beg[iter])+3;
		
		ans1=findmax(kid1,xmid+1,xr,ymid+1,yr,nxl,nxr,nyl,nyr,iter+1);
		ans2=findmax(kid2,xl,xmid,ymid+1,yr,nxl,nxr,nyl,nyr,iter+1);
		ans3=findmax(kid3,xl,xmid,yl,ymid,nxl,nxr,nyl,nyr,iter+1);
		ans4=findmax(kid4,xmid+1,xr,yl,ymid,nxl,nxr,nyl,nyr,iter+1);
	
	return(pmax(ans1,ans2,ans3,ans4));}

void clear()
{
memset(mx,0,1400000);

}
