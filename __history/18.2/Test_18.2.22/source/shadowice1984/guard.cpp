#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int m;int k[60];bool book[120];
struct data{int v;int nxt;int cot;}edge[200010];
int reset[200010];
int alist[120];int cnt=1;
inline void add(int u,int v,int cot)
{
	edge[++cnt].v=v;edge[cnt].nxt=alist[u];alist[u]=cnt;edge[cnt].cot=cot;reset[cnt]=cot;
	edge[++cnt].v=u;edge[cnt].nxt=alist[v];alist[v]=cnt;edge[cnt].cot=0;reset[cnt]=0;
}
queue <int> q;int dep[120];int s;int t;
int tr[50][20];int ctt;
inline bool bfs()
{
	for(int i=1;i<=ctt;i++){dep[i]=0x3f3f3f3f;}
	q.push(s);dep[s]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		int nxt=alist[now];
		while(nxt)
		{
			int v=edge[nxt].v;int cot=edge[nxt].cot;
			if(dep[v]==0x3f3f3f3f&&cot!=0&&!book[v])
			{dep[v]=dep[now]+1;q.push(v);}
			nxt=edge[nxt].nxt;
		}
	}
	return dep[t]!=0x3f3f3f3f;
}
int dfs(int x,int lim)
{
	if(x==t){return lim;}
	int nxt=alist[x];int nowflow=0;
	while(nxt)
	{
		int v=edge[nxt].v;int cot=edge[nxt].cot;
		if(dep[v]==dep[x]+1&&cot!=0)
		{
			int del=dfs(v,min(cot,lim));
			nowflow+=del;lim-=del;
			edge[nxt].cot-=del;edge[nxt^1].cot+=del;
			if(!lim)break;
		}
		nxt=edge[nxt].nxt;
	}
	if(nowflow==0){dep[x]=0x3f3f3f3f;}
	return nowflow;
}
struct query{int a;int b;int c;}qu[2100];int qt=1;int flow;int res;
struct data1{int v;int nxt;}edge1[2100];int alist1[20];int cnt1;
inline void add1(int u,int v)
{edge1[++cnt1].v=v;edge1[cnt1].nxt=alist1[u];alist1[u]=cnt1;}
inline int trt(int x){return (x==m)?1:x+1;}
int main()
{
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	scanf("%d",&m);
	while(scanf("%d%d%d",&qu[qt].a,&qu[qt].b,&qu[qt].c)!=-1)
	{int a=qu[qt].a;int b=qu[qt].b;int c=qu[qt].c;
	k[c]=max(k[c],a);k[trt(c)]=max(k[trt(c)],b);qt++;}qt-=1;
	for(int i=1;i<=m;i++){for(int j=1;j<=k[i];j++){tr[i][j]=++ctt;}}
	flow=ctt;s=++ctt;t=++ctt;
	if(m%2==0)
	{
		for(int i=1;i<=m;i+=2){for(int j=1;j<=k[i];j++){add(s,tr[i][j],1);}}
		for(int i=2;i<=m;i+=2){for(int j=1;j<=k[i];j++){add(tr[i][j],t,1);}}
		for(int i=1;i<=qt;i++)
		{
			int a=qu[i].a;int b=qu[i].b;int c=qu[i].c;
			if(c%2==0){add(tr[trt(c)][b],tr[c][a],1);}
			else {add(tr[c][a],tr[trt(c)][b],1);}
		}
		while(bfs()){flow-=dfs(s,0x3f3f3f);}
		printf("%d",flow);return 0;
	}
	else
	{
		int mi;int mini=0x3f3f3f3f;for(int i=1;i<=m;i++)
		{if(k[i]<mini){mini=k[i];mi=i;}}
		for(int i=1;i<=m;i+=2){if(i==mi)continue;for(int j=1;j<=k[i];j++){add(s,tr[i][j],1);}}
		for(int i=2;i<=m;i+=2){if(i==mi)continue;for(int j=1;j<=k[i];j++){add(tr[i][j],t,1);}}
		for(int i=1;i<=qt;i++)
		{
			int a=qu[i].a;int b=qu[i].b;int t1=qu[i].c;int t2=trt(t1);
			if(t1==mi){add1(a,tr[t2][b]);continue;}
			if(t2==mi){add1(b,tr[t1][a]);continue;}
			if(t1%2==0){add(tr[t2][b],tr[t1][a],1);}
			else {add(tr[t1][a],tr[t2][b],1);}
		}
		for(int i=0;i<=(1<<mini)-1;i++)
		{
			int nas=flow-mini;
			for(int j=1,p=i;p;p>>=1,j++)
			{
				if((p&1)==0)continue;
				int nxt=alist1[i];nas++;
				while(nxt)
				{
					int v=edge1[nxt].v;
					book[v]=true;nas--;
					nxt=edge1[nxt].nxt;
				}
			}
			while(bfs()){nas-=dfs(s,0x3f3f3f3f);}
			res=max(res,nas);
			for(int i=1;i<=cnt;i++){edge[i].cot=reset[i];}
			for(int i=1;i<=ctt;i++){book[i]=false;}
		}
		printf("%d",res);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

