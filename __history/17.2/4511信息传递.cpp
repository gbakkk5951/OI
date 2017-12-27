#include<cstdio>
#include<algorithm>

bool vis[200010];
struct st
{
	int g;
	int in;
	bool del;
	bool friend operator <(st ca,st cb)
	{
		return ca.in <cb.in ;
	}
	
}data[200010];

int index[200010];

using namespace std;

int n;
int ans=2147483647;

void del(int po)
{
	data[po].del =true;
	data[data[po].g].in --;
	if(!(data[data[po].g].in))
	del(data[po].g);
}

int main()
{
	int i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		data[j-1].in ++;
		data[i].g =j-1;
	}
	for(i=0;i<n;i++)
	{
		if(!(data[i].del)&&!(data[i].in) )
		{del(i);
		}
	}

	for(i=0;i<n;i++)
	{if(vis[i]||data[i].del)
	continue;
	int times=1;
		int now=i;
		vis[i]=true;
		while(data[now].g !=i)
		{
		//	printf("%d-",now);
			j=data[now].g;
					
					vis[j]=true;
					now=j;
					times++;
			
			
		}
		ans=min(ans,times);
	}
	printf("%d",ans);
	
}
