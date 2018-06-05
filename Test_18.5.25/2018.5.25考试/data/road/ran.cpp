#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,m,q;
struct gg{int x,y;}f[1111111]={};
struct ff{int x,y,v,c,num,ran,uu;}e[1111111]={};
bool cmp1(gg m,gg n){return m.y<n.y;}
bool cmp2(ff m,ff n){return m.ran<n.ran;}
bool vis[1111111]={};
int main()
{
	srand(time(NULL));
	freopen("1","r",stdin);
	freopen("2","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].v,&e[i].c),e[i].num=i,e[i].ran=rand();
	for(int i=0;i<n-1;i++)
	{
		int temp;
		scanf("%d",&temp);
		vis[temp]=1;
	}
	for(int i=1;i<=n;i++)
		f[i].x=i,f[i].y=rand();
	sort(f+1,f+n+1,cmp1);
	for(int i=1;i<=m;i++)
		e[i].x=f[e[i].x].x,e[i].y=f[e[i].y].x;
	for(int i=1;i<=m;i++)
		if(vis[i])
			e[i].uu=1;
	sort(e+1,e+m+1,cmp2);
	printf("%d %d\n",n,m);
	for(int i=1;i<=100;i++)
		f[i].x=i,f[i].y=rand();
	sort(f+1,f+101,cmp1);
	for(int i=1;i<=m;i++)
		e[i].c=f[e[i].c].x;
	for(int i=1;i<=m;i++)
		printf("%d %d %d %d\n",e[i].x,e[i].y,e[i].v,e[i].c);
	for(int i=1;i<=m;i++)
		if(e[i].uu)
			printf("%d\n",i);
	return 0;
}
