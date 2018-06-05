#include<cstdio>
#include<algorithm>
using namespace std;
const int codeforces=5011;
int weizhi[codeforces]={},shuliang[codeforces]={};
struct uu{int y,size;}e[codeforces*2]={};int gen[codeforces]={};
struct ff{int x,y;}f[codeforces]={};
int n,m,qq;int v[codeforces]={},w[codeforces]={};
int mm[codeforces]={};int kj[codeforces]={};
int size[codeforces]={};
int dp[17][20111]={};int rudu[codeforces]={};
struct gg{int x,y,num,gg;}
aa[codeforces]={};int tou,wei,q[codeforces]={};
int ans[codeforces]={};
bool vis[55]={};int pos=1;int gtx[codeforces]={},num[codeforces]={};
bool cmpp(uu m,uu n){return m.size<n.size;}
bool cmp1(gg m,gg n){return m.gg<n.gg;}
int temp[codeforces]={};int maxx=0;
void dpp(int x)
{
	for(int i=1;i<=22;i++)
		if(!vis[i]){
			if(i>maxx)maxx=i;
			vis[i]=1,temp[x]=i;break;}
	for(int i=1;i<=20000;i++)
		dp[temp[x]][i]=dp[temp[gen[x]]][i];
	for(int i=v[x];i<=20000;i++)
		if(dp[temp[x]][i-v[x]]+w[x]>dp[temp[x]][i])
			dp[temp[x]][i]=dp[temp[x]][i-v[x]]+w[x];
}
void dfs(int a)
{
	gtx[pos++]=a;
	for(int i=weizhi[a];i<weizhi[a+1];i++)
		if(e[i].y!=gen[a])
			dfs(e[i].y);
	return;
}
void del(int x)
{
	vis[x]=0;
	for(int i=0;i<=20000;i++)
		dp[x][i]=0;
}
int main()
{
	freopen("1","r",stdin);
	freopen("3","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&v[i],&w[i]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&qq);
		gen[i]=qq;
		shuliang[i]++,shuliang[qq]++;
		f[i-1].x=i,f[i-1].y=qq;
	}
	for(int i=1;i<=n+1;i++)
		weizhi[i]=weizhi[i-1]+shuliang[i-1];
	for(int i=1;i<n;i++)
		e[weizhi[f[i].x]].y=f[i].y,e[weizhi[f[i].y]].y=f[i].x,weizhi[f[i].x]++,weizhi[f[i].y]++;
	for(int i=n+1;i>0;i--)
		weizhi[i]=weizhi[i-1];
	for(int i=1;i<=m;i++)
		scanf("%d",&aa[i].x),aa[i].num=i;
	for(int i=1;i<=m;i++)
		scanf("%d",&aa[i].y);
	for(int i=1;i<=n;i++)
		rudu[i]=shuliang[i]-1;
	tou=0,wei=-1,rudu[1]++;
	for(int i=1;i<=n;i++)
		if(rudu[i]==0)
			q[++wei]=i;
	while(tou<=wei)
	{
		int te=q[tou];
		rudu[gen[te]]--;
		if(rudu[gen[te]]==0)
			q[++wei]=gen[te];
		size[te]=1;
		for(int i=weizhi[te];i<weizhi[te+1];i++)
			if(e[i].y!=gen[te])
				size[te]+=size[e[i].y];
		tou++;
	}
	for(int i=0;i<weizhi[n+1];i++)
		e[i].size=size[e[i].y];
	for(int i=1;i<=n;i++)
		sort(e+weizhi[i],e+weizhi[i+1],cmpp);
	dfs(1);
	for(int i=1;i<=n;i++)
		num[gtx[i]]=i;
	for(int i=1;i<=m;i++)
		aa[i].gg=num[aa[i].y];
	sort(aa+1,aa+1+m,cmp1);
	for(int i=1;i<=n;i++)
		rudu[i]=shuliang[i]-1;
	pos=1;rudu[1]++;
	for(int i=1;i<=n;i++)
	{
		dpp(gtx[i]);
		rudu[gen[gtx[i]]]--;
		while(aa[pos].y==gtx[i])
			ans[aa[pos].num]=dp[temp[gtx[i]]][aa[pos].x],pos++;
		if(rudu[gen[gtx[i]]]==0)
			del(temp[gen[gtx[i]]]);
		if(rudu[gtx[i]]==0)
			del(temp[gtx[i]]);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	printf("%d\n",maxx);
}
