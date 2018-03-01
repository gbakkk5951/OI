#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100005,inf=1e9;
int n,m,c[105],s,t,cnt=1,h[N],le[N],sum[105],ans,an;
bool del[105];
struct qwe
{
	int ne,to,va;
}e[N<<2];
struct qw
{
	int a,b,c;
}a[N];
void add(int u,int v,int w)
{
	cnt++;
	e[cnt].ne=h[u];
	e[cnt].to=v;
	e[cnt].va=w;
	h[u]=cnt;
}
void ins(int u,int v,int w)
{//cout<<u<<" "<<v<<" "<<w<<endl;
	add(u,v,w);
	add(v,u,0);
}
bool bfs()
{
	queue<int>q;
	memset(le,0,sizeof(le));
	le[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=e[i].ne)
			if(e[i].va>0&&!le[e[i].to])
			{
				le[e[i].to]=le[u]+1;
				q.push(e[i].to);
			}
	}
	return le[t];
}
int dfs(int u,int f)
{
	if(u==t||!f)
		return f;
	int us=0;
	for(int i=h[u];i&&us<f;i=e[i].ne)
		if(e[i].va>0&&le[e[i].to]==le[u]+1)
		{
			int t=dfs(e[i].to,min(e[i].va,f-us));
			e[i].va-=t;
			e[i^1].va+=t;
			us+=t;
		}
	if(!us)
		le[u]=0;
	return us;
}
int dinic()
{
	int re=0;
	while(bfs())
		re+=dfs(s,inf);
	return re;
}
int main()
{
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	scanf("%d",&n);
	m=1;
	while(~scanf("%d%d%d",&a[m].a,&a[m].b,&a[m].c))
	{
		c[a[m].c]=max(c[a[m].c],a[m].a);//cout<<a[m].a<<" "<<a[m].b<<" "<<a[m].c<<endl;
		c[a[m].c+1>n?1:a[m].c+1]=max(c[a[m].c+1>n?1:a[m].c+1],a[m].b);
		m++;
	}
	m--;//cout<<m<<endl;
	s=0,t=101;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+c[i];
	ans=sum[n];
	if((n&1)==0)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=c[i];j++)
			{
				if(i&1)
					ins(s,sum[i-1]+j,1);
				else
					ins(sum[i-1]+j,t,1);
			}
		for(int i=1;i<=m;i++)
		{
			if(a[i].c&1)
				ins(sum[a[i].c-1]+a[i].a,(a[i].c==n?0:sum[a[i].c])+a[i].b,inf);
			else
				ins((a[i].c==n?0:sum[a[i].c])+a[i].b,sum[a[i].c-1]+a[i].a,inf);
		}
		printf("%d\n",ans-dinic());
		return 0;
	}
	int w,mn=1e9;
	for(int i=1;i<=n;i++)
		if(c[i]<mn)
		{//cout<<c[i]<<"？？"<<endl;
			mn=c[i];
			w=i;
		}
	for(int i=0;i<(1<<mn);i++)
	{
		memset(del,0,sizeof(del));
		memset(h,0,sizeof(h));
		cnt=1;
		int x=i,su=ans;
		for(int j=1;j<=c[w];j++)
		{
			if(x&1)
			{
				del[sum[w-1]+j]=1;
				for(int i=1;i<=m;i++)
					if(sum[a[i].c-1]+a[i].a==sum[w-1]+j||(a[i].c==n?0:sum[a[i].c])+a[i].b==sum[w-1]+j)
					{
						if(!del[sum[a[i].c-1]+a[i].a])
							del[sum[a[i].c-1]+a[i].a]=1,su--;
						if(!del[(a[i].c==n?0:sum[a[i].c])+a[i].b])
							del[(a[i].c==n?0:sum[a[i].c])+a[i].b]=1,su--;
					}
			}
			else
				su--;
			x>>=1;
		}
		for(int i=1;i<=n;i++)
			if(i!=w)
				for(int j=1;j<=c[i];j++)
				{
					int now=i;
					if(i>w)
						now--;
					if(now&1)
						ins(s,sum[i-1]+j,1);
					else
						ins(sum[i-1]+j,t,1);
				}
		for(int i=1;i<=m;i++)
			if(a[i].c!=w&&a[i].c!=(w-1==0?n:w-1)&&!del[sum[a[i].c-1]+a[i].a]&&!del[(a[i].c==n?0:sum[a[i].c])+a[i].b])
			{//cout<<"???"<<endl;
				if((a[i].c-(a[i].c>w))&1)
					ins(sum[a[i].c-1]+a[i].a,(a[i].c==n?0:sum[a[i].c])+a[i].b,inf);
				else
					ins((a[i].c==n?0:sum[a[i].c])+a[i].b,sum[a[i].c-1]+a[i].a,inf);
			}
		an=max(an,su-dinic());
	}
	printf("%d\n",an);
	return 0;
}