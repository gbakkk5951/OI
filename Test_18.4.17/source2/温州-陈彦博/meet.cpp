#include<cstdio>
#include<cstring>
#include<algorithm>
#define MO 1000000007
using namespace std;
int du[240000],cnt,id[240000],ee,h,dd[240000],di[240000],w1,w2,t,fl,u1,v1,t1,u2,v2,l1,l2,t2,to[240000],f[240000];
int c[240000][2],a[110000],n,q,u,v,w,tot,g[240000],k[240000],ji[240000],de[110000],d[110000][15];
inline int read(){
    int ret=0;char c=getchar();
    while((c>'9')||(c<'0'))c=getchar();
    while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
    return ret;
}

void dfs(int x,int fa,int deep){
	de[x]=deep; d[x][0]=fa;
	for(int o=a[x];o;o=c[o][1])
	if(c[o][0]!=fa)
	{
	    to[c[o][0]]=o;
	    dfs(c[o][0],x,deep+1);
    }
}

int lca(int a,int b)
{
	if (de[a]>de[b])swap(a,b);
	for(int j=9;j>=0;j--)if(de[d[b][j]]>=de[a])b=d[b][j];
	if(a==b)return a;
	for(int j=9;j>=0;j--)if(d[a][j]!=d[b][j])a=d[a][j],b=d[b][j];
	return d[a][0];
}

void bfs(){
	int q;
	dd[q=1]=ee;
	for(int i=1; i<=q; ++i)
	{
		int x=dd[i];
	    for(int o=a[x];o;o=c[o][1])
	    if(!id[c[o][0]])
	    {
	        id[c[o][0]]=++cnt;
	        h+=f[o];
	        di[cnt]=h;
	        dd[++q]=c[o][0];
        }
    }
}
int main()
{
    freopen("meet.in","r",stdin);
	freopen("meet.out","w",stdout);
	n=read(); 	q=read();
	if(n<=100)
	{
	    for(int i=1; i<n; ++i)
	    {
		    u=read();
		    v=read();
	    	w=read();
		    c[++tot][0]=v; c[tot][1]=a[u]; a[u]=tot; f[tot]=w;
		    c[++tot][0]=u; c[tot][1]=a[v]; a[v]=tot; f[tot]=w;
		}
		dfs(1,0,1);
		for(int i=1;i<=9;i++)
	    for(int j=1;j<=n;j++)d[j][i]=d[j+(1<<(i-1))][i-1];
	    
		for(int i=1; i<=q; ++i)
		{
			memset(k,0,sizeof(k));
			memset(ji,0,sizeof(ji));
			u1=read();	v1=read();	t1=read();
			u2=read();	v2=read();	t2=read();
			l1=lca(u1,v1);
			u=u1;
			while(u!=l1)
			{
				k[to[u]]=t1;
				t1+=f[to[u]];
				ji[to[u]]=t1;
				u=d[u][0];
			}
			v=v1;
			tot=0;
			while(v!=l1)
			{
				g[++tot]=to[v];
				v=d[v][0];
			}
			for(int i=tot; i; --i)
			{
				k[g[i]]=t1;
				t1+=f[g[i]];
				ji[g[i]]=t1;
			}
			
			
			l2=lca(u2,v2);
			u=u2;
			fl=1;
			while(u!=l2)
			{
				t=t2+f[to[u]];
				w1=k[to[u]];
				w2=ji[to[u]];
				if(t2<w2&&t>w1)
				{ fl=0; break; }
				t2=t;
				u=d[u][0];
			}
			v=v2;
			tot=0;
			while(v!=l2)
			{
				g[++tot]=to[v];
				v=d[v][0];
			}
			
			for(int i=tot; i; --i)
			{
				t=t2+f[g[i]];
				w1=k[g[i]];
				w2=ji[g[i]];
				if(t2<w2&&t>w1)
				{ fl=0;break; }
				t2=t;
			}
			
			if(fl)puts("NO");
			else puts("YES");
		}
		return 0;
	}
	for(int i=1; i<n; ++i)
	{
		u=read(); v=read(); w=read();
		c[++tot][0]=v; c[tot][1]=a[u]; a[u]=tot; f[tot]=w;
		c[++tot][0]=u; c[tot][1]=a[v]; a[v]=tot; f[tot]=w;
		++du[u];
		++du[v];
	}
	for(int i=1; i<=n; ++i)if (du[i]==1)
	{
		ee=i;
		break;
	}
	id[ee]=1;
	cnt=1;
	bfs();
	for(int i=1; i<=q; ++i)
	{
		u1=read();	v1=read();	t1=read();
		u2=read();	v2=read();	t2=read();
		if(id[u1]<id[v1])
		{
			if(id[u2]<id[v2])
			{
				puts("NO");
				continue;
			}
			puts("YES");
			continue;
		}
		if(id[u2]>id[v2])
		{
			puts("NO");
			continue;
		}
		puts("YES");
	}
}
