#include<cstdio>
long long stfd[]={6,1,1,1,1,1,1,1,1,1};
int g;long long sum=0;
int n,m;
bool color[111111]={};
struct ff{int x,y,v,c,num;}e[2111111]={},f[1111111]={};
int weizhi[1111111]={},shuliang[1111111]={};int q[1111111]={};
bool vis[1111111]={},vis2[1111111]={};
void cal()
{
	long long tee=0;
	for(int i=1;i<=m;i++)
		if(vis[i])
			color[f[i].c]=1,tee+=f[i].v;
	for(int i=1;i<=100000;i++)
		if(color[i])
			sum++;
	sum*=tee;
}
int main()
{
	freopen("1","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&f[i].x,&f[i].y,&f[i].v,&f[i].c),shuliang[f[i].x]++,shuliang[f[i].y]++,f[i].num=i;
	for(int i=1;i<=n+1;i++)
		weizhi[i]=weizhi[i-1]+shuliang[i-1];
	for(int i=1;i<=m;i++)
		e[weizhi[f[i].x]].y=f[i].y,e[weizhi[f[i].y]].y=f[i].x,e[weizhi[f[i].x]].v=e[weizhi[f[i].y]].v=f[i].v,
		e[weizhi[f[i].x]].c=e[weizhi[f[i].y]].c=f[i].c,e[weizhi[f[i].x]].num=e[weizhi[f[i].y]].num=f[i].num,
		weizhi[f[i].x]++,weizhi[f[i].y]++;
	for(int i=n+1;i>0;i--)
		weizhi[i]=weizhi[i-1];
	int temp;
	for(int i=1;i<n;i++)
		scanf("%d",&temp),vis[temp]=1;
	cal();
	int tou=0,wei=0;
	q[0]=1,vis2[1]=1;
	while(tou<=wei)
	{
		int te=q[tou];
		for(int i=weizhi[te];i<weizhi[te+1];i++)
			if(vis[e[i].num]&&!vis2[e[i].y])
				vis2[e[i].y]=1,q[++wei]=e[i].y;
		tou++;
	}
	for(int i=1;i<=n;i++)
		if(!vis2[i])
		{
			printf("¨º?3?¦Ì?2?¨º?¨¢?¨ª¡§¨ª?\n");
			return 0;
		}
	printf("%lld\n",sum);
}
