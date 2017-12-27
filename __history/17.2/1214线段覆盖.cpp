#include<cstdio>
#include<algorithm>

using namespace std;
struct edge
{
	int l;
	int r;
	
}data[101];


bool cmp(edge a,edge b)
{
	if(a.l==b.l)
	{
		return a.r<b.r; 
	}
	else
	{
		if(a.l<b.l&&a.r>b.r)
		return false;
		if(b.l<a.l&&b.r>a.r)
		return true;
		
		return a.l<b.l;
	}
	
}
int tot;
int main()
{
	int n;
	int i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		j+=1000;
		k+=1000;
		if(j<k)
	{
		data[i].l=j;
		data[i].r=k;
	}
	else
	{
		data[i].l=k;
		data[i].r=j;	
	}
		
	}
	sort(data,data+n,cmp);
	
	int lr=0;
	for(i=0;i<n;i++)
	{
		if(data[i].l <lr)
		{
			tot++;
		}
		else
		{
			lr=data[i].r;
		}	
	}
	printf("%d",n-tot);	
 } 
