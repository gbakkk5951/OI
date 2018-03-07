#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 5000005
#define ll long long
using namespace std;
//====================================================
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
//====================================================
int bin[20];
int n,q,cnt,tot,place,size,tmp;
int T[100005],hash[100005];
int f[100005],a[100005],b[100005];
int fa[100005][17],son[100005],deep[100005],belong[100005],pl[100005];
int root[300005];
int w[M],v[M],s[M],rnd[M],ls[M],rs[M];
bool vis[100005];
//====================================================
struct data{int to,next;}e[200005];int head[100005];
void ins(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
	e[++cnt].to=u;e[cnt].next=head[v];head[v]=cnt;
}
//==================================================== 边表 
int find(int x)
{
	int l=1,r=tot;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(hash[mid]<x)l=mid+1;
		else if(hash[mid]==x)return mid;
		else r=mid-1;
	}
	return l;
}
//==================================================== 二分查找 
void dfs1(int x) 
{
	son[x]=1;vis[x]=1;
	for(int i=1;i<=16;i++)
	    if(bin[i]<=deep[x])fa[x][i]=fa[fa[x][i-1]][i-1];
	    else break;
	for(int i=head[x];i;i=e[i].next)
	{
		if(vis[e[i].to])continue;
		deep[e[i].to]=deep[x]+1;
		fa[e[i].to][0]=x;
		dfs1(e[i].to);
		son[x]+=son[e[i].to];
	}
}
void dfs2(int x,int chain)
{
	place++;pl[x]=place;belong[x]=chain;
	int k=0;
	for(int i=head[x];i;i=e[i].next)
	    if(son[e[i].to]>son[k]&&deep[e[i].to]>deep[x])
	        k=e[i].to;
	if(!k)return;
	dfs2(k,chain);
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=k&&deep[e[i].to]>deep[x])
            dfs2(e[i].to,e[i].to);
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;i<=16;i++)
	    if(bin[i]&t)x=fa[x][i];
	for(int i=16;i>=0;i--)
	    if(fa[x][i]!=fa[y][i])
	        x=fa[x][i],y=fa[y][i];
	if(x==y)return x;
	return fa[x][0];
}
//================================================= 预处理 
void update(int k){s[k]=s[ls[k]]+s[rs[k]]+w[k];}
void rturn(int &k)
{int t=ls[k];ls[k]=rs[t];rs[t]=k;update(k);update(t);k=t;}
void lturn(int &k)
{int t=rs[k];rs[k]=ls[t];ls[t]=k;update(k);update(t);k=t;}
void insert(int &k,int num)
{
	if(!k){k=++size;rnd[k]=rand();w[k]=s[k]=1;v[k]=num;return;}
	s[k]++;
	if(num==v[k]){w[k]++;return;}
	else if(num<v[k]){insert(ls[k],num);if(rnd[ls[k]]<rnd[k])rturn(k);}
	else {insert(rs[k],num);if(rnd[rs[k]]<rnd[k])lturn(k);}
}
void del(int &k,int num)
{
	if(!k)return;
	if(num==v[k])
	{
		if(w[k]>1){w[k]--;s[k]--;return;}
		if(ls[k]*rs[k]==0)k=ls[k]+rs[k];
		else if(rnd[ls[k]]<rnd[rs[k]]){rturn(k);del(k,num);}
		else {lturn(k);del(k,num);}
	}
	else if(num<v[k])
	    {del(ls[k],num);s[k]--;}
	else {del(rs[k],num);s[k]--;}
}
void askrank(int k,int num)
{
	if(!k)return;
	if(num==v[k]){tmp+=s[rs[k]];return;}
	else if(num<v[k]){tmp+=s[rs[k]]+w[k];askrank(ls[k],num);}
	else askrank(rs[k],num);
}
//==================================================== 平衡树 
void change(int k,int l,int r,int pos,int x,int y)
{
	del(root[k],x);insert(root[k],y);
	if(l==r)return;
	int mid=(l+r)>>1;
	if(pos<=mid)change(k<<1,l,mid,pos,x,y);
	else change(k<<1|1,mid+1,r,pos,x,y);
}
void ask(int k,int l,int r,int x,int y,int num)
{
	if(x==l&&y==r){askrank(root[k],num);return;}
	int mid=(l+r)>>1;
	if(y<=mid)ask(k<<1,l,mid,x,y,num);
	else if(x>mid)ask(k<<1|1,mid+1,r,x,y,num);
	else 
	{ask(k<<1,l,mid,x,mid,num);ask(k<<1|1,mid+1,r,mid+1,y,num);}
}
//==================================================== 线段树 
void getrank(int x,int f,int num)
{
	while(belong[x]!=belong[f])
	{
		ask(1,1,n,pl[belong[x]],pl[x],num);
		x=fa[belong[x]][0];
	}
	ask(1,1,n,pl[f],pl[x],num);
}
//====================================================树链剖分 
void solve(int x,int y,int rank)
{
	int t=lca(x,y),ans=-1;
	tmp=0;getrank(y,t,0);getrank(x,t,0);
	if(tmp-1<rank)
	    {printf("invalid request!\n");return;}
	int l=1,r=tot;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		tmp=0;
		getrank(x,t,mid);
		getrank(y,t,mid);
		if(T[t]>mid)tmp--;
		 if(tmp<=rank-1){r=mid-1;ans=mid;}
        else l=mid+1;
	}
	printf("%d\n",hash[ans]);
}
//====================================================
int main()
{
	bin[0]=1;for(int i=1;i<=16;i++)bin[i]=(bin[i-1]<<1);
	n=read();q=read();
	for(int i=1;i<=n;i++)
	    T[i]=read(),hash[++tot]=T[i];
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ins(u,v);
	}
	dfs1(1);dfs2(1,1);
	for(int i=1;i<=q;i++)
	{
		f[i]=read(),a[i]=read(),b[i]=read();
		if(!f[i])hash[++tot]=b[i];
	}
	sort(hash+1,hash+tot+1);
	int top=1;
	for(int i=2;i<=tot;i++)
	    if(hash[i]!=hash[i-1])hash[++top]=hash[i];
	tot=top;
    for(int i=1;i<=n;i++)T[i]=find(T[i]);
    for(int i=1;i<=q;i++)if(!f[i])b[i]=find(b[i]);
    for(int i=1;i<=n;i++)change(1,1,n,pl[i],0,T[i]);
	for(int i=1;i<=q;i++)
	    if(!f[i])
		{
	    	change(1,1,n,pl[a[i]],T[a[i]],b[i]);
	    	T[a[i]]=b[i];
	    }
	    else solve(a[i],b[i],f[i]);
	return 0;
}
