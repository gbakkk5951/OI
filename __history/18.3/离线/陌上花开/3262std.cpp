#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define M 5000005
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,sz,tmp;
int root[200005],ans[100005],sum[100005];
int s[M],ls[M],rs[M],v[M],w[M],rnd[M];
struct data{int a,b,c;}a[100005];
inline bool cmp(data a,data b)
{
	if(a.a==b.a&&a.b==b.b)return a.c<b.c;
	if(a.a==b.a)return a.b<b.b;
	return a.a<b.a;
}
inline int lowbit(int x){return x&(-x);}
void update(int x)
{s[x]=s[ls[x]]+s[rs[x]]+w[x];}
void rturn(int &k)
{int t=ls[k];ls[k]=rs[t];rs[t]=k;update(k);update(t);k=t;}
void lturn(int &k)
{int t=rs[k];rs[k]=ls[t];ls[t]=k;update(k);update(t);k=t;}
void ins(int &k,int num)
{
	if(!k){k=++sz;rnd[k]=rand();v[k]=num;s[k]=w[k]=1;return;}
	s[k]++;
	if(num==v[k]){w[k]++;return;}
	else if(num<v[k]){ins(ls[k],num);if(rnd[ls[k]]<rnd[k])rturn(k);}
	else {ins(rs[k],num);if(rnd[rs[k]]<rnd[k])lturn(k);}
}
void getrank(int k,int num)
{
	if(!k)return;
	if(num==v[k]){tmp+=s[ls[k]]+w[k];return;}
	else if(num<v[k])getrank(ls[k],num);
	else {tmp+=s[ls[k]]+w[k];getrank(rs[k],num);}
}
void ask(int x,int num)
{
	for(int i=x;i;i-=lowbit(i))
	    getrank(root[i],num);
}
void insert(int x,int num)
{
	for(int i=x;i<=m;i+=lowbit(i))
	    ins(root[i],num);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	    a[i].a=read(),a[i].b=read(),a[i].c=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	    {
	    	if(a[i].a==a[i+1].a&&a[i].b==a[i+1].b&&a[i].c==a[i+1].c&&i!=n)
	    	    sum[i+1]+=sum[i]+1;
	    	else 
	    	{
	        	tmp=0;
	        	ask(a[i].b,a[i].c);
	        	ans[tmp]+=sum[i]+1;
	    	}
			insert(a[i].b,a[i].c);
		}
	for(int i=0;i<n;i++)
	    printf("%d\n",ans[i]);
	return 0;
}
