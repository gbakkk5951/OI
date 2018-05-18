#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define si scanf
#define so printf
#define N 30000100
#define M 
#define INF  
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	bool mns=0; 
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp=='-')	mns=1;
		if(tmp==EOF)	return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	if(mns)	r=-r;
	return 1;
} 
int n;
long long lst,ans;
inline int gener(int alst)
{
	return ((1714636915LL*alst + 1681692777)%1000000007)*((846930886LL*lst + 1804289383)%1000000007)%1000000007;
}
int np;
int v[N];
int ch[N][2],h[N];
namespace bg
{
	int rt,cnt;
	int merge(int a,int b)
	{
		if(a==0||b==0)
			return a|b;
		if(v[a]<v[b])
			swap(a,b);
		ch[a][1]=merge(ch[a][1],b);
		if(h[ch[a][1]]>h[ch[a][0]])
			swap(ch[a][1],ch[a][0]);
		h[a]=h[ch[a][1]]+1;
		return a;
	}
	inline void push(int val)
	{
		int o=++np;
		v[o]=val;
		rt=merge(rt,o);
		++cnt;
	}
	inline long long top()
	{
		return v[rt];
	}
	inline int pop()
	{
		int re=rt;
		rt=merge(ch[rt][0],ch[rt][1]);
		--cnt;
		ch[re][0]=ch[re][1]=h[re]=0;
		return re;
	}
}
namespace sml
{
	int rt,cnt;
	int merge(int a,int b)
	{
		if(a==0||b==0)
			return a|b;
		if(v[a]>v[b])
			swap(a,b);
		ch[a][1]=merge(ch[a][1],b);
		if(h[ch[a][1]]>h[ch[a][0]])
			swap(ch[a][1],ch[a][0]);
		h[a]=h[ch[a][1]]+1;
		return a;
	}
	inline void push(long long val)
	{
		int o=++np;
		v[o]=val;
		rt=merge(rt,o);
		++cnt;
	}
	inline long long top()
	{
		return v[rt];
	}
	inline int pop()
	{
		int re=rt;
		rt=merge(ch[rt][0],ch[rt][1]);
		--cnt;
		ch[re][0]=ch[re][1]=h[re]=0;
		return re;
	}
}
void bg_to_sml()
{
	int o=bg::pop();
	sml::rt=sml::merge(sml::rt,o);
	++sml::cnt;
}
void sml_to_bg()
{
	int o=sml::pop();
	bg::rt=bg::merge(bg::rt,o);
	++bg::cnt;
}
int main()
{
	freopen("mid.in","r",stdin);
	freopen("mid.out","w",stdout);
	int a;
	rd(n),rd(a);
	lst=a;
	ans^=lst;
	bg::push(a);
	for(int i=2;i<=n;++i)
	{
		a=gener(a);
		if(a<=bg::top())
			bg::push(a);
		else
			sml::push(a);
		while(bg::cnt>((i+1)>>1))
			bg_to_sml();
		while(bg::cnt<((i+1)>>1))
			sml_to_bg();
		lst=bg::top();
		ans^=lst;
		
	}
	so("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
