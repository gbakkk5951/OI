#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int tgt=1000;
struct ff{int x,y,v,c,num;}e[1111111]={};
long long t1=0,t2=0;
long long pos=0,tee=123456789123456789LL;
int gen[111111]={};
bool vis[111]={},vis2[111]={};
int n=1000000,m=1000000;
int find(int x){if(gen[x]==x)return x;else return find(gen[x]);}
bool cmpp(ff m,ff n){return m.v<n.v;}
int jj(int a)
{
	int cnt=0;
	while(a){if(a&1)cnt++;a>>=1;}
	return cnt;
}
void ttt()
{
	for(int i=1;i<=106;i++)
		vis2[i]=vis[i];
}
void llll()
{
	for(int i=1;i<=m;i++)
		if(vis[i])
			printf("%d ",i);
	printf("\n");
}
int uuuu()
{
	bool vis3[111]={};
	int cnt1=0;
	for(int i=1;i<=m;i++)
		if(!vis[i])
			vis3[e[i].c]=1;
	for(int i=1;i<=100;i++)
		if(vis3[i])
			cnt1++;
	//printf("%d\n",cnt1);
	return cnt1;
}
int ppp=0;
void check()
{
	ppp++;
	if(ppp%100000==0)
		llll();
	for(int i=1;i<=n;i++)
		gen[i]=i;
	long long cnt=0;int uuu=0;
	for(int i=1;i<=m;i++)
	{
		//if(a&(1<<e[i].c-1))
		if(vis[i])
			continue;
		{
			gen[e[i].x]=find(e[i].x),gen[e[i].y]=find(e[i].y);
			if(gen[e[i].x]!=gen[e[i].y])
			{
				gen[gen[e[i].x]]=gen[e[i].y],gen[e[i].x]=gen[e[i].y];
				cnt+=e[i].v;
				uuu++;
				//printf("%d\n",e[i].num);
			}
		}
		
	}
	for(int i=1;i<n;i++)
		if(find(i)!=find(i+1))
			return;
	//cnt*=jj(a);
	cnt*=uuuu();
	if(cnt<tee)
		tee=cnt,ttt();
}
void lll()
{
	for(int i=1;i<=m;i++)
		if(vis2[i])
			printf("%d ",i);
	printf("\n");
}
void dfs(int a,int b)
{
	if(b==0)
	{check();return;}
	if(a>m)return;
	for(int i=a;i<=m;i++)
		vis[i]=1,dfs(i+1,b-1),vis[i]=0;
}
int main()
{
	srand(time(NULL));
	int s,t;
	scanf("%d%d",&s,&t);
	freopen("1","r",stdin);
	//freopen("2","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].v,&e[i].c),e[i].num=i;
	//sort(e+1,e+m+1,cmpp);
	for(int i=s;i<=t;i++)
	{
		vis[i]=1;
		dfs(i+1,6);
		vis[i]=0;
	}
	for(int i=1;i<=106;i++)
		printf("%d\n",i);
	lll();
}

