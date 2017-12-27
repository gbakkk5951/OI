#include<cstdio>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
bool vis[2510];


struct N
{
	int val,point;
    friend bool operator < (N a,N b)
    {return a.val>b.val;
	}

};

priority_queue<N>pq;
int pn,en,ed,beg;
int d[2510];
int head[2510],point[12420],nxt[12420];
int val[12420];
int tot;
void add(int x,int y,int vl)
{
	tot++;
	point[tot]=y;
	val[tot]=vl;
	nxt[tot]=head[x];
	head[x]=tot;
}


int main()
{
    int i,j,k,l;
	for(i=0;i<2510;i++)
d[i]=2147483647;

	scanf("%d%d%d%d",&pn,&en,&beg,&ed);
	d[beg]=0;
	for(i=0;i<en;i++)
	{
		scanf("%d%d%d",&j,&k,&l);
		add(j,k,l);
		add(k,j,l);
	}
	j=head[beg];
	N te;
	while(j)
	{
		te.val=val[j];
		te.point=point[j];
		pq.push(te); 
		d[point[j]]=val[j];
		j=nxt[j];
	}
	vis[beg]=true;
	while(!pq.empty())
	{
		N p=pq.top();
		j=head[p.point];
		
	//	printf("%d",p.point);
		if(!vis[p.point])
		{
		vis[p.point]=true;
		while(j)
		{
			if(d[p.point]+val[j]<d[point[j]])
			d[point[j]]=d[p.point]+val[j];
			N tm;
			tm.point=point[j];
			tm.val=d[point[j]];
			
			
			
			pq.push(tm); 
		//	printf("%d->%d;",p.point,point[j]);
		    
			j=nxt[j];
		}
	
	    }	pq.pop() ;
	}
	printf("%d",d[ed]);
	
}
