#include<cstdio>
#include<queue>
using namespace std;
int next[100],head[100],point[100],tot,n;
bool vis[100];
int len[100],c;
int g=1;
queue<int>q[2];
void add(int x,int y)
{
	tot++;
	point[tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}
void bfs()
{
	while(!q[1].empty()||!q[0].empty())
	{
	
	while(!q[c%2].empty())
	{
	
	int t=q[c%2].front(),f=head[t]; 
	q[c%2].pop() ;
    
	while(f!=0)
	{
		if(!vis[point[f]])
		{
		vis[point[f]]=true;
		q[(c+1)%2].push(point[f]);
		len[point[f]]=c+1;
	    }
		f=next[f];
	}
	
	
	}
	c++;  
    }
}
int main()
{
	
	scanf("%d",&n);
	int i=0;
	int t1,t2;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&t1,&t2);
		add(t1,t2);
		add(t2,t1);
	}
	q[0].push(1);
	vis[1]=true;
	bfs();
	for(i=1;i<=11;i++)
	printf("%d ",len[i]);
	
 } 
 
