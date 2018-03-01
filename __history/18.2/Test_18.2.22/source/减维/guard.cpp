//by ¼õÎ¬
#include<set>
#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define il inline
#define db double
#define rg register
#define mpr make_pair
#define maxn 105
#define eps 1e-8
#define inf (1<<30)
#define pi 3.1415926535897932384626L
using namespace std;

inline int read()
{
    int ret=0;bool fla=0;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-'){fla=1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return fla?-ret:ret;
}

struct edge{
	int to,ne;
}e[maxn*maxn*4];

struct node{
	int id,cnt;
}poi[maxn*maxn];

int n,a,b,c,d,cnt,ans,tmp,ecnt,id[maxn][maxn],head[maxn*maxn];
bool pd[maxn*maxn];

inline bool cmp(node x,node y){return x.cnt<y.cnt;}

void add(int x,int y)
{
	e[++ecnt]=(edge){y,head[x]};head[x]=ecnt;
	e[++ecnt]=(edge){x,head[y]};head[y]=ecnt;
	poi[x].cnt++;
	poi[y].cnt++;
}

int main()
{
	freopen("guard.in","r",stdin);
	freopen("guard.out","w",stdout);
	n=read();
	srand(time(0));
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		d=c==n?1:c+1;
		if(!id[c][a]) id[c][a]=++cnt;
		if(!id[d][b]) id[d][b]=++cnt;
		add(id[c][a],id[d][b]);
	}
	for(int i=1;i<=cnt;++i) poi[i].id=i;
	sort(poi+1,poi+cnt+1,cmp);
	for(int num=1;num<=100000;++num)
	{
		tmp=0;
		memset(pd,0,sizeof pd);
		for(int i=1;i<=cnt;++i)
		{
			int x=poi[i].id;
			if(pd[x]) continue ;
			tmp++;pd[x]=1;
			for(int j=head[x];j;j=e[j].ne) pd[e[j].to]=1;
		}
		ans=max(ans,tmp);
		for(int i=1;i<=cnt;++i) swap(poi[rand()%cnt+1],poi[rand()%cnt+1]);
	}
	printf("%d",ans);
	return 0;
}


























